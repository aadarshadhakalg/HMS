#include "mainwindow.h"
void MainWindow::Roommain(){
    setWindowTitle("Room");
    style();

    QLabel *label = new QLabel();
    label->setText("Common");
    QFont banner("Helvetica",20,QFont::Bold);
    label->setFont(banner);
    label->setFixedHeight(90);

    QLabel *label2 = new QLabel();
    label2->setText("Delux");
    label2->setFont(banner);
    label2->setFixedHeight(90);

    rightside->setStyleSheet("*{background:white"
                             ";}");
    QString StyleSheetBtns =   "QPushButton { color: white; background-color: #1c2c3c; border: solid 5px white; font: 16pt 'Microsoft YaHei UI Light'; font-weight:bold; outline: none; } QPushButton:hover { background-color: #dc2525; border-style: solid; border-width: 3px; border-color: white; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";

    QPushButton* roomBtn = new QPushButton("Rooms");
    QPushButton* PackageBtn = new QPushButton("Packages");
    QPushButton* billBtn = new QPushButton("Billings");
    QPushButton* customerBtn = new QPushButton("Records");
    QPushButton* billBtn1 = new QPushButton("Billings");
    QPushButton* billBtn2 = new QPushButton("Billings");
    QPushButton* billBtn3 = new QPushButton("Billings");
    QPushButton* billBtn4 = new QPushButton("Billings");

    roomBtn->setStyleSheet(StyleSheetBtns);
    PackageBtn->setStyleSheet(StyleSheetBtns);
    billBtn->setStyleSheet(StyleSheetBtns);
    customerBtn->setStyleSheet(StyleSheetBtns);
    billBtn1->setStyleSheet(StyleSheetBtns);
    billBtn2->setStyleSheet(StyleSheetBtns);
    billBtn3->setStyleSheet(StyleSheetBtns);
    billBtn4->setStyleSheet(StyleSheetBtns);


    roomBtn->setFixedSize(200,120);
    PackageBtn->setFixedSize(200,120);
    billBtn->setFixedSize(200,120);
    customerBtn->setFixedSize(200,120);
    billBtn1->setFixedSize(200,120);
    billBtn2->setFixedSize(200,120);
    billBtn3->setFixedSize(200,120);
    billBtn4->setFixedSize(200,120);


    connect(roomBtn,SIGNAL(clicked()), this, SLOT(Room()));
    connect(PackageBtn,SIGNAL(clicked()), this, SLOT(Package()));
    connect(billBtn,SIGNAL(clicked()), this, SLOT(Bill()));
    connect(customerBtn,SIGNAL(clicked()), this, SLOT(Customer()));

    QGridLayout *roomtype= new QGridLayout;
    roomtype-> setHorizontalSpacing(30);
     roomtype-> addWidget(label,0,0,1,4);

    roomtype-> addWidget(roomBtn,1,0,1,1);
    roomtype-> addWidget(PackageBtn,1,1,1,1);
    roomtype-> addWidget(billBtn1,1,2,1,1);
    roomtype-> addWidget(billBtn2,1,3,1,1);



    roomtype-> addWidget(label2);

    roomtype-> addWidget(billBtn,3,0,1,1);
    roomtype-> addWidget(customerBtn,3,1,1,1);
    roomtype-> addWidget(billBtn3,3,2,1,1);
    roomtype-> addWidget(billBtn4,3,3,1,1);




    rightside->setLayout(roomtype);


}
