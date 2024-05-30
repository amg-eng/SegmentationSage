#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include"threshold.h"
// Custom static_cast function implementation
template<typename Target, typename Source>

Target static_cast_scratch(const Source& value) {
    return static_cast<Target>(value);
}

// Function to compute Otsu's threshold
int computeOtsuThreshold(const std::vector<std::pair<int, int>>& histogram, int totalPixels) {
    int size = histogram.size();
    double sum = 0.0;
    for (const auto& pair : histogram) {
        sum += pair.first * pair.second;
    }

    double sumB = 0.0;
    double max_sigma_b = 0.0;
    int threshold = 0;

    auto it2 = histogram.begin();
    for (auto it = histogram.begin(); it != histogram.end(); ++it) {
        float w_b = 0;
        float mu_b = 0;
        float w_f = 0;
        float mu_f = 0;
        float sigma_b = 0;
        if (it == histogram.begin()) {
            continue;
        }
        for (it2; it2 != it; ++it2) {
            w_b += it2->second;
            mu_b += (it2->first) * (it2->second);
        }
        mu_b = mu_b / w_b;
        w_b = w_b / totalPixels;

        for (auto it3 = it2; it3 != histogram.end(); ++it3) {
            w_f += it3->second;
            mu_f += (it3->first) * (it3->second);
        }
        it2 = histogram.begin();
        mu_f = mu_f / w_f;
        w_f = w_f / totalPixels;

        sigma_b = w_b * w_f * (mu_b - mu_f) * (mu_b - mu_f);

        if (sigma_b >= max_sigma_b) {
            max_sigma_b = sigma_b;
            threshold = it->first;
        }
    }

    return threshold;
}

// Function to perform Otsu thresholding on an OpenCV Mat object
cv::Mat otsuThreshold(const cv::Mat& image) {
    // Check if the image is grayscale
    if (image.channels() != 1) {
        std::cerr << "Input image must be grayscale" << std::endl;
        return cv::Mat();
    }

    // Compute histogram
    std::vector<std::pair<int, int>> histogram(256, std::make_pair(0, 0));
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            int pixel = static_cast_scratch<int>(image.at<unsigned char>(i, j));
            histogram[pixel].first = pixel;
            histogram[pixel].second++;
        }
    }

    // Compute total number of pixels
    int totalPixels = image.rows * image.cols;

    // Compute Otsu's threshold
    int threshold = computeOtsuThreshold(histogram, totalPixels);

    // Apply thresholding
    cv::Mat result = image.clone();
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            result.at<unsigned char>(i, j) = (image.at<unsigned char>(i, j) > static_cast_scratch<int>(threshold)) ? 255 : 0;
        }
    }

    return result;
}

// Function to compute entropy of an image
double computeEntropy(const std::vector<int>& histogram, int totalPixels) {
    double entropy = 0.0;
    for (int i = 0; i < 256; ++i) {
        if (histogram[i] > 0) {
            double probability = static_cast_scratch<double>(histogram[i]) / totalPixels;
            entropy -= probability * log2(probability);
        }
    }
    return entropy;
}

// Function to compute histogram of grayscale image
std::vector<int> computeHistogram(const cv::Mat& image) {
    std::vector<int> histogram(256, 0);

    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            int pixel = static_cast_scratch<int>(image.at<unsigned char>(i, j));
            histogram[pixel]++;
        }
    }

    return histogram;
}
// Function to perform entropy-based thresholding
cv::Mat entropyThreshold(const cv::Mat& image) {
    // Check if the image is grayscale
    if (image.channels() != 1) {
        std::cerr << "Input image must be grayscale" << std::endl;
        return cv::Mat();
    }

    // Compute histogram
    std::vector<int> histogram = computeHistogram(image);

    // Compute total number of pixels
    int totalPixels = image.rows * image.cols;

    // Compute entropy
    double entropy = computeEntropy(histogram, totalPixels);

    // Find threshold
    int threshold = 0;
    double maxEntropy = 0.0;
    for (int t = 0; t < 256; ++t) {
        std::vector<int> backgroundHistogram(histogram.begin(), histogram.begin() + t);
        std::vector<int> foregroundHistogram(histogram.begin() + t, histogram.end());

        int backgroundPixels = 0;
        int foregroundPixels = 0;
        for (int i = 0; i < t; ++i) {
            backgroundPixels += backgroundHistogram[i];
        }
        for (int i = t; i < 256; ++i) {
            foregroundPixels += foregroundHistogram[i - t];
        }

        if (backgroundPixels == 0 || foregroundPixels == 0) {
            continue;
        }

        double backgroundEntropy = computeEntropy(backgroundHistogram, backgroundPixels);
        double foregroundEntropy = computeEntropy(foregroundHistogram, foregroundPixels);

        double totalEntropy = (backgroundPixels * backgroundEntropy + foregroundPixels * foregroundEntropy) / totalPixels;
        double informationGain = entropy - totalEntropy;

        if (informationGain > maxEntropy) {
            maxEntropy = informationGain;
            threshold = t;
        }
    }

    // Apply thresholding
    cv::Mat result = image.clone();
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            result.at<unsigned char>(i, j) = (image.at<unsigned char>(i, j) > threshold) ? 255 : 0;
        }
    }

    return result;
}


