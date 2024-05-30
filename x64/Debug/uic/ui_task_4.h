/********************************************************************************
** Form generated from reading UI file 'task_4.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_4_H
#define UI_TASK_4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task_4Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *open_btn;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_no_clusters;
    QRadioButton *RGB;
    QRadioButton *GRAY;
    QPushButton *apply_K_Means_btn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *k_means_input;
    QLabel *k_means_output;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *color_bandwidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *distance_bandwidth;
    QPushButton *apply_Means_shift_btn_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *means_shift_input_2;
    QLabel *means_shift_output_2;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_7;
    QToolBox *toolBox;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_21;
    QLineEdit *low_threshold;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_22;
    QLineEdit *high_threshold;
    QPushButton *apply_double;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLineEdit *regionSize_;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QLineEdit *threshold_;
    QPushButton *apply_var;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_15;
    QPushButton *multi_threshold;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QLineEdit *region_size_line;
    QPushButton *app_ll_btn;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_6;
    QPushButton *otsu_btn;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_8;
    QPushButton *optimal_btn;
    QWidget *page_11;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_27;
    QLineEdit *threshold_global;
    QPushButton *apply_global;
    QWidget *page_8;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_7;
    QLineEdit *threshold_gau;
    QPushButton *Gussian_btn;
    QWidget *page_9;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_8;
    QLineEdit *kernal_mean;
    QPushButton *Local_Mean_btn;
    QWidget *page_10;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_10;
    QLineEdit *padding;
    QPushButton *Padding_btn;
    QVBoxLayout *verticalLayout_23;
    QLabel *input_threshold;
    QLabel *output_threshold;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_32;
    QHBoxLayout *horizontalLayout_36;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_23;
    QLineEdit *agg_clusters;
    QPushButton *agg_apply;
    QHBoxLayout *horizontalLayout_35;
    QLabel *agg_input;
    QLabel *agg_output;
    QWidget *tab_9;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_52;
    QLineEdit *reg_th;
    QLabel *label;
    QLineEdit *Seedx;
    QLabel *label_2;
    QLineEdit *Seedy;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *reg_apply;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_11;
    QLabel *reg_input;
    QVBoxLayout *verticalLayout_47;
    QLabel *output_seed;
    QLabel *reg_gray_output;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_22;
    QLabel *rgb;
    QLabel *gray;
    QLabel *luv;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *task_4Class)
    {
        if (task_4Class->objectName().isEmpty())
            task_4Class->setObjectName("task_4Class");
        task_4Class->resize(1099, 1080);
        centralWidget = new QWidget(task_4Class);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        open_btn = new QPushButton(centralWidget);
        open_btn->setObjectName("open_btn");

        horizontalLayout->addWidget(open_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(16);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(79, 0));
        label_3->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_no_clusters = new QLineEdit(tab);
        lineEdit_no_clusters->setObjectName("lineEdit_no_clusters");

        horizontalLayout_3->addWidget(lineEdit_no_clusters);

        RGB = new QRadioButton(tab);
        RGB->setObjectName("RGB");

        horizontalLayout_3->addWidget(RGB);

        GRAY = new QRadioButton(tab);
        GRAY->setObjectName("GRAY");

        horizontalLayout_3->addWidget(GRAY);

        apply_K_Means_btn = new QPushButton(tab);
        apply_K_Means_btn->setObjectName("apply_K_Means_btn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(68);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(apply_K_Means_btn->sizePolicy().hasHeightForWidth());
        apply_K_Means_btn->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(apply_K_Means_btn);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        k_means_input = new QLabel(tab);
        k_means_input->setObjectName("k_means_input");

        horizontalLayout_2->addWidget(k_means_input);

        k_means_output = new QLabel(tab);
        k_means_output->setObjectName("k_means_output");

        horizontalLayout_2->addWidget(k_means_output);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(1, 15);

        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_8 = new QHBoxLayout(tab_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(79, 0));
        label_4->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(label_4);

        color_bandwidth = new QLineEdit(tab_2);
        color_bandwidth->setObjectName("color_bandwidth");

        horizontalLayout_5->addWidget(color_bandwidth);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(79, 0));
        label_5->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(label_5);

        distance_bandwidth = new QLineEdit(tab_2);
        distance_bandwidth->setObjectName("distance_bandwidth");

        horizontalLayout_4->addWidget(distance_bandwidth);


        horizontalLayout_7->addLayout(horizontalLayout_4);

        apply_Means_shift_btn_2 = new QPushButton(tab_2);
        apply_Means_shift_btn_2->setObjectName("apply_Means_shift_btn_2");
        sizePolicy1.setHeightForWidth(apply_Means_shift_btn_2->sizePolicy().hasHeightForWidth());
        apply_Means_shift_btn_2->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(apply_Means_shift_btn_2);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        means_shift_input_2 = new QLabel(tab_2);
        means_shift_input_2->setObjectName("means_shift_input_2");

        horizontalLayout_6->addWidget(means_shift_input_2);

        means_shift_output_2 = new QLabel(tab_2);
        means_shift_output_2->setObjectName("means_shift_output_2");

        horizontalLayout_6->addWidget(means_shift_output_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout_4->setStretch(1, 10);

        horizontalLayout_8->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        horizontalLayout_9 = new QHBoxLayout(tab_3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        frame_2 = new QFrame(tab_3);
        frame_2->setObjectName("frame_2");
        frame_2->setMaximumSize(QSize(400, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName("verticalLayout_7");
        toolBox = new QToolBox(frame_2);
        toolBox->setObjectName("toolBox");
        toolBox->setMinimumSize(QSize(0, 300));
        toolBox->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        toolBox->setFont(font1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 376, 540));
        verticalLayout_13 = new QVBoxLayout(page_2);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName("verticalLayout_13");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_21 = new QLabel(page_2);
        label_21->setObjectName("label_21");
        label_21->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_14->addWidget(label_21);

        low_threshold = new QLineEdit(page_2);
        low_threshold->setObjectName("low_threshold");
        low_threshold->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_14->addWidget(low_threshold);


        verticalLayout_13->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_22 = new QLabel(page_2);
        label_22->setObjectName("label_22");
        label_22->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_15->addWidget(label_22);

        high_threshold = new QLineEdit(page_2);
        high_threshold->setObjectName("high_threshold");
        high_threshold->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_15->addWidget(high_threshold);


        verticalLayout_13->addLayout(horizontalLayout_15);

        apply_double = new QPushButton(page_2);
        apply_double->setObjectName("apply_double");
        apply_double->setMaximumSize(QSize(200, 16777215));

        verticalLayout_13->addWidget(apply_double);

        toolBox->addItem(page_2, QString::fromUtf8("Doube threshold"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 201, 124));
        verticalLayout_14 = new QVBoxLayout(page_3);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName("verticalLayout_14");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");

        horizontalLayout_13->addWidget(label_9);

        regionSize_ = new QLineEdit(page_3);
        regionSize_->setObjectName("regionSize_");

        horizontalLayout_13->addWidget(regionSize_);


        verticalLayout_14->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");

        horizontalLayout_12->addWidget(label_6);

        threshold_ = new QLineEdit(page_3);
        threshold_->setObjectName("threshold_");

        horizontalLayout_12->addWidget(threshold_);


        verticalLayout_14->addLayout(horizontalLayout_12);

        apply_var = new QPushButton(page_3);
        apply_var->setObjectName("apply_var");
        apply_var->setMaximumSize(QSize(200, 16777215));

        verticalLayout_14->addWidget(apply_var);

        toolBox->addItem(page_3, QString::fromUtf8("Variance threshold"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        page_4->setGeometry(QRect(0, 0, 115, 52));
        verticalLayout_15 = new QVBoxLayout(page_4);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName("verticalLayout_15");
        multi_threshold = new QPushButton(page_4);
        multi_threshold->setObjectName("multi_threshold");
        multi_threshold->setMaximumSize(QSize(200, 16777215));

        verticalLayout_15->addWidget(multi_threshold);

        toolBox->addItem(page_4, QString::fromUtf8("Multi level threshold"));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        page_5->setGeometry(QRect(0, 0, 209, 88));
        verticalLayout_16 = new QVBoxLayout(page_5);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName("verticalLayout_16");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_16 = new QLabel(page_5);
        label_16->setObjectName("label_16");
        label_16->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(label_16);

        region_size_line = new QLineEdit(page_5);
        region_size_line->setObjectName("region_size_line");
        region_size_line->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_10->addWidget(region_size_line);


        verticalLayout_16->addLayout(horizontalLayout_10);

        app_ll_btn = new QPushButton(page_5);
        app_ll_btn->setObjectName("app_ll_btn");
        app_ll_btn->setMaximumSize(QSize(200, 16777215));

        verticalLayout_16->addWidget(app_ll_btn);

        toolBox->addItem(page_5, QString::fromUtf8("Region spectral threshold"));
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        page_6->setGeometry(QRect(0, 0, 115, 52));
        verticalLayout_6 = new QVBoxLayout(page_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName("verticalLayout_6");
        otsu_btn = new QPushButton(page_6);
        otsu_btn->setObjectName("otsu_btn");
        otsu_btn->setMaximumSize(QSize(200, 16777215));

        verticalLayout_6->addWidget(otsu_btn);

        toolBox->addItem(page_6, QString::fromUtf8("Otsu threshold"));
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        page_7->setGeometry(QRect(0, 0, 115, 52));
        verticalLayout_8 = new QVBoxLayout(page_7);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName("verticalLayout_8");
        optimal_btn = new QPushButton(page_7);
        optimal_btn->setObjectName("optimal_btn");
        optimal_btn->setMaximumSize(QSize(200, 16777215));

        verticalLayout_8->addWidget(optimal_btn);

        toolBox->addItem(page_7, QString::fromUtf8("Optimal threshod"));
        page_11 = new QWidget();
        page_11->setObjectName("page_11");
        page_11->setGeometry(QRect(0, 0, 193, 88));
        verticalLayout_19 = new QVBoxLayout(page_11);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName("verticalLayout_19");
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName("horizontalLayout_33");
        label_27 = new QLabel(page_11);
        label_27->setObjectName("label_27");

        horizontalLayout_33->addWidget(label_27);

        threshold_global = new QLineEdit(page_11);
        threshold_global->setObjectName("threshold_global");

        horizontalLayout_33->addWidget(threshold_global);


        verticalLayout_19->addLayout(horizontalLayout_33);

        apply_global = new QPushButton(page_11);
        apply_global->setObjectName("apply_global");

        verticalLayout_19->addWidget(apply_global);

        toolBox->addItem(page_11, QString::fromUtf8("Global threshold"));
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        page_8->setGeometry(QRect(0, 0, 193, 88));
        verticalLayout_12 = new QVBoxLayout(page_8);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName("verticalLayout_12");
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_7 = new QLabel(page_8);
        label_7->setObjectName("label_7");

        horizontalLayout_19->addWidget(label_7);

        threshold_gau = new QLineEdit(page_8);
        threshold_gau->setObjectName("threshold_gau");

        horizontalLayout_19->addWidget(threshold_gau);


        verticalLayout_12->addLayout(horizontalLayout_19);

        Gussian_btn = new QPushButton(page_8);
        Gussian_btn->setObjectName("Gussian_btn");

        verticalLayout_12->addWidget(Gussian_btn);

        toolBox->addItem(page_8, QString::fromUtf8("Local gaussian threshold"));
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        page_9->setGeometry(QRect(0, 0, 204, 88));
        verticalLayout_17 = new QVBoxLayout(page_9);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName("verticalLayout_17");
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_8 = new QLabel(page_9);
        label_8->setObjectName("label_8");

        horizontalLayout_20->addWidget(label_8);

        kernal_mean = new QLineEdit(page_9);
        kernal_mean->setObjectName("kernal_mean");

        horizontalLayout_20->addWidget(kernal_mean);


        verticalLayout_17->addLayout(horizontalLayout_20);

        Local_Mean_btn = new QPushButton(page_9);
        Local_Mean_btn->setObjectName("Local_Mean_btn");

        verticalLayout_17->addWidget(Local_Mean_btn);

        toolBox->addItem(page_9, QString::fromUtf8("Local mean threshold"));
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        page_10->setGeometry(QRect(0, 0, 219, 88));
        verticalLayout_18 = new QVBoxLayout(page_10);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName("verticalLayout_18");
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_10 = new QLabel(page_10);
        label_10->setObjectName("label_10");

        horizontalLayout_21->addWidget(label_10);

        padding = new QLineEdit(page_10);
        padding->setObjectName("padding");

        horizontalLayout_21->addWidget(padding);


        verticalLayout_18->addLayout(horizontalLayout_21);

        Padding_btn = new QPushButton(page_10);
        Padding_btn->setObjectName("Padding_btn");

        verticalLayout_18->addWidget(Padding_btn);

        toolBox->addItem(page_10, QString::fromUtf8("Adaptive Padding Function"));

        verticalLayout_7->addWidget(toolBox);


        verticalLayout_5->addWidget(frame_2);


        horizontalLayout_9->addLayout(verticalLayout_5);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName("verticalLayout_23");
        input_threshold = new QLabel(tab_3);
        input_threshold->setObjectName("input_threshold");

        verticalLayout_23->addWidget(input_threshold);

        output_threshold = new QLabel(tab_3);
        output_threshold->setObjectName("output_threshold");

        verticalLayout_23->addWidget(output_threshold);


        horizontalLayout_9->addLayout(verticalLayout_23);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        verticalLayout_32 = new QVBoxLayout(tab_4);
        verticalLayout_32->setSpacing(6);
        verticalLayout_32->setContentsMargins(11, 11, 11, 11);
        verticalLayout_32->setObjectName("verticalLayout_32");
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName("horizontalLayout_36");
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_23 = new QLabel(tab_4);
        label_23->setObjectName("label_23");
        label_23->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_16->addWidget(label_23);

        agg_clusters = new QLineEdit(tab_4);
        agg_clusters->setObjectName("agg_clusters");
        agg_clusters->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_16->addWidget(agg_clusters);

        agg_apply = new QPushButton(tab_4);
        agg_apply->setObjectName("agg_apply");
        agg_apply->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_16->addWidget(agg_apply);


        horizontalLayout_36->addLayout(horizontalLayout_16);


        verticalLayout_32->addLayout(horizontalLayout_36);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName("horizontalLayout_35");
        agg_input = new QLabel(tab_4);
        agg_input->setObjectName("agg_input");

        horizontalLayout_35->addWidget(agg_input);

        agg_output = new QLabel(tab_4);
        agg_output->setObjectName("agg_output");

        horizontalLayout_35->addWidget(agg_output);


        verticalLayout_32->addLayout(horizontalLayout_35);

        tabWidget->addTab(tab_4, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        verticalLayout_10 = new QVBoxLayout(tab_9);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_52 = new QLabel(tab_9);
        label_52->setObjectName("label_52");
        sizePolicy.setHeightForWidth(label_52->sizePolicy().hasHeightForWidth());
        label_52->setSizePolicy(sizePolicy);
        label_52->setMinimumSize(QSize(79, 0));
        label_52->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_18->addWidget(label_52);

        reg_th = new QLineEdit(tab_9);
        reg_th->setObjectName("reg_th");

        horizontalLayout_18->addWidget(reg_th);

        label = new QLabel(tab_9);
        label->setObjectName("label");

        horizontalLayout_18->addWidget(label);

        Seedx = new QLineEdit(tab_9);
        Seedx->setObjectName("Seedx");

        horizontalLayout_18->addWidget(Seedx);

        label_2 = new QLabel(tab_9);
        label_2->setObjectName("label_2");

        horizontalLayout_18->addWidget(label_2);

        Seedy = new QLineEdit(tab_9);
        Seedy->setObjectName("Seedy");

        horizontalLayout_18->addWidget(Seedy);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_2);

        reg_apply = new QPushButton(tab_9);
        reg_apply->setObjectName("reg_apply");
        sizePolicy1.setHeightForWidth(reg_apply->sizePolicy().hasHeightForWidth());
        reg_apply->setSizePolicy(sizePolicy1);

        horizontalLayout_18->addWidget(reg_apply);


        verticalLayout_9->addLayout(horizontalLayout_18);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName("verticalLayout_11");
        reg_input = new QLabel(tab_9);
        reg_input->setObjectName("reg_input");

        verticalLayout_11->addWidget(reg_input);


        horizontalLayout_17->addLayout(verticalLayout_11);

        verticalLayout_47 = new QVBoxLayout();
        verticalLayout_47->setSpacing(6);
        verticalLayout_47->setObjectName("verticalLayout_47");
        output_seed = new QLabel(tab_9);
        output_seed->setObjectName("output_seed");

        verticalLayout_47->addWidget(output_seed);

        reg_gray_output = new QLabel(tab_9);
        reg_gray_output->setObjectName("reg_gray_output");

        verticalLayout_47->addWidget(reg_gray_output);


        horizontalLayout_17->addLayout(verticalLayout_47);


        verticalLayout_9->addLayout(horizontalLayout_17);

        verticalLayout_9->setStretch(1, 10);

        verticalLayout_10->addLayout(verticalLayout_9);

        tabWidget->addTab(tab_9, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        verticalLayout_20 = new QVBoxLayout(tab_5);
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName("verticalLayout_20");
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        rgb = new QLabel(tab_5);
        rgb->setObjectName("rgb");

        horizontalLayout_22->addWidget(rgb);

        gray = new QLabel(tab_5);
        gray->setObjectName("gray");

        horizontalLayout_22->addWidget(gray);

        luv = new QLabel(tab_5);
        luv->setObjectName("luv");

        horizontalLayout_22->addWidget(luv);


        verticalLayout_20->addLayout(horizontalLayout_22);

        tabWidget->addTab(tab_5, QString());

        verticalLayout->addWidget(tabWidget);

        task_4Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(task_4Class);
        mainToolBar->setObjectName("mainToolBar");
        task_4Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(task_4Class);
        statusBar->setObjectName("statusBar");
        task_4Class->setStatusBar(statusBar);

        retranslateUi(task_4Class);

        tabWidget->setCurrentIndex(5);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(task_4Class);
    } // setupUi

    void retranslateUi(QMainWindow *task_4Class)
    {
        task_4Class->setWindowTitle(QCoreApplication::translate("task_4Class", "task_4", nullptr));
        open_btn->setText(QCoreApplication::translate("task_4Class", "Open", nullptr));
        label_3->setText(QCoreApplication::translate("task_4Class", "No. of Clusters", nullptr));
        RGB->setText(QCoreApplication::translate("task_4Class", "RGB", nullptr));
        GRAY->setText(QCoreApplication::translate("task_4Class", "Gray Scale", nullptr));
        apply_K_Means_btn->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        k_means_input->setText(QString());
        k_means_output->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("task_4Class", "K_MEANS", nullptr));
        label_4->setText(QCoreApplication::translate("task_4Class", "Color Bandwidth", nullptr));
        label_5->setText(QCoreApplication::translate("task_4Class", "Distance Bandwidth", nullptr));
        apply_Means_shift_btn_2->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        means_shift_input_2->setText(QString());
        means_shift_output_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("task_4Class", "MEAN_SHIFT", nullptr));
        label_21->setText(QCoreApplication::translate("task_4Class", "Low threshold", nullptr));
        label_22->setText(QCoreApplication::translate("task_4Class", "High threshold", nullptr));
        apply_double->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("task_4Class", "Doube threshold", nullptr));
        label_9->setText(QCoreApplication::translate("task_4Class", "regionSize", nullptr));
        label_6->setText(QCoreApplication::translate("task_4Class", "threshold", nullptr));
        apply_var->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("task_4Class", "Variance threshold", nullptr));
        multi_threshold->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("task_4Class", "Multi level threshold", nullptr));
        label_16->setText(QCoreApplication::translate("task_4Class", "Region size", nullptr));
        app_ll_btn->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QCoreApplication::translate("task_4Class", "Region spectral threshold", nullptr));
        otsu_btn->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_6), QCoreApplication::translate("task_4Class", "Otsu threshold", nullptr));
        optimal_btn->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_7), QCoreApplication::translate("task_4Class", "Optimal threshod", nullptr));
        label_27->setText(QCoreApplication::translate("task_4Class", "threshold", nullptr));
        apply_global->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_11), QCoreApplication::translate("task_4Class", "Global threshold", nullptr));
        label_7->setText(QCoreApplication::translate("task_4Class", "threshold", nullptr));
        Gussian_btn->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_8), QCoreApplication::translate("task_4Class", "Local gaussian threshold", nullptr));
        label_8->setText(QCoreApplication::translate("task_4Class", "Kernal size", nullptr));
        Local_Mean_btn->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_9), QCoreApplication::translate("task_4Class", "Local mean threshold", nullptr));
        label_10->setText(QCoreApplication::translate("task_4Class", "Padding size", nullptr));
        Padding_btn->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_10), QCoreApplication::translate("task_4Class", "Adaptive Padding Function", nullptr));
        input_threshold->setText(QString());
        output_threshold->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("task_4Class", "Thresholding", nullptr));
        label_23->setText(QCoreApplication::translate("task_4Class", "Clusters", nullptr));
        agg_apply->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        agg_input->setText(QString());
        agg_output->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("task_4Class", "Agglomerative", nullptr));
        label_52->setText(QCoreApplication::translate("task_4Class", "Threshold", nullptr));
        label->setText(QCoreApplication::translate("task_4Class", "Seed_X", nullptr));
        label_2->setText(QCoreApplication::translate("task_4Class", "Seed_Y", nullptr));
        reg_apply->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        reg_input->setText(QString());
        output_seed->setText(QString());
        reg_gray_output->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("task_4Class", "Region growing", nullptr));
        rgb->setText(QString());
        gray->setText(QString());
        luv->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("task_4Class", "Color Modes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task_4Class: public Ui_task_4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_4_H
