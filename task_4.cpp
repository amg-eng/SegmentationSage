#include "task_4.h"
#include <iostream>
#include "k_means.h"
#include "meanshift.h"
#include "threshold.h"
#include "optimal_luv.h"
#include "agglomerative.h"
#include "color.h"

Mat Input_Img;
Mat Input_Img_Gray;
QString Input_Img_Path;
QString processType;

int no_clusters;
float distance_bandwidth;
float color_bandwidth;

int low_threshold;
int high_threshold;
int region_size;

int region_Size_var;
int threshold_var;

int agg_clusters;
int reg_th;

int global_var;
int local_var;

int size_padding;
int size_kernal;

int seed_x, seed_y;


task_4::task_4(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::task_4Class)
{
    ui->setupUi(this);


    connect(ui->open_btn, &QPushButton::clicked, this, &task_4::upload_global_img);         
    connect(ui->apply_K_Means_btn, &QPushButton::clicked, this, &task_4::on_applyButton_K_Means_clicked);
    connect(ui->GRAY, &QRadioButton::toggled, this, &task_4::on_radioGrayscale);
    connect(ui->RGB, &QRadioButton::toggled, this, &task_4::on_radioRGB);   

    connect(ui->lineEdit_no_clusters, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_No_Clusters);
    connect(ui->color_bandwidth, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_Color_Bandwidth);
    connect(ui->distance_bandwidth, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_Distance_Bandwidth);   

    connect(ui->apply_Means_shift_btn_2, &QPushButton::clicked, this, &task_4::on_applyButton_Mean_Shift_clicked);
    
    connect(ui->app_ll_btn, &QPushButton::clicked, this, &task_4::on_applyButton_local_spectral_image_clicked);
    
    connect(ui->apply_double, &QPushButton::clicked, this, &task_4::on_applyButton_Double_threshold_clicked);

    connect(ui->low_threshold, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_low_thresh);
    connect(ui->high_threshold, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_high_thresh);


    connect(ui->region_size_line, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_region_size);


        ////////                    
    connect(ui->threshold_, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_var_thresh);
    connect(ui->regionSize_, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_region_size_var);     
    connect(ui->apply_var, &QPushButton::clicked, this, &task_4::on_applyButton_Var_threshold_clicked);
    

    
    connect(ui->multi_threshold, &QPushButton::clicked, this, &task_4::on_applyButton_multi_threshold_clicked);


    connect(ui->otsu_btn, &QPushButton::clicked, this, &task_4::on_applyButton_otsu_threshold_clicked);


    connect(ui->optimal_btn, &QPushButton::clicked, this, &task_4::on_applyButton_optimal_threshold_clicked);


    connect(ui->agg_apply, &QPushButton::clicked, this, &task_4::on_applyAgg_clicked);
    connect(ui->agg_clusters, &QLineEdit::textChanged, this, &task_4::on_Agg_No_Clusters);


    connect(ui->reg_apply, &QPushButton::clicked, this, &task_4::on_applyRegGr_clicked);
    connect(ui->reg_th, &QLineEdit::textChanged, this, &task_4::on_Reg_Threshold);


    /////////////////////////////////////////////////////////////////////////////////////////////////
    connect(ui->threshold_global, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_global_var);
    connect(ui->apply_global, &QPushButton::clicked, this, &task_4::on_applyButton_global_threshold_clicked);

    /////////////////////////////////////////////////////////////////////////////////////////////////
    connect(ui->threshold_gau, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_Local_Gaussian);
    connect(ui->Gussian_btn, &QPushButton::clicked, this, &task_4::Local_Gaussian);

    /////////////////////////////////////////////////////////////////////////////////////////////////
    connect(ui->padding, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_padding);
    connect(ui->Padding_btn, &QPushButton::clicked, this, &task_4::Padding_Threshold);
    /////////////////////////////////////////////////////////////////////////////////////////////////
    connect(ui->kernal_mean, &QLineEdit::textChanged, this, &task_4::on_lineEditInput_adaptive_kernal_size);
    connect(ui->Local_Mean_btn, &QPushButton::clicked, this, &task_4::local_AdaptiveMeanThreshold);










    connect(ui->Seedy, &QLineEdit::textChanged, this, &task_4::Seedy);
    connect(ui->Seedx, &QLineEdit::textChanged, this, &task_4::Seedx);


}


task_4::~task_4()
{
    delete ui;
}