// Function to compute histogram of a region in grayscale image
std::vector<int> computeRegionHistogram(const cv::Mat& image, int row, int col, int regionSize) {
    std::vector<int> histogram(256, 0);

    for (int i = row - regionSize / 2; i <= row + regionSize / 2; ++i) {
        for (int j = col - regionSize / 2; j <= col + regionSize / 2; ++j) {
            if (i >= 0 && i < image.rows && j >= 0 && j < image.cols) {
                int pixel = static_cast_scratch<int>(image.at<unsigned char>(i, j));
                histogram[pixel]++;
            }
        }
    }

    return histogram;
}

// Function to compute Otsu's threshold for a region
int computeRegionOtsuThreshold(const std::vector<int>& histogram, int totalPixels) {
    double sum = 0.0;
    for (int i = 0; i < 256; ++i) {
        sum += i * histogram[i];
    }

    double sumB = 0.0;
    int wB = 0;
    int wF;

    double varMax = 0.0;
    int threshold = 0;

    for (int i = 0; i < 256; ++i) {
        wB += histogram[i];
        if (wB == 0) continue;

        wF = totalPixels - wB;
        if (wF == 0) break;

        sumB += i * histogram[i];

        double mB = sumB / wB;
        double mF = (sum - sumB) / wF;

        double varBetween = wB * wF * (mB - mF) * (mB - mF);

        if (varBetween > varMax) {
            varMax = varBetween;
            threshold = i;
        }
    }

    return threshold;
}

// Function to perform local spectral thresholding
cv::Mat localSpectralThreshold(const cv::Mat& image, int regionSize) {
    // Check if the image is grayscale
    if (image.channels() != 1) {
        std::cerr << "Input image must be grayscale" << std::endl;
        return cv::Mat();
    }

    // Initialize result image
    cv::Mat result = cv::Mat::zeros(image.size(), CV_8UC1);

    // Compute total number of pixels
    int totalPixels = regionSize * regionSize;

    // Iterate over each pixel in the image
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            // Compute histogram for the region around the current pixel
            std::vector<int> histogram = computeRegionHistogram(image, i, j, regionSize);

            // Compute Otsu's threshold for the region
            int threshold = computeRegionOtsuThreshold(histogram, totalPixels);

            // Apply thresholding to the current pixel
            result.at<unsigned char>(i, j) = (image.at<unsigned char>(i, j) > threshold) ? 255 : 0;
        }
    }

    return result;
}


// Function to perform double thresholding
cv::Mat doubleThresholding(const cv::Mat& image, int lowThreshold, int highThreshold) {
    // Check if the image is grayscale
    if (image.channels() != 1) {
        std::cerr << "Input image must be grayscale" << std::endl;
        return cv::Mat();
    }

    // Initialize result image
    cv::Mat result = cv::Mat::zeros(image.size(), CV_8UC1);

    // Iterate over each pixel in the image
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            // Check if the pixel intensity is within the specified thresholds
            if (image.at<unsigned char>(i, j) >= lowThreshold && image.at<unsigned char>(i, j) <= highThreshold) {
                result.at<unsigned char>(i, j) = 255; // Set as white (foreground)
            }
        }
    }

    return result;
}


