#include "mainwindow.h"
void MainWindow::Room(){
    setWindowTitle("Room");
    style();

    rightside->setStyleSheet("*{background:white"
                             ";}");
    QString StyleSheetBtns =   "QPushButton { color: white; background-color: #1c2c3c; border: solid 5px white; font: 16pt 'Microsoft YaHei UI Light'; font-weight:bold; outline: none; } QPushButton:hover { background-color: #dc2525; border-style: solid; border-width: 3px; border-color: white; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";

    QPushButton* roomBtn = new QPushButton("Rooms");
    QPushButton* PackageBtn = new QPushButton("Packages");
    QPushButton* billBtn = new QPushButton("Billings");
    QPushButton* customerBtn = new QPushButton("Records");
    QPushButton* exitBtn = new QPushButton("Exit");

    roomBtn->setStyleSheet(StyleSheetBtns);
    PackageBtn->setStyleSheet(StyleSheetBtns);
    billBtn->setStyleSheet(StyleSheetBtns);
    customerBtn->setStyleSheet(StyleSheetBtns);


    roomBtn->setFixedSize(100,120);
    PackageBtn->setFixedSize(100,120);
    billBtn->setFixedSize(100,120);
    customerBtn->setFixedSize(100,120);

    connect(roomBtn,SIGNAL(clicked()), this, SLOT(Room()));
    connect(PackageBtn,SIGNAL(clicked()), this, SLOT(Package()));
    connect(billBtn,SIGNAL(clicked()), this, SLOT(Bill()));
    connect(customerBtn,SIGNAL(clicked()), this, SLOT(Customer()));

    QGridLayout *roomtype= new QGridLayout;
    roomtype-> setHorizontalSpacing(30);
    roomtype-> setVerticalSpacing(3);
    roomtype-> addWidget(roomBtn,0,0,1,1);
    roomtype-> addWidget(PackageBtn,0,1,1,1);
    roomtype-> addWidget(billBtn,1,0,1,1);
    roomtype-> addWidget(customerBtn,1,1,1,1);




    rightside->setLayout(roomtype);


}