void task_4::UploadImage(cv::Mat& imageMat, bool grayScale, QString& imgPath)
{
    // Open a file dialog to select an image file
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    if (fileName.isEmpty()) return;  // User cancelled the dialog

    // Save the image path
    imgPath = fileName;

    // Load the image using cv::imread
    imageMat = cv::imread(fileName.toStdString());
    if (imageMat.empty()) {
        qDebug() << "Failed to load image from file: " << fileName;
        return;
    }

    // Optionally convert to grayscale
    if (grayScale && imageMat.channels() > 1) {
        cv::cvtColor(imageMat, imageMat, cv::COLOR_BGR2GRAY);
    }
}

void task_4::displayOutputImage(const cv::Mat& image, QLabel* label)
{
    if (!image.empty()) {
        cv::Mat displayImage;

        // Convert grayscale image to RGB for displaying
        if (image.channels() == 1) {
            cv::cvtColor(image, displayImage, cv::COLOR_GRAY2RGB);
        }
        else {
            displayImage = image.clone();
        }

        // Convert the OpenCV Mat image to QImage
        QImage qImage(displayImage.data, displayImage.cols, displayImage.rows, displayImage.step, QImage::Format_RGB888);
        if (qImage.isNull()) {
            qDebug() << "Error: Unable to convert image to QImage.";
            return;
        }

        // Scale the image to fit the QLabel
        QPixmap pixmap = QPixmap::fromImage(qImage);
        pixmap = pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // Display the scaled image in the specified QLabel
        label->setPixmap(pixmap);
        label->setAlignment(Qt::AlignCenter);
    }
    else {
        qDebug() << "Error: Image is empty.";
    }
}


void task_4::displayImageInLabel(const cv::Mat& image, QLabel* label)
{
    if (!image.empty()) {
        cv::Mat displayImage;

        // Convert BGR image to RGB format for displaying in Qt
        cv::cvtColor(image, displayImage, cv::COLOR_BGR2RGB);

        // Convert the OpenCV Mat image to QImage
        QImage qImage(displayImage.data, displayImage.cols, displayImage.rows, displayImage.step, QImage::Format_RGB888);
        if (qImage.isNull()) {
            qDebug() << "Error: Unable to convert image to QImage.";
            return;
        }

        // Display the image in the specified QLabel
        QPixmap pixmap = QPixmap::fromImage(qImage);
        label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio));
        label->setAlignment(Qt::AlignCenter);
    }
    else {
        qDebug() << "Error: Image is empty.";
    }
}


void task_4::upload_global_img()
{
    UploadImage(Input_Img, false, Input_Img_Path);
    if (Input_Img.empty()) return;
    
    cv::cvtColor(Input_Img, Input_Img_Gray, cv::COLOR_BGR2GRAY);
    Mat luv_img = rgb_to_luv(Input_Img);

    displayImageInLabel(Input_Img, ui->k_means_input); 
    displayImageInLabel(Input_Img, ui->means_shift_input_2);
    displayImageInLabel(Input_Img, ui->input_threshold);
    displayImageInLabel(Input_Img, ui->agg_input);
    displayImageInLabel(Input_Img, ui->reg_input);      
    displayImageInLabel(Input_Img, ui->rgb);
    displayOutputImage(Input_Img_Gray, ui->gray);
    displayImageInLabel(luv_img, ui->luv);

}

void task_4::on_radioGrayscale(bool checked)
{
    if (checked) {
        processType = "Grayscale";
    }
}

void task_4::on_radioRGB(bool checked)
{
    if (checked) {
        processType = "RGB";
    }
}

void task_4::on_lineEditInput_No_Clusters(const QString& text)
{
    // Convert text to integer
    bool ok;
    no_clusters = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << no_clusters;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}


void task_4::on_applyButton_K_Means_clicked()
{   
    int clusters = no_clusters;
    if (processType == "Grayscale") {
        // Execute grayscale processing
        Mat segmented_gray = Gray_kmeans_segmentation(Input_Img.clone(), clusters);
        displayOutputImage(segmented_gray, ui->k_means_output);
    }
    else if (processType == "RGB") {
        // Execute RGB processing
        Mat segmented_rgb = RGB_kmeans_segmentation(Input_Img.clone(), clusters);
        displayImageInLabel(segmented_rgb, ui->k_means_output);
    }
}


