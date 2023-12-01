#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <ctime>
#include <time.h>
#include <math.h>


cv::Mat BlurFilter (cv::Mat image, int size) {
    int coreRadius = (size - 1)/2;
    cv::Mat res = image.clone();
    int area = pow((coreRadius * 2 + 1), 2);
    for (int i = coreRadius; i < res.rows - coreRadius; i++) {
        for (int j = coreRadius; j < res.cols - coreRadius; j++) {
            int res_pix = 0;
            for (int row = i - coreRadius; row <= i + coreRadius; row++) {
                for (int col = j - coreRadius; col <= j + coreRadius; col++) {
                    res_pix = res_pix + (int)image.at<uint8_t>(row, col);
                }
            }
            res.at<uint8_t>(i, j) = cv::saturate_cast<uint8_t>((int)res_pix/area);
        }
    }
    return res;
}


int SimilarImages(cv::Mat firstImage, cv::Mat secondImage)
{
    int counter = 0;  // результат совпадения пикселей
    cv::resize(secondImage, secondImage, cv::Size(firstImage.cols, firstImage.rows));
    unsigned int pixels_num = firstImage.rows * firstImage.cols;
    for (int row = 0; row < firstImage.rows; row++) {
        for (int col = 0; col < firstImage.cols; col++){
            if (firstImage.at<uchar>(row, col) == secondImage.at<uchar>(row, col)) {
                counter++;
            }
        }
    }
    int res = counter * 100 / pixels_num;
    return res;
}


cv::Mat NegativeTransformation(cv::Mat image) {
    cv::Mat res = image.clone();
    for (int row = 0; row < image.rows; row++) {
        for (int col = 0; col < image.cols; col++) {
            res.at<uchar>(row, col) = 255 - (int)image.at<uchar>(row, col);
        }
    }
    return res;
}


cv::Mat LogarithmicTransformation(cv::Mat image, int c) {
    cv::Mat res = image.clone();
    for (int row = 0; row < image.rows; row++) {
        for (int col = 0; col < image.cols; col++) {
            res.at<uint8_t>(row, col) = c * (int)log(1 + image.at<uint8_t>(row, col));
        }
    }
    return res;
}


cv::Mat IntensityFilter(cv::Mat image) {
    cv::Mat res = image.clone();
    for (int row = 0; row < image.rows; row++) {
        for (int col = 0; col < image.cols; col++) {
            if (image.at<uchar>(row, col) >= 127) {
                res.at<uchar>(row, col) = 255;
            } else {
                res.at<uchar>(row, col) = 0;
            }
        }
    }
    return res;
}


cv::Mat ImageSubstraction(cv::Mat firstImage, cv::Mat secondImage) {
    // cv::resize(secondImage, secondImage, cv::Size(firstImage.cols, firstImage.rows));
    if (firstImage.size != secondImage.size) {
        return firstImage;
    }
    cv::Mat res = firstImage.clone();
    for (int row = 0; row < firstImage.rows; row++) {
        for (int col = 0; col < firstImage.cols; col++) {
            res.at<uchar>(row, col) = abs(firstImage.at<uchar>(row, col) - secondImage.at<uchar>(row, col));
        }
    }
    return res;
}


cv::Mat ImageSummation(cv::Mat firstImage, cv::Mat secondImage) {
    // cv::resize(secondImage, secondImage, cv::Size(firstImage.cols, firstImage.rows));
    if (firstImage.size != secondImage.size) {
        return firstImage;
    }
    if (firstImage.type() != secondImage.type()) {
      return firstImage;
    }
    cv::Mat res = firstImage.clone();
    for (int row = 0; row < firstImage.rows; row++) {
        for (int col = 0; col < firstImage.cols; col++) {
            res.at<uchar>(row, col) = firstImage.at<uchar>(row, col) + secondImage.at<uchar>(row, col);
        }
    }
    return res;
}


cv::Mat ImageMultiplication(cv::Mat image, int num) {
    cv::Mat res = image.clone();
    for (int row = 0; row < image.rows; row++) {
        for (int col = 0; col < image.cols; col++) {
            res.at<uchar>(row, col) = image.at<uchar>(row, col) * num;
        }
    }
    return res;
}


cv::Mat LaplasFilter(cv::Mat image, int multCoef) {
    cv::Mat res = image.clone();
    // int counter = 0;
    int coreRadius = 1;
    int pixelIntens = 0;
    int coreCoef = 1;
    for (int row = 0; row < image.rows - coreRadius; row++){
        for (int col = 0; col < image.cols - coreRadius; col++) {
            pixelIntens = 0;
            for (int i = row - coreRadius; i <= row + coreRadius; i++) {
                for (int j = col - coreRadius; j <= col + coreRadius; j++) {
                    if (i == coreRadius && j == coreRadius) {
                        coreCoef = -8;
                    }
                    pixelIntens = pixelIntens + image.at<uchar>(i, j) * coreCoef;
                }
            }
            res.at<uchar>(row, col) = (pixelIntens);
        }
    }
    return ImageSubstraction(image, (ImageMultiplication(res, multCoef)));
}


