/* required libraries */
#include "color.h"


struct Cluster {
    int label; // Cluster label
    Scalar color; // Color for visualization
    vector<Point> points; // Points belonging to this cluster
};
/*  ------------------------------------------------------------------------------------------------------
this function :
  * Get the number of rows, columns , and the required region matrix for segmentation.
  * colorize this region according to the label given to it.
  * support grayscale and colored images.
*/
void color_region(int rows, int cols, Mat& inputImage, Mat& labelMatrix, Mat& outputImage, bool colorflag) {


    // Assign the colors to the output image based on the label matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int label = labelMatrix.at<uchar>(i, j);

            if (colorflag == true) {
                if (label == 1) {
                    outputImage.at<Vec3b>(i, j) = inputImage.at<Vec3b>(i, j);
                }
            }
            else {
                if (label != 0) {
                    // Colorize the pixel with a unique color based on its label
                    outputImage.at<Vec3b>(i, j) = Vec3b((label * 50) % 255, (label * 100) % 255, (label * 150) % 255);
                }
            }
        }
    }
}



/*  ------------------------------------------------------------------------------------------------------
this function :
  * Get the image, the vector of seed points, the intial label matrix, and the threshold from the user as input.
  * start from a given seed point and iterate over 8-directions pixel according to a given thresold.
  * if the difference is less than thresold , add this point to this region with its label.
  * add this point also to the queue of seed points to iterate around it also.
*/
void region_detection(std::queue<Point> Q, int rows, int cols, Mat& inputImage, Mat& labelMatrix, int threshold, bool colorflag) {

    int newLabel = 0;

    while (!Q.empty())
    {
        // Get the next point from the queue
        Point currentPoint = Q.front();
        Q.pop();

        if (colorflag == true) {
            // Get the pixel value at the current point
            Vec3b currentValue = inputImage.at<Vec3b>(currentPoint);

            // Check the 8-connected neighborhood of the current point.
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    // Skip the current point
                    if (i == 0 && j == 0)
                        continue;

                    // Get the coordinates of the neighboring point
                    int x = currentPoint.x + j;
                    int y = currentPoint.y + i;

                    // Check if the neighboring point is within the image boundaries
                    if (x >= 0 && y >= 0 && x < cols && y < rows)
                    {
                        // Get the pixel value at the neighboring point
                        Vec3b neighborValue = inputImage.at<Vec3b>(y, x);


                        // Calculate the absolute difference between the current pixel value and the neighboring pixel value
                        int diff = abs(currentValue[0] - neighborValue[0]) + abs(currentValue[1] - neighborValue[1]) + abs(currentValue[2] - neighborValue[2]);

                        // Check if the difference is within the threshold
                        if (diff <= threshold)
                        {
                            // Check if the neighboring point has already been labeled
                            if (labelMatrix.at<uchar>(y, x) == 0)
                            {
                                // Assign the current label to the neighboring point
                                labelMatrix.at<uchar>(y, x) = 1;

                                // Add the neighboring point to the queue
                                Q.push(Point(x, y));
                            }
                        }
                    }
                }
            }
        }

        else {
            // Check the 8-connected neighbors of the current point
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {

                    // Skip the current point and out-of-bounds pixels
                    if (i == 0 && j == 0)
                        continue;

                    int x = currentPoint.x + i;
                    int y = currentPoint.y + j;

                    if (x < 0 || x >= cols || y < 0 || y >= rows)
                        continue;

                    // Check if the neighbor is within the threshold
                    int difference = abs(inputImage.at<uchar>(currentPoint) - inputImage.at<uchar>(y, x));
                    if (difference <= threshold && labelMatrix.at<uchar>(y, x) == 0)
                    {
                        // Assign a new label to the neighbor and add it to the queue
                        newLabel = labelMatrix.at<uchar>(currentPoint);
                        labelMatrix.at<uchar>(y, x) = newLabel;
                        Q.push(Point(x, y));
                    }
                }
            }
        }
    }
}


/*  ------------------------------------------------------------------------------------------------------
this function :
  * Get the image, the vector of seed points , and the threshold from the user as input.
  * define the output image matrix with intial condition zeros .
  * define the matrix that hold the required region labels with intial condition zeros.
  * define the queue that will hold the seed points over every iteration.
  * add the first seed point to the queue.
  * call the functions for iterations and colorization.
*/
Mat regionGrowingHelper(Mat& inputImage, Point& seedPoint, int threshold, int labelNumber, bool colorflag)
{
    // no. of image rows
    int rows = inputImage.rows;

    // no. of image columns
    int cols = inputImage.cols;

    // Create an empty label matrix
    Mat labelMatrix = Mat::zeros(rows, cols, CV_32SC1); // Use CV_32SC1 for labelMatrix

    // Create a queue for storing the neighboring points to be checked
    std::queue<Point> Q;

    // Initialize the queue with the seed point and set its label
    Q.push(seedPoint);

    // Assigns a new label to the seed point in the labelMatrix matrix.
    labelMatrix.at<int>(seedPoint) = labelNumber;

    region_detection(Q, rows, cols, inputImage, labelMatrix, threshold, colorflag);

    // Create an output image to show the segmented regions
    Mat outputImage = Mat::zeros(inputImage.size(), CV_8UC3);

    color_region(rows, cols, inputImage, labelMatrix, outputImage, colorflag);

    return outputImage;
}

