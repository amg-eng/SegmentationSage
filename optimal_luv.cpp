#include"optimal_luv.h"

void display_img(Mat img) {
    imshow("Grey-Scaled Image", img);
    waitKey(0);
}
Mat read_image(String image_path) {
    Mat img = imread(image_path, IMREAD_COLOR);
    return img;
}
Mat convertToGrayScale(const Mat& input) {
    Mat output(input.rows, input.cols, CV_8UC1);

    // Iterate through each pixel
    for (int y = 0; y < input.rows; ++y) {
        for (int x = 0; x < input.cols; ++x) {
            // Get the pixel value
            Vec3b pixel = input.at<Vec3b>(y, x);
            // Compute grayscale value using formula: Y = 0.299R + 0.587G + 0.114B
            unsigned char gray = (unsigned char)(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);
            // Set the grayscale value for all channels
            output.at<unsigned char>(y, x) = gray;
        }
    }

    return output;
}
Mat mearge(Mat img_1, Mat img_2) {
    Mat output;
    int max_height = std::max(img_1.rows, img_2.rows);
    int total_width = img_1.cols + img_2.cols;
    output.create(max_height, total_width, CV_8UC3);
    output.setTo(Scalar(255, 255, 255)); // White background
    // Draw images
    Mat left_roi(output, Rect(0, 0, img_1.cols, img_1.rows));
    img_1.copyTo(left_roi);
    Mat right_roi(output, Rect(img_1.cols, 0, img_2.cols, img_2.rows));
    img_2.copyTo(right_roi);
    return output;
}
Mat optimal_thresholding(Mat image,float accuracy) {


    Mat image_grayscale=convertToGrayScale(image);
    Mat background_vs_object = Mat::ones(image_grayscale.size(), CV_32F);
    //set the corner to be zero
    background_vs_object.at<float>(0, 0) = 0;
    background_vs_object.at<float>(image_grayscale.rows-1, 0) = 0;
    background_vs_object.at<float>(0, image_grayscale.cols-1) = 0;
    background_vs_object.at<float>(image_grayscale.rows-1, image_grayscale.cols-1) = 0;
    //intialize the counter of the number of the pixel of background and object and the sum of thier values
    int background_count = 0;
    int object_count = 0;
    int background_sum = 0;
    int object_sum = 0;
    for (int i = 0; i < image_grayscale.rows; i++) {
        for (int j = 0; j < image_grayscale.cols; j++) {
            if (background_vs_object.at<float>(i, j) == 0) {
                background_count++;
                background_sum += image_grayscale.at<uchar>(i, j);
            }
            else {
                object_count++;
                object_sum += image_grayscale.at<uchar>(i, j);
            }
            
        }
    }
    float background_mean = background_sum / background_count;
    float object_mean = object_sum / object_count;
    float threshold = (object_mean + background_mean) / 2;
    float new_threshold = 0;


    while (1) {
        background_count = 0; 
        object_count = 0;
        background_sum = 0.0;
        object_sum = 0.0;
        for (int i = 0; i < image_grayscale.rows; ++i) {
            for (int j = 0; j < image_grayscale.cols; ++j) {
                if (image_grayscale.at<uchar>(i, j) > threshold) {
                    object_count++;
                    object_sum += image_grayscale.at<uchar>(i, j);
                    background_vs_object.at<float>(i, j) = 255;
                }
                else {
                    background_count++;
                    background_sum += image_grayscale.at<uchar>(i, j);
                    background_vs_object.at<float>(i, j) = 0;
                }

            }
        }
        background_mean = background_sum / background_count;
        object_mean = object_sum / object_count;
        new_threshold = (object_mean + background_mean) / 2;
        if (new_threshold > (threshold - threshold * accuracy) && new_threshold < (threshold + threshold * accuracy))
            break;
        else
            threshold = new_threshold;
    }
    background_vs_object.convertTo(background_vs_object, CV_8U);
    return background_vs_object;
    }


Mat rgb_to_luv(Mat rgb_iamge) {
    Mat luv_image = Mat(rgb_iamge.size(),rgb_iamge.type());//CV_8UC3
    float x, y, z;
    float l, u, v;
    for (int i = 0; i < rgb_iamge.rows; ++i) {
        for (int j = 0; j < rgb_iamge.cols; ++j) {
            Vec3b pixel = rgb_iamge.at<Vec3b>(i, j);
            x = 0.412453 * pixel[2] / 255.0 + 0.357580 * pixel[1] / 255.0 + 0.180423 * pixel[0] / 255.0;
            y = 0.212671 * pixel[2] / 255.0 + 0.715160 * pixel[1] / 255.0 + 0.072169 * pixel[0] / 255.0;
            z = 0.019334 * pixel[2] / 255.0 + 0.119193 * pixel[1] / 255.0 + 0.950227 * pixel[0] / 255.0;
            if (y > 0.008856) {
                l = (116.0 * pow(y, 1.0 / 3.0)) - 16.0;
            }
            else {
                l = 903.3 * y;
            }
            u = 13.0 * l * (4.0 * x / (x + 15.0 * y + 3.0 * z) - 0.19793943);
            v = 13.0 * l * (9.0 * x / (x + 15.0 * y + 3.0 * z) - 0.46831096);
            luv_image.at<Vec3b>(i, j)[0] = (255.0 / 100.0) * l;
            luv_image.at<Vec3b>(i, j)[1] = (255.0 / 354.0) * (u + 134.0);
            luv_image.at<Vec3b>(i, j)[2] = (255.0 / 262.0) * (v + 140.0);
        }
    }
    return luv_image;
}