int main() {
    std::string imageName = "/home/sergei/QT_projects/STZ/laba_2/image.jpeg";
    //std::string imageName = "/home/sergei/Pictures/Снимок.png";
    cv::Mat inputImage = cv::imread(imageName, cv::IMREAD_GRAYSCALE);
    cv::imshow("original", inputImage);
    cv::Rect roi = cv::Rect(200, 200, 800, 500);
    cv::imshow("roi", inputImage(roi));
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/roi.png", inputImage(roi));

    clock_t startTime = clock();

    cv::Mat boxFilter;
    cv::blur(inputImage(roi), boxFilter, cv::Size(5, 5));
    std::cout << "boxFilter " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
    cv::imshow("boxFilterOpencv", boxFilter);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/boxFilter.png", boxFilter);

    startTime = clock();
    cv::Mat boxFilterMade = BlurFilter(inputImage(roi), 5);
    std::cout << "boxFilterMade " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
    cv::imshow("boxFilterMade", boxFilterMade);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/boxFilterMade.png", boxFilterMade);

    cv::imshow("boxFilterMade - boxFilter -> log ", LogarithmicTransformation(ImageSubstraction(boxFilterMade, boxFilter), 2));
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/boxFilterMade_boxFilter_log.png", LogarithmicTransformation(ImageSubstraction(boxFilterMade, boxFilter), 2));


    int procent = SimilarImages(boxFilterMade, boxFilter);
    std::cout << procent << std::endl;

    cv::Mat laplace;
    startTime = clock();
    cv::Laplacian(inputImage(roi), laplace, CV_16S, 5);
    std::cout << "laplace " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
    cv::imshow("laplace", laplace);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/laplace.png", laplace);

    startTime = clock();
    cv::Mat laplaceMade = LaplasFilter(inputImage(roi), 5);
    std::cout << "laplaceMade " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
    cv::imshow("laplaceMade", laplaceMade);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/laplaceMade.png", laplaceMade);

    int sharp = 5;
    startTime = clock();
    cv::Mat unsharp_mask_box = ImageSummation(ImageMultiplication(ImageSubstraction(boxFilterMade, inputImage(roi)), sharp), inputImage(roi));
    std::cout << "unsharp_mask_box " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
    cv::imshow("unsharp_mask_box", unsharp_mask_box);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/unsharp_mask_box.png", unsharp_mask_box);

    startTime = clock();
    cv::Mat gauss;
    cv::GaussianBlur(inputImage(roi), gauss, cv::Size(5, 5), (0, 0));
    std::cout << "gauss " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
    cv::imshow("gauss", gauss);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/gauss.png", gauss);

    startTime = clock();
    cv::Mat unsharp_mask_gauss = ImageSummation(ImageMultiplication(ImageSubstraction(gauss, inputImage(roi)), sharp), inputImage(roi));
    std::cout << "unsharp_mask_gauss " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
    cv::imshow("unsharp_mask_gauss", unsharp_mask_gauss);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/unsharp_mask_gauss.png", unsharp_mask_gauss);

    startTime = clock();
    cv::Mat unsharp_mask_laplace = ImageSummation(ImageMultiplication(ImageSubstraction(laplace, inputImage(roi)), sharp), inputImage(roi));
    std::cout << "unsharp_mask_laplace " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
    cv::imshow("unsharp_mask_laplace", unsharp_mask_laplace);
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/unsharp_mask_laplace.png", unsharp_mask_laplace);


    cv::imshow("boxFilterMade - gauss -> log ",
               LogarithmicTransformation(ImageSubstraction(boxFilterMade, gauss), 2));
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/boxFilterMade_gauss_log.png",
               LogarithmicTransformation(ImageSubstraction(boxFilterMade, gauss), 2));

    cv::imshow("unsharp_mask_box - unsharp_mask_gauss -> logarithmic ",
           LogarithmicTransformation(ImageSubstraction(unsharp_mask_box, unsharp_mask_gauss),2));
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/unsharp_mask_box_unsharp_mask_gauss_logarithmic.png",
           LogarithmicTransformation(ImageSubstraction(unsharp_mask_box, unsharp_mask_gauss),2));

    cv::imshow("unsharp_mask_laplace - unsharp_mask_gauss -> logarithmic",
           LogarithmicTransformation(ImageSubstraction(unsharp_mask_laplace, unsharp_mask_gauss),2));
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/unsharp_mask_laplace_unsharp_mask_gauss_logarithmic.png",
           LogarithmicTransformation(ImageSubstraction(unsharp_mask_laplace, unsharp_mask_gauss),2));

    cv::imshow("unsharp_mask_box - unsharp_mask_laplace -> logarithmic",
           LogarithmicTransformation(ImageSubstraction(unsharp_mask_box, unsharp_mask_laplace),2));
    cv::imwrite("/home/sergei/QT_projects/STZ/laba_2/unsharp_mask_box_unsharp_mask_laplace_logarithmic.png",
           LogarithmicTransformation(ImageSubstraction(unsharp_mask_box, unsharp_mask_laplace),2));

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
