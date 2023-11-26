#include <iostream>

#include "opencv4/opencv2/core.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/imgcodecs.hpp"
#include "opencv4/opencv2/imgproc.hpp"


void makeRobotBody(cv::Mat robot_body) {  // создание прямоугольника и 6 колес
  cv::rectangle(robot_body, cv::Point(robot_body.rows/2 - 30, robot_body.cols/2 - 10), cv::Point(robot_body.rows/2 + 30, robot_body.cols/2 + 10), cv::Scalar(0, 0, 50), -1);

  cv::ellipse(robot_body, cv::Point(robot_body.rows/2 - 15, robot_body.cols/2 - 10), cv::Size(5, 5), 0, 0, -180, cv::Scalar(255, 255, 255), -1);

  cv::ellipse(robot_body, cv::Point(robot_body.rows/2, robot_body.cols/2 - 10), cv::Size(5, 5), 0, 0, -180, cv::Scalar(255, 255, 255), -1);

  cv::ellipse(robot_body, cv::Point(robot_body.rows/2 + 15, robot_body.cols/2 - 10), cv::Size(5, 5), 0, 0, -180, cv::Scalar(255, 255, 255), -1);

  cv::ellipse(robot_body, cv::Point(robot_body.rows/2 - 15, robot_body.cols/2 + 10), cv::Size(5, 5), 0, 0, 180, cv::Scalar(255, 255, 255), -1);

  cv::ellipse(robot_body, cv::Point(robot_body.rows/2 + 15, robot_body.cols/2 + 10), cv::Size(5, 5), 0, 0, 180, cv::Scalar(255, 255, 255), -1);

  cv::ellipse(robot_body, cv::Point(robot_body.rows/2, robot_body.cols/2 + 10), cv::Size(5, 5), 0, 0, 180, cv::Scalar(255, 255, 255), -1);
}

int main() {
  float freq = 0.05;
  float phase = 0;

  cv::Mat font_image = cv::imread("/home/sergei/Pictures/Снимок.png");

  int width = font_image.cols;
  int height = font_image.rows;
  int coord_x = 0;
  int coord_y = 0;
  int amp = height/4;
  int rob_height = 50;
  int rob_width = 50;

  cv::Mat robot_body(rob_height, rob_width, CV_8UC3, cv::Scalar(0, 0, 255));
  makeRobotBody(robot_body);

  while (true)
  {
    coord_x++;
    coord_y = amp * sin(freq * coord_x + phase) + height/2;

    robot_body.copyTo(font_image(cv::Rect(coord_x, coord_y - robot_body.rows/2, robot_body.rows, robot_body.cols)));
    if (coord_x == width / 2)
    {
      cv::imwrite("/home/sergei/QT_projects/STZ/laba_1_stz/output.png", font_image);
    }

    if (coord_x + rob_width/2 == width) coord_x = 0;

    cv::imshow("output", font_image);
    if (cv::waitKey(10) >= 0) break;
  }
  cv::waitKey(0);
  return 0;
}
