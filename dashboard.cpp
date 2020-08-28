#include "mainwindow.h"
#include<QDebug>
#include "package.h"

void MainWindow::dashboard(){
    Action();
    MenuItem();
    setWindowTitle("Dashboard");
    style();

    QVBoxLayout  *layout = new QVBoxLayout();
    QLabel *title = new QLabel("Welcome to Ocean View");
    QFont banner("Helvetica",30,QFont::Bold);
    title->setFont(banner);
    title->setAlignment(Qt::AlignHCenter);
    title->setFixedHeight(70);

    QWidget *image = new QWidget();
    image->setStyleSheet("*{border-image: url('/home/aadarsha/Documents/hotel.jpg') 0 0 0 0 stretch stretch;}");
    layout->addWidget(title);
    layout->addWidget(image);
    rightside->setLayout(layout);
    rightside->setStyleSheet("*{background:white;}");
}

//void MainWindow::PackageScreen(){
//    setWindowTitle("Packages");
//    style();
//    QVBoxLayout *layout = new QVBoxLayout();
////    Database database;
////    database.addPackages("Rafting","Ayush Soft","This is detail",4500,1);
////    Package pkgs[10];
////    database.getAvailablePackages(pkgs);
////    for(Package i : pkgs){
////     qDebug() << i.getName();
////    }

//    rightside->setStyleSheet("*{background:black;}");
//}

void MainWindow::Bill(){
    setWindowTitle("Billings");
    style();
    rightside->setStyleSheet("*{background:green;}");
}
void MainWindow::Customer(){
    setWindowTitle("Guests Records");
    style();
    QVBoxLayout *tablelayout = new QVBoxLayout();
    rightside->setLayout(tablelayout);
    rightside->setStyleSheet("*{background:white;}");
    tablelayout->addWidget(guesttable());
}


