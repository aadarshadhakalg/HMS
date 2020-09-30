#include "mainwindow.h"

void MainWindow::style(){

    QWidget *dashboard = new QWidget; // parent widget
    setCentralWidget(dashboard);
    QString StyleSheetBtns =   "QPushButton { color: white; background-color: #24510c; border: solid 5px white; font: 16pt 'Microsoft YaHei UI Light'; font-weight:bold; outline: none; } QPushButton:hover { background-color: #dc2525; border-style: solid; border-width: 3px; border-color: white; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";

    QWidget *leftside = new QWidget;  // left column of window
    leftside->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    leftside-> setMaximumWidth(300);
    leftside->setStyleSheet("*{background:#24510c;}");

    QPushButton* roomBtn = new QPushButton("Rooms");
    QPushButton* PackageBtn = new QPushButton("Packages");
    QPushButton* billBtn = new QPushButton("Billings");
    QPushButton* customerBtn = new QPushButton("Records");
    QPushButton* exitBtn = new QPushButton("Exit");

    QPixmap logo = QPixmap(":/Resources/logo.png");
    QLabel *logoLabel = new QLabel();
    logoLabel->setPixmap(logo);
    logoLabel->setScaledContents(true);
    logoLabel->setFixedHeight(200);

    roomBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    PackageBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    billBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    customerBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    exitBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    roomBtn->setStyleSheet(StyleSheetBtns);
    PackageBtn->setStyleSheet(StyleSheetBtns);
    billBtn->setStyleSheet(StyleSheetBtns);
    customerBtn->setStyleSheet(StyleSheetBtns);
    exitBtn->setStyleSheet("*{background:white;}");


    connect(roomBtn,SIGNAL(clicked()), this, SLOT(Roommain()));
    connect(PackageBtn,SIGNAL(clicked()), this, SLOT(PackageScreen()));
    connect(billBtn,SIGNAL(clicked()), this, SLOT(Bill()));
    connect(customerBtn,SIGNAL(clicked()), this, SLOT(Customer()));
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(close()));

    QVBoxLayout *btnLayout = new QVBoxLayout;

    btnLayout->addWidget(logoLabel);
    btnLayout->addWidget(roomBtn);
    btnLayout->addWidget(PackageBtn);
    btnLayout->addWidget(billBtn);
    btnLayout->addWidget(customerBtn);

    btnLayout->addWidget(exitBtn);
    leftside->setLayout(btnLayout);


    QHBoxLayout *layout =new QHBoxLayout;
    layout->setMargin(1);
    layout->addWidget(leftside);

    rightside = new QWidget();
   layout->addWidget(rightside);
   dashboard->setStyleSheet("*{backgtound-color:white;}");
   dashboard->setLayout(layout);


}
