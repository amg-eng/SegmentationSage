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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
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
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *task_4Class)
    {
        if (task_4Class->objectName().isEmpty())
            task_4Class->setObjectName("task_4Class");
        task_4Class->resize(1091, 847);
        centralWidget = new QWidget(task_4Class);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        open_btn = new QPushButton(centralWidget);
        open_btn->setObjectName("open_btn");

        horizontalLayout->addWidget(open_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(17);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(65, 0));
        label_3->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_3->addWidget(lineEdit_2);

        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_3->addWidget(lineEdit);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(tab);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(1, 15);

        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        task_4Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(task_4Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1091, 26));
        task_4Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(task_4Class);
        mainToolBar->setObjectName("mainToolBar");
        task_4Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(task_4Class);
        statusBar->setObjectName("statusBar");
        task_4Class->setStatusBar(statusBar);

        retranslateUi(task_4Class);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(task_4Class);
    } // setupUi

    void retranslateUi(QMainWindow *task_4Class)
    {
        task_4Class->setWindowTitle(QCoreApplication::translate("task_4Class", "task_4", nullptr));
        open_btn->setText(QCoreApplication::translate("task_4Class", "Open", nullptr));
        label_3->setText(QCoreApplication::translate("task_4Class", "Max Iterations", nullptr));
        label_4->setText(QCoreApplication::translate("task_4Class", "No. of Clusters", nullptr));
        pushButton_2->setText(QCoreApplication::translate("task_4Class", "Apply", nullptr));
        label_2->setText(QCoreApplication::translate("task_4Class", "Input Img", nullptr));
        label->setText(QCoreApplication::translate("task_4Class", "Output img", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("task_4Class", "K_MEANS", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("task_4Class", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task_4Class: public Ui_task_4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_4_H
