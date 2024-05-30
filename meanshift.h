#ifndef MEANSHIFT_H
#define MEANSHIFT_H

#include <math.h>
#include "opencv2/core/mat.hpp"
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;


// Define your constants here if needed
const float MS_MEAN_SHIFT_TOL_COLOR = 10;
const float MS_MEAN_SHIFT_TOL_SPATIAL = 1;
const int MS_MAX_NUM_CONVERGENCE_STEPS = 100;

struct Pixel {
    float x, y; // Coordinates
    float l, a, b; // Lab color components
};

// Function declarations
void setPoint(Pixel* p, float px, float py, float pl, float pa, float pb);
void convertLab(Pixel* pt);
void copyPoint(Pixel* p1, Pixel* p2);
float colorDistance(Pixel Pt1, Pixel Pt2);
float spatialDistance(Pixel Pt1, Pixel Pt2);
void scalePoint(Pixel* p, float scale);
void accumulatePoint(Pixel* mainPt, Pixel Pt);
void convertRGB(Pixel* p);
cv::Mat segment(cv::Mat Img, float distanceBandwidth, float colorBandwidth);

#endif // MEANSHIFT_H
