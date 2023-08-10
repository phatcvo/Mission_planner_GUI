/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <renderarea.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    RenderArea *renderArea;
    QPushButton *startButton;
    QPushButton *resetButton;
    QTextBrowser *textBrowser;
    QLabel *stepSizeLabel;
    QLineEdit *stepSize;
    QLabel *label;
    QLineEdit *maxIterations;
    QLabel *label_2;
    QTextBrowser *statusBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        renderArea = new RenderArea(centralWidget);
        renderArea->setObjectName(QString::fromUtf8("renderArea"));
        renderArea->setGeometry(QRect(0, 0, 400, 400));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(400, 0, 99, 30));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(400, 30, 99, 27));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(400, 300, 100, 100));
        stepSizeLabel = new QLabel(centralWidget);
        stepSizeLabel->setObjectName(QString::fromUtf8("stepSizeLabel"));
        stepSizeLabel->setGeometry(QRect(400, 80, 100, 17));
        stepSizeLabel->setAlignment(Qt::AlignCenter);
        stepSize = new QLineEdit(centralWidget);
        stepSize->setObjectName(QString::fromUtf8("stepSize"));
        stepSize->setGeometry(QRect(400, 100, 100, 27));
        stepSize->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 140, 100, 17));
        label->setAlignment(Qt::AlignCenter);
        maxIterations = new QLineEdit(centralWidget);
        maxIterations->setObjectName(QString::fromUtf8("maxIterations"));
        maxIterations->setGeometry(QRect(400, 160, 100, 27));
        maxIterations->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(400, 200, 100, 17));
        label_2->setAlignment(Qt::AlignCenter);
        statusBox = new QTextBrowser(centralWidget);
        statusBox->setObjectName(QString::fromUtf8("statusBox"));
        statusBox->setGeometry(QRect(400, 219, 100, 81));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RRT Simulator", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Draw obstacles by clicking and dragging on the field.</p></body></html>", nullptr));
        stepSizeLabel->setText(QApplication::translate("MainWindow", "Step Size", nullptr));
        stepSize->setText(QApplication::translate("MainWindow", "3", nullptr));
        label->setText(QApplication::translate("MainWindow", "Max Iterations", nullptr));
        maxIterations->setText(QApplication::translate("MainWindow", "3000", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