void task_4::on_lineEditInput_Color_Bandwidth(const QString& text)
{
    // Convert text to float
    bool ok; 
    color_bandwidth = text.toFloat(&ok);
    if (ok) {
        // Input is a valid float, use inputFloat as needed
        qDebug() << "Input as float:" << color_bandwidth;
    }
    else {
        // Input is not a valid float, handle error or provide feedback
        qDebug() << "Invalid input. Please enter a float.";
    }
}
void task_4::on_lineEditInput_Distance_Bandwidth(const QString& text)
{
    // Convert text to float
    bool ok;
    distance_bandwidth = text.toFloat(&ok);
    if (ok) {
        // Input is a valid float, use inputFloat as needed
        qDebug() << "Input as float:" << distance_bandwidth;
    }
    else {
        // Input is not a valid float, handle error or provide feedback
        qDebug() << "Invalid input. Please enter a float.";
    }
}

void task_4::on_applyButton_Mean_Shift_clicked()
{
    float distance = distance_bandwidth;
    float color = color_bandwidth;
    Mat segmentedImg = segment(Input_Img, distance_bandwidth, color);
    displayImageInLabel(segmentedImg, ui->means_shift_output_2);

}

/////////////////////////////////////////////////////////      -- thresholding

void task_4::on_lineEditInput_region_size(const QString& text)
{
    // Convert text to integer
    bool ok;
    region_size = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << region_size;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}

void task_4::on_applyButton_local_spectral_image_clicked()
{
    Mat grayImg;
    int regionSize = region_size;
    cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
    Mat local_spectral_image = localSpectralThreshold(grayImg, regionSize);

    displayOutputImage(local_spectral_image, ui->output_threshold);


}

void task_4::on_lineEditInput_low_thresh(const QString& text)
{
    // Convert text to integer
    bool ok;
    low_threshold = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << low_threshold;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}
void task_4::on_lineEditInput_high_thresh(const QString& text)
{
    // Convert text to integer
    bool ok;
    high_threshold = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << high_threshold;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}


void task_4::on_applyButton_Double_threshold_clicked()
{
    Mat grayImg;
    int lowThreshold = low_threshold, highThreshold = high_threshold;

    cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
    Mat doubled_thresholded = doubleThresholding(grayImg, lowThreshold, highThreshold);
    displayOutputImage(doubled_thresholded, ui->output_threshold);


}



/////////////////

void task_4::on_lineEditInput_var_thresh(const QString& text)
{
    // Convert text to integer
    bool ok;
    threshold_var = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << threshold_var;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}



void task_4::on_lineEditInput_region_size_var(const QString& text)
{
    // Convert text to integer
    bool ok;
    region_Size_var = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << region_Size_var;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}


void task_4::on_applyButton_Var_threshold_clicked()
{
    Mat grayImg;
    int regionSize = region_Size_var;
    int threshold = threshold_var;
    cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
    Mat variance_image = varianceThreshold(grayImg, regionSize, threshold);
    displayOutputImage(variance_image, ui->output_threshold);

}

void task_4::on_applyButton_multi_threshold_clicked()
{
    Mat grayImg;
    std::vector<int> thresholds = { 50, 100, 150 }; 
    cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
    Mat multiLevelThresholdImage = multiLevelThresholding(grayImg, thresholds);
    displayOutputImage(multiLevelThresholdImage, ui->output_threshold);

}

void task_4::on_applyButton_otsu_threshold_clicked()
{
    Mat grayImg;
    cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
    Mat Otsu_image = otsuThreshold(grayImg);
    displayOutputImage(Otsu_image, ui->output_threshold);

}

void task_4::on_applyButton_optimal_threshold_clicked()
{
    //Mat grayImg;
    //cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
    Mat optimal_img = optimal_thresholding(Input_Img.clone(), .01);
        displayOutputImage(optimal_img, ui->output_threshold);

}

//--------------------------------------------------AGGLOMERATIVE---------------------------------------------//
void task_4::on_Agg_No_Clusters(const QString& text) {
    bool ok;
    agg_clusters = text.toInt(&ok);
}


void task_4::on_applyAgg_clicked() {
    Mat agg_image = Input_Img.clone();
    // // Perform agglomerative hierarchical clustering with 5 clusters
    // Mat clustered_image = agglomerativeClustering(agg_image, agg_clusters);
    // displayOutputImage(clustered_image, ui->agg_output);
    Mat agglomerativePixels;
    Mat agglomerativeResizedImage;
    Mat agg_output;
    tie(agglomerativePixels, agglomerativeResizedImage) = image_preperation(agg_image);
    agg_output = image_color_segmentation(agg_clusters, agglomerativePixels, agglomerativeResizedImage);
    displayOutputImage(agg_output, ui->agg_output);

}