// Function to compute the variance of a given region in the image
float computeRegionVariance(const cv::Mat& image, int row, int col, int regionSize) {
    float mean = 0.0;
    float variance = 0.0;
    int count = 0;

    // Compute mean intensity of the region
    for (int i = row - regionSize / 2; i <= row + regionSize / 2; ++i) {
        for (int j = col - regionSize / 2; j <= col + regionSize / 2; ++j) {
            if (i >= 0 && i < image.rows && j >= 0 && j < image.cols) {
                mean += image.at<unsigned char>(i, j);
                count++;
            }
        }
    }
    mean /= count;

    // Compute variance of the region
    for (int i = row - regionSize / 2; i <= row + regionSize / 2; ++i) {
        for (int j = col - regionSize / 2; j <= col + regionSize / 2; ++j) {
            if (i >= 0 && i < image.rows && j >= 0 && j < image.cols) {
                float intensity = image.at<unsigned char>(i, j);
                variance += (intensity - mean) * (intensity - mean);
            }
        }
    }
    variance /= count;

    return variance;
}

// Function to perform Variance-based Thresholding
cv::Mat varianceThreshold(const cv::Mat& image, int regionSize,float threshold) {
    // Check if the image is grayscale
    if (image.channels() != 1) {
        std::cerr << "Input image must be grayscale" << std::endl;
        return cv::Mat();
    }

    // Initialize result image
    cv::Mat result = cv::Mat::zeros(image.size(), CV_8UC1);

    // Iterate over each pixel in the image
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            // Compute variance for the region around the current pixel
            float regionVariance = computeRegionVariance(image, i, j, regionSize);

            // Apply thresholding to the current pixel based on region variance
            result.at<unsigned char>(i, j) = (regionVariance > threshold) ? 255 : 0;
        }
    }

    return result;
}


// Function to apply Multi-level Thresholding
cv::Mat multiLevelThresholding(const cv::Mat& image, const std::vector<int>& thresholds) {
    // Check if the image is grayscale
    if (image.channels() != 1) {
        std::cerr << "Input image must be grayscale" << std::endl;
        return cv::Mat();
    }

    // Initialize result image
    cv::Mat result = cv::Mat::zeros(image.size(), CV_8UC1);

    // Iterate over each pixel in the image
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            // Get the pixel intensity
            int intensity = image.at<unsigned char>(i, j);

            // Check against each threshold value
            for (size_t k = 0; k < thresholds.size(); ++k) {
                // If the intensity is greater than or equal to the threshold value, set the pixel to white
                if (intensity >= thresholds[k]) {
                    result.at<unsigned char>(i, j) = 255;
                    break; // No need to check further thresholds
                }
            }
        }
    }

    return result;
}


/**
 * Applies global thresholding to the input image based on a threshold value.
 * Pixels with intensities greater than the threshold value are set to maximum_value (255),
 * while pixels with intensities less than or equal to the threshold value are set to minimum_value (0).
 *
 * @param inputImage The input image to be thresholded.
 * @param thresholdValue The threshold value for thresholding.
 * @param maximum_value The maximum value to set for pixels above the threshold.
 * @param minimum_value The minimum value to set for pixels below or equal to the threshold.
 * @return The thresholded image.
 */
Mat globalThreshold(const Mat& inputImage, int thresholdValue, unsigned char maximum_value, unsigned char minimum_value) {
    Mat result = inputImage.clone();

    for (int row = 0; row < inputImage.rows; ++row) {
        for (int column = 0; column < inputImage.cols; ++column) {
            result.at<uchar>(row, column) = (inputImage.at<uchar>(row, column) > thresholdValue) ? 255 : 0;
        }
    }

    return result;
}


/**
 * Applies local adaptive mean thresholding to the input image using a specified kernel size and constant.
 * The threshold for each pixel is computed based on the mean intensity of its local neighborhood.
 *
 * @param inputImage The input image to be thresholded.
 * @param kernalSize The size of the local neighborhood kernel.
 * @param constant The constant value subtracted from the mean for threshold calculation.
 * @param maximum_value The maximum value to set for pixels above the local threshold.
 * @param minimum_value The minimum value to set for pixels below or equal to the local threshold.
 * @return The thresholded image using local adaptive mean thresholding.
 */