// Function to perform region growing for multiple seed points
Mat regionGrowingMultiSeed(Mat& inputImage, vector<Point>& seedPoints, int threshold, bool colorflag) {
    Mat outputImage = Mat::zeros(inputImage.size(), CV_8UC3);
    int labelNumber = 1;

    // Create a map to store clusters
    unordered_map<int, Cluster> clusters;

    // Process each seed point
    for (Point seedPoint : seedPoints) {
        // Call region growing for each seed point
        Mat region = regionGrowingHelper(inputImage, seedPoint, threshold, labelNumber, colorflag);

        // Create a new cluster for each region
        Cluster cluster;
        cluster.label = labelNumber;
        cluster.color = Scalar(rand() % 256, rand() % 256, rand() % 256); // Random color for the cluster

        // Add points of the region to the cluster
        for (int i = 0; i < region.rows; i++) {
            for (int j = 0; j < region.cols; j++) {
                Vec3b color = region.at<Vec3b>(i, j);
                if (color != Vec3b(0, 0, 0)) { // Check if the pixel is part of a region
                    cluster.points.push_back(Point(j, i)); // Add the point to the cluster
                }
            }
        }

        // Add the cluster to the clusters map
        clusters[labelNumber] = cluster;

        // Increment label number for the next region
        labelNumber++;
    }

    // Colorize the output image based on the clusters
    for (auto& pair : clusters) {
        Cluster& cluster = pair.second;
        Scalar color = cluster.color;
        for (Point point : cluster.points) {
            outputImage.at<Vec3b>(point) = Vec3b(color[0], color[1], color[2]);
        }
    }

    return outputImage;
}




// Function to compute the color difference between two RGB pixels
int colorDifference(const Vec3b& pixel1, const Vec3b& pixel2) {
    return abs(pixel1[0] - pixel2[0]) + abs(pixel1[1] - pixel2[1]) + abs(pixel1[2] - pixel2[2]);
}

// Function to perform region growing on RGB images
void regionGrowingRGB(const Mat& inputImage, Mat& outputImage, int seedX, int seedY, int threshold) {
    // Ensure the seed coordinates are within the image bounds
    if (seedX < 0 || seedX >= inputImage.cols || seedY < 0 || seedY >= inputImage.rows)
        return;

    // Initialize output image
    outputImage = Mat::zeros(inputImage.size(), CV_8UC3);

    // Create a queue for storing pixels to be processed
    queue<PixelCoord> pixelsQueue;

    // Convert input image to LAB color space for better color comparison
    Mat labImage;
    cvtColor(inputImage, labImage, COLOR_BGR2Lab);

    // Get LAB color of seed pixel
    Vec3b seedColor = labImage.at<Vec3b>(seedY, seedX);

    // Set the background color to blue
    Vec3b backgroundColor(255, 0, 0); // Blue background color

    // Push seed pixel onto the queue
    pixelsQueue.push(PixelCoord(seedX, seedY));

    // Process pixels in the queue until the queue is empty
    while (!pixelsQueue.empty()) {
        // Get the current pixel from the queue
        PixelCoord currentPixel = pixelsQueue.front();
        pixelsQueue.pop();

        // Check if the pixel has already been processed
        if (outputImage.at<Vec3b>(currentPixel.y, currentPixel.x) == Vec3b(0, 0, 0)) {
            // Create a mask for the current region
            Mat mask = Mat::zeros(inputImage.size(), CV_8UC1);

            // Create a queue for this region
            queue<PixelCoord> regionQueue;

            // Push seed pixel onto the queue
            regionQueue.push(currentPixel);

            // Process pixels in the queue until the queue is empty
            while (!regionQueue.empty()) {
                // Get the current pixel from the queue
                PixelCoord currentRegionPixel = regionQueue.front();
                regionQueue.pop();

                // Check if the pixel has already been processed
                if (mask.at<uchar>(currentRegionPixel.y, currentRegionPixel.x) == 0) {
                    // Mark the pixel as processed
                    mask.at<uchar>(currentRegionPixel.y, currentRegionPixel.x) = 255;

                    // Check if the pixel belongs to the object (similar color to seed pixel)
                    Vec3b pixelColor = labImage.at<Vec3b>(currentRegionPixel.y, currentRegionPixel.x);
                    int diff = colorDifference(seedColor, pixelColor);
                    if (diff <= threshold) {
                        // Assign color to the output image
                        outputImage.at<Vec3b>(currentRegionPixel.y, currentRegionPixel.x) = inputImage.at<Vec3b>(currentRegionPixel.y, currentRegionPixel.x);

                        // Check neighboring pixels
                        for (int dy = -1; dy <= 1; dy++) {
                            for (int dx = -1; dx <= 1; dx++) {
                                int x = currentRegionPixel.x + dx;
                                int y = currentRegionPixel.y + dy;

                                // Check if the neighboring pixel is within the image bounds
                                if (x >= 0 && x < inputImage.cols && y >= 0 && y < inputImage.rows) {
                                    // Add the neighboring pixel to the region queue
                                    regionQueue.push(PixelCoord(x, y));
                                }
                            }
                        }
                    }
                    else {
                        // Set background color
                        outputImage.at<Vec3b>(currentRegionPixel.y, currentRegionPixel.x) = backgroundColor;
                    }
                }
            }
        }
    }
}
