#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
   QPushButton button("Draw obstacles by clicking \n and dragging on the field!", nullptr);
   button.resize(200, 100);
   button.show();
    MainWindow w;
    w.show();

    return a.exec();
}