Mat localAdaptiveMeanThreshold(const Mat& inputImage, int kernalSize, int constant, unsigned char maximum_value, unsigned char minimum_value) {
    //    A copy of the input image is created to store the result.
    Mat result = inputImage.clone();
    //    Calculate half of the kernel size to facilitate traversal around each pixel.
    int halfKernalSize = kernalSize / 2;

    //    Nested loops iterate through each pixel of the image,
    //    excluding the boundary pixels where the kernel cannot fit completely.
    for (int imageRows = halfKernalSize; imageRows < inputImage.rows - halfKernalSize; ++imageRows) {
        for (int imageColumn = halfKernalSize; imageColumn < inputImage.cols - halfKernalSize; ++imageColumn) {
            //            Calculate the sum of pixel intensities within the local neighborhood defined by the kernel.
            //            Compute the mean intensity value by dividing the sum by the total number of pixels in the kerne
            int sum = 0;

            for (int kernalFirstIndex = -halfKernalSize; kernalFirstIndex <= halfKernalSize; ++kernalFirstIndex) {
                for (int l = -halfKernalSize; l <= halfKernalSize; ++l) {
                    sum += inputImage.at<uchar>(imageRows + kernalFirstIndex, imageColumn + l);
                }
            }

            int mean = sum / (kernalSize * kernalSize);
            result.at<uchar>(imageRows, imageColumn) = (inputImage.at<uchar>(imageRows, imageColumn) > (mean - constant)) ? 255 : 0;
        }
    }
    return result;
}



/**
 * Adds padding to the input image based on the specified padding size.
 * This function creates a new image with padding around the input image.
 *
 * @param inputImage The input image to which padding will be added.
 * @param paddingSize The size of the padding to be added around the image.
 * @return The padded image.
 */
Mat adaptivePaddingFunction(const Mat& inputImage, int paddingSize) {
    Mat result(inputImage.rows + 2 * paddingSize, inputImage.cols + 2 * paddingSize, CV_8UC1, Scalar(0));
    inputImage.copyTo(result(Rect(paddingSize, paddingSize, inputImage.cols, inputImage.rows)));

    for (int i = 0; i < paddingSize; ++i) {
        result.row(i).copyTo(result.row(i + inputImage.rows));
    }

    for (int j = 0; j < paddingSize; ++j) {
        result.col(j).copyTo(result.col(j + inputImage.cols));
    }

    return result;
}


/**
 * Computes the local mean of pixel intensities in the input image using a specified kernel size.
 * Each pixel in the output image is replaced with the mean intensity of its local neighborhood.
 *
 * @param inputImage The input image for local mean calculation.
 * @param kernalSize The size of the local neighborhood kernel for mean calculation.
 * @return The image with local mean intensity values.
 */
Mat localThresholdMeanCalculation(const Mat& inputImage, int kernalSize) {
    Mat result = inputImage.clone();
    int halfKernalSize = kernalSize / 2;

    for (int imageRows = halfKernalSize; imageRows < inputImage.rows - halfKernalSize; ++imageRows) {
        for (int imageColumn = halfKernalSize; imageColumn < inputImage.cols - halfKernalSize; ++imageColumn) {
            int sum = 0;

            for (int kernalFirstIndex = -halfKernalSize; kernalFirstIndex <= halfKernalSize; ++kernalFirstIndex) {
                for (int kernalSecondIndex = -halfKernalSize; kernalSecondIndex <= halfKernalSize; ++kernalSecondIndex) {
                    sum += inputImage.at<uchar>(imageRows + kernalFirstIndex, imageColumn + kernalSecondIndex);
                }
            }

            result.at<uchar>(imageRows, imageColumn) = sum / (kernalSize * kernalSize);
        }
    }

    return result;
}


/**
 * Applies local Gaussian thresholding to the input image using a specified block size and constant.
 * This function computes a weighted mean within a local neighborhood using Gaussian weighting.
 * Thresholding is then applied based on the weighted mean and the constant value.
 *
 * @param inputImage The input image to be thresholded.
 * @param outputImage The output image where the thresholded result will be stored.
 * @param blockSize The size of the local neighborhood block for Gaussian weighting.
 * @param C The constant value subtracted from the weighted mean for threshold calculation.
 */
