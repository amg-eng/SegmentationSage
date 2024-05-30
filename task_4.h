#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_task_4.h"
#include <QLabel>
#include <QFileDialog>
#include <QDebug>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <QLabel>
#include <QFileDialog>
#include <QPainter> 
#include <QRadioButton>


using namespace cv;


QT_BEGIN_NAMESPACE
namespace Ui { class task_4Class; };
QT_END_NAMESPACE

class task_4 : public QMainWindow
{
    Q_OBJECT

public:
    task_4(QWidget *parent = nullptr);
    ~task_4();

    void UploadImage(cv::Mat& imageMat, bool grayScale, QString& imgPath);

    void displayOutputImage(const cv::Mat& image, QLabel* label);

    void displayImageInLabel(const cv::Mat& image, QLabel* label);

    void upload_global_img();

    void on_radioGrayscale(bool checked);

    void on_radioRGB(bool checked);

    void on_lineEditInput_No_Clusters(const QString& text);

    void on_applyButton_K_Means_clicked();

    void on_lineEditInput_Color_Bandwidth(const QString& text);

    void on_lineEditInput_Distance_Bandwidth(const QString& text);

    void on_applyButton_Mean_Shift_clicked();

    void on_lineEditInput_region_size(const QString& text);

    void on_applyButton_local_spectral_image_clicked();

    void on_lineEditInput_low_thresh(const QString& text);

    void on_lineEditInput_high_thresh(const QString& text);

    void on_applyButton_Double_threshold_clicked();

    void on_lineEditInput_var_thresh(const QString& text);

    void on_lineEditInput_region_size_var(const QString& text);

    void on_applyButton_Var_threshold_clicked();

    void on_applyButton_multi_threshold_clicked();

    void on_applyButton_otsu_threshold_clicked();

    void on_applyButton_optimal_threshold_clicked();

    void on_Agg_No_Clusters(const QString& text);

    void on_applyAgg_clicked();

    void on_Reg_Threshold(const QString& text);

    void Seedx(const QString& text);

    void Seedy(const QString& text);

    void on_applyRegGr_clicked();

    void on_lineEditInput_global_var(const QString& text);

    void on_applyButton_global_threshold_clicked();

    void on_lineEditInput_Local_Gaussian(const QString& text);

    void Local_Gaussian();

    void on_lineEditInput_padding(const QString& text);

    void Padding_Threshold();

    void on_lineEditInput_adaptive_kernal_size(const QString& text);

    void on_lineEditInput_adaptive(const QString& text);

    void local_AdaptiveMeanThreshold();


private:
    Ui::task_4Class *ui;
};
