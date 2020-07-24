#include "mainwindow.h"
void MainWindow::Room(){


    Action();
    MenuItem();
    //dashboard();

    QWidget *room = new QWidget;
    setCentralWidget(room);


    QString StyleSheetBtns ="QPushButton { color: black; background-color: #778899; border: none; font: 19pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #2ECCFA; border-style: solid; border-width: 3px; border-color: #58D3F7; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";

    QWidget *rightside=new QWidget;
    rightside->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);




    infoLabel = new QLabel();
    infoLabel -> setAlignment(Qt::AlignCenter);
    infoLabel->setText("give package if can");
    QFont banner("Helvetica",30,QFont::Bold);
    infoLabel->setFont(banner);


    QPushButton* DosthotelBtn = new QPushButton("Sushantdost hotel");
    QPushButton* roomBtn = new QPushButton("room");
    QPushButton* PackageBtn = new QPushButton("Package");
    QPushButton* billBtn = new QPushButton("bill");
    QPushButton* customerBtn = new QPushButton("customer info");
    QPushButton* exitBtn = new QPushButton("exit");
    QPushButton* statusBtn = new QPushButton("status");

    DosthotelBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    roomBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    PackageBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    billBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    customerBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    exitBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    statusBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    DosthotelBtn->setFixedHeight(40);
    roomBtn->setFixedHeight(40);
    PackageBtn->setFixedHeight(40);
    billBtn->setFixedHeight(40);
    customerBtn->setFixedHeight(40);
    exitBtn->setFixedHeight(40);
    statusBtn->setFixedHeight(40);


    DosthotelBtn->setStyleSheet(StyleSheetBtns);
    roomBtn->setStyleSheet(StyleSheetBtns);
    PackageBtn->setStyleSheet(StyleSheetBtns);
    billBtn->setStyleSheet(StyleSheetBtns);
    customerBtn->setStyleSheet(StyleSheetBtns);
    exitBtn->setStyleSheet(StyleSheetBtns);
    statusBtn->setStyleSheet(StyleSheetBtns);


    connect(DosthotelBtn,SIGNAL(clicked()), this, SLOT(Hotel()));
    connect(roomBtn,SIGNAL(clicked()), this, SLOT(Room()));
    connect(PackageBtn,SIGNAL(clicked()), this, SLOT(Package()));
    connect(billBtn,SIGNAL(clicked()), this, SLOT(Bill()));
    connect(customerBtn,SIGNAL(clicked()), this, SLOT(Customer()));
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(statusBtn,SIGNAL(clicked()),this,SLOT(Status()));

    QGridLayout *roomnumb= new QGridLayout;
    roomnumb->setMargin(2);
    roomnumb->addWidget(DosthotelBtn,0,0);
    roomnumb->addWidget(PackageBtn,0,1);
    roomnumb->addWidget(billBtn,1,0);

    rightside->setLayout(roomnumb);

   /* QVBoxLayout *leftlayout = new QVBoxLayout;
    leftlayout->addwidget(displaytxt);
    left layout->addwidget (imageLabel);
    leftfiller->setlayout(leftlayout);*/

    QHBoxLayout *rightlayout = new QHBoxLayout;
        rightlayout->addWidget(infoLabel);
        rightlayout->addWidget(rightside);
       room->setLayout(rightlayout);



     }
