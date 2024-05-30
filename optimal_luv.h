#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;

// Function declarations
void display_img(Mat img);
Mat read_image(String image_path);
Mat convertToGrayScale(const Mat& input);
Mat mearge(Mat img_1, Mat img_2);
Mat optimal_thresholding(Mat image, float accuracy);
Mat rgb_to_luv(Mat rgb_image);

#endif // MY_HEADER_FILE_H