#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setStyle("plastique");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.resize(800,600);
    return a.exec();
}
