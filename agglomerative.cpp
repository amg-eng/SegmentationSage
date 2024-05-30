#include <opencv2/opencv.hpp>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>
#include <queue>

using namespace cv;
using namespace std;


double euclidean_distance(const std::vector<double>& point1, const std::vector<double>& point2)
{
    if (point1.size() != point2.size())
    {
        throw invalid_argument("Point dimensions do not match");
    }
    double sum = 0.0;
    for (size_t i = 0; i < point1.size(); ++i)
    {
        double diff = point1[i] - point2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double clusters_distance(const vector<vector<double>>& cluster1,
    const vector<vector<double>>& cluster2)
{
    double max_dist = 0.0;
    for (const auto& point1 : cluster1)
    {
        for (const auto& point2 : cluster2)
        {
            double dist = euclidean_distance(point1, point2);
            if (dist > max_dist)
            {
                max_dist = dist;
            }
        }
    }
    return max_dist;
}


vector<vector<vector<double>>> initial_clusters(Mat PixelsMatrix)
{
    vector<vector<vector<double>>> clusters;
    vector<double> allComparingResult;
    int initial_k = 25;
    vector<vector<vector<double>>> groups(initial_k);

    int d = static_cast<int>(256 / initial_k);

    for (int i = 0; i < PixelsMatrix.rows; i++)
    {
        vector<double> matrix_value_point = PixelsMatrix.row(i);

        for (int j = 0; j < initial_k; j++)
        {
            double k = j * d;
            vector<double> color_value_point = { k, k, k };
            double result = euclidean_distance(matrix_value_point, color_value_point);
            allComparingResult.push_back(result);
        }

        auto it = std::min_element(allComparingResult.begin(), allComparingResult.end());

        int index = std::distance(allComparingResult.begin(), it);
        groups[index].push_back(matrix_value_point);

        allComparingResult.clear();
    }

    for (const auto& group : groups)
    {
        if (!group.empty())
        {
            vector<vector<double>> point_group;
            for (const auto& point : group)
            {
                point_group.push_back(point);
            }
            clusters.push_back(point_group);
        }
    }

    return clusters;
}



void fit(int k, Mat& pixels, vector<int>& labels, map<int, vector<double>>& centers, map<vector<double>, int>& cluster_map)
{
    // Initially, assign each point to a distinct cluster
    vector<vector<vector<double>>> clusters_list = initial_clusters(pixels);

    while (clusters_list.size() > k)
    {
        // Find the closest (most similar) pair of clusters
        vector<vector<double>> cluster1, cluster2;

        // DBL_MAX is a constant defined in the <cfloat> header file that represents the maximum finite value of type double.
        double min_distance = DBL_MAX;

        for (int i = 0; i < clusters_list.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                double distance = clusters_distance(clusters_list[i], clusters_list[j]);

                if (distance < min_distance)
                {
                    min_distance = distance;
                    cluster1 = clusters_list[i];
                    cluster2 = clusters_list[j];
                }
            }
        }

        // Remove the two clusters from the clusters list
        clusters_list.erase(std::remove(clusters_list.begin(), clusters_list.end(), cluster1), clusters_list.end());
        clusters_list.erase(std::remove(clusters_list.begin(), clusters_list.end(), cluster2), clusters_list.end());

        // Merge the two clusters
        vector<vector<double>> merged_cluster = cluster1;
        merged_cluster.insert(merged_cluster.end(), cluster2.begin(), cluster2.end());

        // Add the merged cluster to the clusters list
        clusters_list.push_back(merged_cluster);
    }

    // Assign cluster number to each point
    cluster_map.clear();
    for (int i = 0; i < clusters_list.size(); ++i)
    {
        for (int j = 0; j < clusters_list[i].size(); ++j)
        {
            cluster_map[clusters_list[i][j]] = i;
        }
    }

    // Compute cluster centers
    centers.clear();
    for (int i = 0; i < clusters_list.size(); ++i)
    {
        Mat cluster_mat(clusters_list[i].size(), clusters_list[i][0].size(), CV_64FC1);

        for (int j = 0; j < clusters_list[i].size(); ++j)
        {
            for (int k = 0; k < clusters_list[i][j].size(); ++k)
            {
                cluster_mat.at<double>(j, k) = clusters_list[i][j][k];
            }
        }

        Mat center_mat;
        reduce(cluster_mat, center_mat, 0, REDUCE_AVG);

        vector<double> center;
        for (int j = 0; j < center_mat.cols; ++j)
        {
            center.push_back(center_mat.at<double>(0, j));
        }
        centers[i] = center;
    }

    // Assign cluster center to each point
    labels.clear();
    for (int i = 0; i < pixels.rows; ++i)
    {
        vector<double> pixel = pixels.row(i);
        int cluster_num = cluster_map[pixel];
        labels.push_back(cluster_num);
    }
}

// Function to predict the cluster number of a given point
int predict_cluster(map<vector<double>, int>& cluster_map, vector<double>& point)
{
    // Find cluster number of point
    return cluster_map[point];
}

// Function to predict the center of the cluster that a given point belongs to
vector<double> predict_center(map<int, vector<double>>& centers, map<vector<double>, int>& cluster_map, vector<double>& point)
{
    // Find center of the cluster that point belongs to
    int point_cluster_num = predict_cluster(cluster_map, point);
    vector<double> center = centers[point_cluster_num];
    return center;
}

std::pair<Mat, Mat> image_preperation(Mat& image)
{
    Mat resized_image;
    Mat pixels;
    // Resize the image to 300x300 pixels
    resize(image, resized_image, Size(100, 100));
    // Convert the input image to a one-dimensional array of pixels
    pixels = resized_image.reshape(1, resized_image.rows * resized_image.cols);
    return { pixels, resized_image };
}

Mat image_color_segmentation(int k, Mat& pixels, Mat& resized_image)
{

    // Perform agglomerative clustering to segment the image into k clusters
    vector<int> labels;
    map<int, vector<double>> centers;
    map<vector<double>, int> cluster_map;
    fit(k, pixels, labels, centers, cluster_map);

    // Create a new image with each pixel assigned to its corresponding cluster center
    Mat segmented_image(resized_image.size(), resized_image.type());
    for (int i = 0; i < resized_image.rows; ++i)
    {
        for (int j = 0; j < resized_image.cols; ++j)
        {
            Vec3b pixel = resized_image.at<Vec3b>(i, j);
            vector<double> point = { (double)pixel[0], (double)pixel[1], (double)pixel[2] };
            vector<double> center = predict_center(centers, cluster_map, point);
            Vec3b new_pixel(center[0], center[1], center[2]);
            segmented_image.at<Vec3b>(i, j) = new_pixel;
        }
    }
    return segmented_image;
}
