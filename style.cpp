#include "mainwindow.h"

void MainWindow::style(){
   /* QString StyleSheetBtns =   "QPushButton { color: black; background-color: #778899; border: none; font: 19pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #2ECCFA; border-style: solid; border-width: 3px; border-color: #58D3F7; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";
// yei style rakham.. hover ani clicked ma different cha

    QString StyleSheetBtn ="*{background:red;height:30px;}";
//yo timle banako wala try gari hera yo ramro dekhena;

    QWidget *dashboard = new QWidget;
    setCentralWidget(dashboard);

    QWidget *leftside = new QWidget;
    leftside->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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

    DosthotelBtn->setFixedHeight(50);
    roomBtn->setFixedHeight(50);
    PackageBtn->setFixedHeight(50);
    billBtn->setFixedHeight(50);
    customerBtn->setFixedHeight(50);
    exitBtn->setFixedHeight(50);
    statusBtn->setFixedHeight(50);


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
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(close())); //Exits the App
    connect(statusBtn,SIGNAL(clicked()),this,SLOT(close())); //Exits the App

    QVBoxLayout *btnLayout = new QVBoxLayout;

    btnLayout->addWidget(DosthotelBtn);
    btnLayout->addWidget(roomBtn);
    btnLayout->addWidget(PackageBtn);
    btnLayout->addWidget(billBtn);
    btnLayout->addWidget(customerBtn);
    btnLayout->addWidget(statusBtn);

    leftside->setLayout(btnLayout);


    QHBoxLayout *layout =new QHBoxLayout;
    layout->setMargin(3);
    layout->addWidget(leftside);
    dashboard->setLayout(layout);*/


    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    infoLabel = new QLabel();
    infoLabel -> setAlignment(Qt::AlignCenter);


    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(infoLabel);
    widget->setLayout(layout);
}
