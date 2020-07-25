#include "mainwindow.h"

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

void MainWindow::Package(){
    setWindowTitle("Packages");
    style();
    rightside->setStyleSheet("*{background:black;}");
}
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

void MainWindow::Room(){
    setWindowTitle("Rooms");
    style();
    rightside->setStyleSheet("*{background:blue;}");
}
