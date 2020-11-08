#include "mainwindow.h"
#include<QDebug>
#include "package.h"

void MainWindow::dashboard(){
    Action();
    MenuItem();
    setWindowTitle("Dashboard");
    style();

    QVBoxLayout  *layout = new QVBoxLayout();
//    QLabel *title = new QLabel("Sano Hotel Administration");
//    QFont banner("Helvetica",30,QFont::Bold);
//    title->setFont(banner);
//    title->setAlignment(Qt::AlignHCenter);
//    title->setFixedHeight(70);

    QWidget *image = new QWidget();
    image->setStyleSheet("*{border-image: url(':/Resources/hotel.jpg') 0 0 0 0 stretch stretch;}");
//    layout->addWidget(title);
    layout->addWidget(image);
    rightside->setLayout(layout);
    rightside->setStyleSheet("*{background:white;}");
}



void MainWindow::Customer(){
    setWindowTitle("Guests Records");
    style();
    QVBoxLayout *tablelayout = new QVBoxLayout();
    rightside->setLayout(tablelayout);
    rightside->setStyleSheet("*{background:white;}");
    tablelayout->addWidget(guesttable());
}


