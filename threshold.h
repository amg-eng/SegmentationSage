#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <cmath>
using namespace cv;

template<typename Target, typename Source>
Target static_cast_scratch(const Source& value);

int computeOtsuThreshold(const std::vector<std::pair<int, int>>& histogram, int totalPixels);

cv::Mat otsuThreshold(const cv::Mat& image);

double computeEntropy(const std::vector<int>& histogram, int totalPixels);

std::vector<int> computeHistogram(const cv::Mat& image);

cv::Mat entropyThreshold(const cv::Mat& image);

std::vector<int> computeRegionHistogram(const cv::Mat& image, int row, int col, int regionSize);

int computeRegionOtsuThreshold(const std::vector<int>& histogram, int totalPixels);

cv::Mat localSpectralThreshold(const cv::Mat& image, int regionSize);

cv::Mat doubleThresholding(const cv::Mat& image, int lowThreshold, int highThreshold);

float computeRegionVariance(const cv::Mat& image, int row, int col, int regionSize);

cv::Mat varianceThreshold(const cv::Mat& image, int regionSize, float threshold);

cv::Mat multiLevelThresholding(const cv::Mat& image, const std::vector<int>& thresholds);


Mat globalThreshold(const Mat& inputImage, int thresholdValue, unsigned char maximum_value, unsigned char minimum_value);

Mat localAdaptiveMeanThreshold(const Mat& inputImage, int kernalSize, int constant, unsigned char maximum_value, unsigned char minimum_value);

Mat adaptivePaddingFunction(const Mat& inputImage, int paddingSize);

Mat localThresholdMeanCalculation(const Mat& inputImage, int kernalSize);


void applyLocalGaussianThreshold(const cv::Mat& inputImage, cv::Mat& outputImage, int blockSize, double C);
Mat gaussianBlur(const Mat& inputImage);
Mat gaussianThreshold(const Mat& inputImage, int thresholdValue);



#endif // IMAGE_PROCESSING_H
