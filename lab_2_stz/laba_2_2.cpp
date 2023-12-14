#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

#include <ctime>
#include <time.h>

#include <math.h>


cv::Mat BlurFilter(cv::Mat image, int size) {
  int radius = (size - 1) / 2;
  cv::Mat res = image.clone();
  int area = pow((2 * radius + 1), 2);
  for (int i = radius; i < res.rows - radius; i++) {
    for (int j = radius; j < res.cols - radius; j++) {
      int res_pixel = 0;
      for (int row = i - radius; row < i + radius + 1; row++) {
        for (int col = j - radius; col < j + radius + 1; col++) {
          res_pixel += ((int)image.at<uint8_t>(row, col));
        }
      }
      res.at<uint8_t>(i, j) = cv::saturate_cast<uint8_t>((int)res_pixel / area);
    }
  }
  return res;
}


int SimilarImages(cv::Mat firstImage, cv::Mat secondImage) {
  int counter = 0;
  int eps = 2;
  int pixel_num = firstImage.rows * firstImage.cols;
  if (firstImage.type() != secondImage.type() || firstImage.size != secondImage.size)
    return 0;
  for (int row = 0; row < firstImage.rows; row++) {
    for (int col = 0; col < firstImage.cols; col++) {
      if (abs(firstImage.at<uchar>(row, col) - secondImage.at<uchar>(row, col)) <= eps)
          counter++;
    }
  }
  return counter * 100 / pixel_num;
}


cv::Mat ImageSubtraction(cv::Mat firstImage, cv::Mat secondImage) {
  if (firstImage.type() != secondImage.type())
    return firstImage;
  if (firstImage.size != secondImage.size)
    return secondImage;
  cv::Mat res = firstImage.clone();

  for (int row = 0; row < firstImage.rows; row++) {
    for (int col = 0; col < firstImage.cols; col++) {
      res.at<uchar>(row, col) =
          abs(firstImage.at<uchar>(row, col) - secondImage.at<uchar>(row, col));
    }
  }
  return res;
}


cv::Mat ImageSummation(cv::Mat firstImage, cv::Mat secondImage) {
  if (firstImage.type() != secondImage.type())
    return firstImage;
  if (firstImage.size != secondImage.size)
    return secondImage;
  cv::Mat res = firstImage.clone();
  for (int row = 0; row < firstImage.rows; row++) {
    for (int col = 0; col < firstImage.cols; col++) {
      res.at<uchar>(row, col) = cv::saturate_cast<uchar>(firstImage.at<uchar>(row, col) + secondImage.at<uchar>(row, col));
    }
  }
  return res;
}

cv::Mat ImageMult(cv::Mat first, int coef) {
  cv::Mat res = first.clone();
  for (int row = 0; row < first.rows; row++) {
    for (int col = 0; col < first.cols; col++) {
      res.at<uchar>(row, col) = first.at<uchar>(row, col) * coef;
    }
  }
  return res;
}

cv::Mat LaplacFilter(cv::Mat image, int coef) {
  cv::Mat res = image.clone();
  int counter = 0;
  int rad = 1;
  int coreCoef = 0;
  for (int i = rad; i < res.rows - rad; i++) {
    for (int j = rad; j < res.cols - rad; j++) {
      int res_pixel = 0;
      for (int row = i - rad; row <= i + rad; row++) {
        for (int col = j - rad; col <= j + rad; col++) {
          counter++;
          if (row == rad && col == rad) {
              coreCoef = -8;
          }
          else {
              coreCoef = 1;
          }
          res_pixel = res_pixel + ((int)image.at<uint8_t>(row, col)) * coreCoef;
        }
        counter = 0;
      }
      res.at<uint8_t>(i, j) = cv::saturate_cast<uint8_t>(res_pixel);
    }
  }
  return ImageSubtraction(image , ImageMult(res, coef));
}


cv::Mat logTransform(cv::Mat image, int coef){
    cv::Mat res = image.clone();
    for (int i = 0; i < res.rows; i++) {
      for (int j = 0; j < res.cols; j++) {
          res.at<uint8_t>(i, j) = cv::saturate_cast<uint8_t>(coef * log(1 +((int)image.at<uint8_t>(i, j))));
      }
    }
    return res;
}

