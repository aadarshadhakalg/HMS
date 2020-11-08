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
    label2->setText("Deluxe");
    label2->setFont(banner);
    label2->setFixedHeight(90);

    rightside->setStyleSheet("*{background:white"
                             ";}");
    QString StyleSheetBtns = "QPushButton { color: white; background-color: #24510c; border: solid 5px white; font: 16pt 'Microsoft YaHei UI Light'; font-weight:bold; outline: none; } QPushButton:hover { background-color: #dc2525; border-style: solid; border-width: 3px; border-color: white; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";

    QPushButton* room1Btn = new QPushButton("Room 1");
    QPushButton* room2Btn = new QPushButton("Room 2");
    QPushButton* room3Btn = new QPushButton("Room 3");
    QPushButton* room4Btn = new QPushButton("Room 4");
    QPushButton* room5Btn = new QPushButton("Room 5");
    QPushButton* room6Btn = new QPushButton("Room 6");
    QPushButton* room7Btn = new QPushButton("Room 7");
    QPushButton* room8Btn = new QPushButton("Room 8");

    //Book now Button
    QPushButton *bookbtn = new QPushButton("Book");
    bookbtn->setStyleSheet("*{background:red;height:30px;}");

    room1Btn->setStyleSheet(StyleSheetBtns);
    room2Btn->setStyleSheet(StyleSheetBtns);
    room3Btn->setStyleSheet(StyleSheetBtns);
    room4Btn->setStyleSheet(StyleSheetBtns);
    room5Btn->setStyleSheet(StyleSheetBtns);
    room6Btn->setStyleSheet(StyleSheetBtns);
    room7Btn->setStyleSheet(StyleSheetBtns);
    room8Btn->setStyleSheet(StyleSheetBtns);


    room1Btn->setFixedSize(200,120);
    room2Btn->setFixedSize(200,120);
    room3Btn->setFixedSize(200,120);
    room4Btn->setFixedSize(200,120);
    room5Btn->setFixedSize(200,120);
    room6Btn->setFixedSize(200,120);
    room7Btn->setFixedSize(200,120);
    room8Btn->setFixedSize(200,120);

    connect(room1Btn,SIGNAL(clicked()), this, SLOT(room1()));
    connect(room2Btn,SIGNAL(clicked()), this, SLOT(room2()));
    connect(room3Btn,SIGNAL(clicked()), this, SLOT(room3()));
    connect(room4Btn,SIGNAL(clicked()), this, SLOT(room4()));
    connect(room5Btn,SIGNAL(clicked()), this, SLOT(room5()));
    connect(room6Btn,SIGNAL(clicked()), this, SLOT(room6()));
    connect(room7Btn,SIGNAL(clicked()), this, SLOT(room7()));
    connect(room8Btn,SIGNAL(clicked()), this, SLOT(room8()));

    connect(room1Btn,SIGNAL(clicked()), this, SLOT(room_details()));
    connect(room2Btn,SIGNAL(clicked()), this, SLOT(room_details()));
    connect(room3Btn,SIGNAL(clicked()), this, SLOT(room_details()));
    connect(room4Btn,SIGNAL(clicked()), this, SLOT(room_details()));
    connect(room5Btn,SIGNAL(clicked()), this, SLOT(room_details()));
    connect(room6Btn,SIGNAL(clicked()), this, SLOT(room_details()));
    connect(room7Btn,SIGNAL(clicked()), this, SLOT(room_details()));
    connect(room8Btn,SIGNAL(clicked()), this, SLOT(room_details()));
    connect(bookbtn,SIGNAL(clicked()), this, SLOT(roombooking()));

    QGridLayout *roomtype= new QGridLayout;
    roomtype-> setHorizontalSpacing(30);
    roomtype-> addWidget(label,0,0,1,4);

    roomtype-> addWidget(room1Btn,1,0,1,1);
    roomtype-> addWidget(room2Btn,1,1,1,1);
    roomtype-> addWidget(room3Btn,1,2,1,1);
    roomtype-> addWidget(room4Btn,1,3,1,1);

    roomtype-> addWidget(label2);

    roomtype-> addWidget(room5Btn,3,0,1,1);
    roomtype-> addWidget(room6Btn,3,1,1,1);
    roomtype-> addWidget(room7Btn,3,2,1,1);
    roomtype-> addWidget(room8Btn,3,3,1,1);
    roomtype-> addWidget(bookbtn,4,3,1,1);

    rightside->setLayout(roomtype);


}
