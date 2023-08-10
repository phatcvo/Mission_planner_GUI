//
// Created by rml-phat on 2/10/22.
//

#ifndef RRTSTAR_CFS_DUBINS_MAINWINDOW_H
#define RRTSTAR_CFS_DUBINS_MAINWINDOW_H


#include <QMainWindow>
#include "renderarea.h"
#include "rrtstar.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    RRTSTAR *rrtstar;
    bool simulated;
private slots:
    void on_startButton_clicked();
    void on_resetButton_clicked();
};


#endif //RRTSTAR_CFS_DUBINS_MAINWINDOW_H
