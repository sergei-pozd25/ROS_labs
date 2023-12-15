#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <vector>
#include <string>
#include<opencv2/videoio.hpp>

const int THRESHOLD_VALUE = 229;

void drawTarger (cv::Mat image, int point1, int point2, std::string color) {
    cv::Scalar circle_color;
    if (color == "r") circle_color = cv::Scalar(0, 0, 255);
    if (color == "g") circle_color = cv::Scalar(0, 255, 0);
    if (color == "b") circle_color = cv::Scalar (255, 0, 0);
    if (color == "y") circle_color = cv::Scalar (0, 255, 255);
    cv::circle(image, cv::Point(point1, point2), 6, circle_color, 2);
    cv::line(image, cv::Point(point1 - 8, point2), cv::Point(point1 + 8, point2), cv::Scalar(0, 0, 0), 1);
    cv::line(image, cv::Point(point1, point2 - 8), cv::Point(point1, point2 + 8), cv::Scalar(0, 0, 0), 1);
}

void allababah(cv::Mat image) {
    cv::Mat thresholded;
    thresholded.create(image.size(), image.type());
    cv::Mat grayscale;
    cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);
    cv::threshold(grayscale, thresholded, THRESHOLD_VALUE, 255, cv::THRESH_BINARY);

    std::vector<std::vector<cv::Point>> allababah_contours;
    cv::findContours(thresholded, allababah_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    int index_m = -1;
    double area = 0;
    for (int index = 0; index < allababah_contours.size(); index++) {
        double countur_area = cv::contourArea(allababah_contours[index]);
        if (countur_area > area) {
            area = countur_area;
            index_m = index;
        }
    }
    cv::Moments im_moment = cv::moments(allababah_contours[index_m]);
    int x_coord = int(im_moment.m10 / im_moment.m00);
    int y_coord = int(im_moment.m01 / im_moment.m00);

    drawTarger(image, x_coord, y_coord, "r");
}


