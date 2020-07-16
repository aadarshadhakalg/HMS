#include "mainwindow.h"

void MainWindow::dashboard(){

    Action();
    MenuItem();
    setWindowTitle("Dashboard");


    QString StyleSheetBtns =   "QPushButton { color: black; background-color: #778899; border: none; font: 19pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #2ECCFA; border-style: solid; border-width: 3px; border-color: #58D3F7; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";

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
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(statusBtn,SIGNAL(clicked()),this,SLOT(Status()));

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

    //layout->addWidget(rightside);



    QWidget *rightside = new QWidget;
    rightside->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QFont banner("Helvetica",30,QFont::Bold);


    QGroupBox *groupBox = new QGroupBox();
    groupBox->setTitle("Hotel Ko Basic photo haru");
    groupBox->setFont(banner);


    groupBox->setAlignment(Qt::AlignCenter);


    QVBoxLayout *btnLayout2 = new QVBoxLayout;
    btnLayout2->addWidget(groupBox);
   btnLayout2->addWidget(exitBtn);

    rightside->setLayout(btnLayout2);

   layout->addWidget(rightside);
   dashboard->setLayout(layout);

}
void MainWindow::Hotel(){
    style();
    infoLabel->setText(tr("Hotel ko bare"));
}

void MainWindow::Room(){
    style();
   infoLabel->setText("Open room option");
}
void MainWindow::Package(){
    style();
    infoLabel->setText("give package if can");
}
void MainWindow::Bill(){
    style();
    infoLabel->setText("Billing of customer");
}
void MainWindow::Customer(){
    style();
    infoLabel->setText("INformation");
}
void MainWindow::Status(){
    style();
    infoLabel->setText("active or not");
}