//------------------------------------------------Reigon Growing---------------------------------------------//
void task_4::on_Reg_Threshold(const QString& text) {
    bool ok;
    reg_th = text.toInt(&ok);
}
void task_4::Seedx(const QString& text) {
    bool ok;
    seed_x = text.toInt(&ok);
}
void task_4::Seedy(const QString& text) {
    bool ok;
    seed_y = text.toInt(&ok);
}
void task_4::on_applyRegGr_clicked() {
    Mat RegImage = Input_Img.clone();
    Mat RegImage_Gray = Input_Img_Gray.clone();
    //vector<Point> seedPoints;
    //seedPoints.push_back(Point(100, 100));  // Example seed point 1
    //seedPoints.push_back(Point(150, 150));  // Example seed point 2

    int threshold = reg_th;  // Example threshold value

    //Mat output_img = regionGrowingMultiSeed(RegImage, seedPoints, 4, true);
    //Mat output_grey = regionGrowingMultiSeed(RegImage_Gray, seedPoints, 4, false);
    //displayOutputImage(output_img, ui->reg_color_output);
    //displayImageInLabel(output_img, ui->reg_gray_output);




        // Define seed points (you can adjust these based on your requirements)
        vector<Point> seedPoints;
        seedPoints.push_back(Point(100, 100)); // Example seed point 1
        seedPoints.push_back(Point(200, 200)); // Example seed point 2
        seedPoints.push_back(Point(300, 300)); // Example seed point 3

        // Set threshold for region growing (you can adjust this based on your requirements)
        int _threshold = 20;

        // Set colorflag to true to maintain colors in the output
        bool colorflag = true;

        // Perform region growing
        Mat segmentedImage = regionGrowingMultiSeed(RegImage, seedPoints, _threshold, colorflag);


        displayImageInLabel(segmentedImage, ui->reg_gray_output);



        // Perform region growing on RGB image
        Mat segmentedImg;
        regionGrowingRGB(RegImage, segmentedImg, seed_x, seed_y, threshold);

        displayImageInLabel(segmentedImg, ui->output_seed);



}




































void task_4::on_lineEditInput_global_var(const QString& text)
{
    // Convert text to integer
    bool ok;
    global_var = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << global_var;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}


void task_4::on_applyButton_global_threshold_clicked()
{
    Mat grayImg;
    int regionSize = global_var;
    cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
    Mat glob_image = globalThreshold(grayImg, global_var, 255, 0);
    displayOutputImage(glob_image, ui->output_threshold);

}




void task_4::on_lineEditInput_Local_Gaussian(const QString& text)
{
    // Convert text to integer
    bool ok;
    local_var = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << local_var;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}

void task_4::Local_Gaussian()
{
        Mat grayImg;
        int threshold = local_var;
        cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
        Mat blur_img = gaussianBlur(grayImg);
        Mat res = gaussianThreshold(blur_img, threshold);
        displayOutputImage(res, ui->output_threshold);


}


void task_4::on_lineEditInput_padding(const QString& text)
{
    // Convert text to integer
    bool ok;
    size_padding = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << local_var;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}

void task_4::Padding_Threshold()
{
        Mat grayImg;
        int size = size_padding;
        cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
        Mat Padding_Threshold_gray = adaptivePaddingFunction(grayImg, size);
        displayOutputImage(Padding_Threshold_gray, ui->output_threshold);

}

void task_4::on_lineEditInput_adaptive_kernal_size(const QString& text)
{
    // Convert text to integer
    bool ok;
    size_kernal = text.toInt(&ok);
    if (ok) {
        // Input is a valid integer, use userInput as needed
        qDebug() << "Input as integer:" << size_kernal;
    }
    else {
        // Input is not a valid integer, handle error or provide feedback
        qDebug() << "Invalid input. Please enter an integer.";
    }
}

void task_4::local_AdaptiveMeanThreshold()
{
        Mat grayImg;
        int size = size_kernal;
        cvtColor(Input_Img.clone(), grayImg, COLOR_BGR2GRAY);
        Mat Mean_Threshold_gray = localAdaptiveMeanThreshold(grayImg, size_kernal, 2, 255, 0);

        displayOutputImage(Mean_Threshold_gray, ui->output_threshold);
       
      
}