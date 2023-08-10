//
// Created by rml-phat on 2/10/22.
//

#ifndef RRTSTAR_CFS_DUBINS_UI_MAINWINDOW_H
#define RRTSTAR_CFS_DUBINS_UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "renderarea.h"

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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));

        renderArea = new RenderArea(centralWidget);
        renderArea->setObjectName(QStringLiteral("renderArea"));
        renderArea->setGeometry(QRect(0, 0, 400, 397));

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(200, 400, 99, 57));

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(300, 400, 99, 57));

        stepSizeLabel = new QLabel(centralWidget);
        stepSizeLabel->setObjectName(QStringLiteral("stepSizeLabel"));
        stepSizeLabel->setGeometry(QRect(0, 400, 100, 17));
        stepSizeLabel->setAlignment(Qt::AlignCenter);

        stepSize = new QLineEdit(centralWidget);
        stepSize->setObjectName(QStringLiteral("stepSize"));
        stepSize->setGeometry(QRect(100, 400, 100, 27));
        stepSize->setAlignment(Qt::AlignCenter);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 430, 100, 17));
        label->setAlignment(Qt::AlignCenter);

        maxIterations = new QLineEdit(centralWidget);
        maxIterations->setObjectName(QStringLiteral("maxIterations"));
        maxIterations->setGeometry(QRect(100, 430, 100, 27));
        maxIterations->setAlignment(Qt::AlignCenter);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 460, 100, 17));
        label_2->setAlignment(Qt::AlignCenter);

        statusBox = new QTextBrowser(centralWidget);
        statusBox->setObjectName(QStringLiteral("statusBox"));
        statusBox->setGeometry(QRect(100, 460, 297, 27));

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(3, 490, 394, 87));
//        textBrowser->setAlignment(Qt::AlignCenter);

        MainWindow->setCentralWidget(centralWidget);
        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RRT*-CFS | Phat C. Vo in RML", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
//        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
//                                                                   "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
//                                                                   "p, li { white-space: pre-wrap; }\n"
//                                                                   "</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
//                                                                   "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Draw obstacles by clicking and dragging on the field.</p></body></html>", Q_NULLPTR));
//        textBrowser->setText(QApplication::translate("MainWindow", "Draw obstacles by clicking and dragging on the field.", Q_NULLPTR));
        stepSizeLabel->setText(QApplication::translate("MainWindow", "Step Size", Q_NULLPTR));
        stepSize->setText(QApplication::translate("MainWindow", "25", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Max Iterations", Q_NULLPTR));
        maxIterations->setText(QApplication::translate("MainWindow", "5000", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Status", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE


#endif //RRTSTAR_CFS_DUBINS_UI_MAINWINDOW_H
