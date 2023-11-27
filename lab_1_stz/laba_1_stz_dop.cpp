#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>


int main()
{
    std::string image_1_name = "/home/sergei/Pictures/Снимок.png";
    std::string image_2_name = "/home/sergei/Pictures/Снимок2.png";

    cv::Mat image_1 = cv::imread(image_1_name);  // загрузка первого изображения
    cv::Mat image_2 = cv::imread(image_2_name);  // загрузка второго изображения
    cv::resize(image_2, image_2, cv::Size(image_1.cols, image_1.rows), cv::INTER_LINEAR);  // приведение изображений к одному размеру

    cv::imshow("image_1", image_1);
    cv::imshow("image_2", image_2);

    cv::Mat blended_image;  // создание объекта под результат смешивания
    blended_image.create(image_1.rows, image_1.cols, CV_8UC3);
    float alpha = 0.5;

    for (int row = 0; row < image_1.rows; row++)
    {
        for (int col = 0; col < image_1.cols; col++)
        {
            blended_image.at<cv::Vec3b>(row, col)[0] = alpha*image_1.at<cv::Vec3b>(row, col)[0] + (1 - alpha)*(image_2.at<cv::Vec3b>(row, col)[0]);  // B
            blended_image.at<cv::Vec3b>(row, col)[1] = alpha*image_1.at<cv::Vec3b>(row, col)[1] + (1 - alpha)*(image_2.at<cv::Vec3b>(row, col)[1]);  // G
            blended_image.at<cv::Vec3b>(row, col)[2] = alpha*image_1.at<cv::Vec3b>(row, col)[2] + (1 - alpha)*(image_2.at<cv::Vec3b>(row, col)[2]);  // R
        }
    }
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_1_stz_dop/blended_image.png", blended_image);
    cv::imshow("blended_image", blended_image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