void applyLocalGaussianThreshold(const cv::Mat& inputImage, cv::Mat& outputImage, int blockSize, double C) {
    // Convert the input image to grayscale
    cv::Mat grayscaleImage;
    cv::cvtColor(inputImage, grayscaleImage, cv::COLOR_BGR2GRAY);

    // Ensure outputImage has the same size and type as the input grayscaleImage
    outputImage.create(grayscaleImage.size(), grayscaleImage.type());

    // Compute the half size of the block
    int halfBlockSize = blockSize / 2;

    // Create a kernel for Gaussian weighting

//    Generate a 1D Gaussian kernel of size blockSize,
//    then create a 2D Gaussian kernel by multiplying the 1D kernel with its transpose.
    cv::Mat kernel = cv::getGaussianKernel(blockSize, -1, CV_64F);
    cv::Mat kernel2d = kernel * kernel.t();

    // Iterate through each pixel of the image
    for (int y = 0; y < grayscaleImage.rows; ++y) {
        for (int x = 0; x < grayscaleImage.cols; ++x) {
            // Calculate the bounding box for the local neighborhood
            int startX = std::max(0, x - halfBlockSize);
            int endX = std::min(grayscaleImage.cols - 1, x + halfBlockSize);
            int startY = std::max(0, y - halfBlockSize);
            int endY = std::min(grayscaleImage.rows - 1, y + halfBlockSize);

            // Compute the weighted sum of pixel intensities in the local neighborhood
            double sum = 0.0;
            double weightSum = 0.0;
            for (int ny = startY; ny <= endY; ++ny) {
                for (int nx = startX; nx <= endX; ++nx) {
                    double weight = kernel2d.at<double>(ny - startY, nx - startX);
                    sum += static_cast<double>(grayscaleImage.at<uchar>(ny, nx)) * weight;
                    weightSum += weight;
                }
            }
            double mean = sum / weightSum;

            // Apply thresholding
            outputImage.at<uchar>(y, x) = (grayscaleImage.at<uchar>(y, x) > mean - C) ? 255 : 0;
        }
    }

    cv::imshow("gaus", outputImage);
}


/**
 * Applies Gaussian blur to the input grayscale image.
 * This function smooths the image using Gaussian filtering with a specified kernel size.
 *
 * @param inputImage The input grayscale image to be blurred.
 * @return The blurred image.
 */
Mat gaussianBlur(const Mat& inputImage) {
    Mat blurredImage;
    GaussianBlur(inputImage, blurredImage, Size(5, 5), 0);
    return blurredImage;
}


/**
 * Applies Gaussian thresholding to the input grayscale image based on a threshold value.
 * Pixels with intensities greater than the threshold value are set to 255 (white),
 * while pixels with intensities less than or equal to the threshold value are set to 0 (black).
 *
 * @param inputImage The input grayscale image to be thresholded.
 * @param thresholdValue The threshold value for thresholding.
 * @return The thresholded image.
 */
Mat gaussianThreshold(const Mat& inputImage, int thresholdValue) {
    Mat thresholded;
    threshold(inputImage, thresholded, thresholdValue, 255, THRESH_BINARY);
    return thresholded;
}
//
//// Example usage
//int main() {
//    // Load an image using imread
//    cv::Mat image = cv::imread("orig.jpg", cv::IMREAD_GRAYSCALE);
//    if (image.empty()) {
//        std::cout << "Could not open or find the image" << std::endl;
//        return -1;
//    }
//
//    // Set region size for local thresholding
//    int regionSize = 15;
//
//
//    // Set low and high thresholds for double thresholding
//    int lowThreshold = 50;
//    int highThreshold = 150;
//
//    float threshold = 100.0; // Adjust this value as needed
//
//
//    // Define threshold values
//    std::vector<int> thresholds = { 50, 100, 150 }; // Example threshold values
//
//
//    // Perform Otsu thresholding
//    cv::Mat Otsu_image = otsuThreshold(image);
//
//    // Perform entropy-based thresholding
//    cv::Mat entropy_image = entropyThreshold(image);
//
//    cv::Mat local_spectral_image = localSpectralThreshold(image, regionSize);
//    // Perform double thresholding
//    cv::Mat doubled_thresholded = doubleThresholding(image, lowThreshold, highThreshold);
//
//
//    // Perform Variance-based thresholding
//    cv::Mat variance_image = varianceThreshold(image, regionSize,threshold);
//
//
//    // Perform Multi-level Thresholding
//    cv::Mat multiLevelThresholdImage = multiLevelThresholding(image, thresholds);
//
//
//    // Display the original and binary images
//    cv::imshow("Original Image", image);
//    cv::imshow("otsu Image", Otsu_image);
//    cv::imshow("entropy Image", entropy_image);
//    cv::imshow("local Image", local_spectral_image);
//    cv::imshow("double threshold Image", doubled_thresholded);
//    cv::imshow("Variance-based Threshold Image", variance_image);
//    cv::imshow("Multi-level Thresholding Image", multiLevelThresholdImage);
//    cv::waitKey(0);
//
//    return 0;
//}