void teplovizor(cv::Mat image) {
    cv::Mat mask_image;
    cv::Mat hsvimage;
    cv::cvtColor(image, hsvimage, cv::COLOR_BGR2HSV);

    cv::Scalar red_begin_left = cv::Scalar(0, 60, 70);
    cv::Scalar red_end_left = cv::Scalar(40, 255, 255);

    cv::inRange(hsvimage, red_begin_left, red_end_left, mask_image);
    std::vector<std::vector<cv::Point>> teplovizor_contours;
    cv::findContours(mask_image, teplovizor_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    int area = 0;
    int num = -1;
    for (int index = 0; index < teplovizor_contours.size(); index++) {
        int teplo_area = cv::contourArea(teplovizor_contours[index]);
        if (teplo_area > area) {
            area = teplo_area;
            num = index;
        }
        cv::Moments im_moment = cv::moments(teplovizor_contours[num]);
        int x_coord = int(im_moment.m10 / im_moment.m00);
        int y_coord = int(im_moment.m01 / im_moment.m00);
        drawTarger(image, x_coord, y_coord, "r");
    }

}

void find_robot(cv::Mat image) {
    cv::Mat hsvimage;
    cv::cvtColor(image, hsvimage, cv::COLOR_BGR2HSV);

    cv::Scalar red_begin_left = cv::Scalar(155, 100, 100);
    cv::Scalar red_end_left = cv::Scalar(179, 255, 255);

    cv::Scalar green_begin = cv::Scalar(70, 80, 125);
    cv::Scalar green_end = cv::Scalar(75, 255, 255);

    cv::Scalar blue_begin = cv::Scalar(90, 98, 150);
    cv::Scalar blue_end = cv::Scalar(100, 255, 255);

    cv::Mat red_mask_left/*, red_mask_right*/, green_mask, blue_mask;
    cv::inRange(hsvimage, red_begin_left, red_end_left, red_mask_left);
    cv::inRange(hsvimage, green_begin, green_end, green_mask);
    cv::inRange(hsvimage, blue_begin, blue_end, blue_mask);

    std::vector<std::vector<cv::Point>> contours_green, contours_blue, contours_red;
    cv::findContours(green_mask, contours_green, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::findContours(blue_mask, contours_blue, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::findContours(red_mask_left, contours_red, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat core = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(20, 20));

    cv::Mat /*red_mask_right_dilated,*/ red_mask_left_dilated, red_mask_left_eroded; //, red_mask_right_eroded;
    cv::morphologyEx(red_mask_left, red_mask_left_dilated, cv::MORPH_DILATE, core);
    cv::morphologyEx(red_mask_left_dilated, red_mask_left_eroded, cv::MORPH_ERODE, core);

    cv::Mat green_mask_dilated, green_mask_eroded;
    cv::morphologyEx(green_mask, green_mask_dilated, cv::MORPH_DILATE, core);
    cv::morphologyEx(green_mask_dilated, green_mask_eroded, cv::MORPH_ERODE, core);

    cv::Mat blue_mask_dilated, blue_mask_eroded;
    cv::morphologyEx(blue_mask, blue_mask_dilated, cv::MORPH_DILATE, core);
    cv::morphologyEx(blue_mask_dilated, blue_mask_eroded, cv::MORPH_ERODE, core);

    std::vector<std::vector<cv::Point>> contours_red_left_morph /*, contours_red_right_morph*/, contours_green_morph, contours_blue_morph;
    cv::findContours(green_mask_eroded, contours_green_morph, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::findContours(blue_mask_eroded, contours_blue_morph, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::findContours(red_mask_left_eroded, contours_red_left_morph, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (int index = 0; index < contours_green_morph.size(); index++) {
        if (cv::contourArea(contours_green_morph[index]) < 120) {
            contours_green_morph.erase(contours_green_morph.begin() + index);
           index--;
        }
    }
    for (int index = 0; index < contours_blue_morph.size(); index++) {
        if (cv::contourArea(contours_blue_morph[index]) < 20) {
            contours_blue_morph.erase(contours_blue_morph.begin() + index);
            index--;
        }
    }
    for (int index = 0; index < contours_red_left_morph.size(); index++) {
        if (cv::contourArea(contours_red_left_morph[index]) < 20) {
            contours_red_left_morph.erase(contours_red_left_morph.begin() + index);
            index--;
        }
    }

    cv::drawContours(image, contours_green_morph, -1, cv::Scalar(0, 255, 0), 2);
    cv::drawContours(image, contours_blue_morph, -1, cv::Scalar(255, 0, 0), 2);
    cv::drawContours(image, contours_red_left_morph, -1, cv::Scalar(0, 0, 255), 2);

    cv::Mat v_channel;
    cv::extractChannel(hsvimage, v_channel, 2);

    cv::Mat mask;
    cv::threshold(v_channel, mask, 252, 255, cv::THRESH_BINARY);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    int area = 0;
    int index_m = -1;
    for (int index = 0; index < contours.size(); index++) {
        int countur_area = cv::contourArea(contours[index]);
        if (countur_area > area) {
            area = countur_area;
            index_m = index;
        }
    }

    cv::Point lamp_point;
    if (index_m != -1) {
        cv::drawContours(image, contours, index_m, cv::Scalar(0, 200, 250), 1);
        cv::Moments im_moment = moments(contours[index_m]);
        int x_coord = int(im_moment.m10 / im_moment.m00);
        int y_coord = int(im_moment.m01 / im_moment.m00);
        lamp_point = cv::Point(x_coord, y_coord);
        drawTarger(image, x_coord, y_coord, "y");
        cv::putText(image, "Lamp", cv::Point(x_coord, y_coord + 30), 1, 2, cv::Scalar(0, 200, 250), 2);
    }

    std::vector<cv::Point> mass_center_green, mass_center_blue, mass_center_red;
    std::vector<double> distances_green, distances_blue, distances_red;


    for (int index = 0; index < contours_red.size(); index++) {
        cv::Moments im_moment = moments(contours_red[index]);
        int x_coord = int(im_moment.m10 / im_moment.m00);
        int y_coord = int(im_moment.m01 / im_moment.m00);
        mass_center_red.push_back(cv::Point(x_coord, y_coord));
        double dist = norm(cv::Point(x_coord, y_coord) - lamp_point);
        distances_red.push_back(dist);
    }
    for (int index = 0; index < contours_green.size(); index++) {
        cv::Moments im_moment = moments(contours_green[index]);
        int x_coord = int(im_moment.m10 / im_moment.m00);
        int y_coord = int(im_moment.m01 / im_moment.m00);
        mass_center_green.push_back(cv::Point(x_coord, y_coord));
        double dist = norm(cv::Point(x_coord, y_coord) - lamp_point);
        distances_green.push_back(dist);
    }
    for (int index = 0; index < contours_blue.size(); index++) {
        cv::Moments im_moment = moments(contours_blue[index]);
        int x_coord = int(im_moment.m10 / im_moment.m00);
        int y_coord = int(im_moment.m01 / im_moment.m00);
        mass_center_blue.push_back(cv::Point(x_coord, y_coord));
        double dist = norm(cv::Point(x_coord, y_coord) - lamp_point);
        distances_blue.push_back(dist);
    }

    int min_index_red = -1;
    int min_index_green = -1;
    int min_index_blue = -1;
    double min_dist_red = DBL_MAX;
    double min_dist_green = DBL_MAX;
    double min_dist_blue = DBL_MAX;

    for (int index = 0; index < distances_red.size(); index++) {
        if (distances_red[index] <= min_dist_red) {
            min_dist_red = distances_red[index];
            min_index_red = index;
        }
    }
    for (int index = 0; index < distances_green.size(); index++) {
        if (distances_green[index] <= min_dist_green) {
            min_dist_green = distances_green[index];
            min_index_green = index;
        }
    }
    for (int index = 0; index < distances_blue.size(); index++) {
        if (distances_blue[index] <= min_dist_blue) {
            min_dist_blue = distances_blue[index];
            min_index_blue = index;
        }
    }

    if (min_index_red != -1) {
        cv::line(image, lamp_point, mass_center_red[min_index_red], cv::Scalar(0, 0, 255), 2);
        drawTarger(image, mass_center_red[min_index_red].x, mass_center_red[min_index_red].y, "r");
        cv::putText(image, std::to_string(int(min_dist_red)), cv::Point((lamp_point.x + mass_center_red[min_index_red].x) / 2,
                                        (lamp_point.y + mass_center_red[min_index_red].y) / 2 - 10), 1, 1, cv::Scalar(0, 0, 255), 2);
    }
    if (min_index_green != -1) {
        cv::line(image, lamp_point, mass_center_green[min_index_green], cv::Scalar(0, 255, 0), 2);
        drawTarger(image, mass_center_green[min_index_green].x, mass_center_green[min_index_green].y, "g");
        cv::putText(image, std::to_string(int(min_dist_green)), cv::Point((lamp_point.x + mass_center_green[min_index_green].x) / 2 - 20,
                                        (lamp_point.y + mass_center_green[min_index_green].y) / 2 - 10), 1, 1, cv::Scalar(0, 255, 0), 2);
    }
    if (min_index_blue != -1) {
        cv::line(image, lamp_point, mass_center_blue[min_index_blue], cv::Scalar(255, 0, 0), 2);
        drawTarger(image, mass_center_blue[min_index_blue].x, mass_center_blue[min_index_blue].y, "b");
        cv::putText(image, std::to_string(int(min_dist_blue)), cv::Point((lamp_point.x + mass_center_blue[min_index_blue].x) / 2 + 10,
                                        (lamp_point.y + mass_center_blue[min_index_blue].y) / 2), 1, 1, cv::Scalar(255, 0, 0), 2);
    }
}
void findWrenchs(cv::Mat image, cv::Mat mask_Image) {
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::Mat threshImage;
    cv::threshold(grayImage, threshImage, 200, 255, cv::THRESH_BINARY_INV);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(threshImage, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::threshold(mask_Image, mask_Image, 200, 255, cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> mask;
    cv::findContours(mask_Image, mask, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    double mask_area = cv::contourArea(mask[0]);
    for (int index = 0; index < contours.size(); index++) {
        cv::Mat contour = cv::Mat::zeros(image.size(), image.type());
        cv::drawContours(contour, contours, index, cv::Scalar(255, 255, 255), -1);
        cv::Mat maskedImage;
        cv::bitwise_and(image, contour, maskedImage);
        double contour_area = cv::contourArea(contours[index]);
        double diff_area = contour_area / mask_area;
        cv::Scalar color;
        std::string text;
        if ((diff_area < 1.01) and (diff_area > 0.99)) {
            text = "NORMAL";
            color = cv::Scalar(0, 200, 0);
        }
        else {
            text = "BROKEN";
            color = cv::Scalar(0, 0, 200);
        }

        cv::Moments im_moment = moments(contours[index]);
        int x_coord = int(im_moment.m10 / im_moment.m00);
        int y_coord = int(im_moment.m01 / im_moment.m00);
        cv::putText(image, text, cv::Point(x_coord - 50, y_coord), 1, 2, color, 2);
    }
}

void find_on_video() {
    cv::VideoCapture video;
    video.open("/home/sergei/Downloads/Robot Swarm - University of Sheffield (HD) (online-video-cutter.com).mp4");
    while (true) {
        cv::Mat cadr;
        bool ret = video.read(cadr);
        if (!ret) {
            break;
        }
        cv::Mat hsvimage;
        cv::cvtColor(cadr, hsvimage, cv::COLOR_BGR2HSV);

        cv::Scalar red_begin_left = cv::Scalar(165, 60, 60);
        cv::Scalar red_end_left = cv::Scalar(179, 255, 255);
        cv::Scalar green_begin = cv::Scalar(70, 60, 120);
        cv::Scalar green_end = cv::Scalar(75, 255, 255);

        cv::Scalar blue_begin = cv::Scalar(90, 100, 150);
        cv::Scalar blue_end = cv::Scalar(100, 255, 255);

        cv::Mat green_mask, blue_mask, red_mask;
        cv::inRange(hsvimage, red_begin_left, red_end_left, red_mask);
        cv::inRange(hsvimage, green_begin, green_end, green_mask);
        cv::inRange(hsvimage, blue_begin, blue_end, blue_mask);

        std::vector<std::vector<cv::Point>> contours_green, contours_blue, contours_red;
        cv::findContours(green_mask, contours_green, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        cv::findContours(blue_mask, contours_blue, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        cv::findContours(red_mask, contours_red, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);


        cv::Mat core = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(20, 20));

        cv::Mat green_mask_dilated, green_mask_eroded, blue_mask_dilated,
                blue_mask_eroded, red_mask_dilated, red_mask_eroded;
        cv::morphologyEx(green_mask, green_mask_dilated, cv::MORPH_DILATE, core);
        cv::morphologyEx(blue_mask, blue_mask_dilated, cv::MORPH_DILATE, core);
        cv::morphologyEx(red_mask, red_mask_dilated, cv::MORPH_DILATE, core);

        cv::morphologyEx(green_mask_dilated, green_mask_eroded, cv::MORPH_ERODE, core);
        cv::morphologyEx(blue_mask_dilated, blue_mask_eroded, cv::MORPH_ERODE, core);
        cv::morphologyEx(red_mask_dilated, red_mask_eroded, cv::MORPH_ERODE, core);

        std::vector<std::vector<cv::Point>> green_morph_contours, blue_morph_contours, red_morph_contours;
        cv::findContours(green_mask_eroded, green_morph_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        cv::findContours(blue_mask_eroded, blue_morph_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        cv::findContours(red_mask_eroded, red_morph_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        for (int index = 0; index < red_morph_contours.size(); index++) {
            if (cv::contourArea(red_morph_contours[index]) < 120) {
                red_morph_contours.erase(red_morph_contours.begin() + index);
                index--;
            }
        }
        for (int index = 0; index < green_morph_contours.size(); index++) {
            if (cv::contourArea(green_morph_contours[index]) < 120) {
                green_morph_contours.erase(green_morph_contours.begin() + index);
                index--;
            }
        }
        for (int index = 0; index < blue_morph_contours.size(); index++) {
            if (cv::contourArea(blue_morph_contours[index]) < 120) {
                blue_morph_contours.erase(blue_morph_contours.begin() + index);
                index--;
            }
        }
        cv::drawContours(cadr, red_morph_contours, -1, cv::Scalar(0, 0, 255), 2);
        cv::drawContours(cadr, green_morph_contours, -1, cv::Scalar(0, 255, 0), 2);
        cv::drawContours(cadr, blue_morph_contours, -1, cv::Scalar(255, 0, 0), 2);

        cv::imshow("Cadr", cadr);
        cv::imwrite("/home/sergei/QT_projects/STZ/laba_3_1/Cadr.jpg", cadr);

        if (cv::waitKey(25) == 27) {
            break;
        }
    }
    video.release();
}

int main() {
    std::string allababah_name = "/home/sergei/QT_projects/STZ/laba_3_1/task/img_zadan/allababah/ig_1.jpg";
    std::string thermal_image_name = "/home/sergei/QT_projects/STZ/laba_3_1/task/картинки_1/size0-army.mil-2008-08-28-082221.jpg";
    std::string robots_image_name = "/home/sergei/QT_projects/STZ/laba_3_1/task/img_zadan/roboti/roi_robotov.jpg";
    std::string wrench_image_name = "/home/sergei/QT_projects/STZ/laba_3_1/task/img_zadan/gk/gk.jpg";
    std::string template_wrench_name = "/home/sergei/QT_projects/STZ/laba_3_1/task/img_zadan/gk/gk_tmplt.jpg";

    cv::Mat image = cv::imread(allababah_name);
    cv::Mat thermal_image = cv::imread(thermal_image_name);
    cv::Mat robots_image = cv::imread(robots_image_name);
    cv::Mat wrench_image = cv::imread(wrench_image_name);
    cv::Mat template_wrench = cv::imread(template_wrench_name, cv::IMREAD_GRAYSCALE);

    teplovizor(thermal_image);

    allababah(image);

    find_robot(robots_image);

    findWrenchs(wrench_image, template_wrench);

    cv::imshow("Task 1 - threshold_image", image);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_3_1/Task1.jpg", image);

    cv::imshow("Task 2 - roi robots", robots_image);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_3_1/Task2.jpg", robots_image);

    cv::imshow("Task 3 - thermal imager", thermal_image);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_3_1/Task3.jpg", thermal_image);

    cv::imshow("Task 4 - wrench", wrench_image);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_3_1/Task4.jpg", wrench_image);

    find_on_video();

    cv::waitKey(0);
    return 0;
}
