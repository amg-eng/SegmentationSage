#ifndef REGIONGROWING
#define REGIONGROWING

#include <opencv2/photo/photo.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
#include <queue>
#include <time.h>
#include <fstream>
#include <cmath>
#include <iostream>
#include <time.h>
#include <opencv2/opencv.hpp>
#include <map>
#include <queue>

using namespace cv;
using namespace std;

// Structure to store a pixel's coordinates
struct PixelCoord {
    int x, y;
    PixelCoord(int _x, int _y) : x(_x), y(_y) {}
};


Mat regionGrowingHelper(Mat &inputImage, Point &seedPoint , int threshold, int labelNumber, bool colorflag);

Mat regionGrowingMultiSeed(Mat &inputImage, vector<Point> &seedPoints, int threshold, bool colorflag);

void region_detection(std::queue<Point> Q, int rows, int cols, Mat &inputImage, Mat &labelMatrix, int threshold, bool colorflag);

void color_region(int rows, int cols, Mat &inputImage, Mat &labelMatrix, Mat &outputImage, bool colorflag);

void regionGrowingRGB(const Mat& inputImage, Mat& outputImage, int seedX, int seedY, int threshold);

int colorDifference(const Vec3b& pixel1, const Vec3b& pixel2);
#endif