int main() {
  cv::Mat input_image = cv::imread("/home/sergei/QT_projects/STZ/laba_2/task_2/picture.jpg", cv::IMREAD_GRAYSCALE);
  cv::Mat image = input_image.clone();
  cv::Mat box_filter_opencv;
  cv::Rect ROI = cv::Rect(200, 400, 600, 600);

  clock_t start = clock();
  cv::blur(image(ROI), box_filter_opencv, cv::Size(3, 3));
  std::cout << "box_filter_opencv =  "
            << (double)(clock() - start) / CLOCKS_PER_SEC << " s" << std::endl;

  start = clock();
  cv::Mat box_filter_made = BlurFilter(image(ROI), 7);
  std::cout << "box_filter_made =  " << (double)(clock() - start) / CLOCKS_PER_SEC
            << " s" << std::endl;

  int k = SimilarImages(box_filter_made, box_filter_opencv);

  cv::Mat laplace;
  start = clock();
  cv::Mat laplace_made = LaplacFilter(image(ROI), 7);
  std::cout << "laplace_made =  " << (double)(clock() - start) / CLOCKS_PER_SEC
            << " s" << std::endl;
  start = clock();
  cv::Laplacian(image(ROI), laplace, CV_16S, 7);
  std::cout << "laplace =  " << (double)(clock() - start) / CLOCKS_PER_SEC
            << " s" << std::endl;

  int sharp = 2;
  start = clock();
  cv::Mat unsharp_mask_box = ImageSummation(
      ImageMult(ImageSubtraction(box_filter_made, image(ROI)), sharp),
      image(ROI));
  std::cout << "unsharp_mask_box =  "
            << (double)(clock() - start) / CLOCKS_PER_SEC << " s" << std::endl;

  cv::Mat gauss;
  start = clock();
  cv::GaussianBlur(image(ROI), gauss, cv::Size(7, 7), (0, 0));
  std::cout << "gauss =  " << (double)(clock() - start) / CLOCKS_PER_SEC
            << " s" << std::endl;

  start = clock();
  cv::Mat unsharp_mask_gauss = ImageSummation(
      ImageMult(ImageSubtraction(gauss, image(ROI)), sharp),
      image(ROI));
  std::cout << "unsharp_mask_gauss =  "
            << (double)(clock() - start) / CLOCKS_PER_SEC << " s" << std::endl;
  start = clock();
  cv::Mat unsharp_mask_laplace = ImageSummation(
      ImageMult(ImageSubtraction(laplace, image(ROI)), sharp),
      image(ROI));
  std::cout << "unsharp_mask_laplace =  "
            << (double)(clock() - start) / CLOCKS_PER_SEC << " s" << std::endl;



  cv::imshow("image", image);
  cv::imshow("image_ROI", image(ROI));
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/roi.png", image(ROI));

  cv::imshow("box_filter_made", box_filter_made);
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/box_filter_made.png", box_filter_made);

  cv::imshow("box_filter_opencv", box_filter_opencv);
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/box_filter_opencv.png", box_filter_opencv);

  cv::imshow("box_filter_made - box_filter_opencv-> logTransform ",
         logTransform(ImageSubtraction(box_filter_made, box_filter_opencv), 2));
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/box_filter_made-box_filter_opencv->logTransform.png",
              logTransform(ImageSubtraction(box_filter_made, box_filter_opencv), 2));

  cv::imshow("box_filter_made - gauss-> logTransform ",
         logTransform(ImageSubtraction(box_filter_made, gauss), 2));
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/box_filter_made-gauss->logTransform.png",
              logTransform(ImageSubtraction(box_filter_made, gauss), 2));

  cv::imshow("laplace_made", laplace_made);
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/laplace_made.png", laplace_made);

  cv::imshow("laplace", laplace);
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/laplace.png", laplace);

  cv::imshow("gauss", gauss);
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/gauss.png", gauss);

  cv::imshow("unsharp_mask_box", unsharp_mask_box);
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/unsharp_mask_box.png", unsharp_mask_box);

  cv::imshow("unsharp_mask_gauss", unsharp_mask_gauss);
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/unsharp_mask_gauss.png", unsharp_mask_gauss);

  cv::imshow("unsharp_mask_laplace", unsharp_mask_laplace);
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/unsharp_mask_laplace.png", unsharp_mask_laplace);

  cv::imshow("unsharp_mask_box - unsharp_mask_gauss -> logTransform ",
         logTransform(ImageSubtraction(unsharp_mask_box, unsharp_mask_gauss),2));
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/unsharp_mask_box-unsharp_mask_gauss->logTransform.png",
              logTransform(ImageSubtraction(unsharp_mask_box, unsharp_mask_gauss),2));

  cv::imshow("unsharp_mask_laplace - unsharp_mask_gauss -> logTransform",
         logTransform(ImageSubtraction(unsharp_mask_laplace, unsharp_mask_gauss),2));
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/unsharp_mask_laplace-unsharp_mask_gauss->logTransform.png",
              logTransform(ImageSubtraction(unsharp_mask_laplace, unsharp_mask_gauss),2));

  cv::imshow("unsharp_mask_box - unsharp_mask_laplace -> logTransform",
         logTransform(ImageSubtraction(unsharp_mask_box, unsharp_mask_laplace),2));
  cv::imwrite("/home/sergei/QT_projects/STZ/laba_2_new/unsharp_mask_box-unsharp_mask_laplace->logTransform.png",
              logTransform(ImageSubtraction(unsharp_mask_box, unsharp_mask_laplace),2));

  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}

