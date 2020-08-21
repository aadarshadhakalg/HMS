#include"mainwindow.h"
void MainWindow::Package(){
    setWindowTitle("Packages");
    style();
    //rightside->setStyleSheet("*{background:green;}");


    QString StyleSheetBtns =   "QPushButton { color: white; background-color: #1c2c3c; border: solid 5px white; font: 16pt 'Microsoft YaHei UI Light'; font-weight:bold; outline: none; } QPushButton:hover { background-color: #dc2525; border-style: solid; border-width: 3px; border-color: white; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";



    QLabel *label = new QLabel();

    label->setText("Packages");
    QFont banner("Helvetica",40,QFont::Bold);
    label->setFont(banner);
    label->setFixedHeight(90);
    label -> setAlignment(Qt::AlignCenter);
    label->adjustSize();

    QLabel *label1 = new QLabel();
    label1->setText("Available");
    QFont banner1("Helvetica",30,QFont::Bold);
    label1->setFont(banner1);
    label1->setFixedHeight(90);
    label1->adjustSize();
    label1 -> setAlignment(Qt::AlignCenter);


    QLabel *label2 = new QLabel();
    label2->setText("Not Available");
    //QFont banner1("Helvetica",15,QFont::Bold);
    label2->setFont(banner1);
    label2->setFixedHeight(90);
    label2->adjustSize();
    label2 -> setAlignment(Qt::AlignCenter);




    QPushButton* addPackage = new QPushButton("Add Package");
    QPushButton* removePackage = new QPushButton("Remove Package");
    QPushButton* availableBtn1 = new QPushButton("Package1");
    QPushButton* availableBtn2 = new QPushButton("Package2");
    QPushButton* availableBtn3 = new QPushButton("Package3");
    QPushButton* availableBtn4 = new QPushButton("Package4");
    QPushButton* notavailableBtn1 = new QPushButton("nopackage1");
    QPushButton* notavailableBtn2 = new QPushButton("nopackage2");
    QPushButton* notavailableBtn3 = new QPushButton("nopackage3");
    QPushButton* notavailableBtn4 = new QPushButton("nopackage4");

    addPackage->setStyleSheet(StyleSheetBtns);
   removePackage->setStyleSheet(StyleSheetBtns);
    availableBtn1->setStyleSheet(StyleSheetBtns);
    availableBtn2->setStyleSheet(StyleSheetBtns);
    availableBtn3->setStyleSheet(StyleSheetBtns);
    availableBtn4->setStyleSheet(StyleSheetBtns);
    notavailableBtn1->setStyleSheet(StyleSheetBtns);
    notavailableBtn2->setStyleSheet(StyleSheetBtns);
    notavailableBtn3->setStyleSheet(StyleSheetBtns);
    notavailableBtn4->setStyleSheet(StyleSheetBtns);

    addPackage->setFixedSize(300,60);
    removePackage->setFixedSize(300,60);
    availableBtn1->setFixedSize(300,60);
    availableBtn2->setFixedSize(300,60);
    availableBtn3->setFixedSize(300,60);
    availableBtn4->setFixedSize(300,60);
    notavailableBtn1->setFixedSize(300,60);
    notavailableBtn2->setFixedSize(300,60);
    notavailableBtn3->setFixedSize(300,60);
    notavailableBtn4->setFixedSize(300,60);

    addPackage->adjustSize();
    removePackage->adjustSize();
    availableBtn1->adjustSize();
    availableBtn2->adjustSize();
    availableBtn3->adjustSize();
    availableBtn4->adjustSize();
    notavailableBtn1->adjustSize();
    notavailableBtn2->adjustSize();
    notavailableBtn3->adjustSize();
    notavailableBtn4->adjustSize();



    /*QHBoxLayout *HLayout = new QHBoxLayout();
       HLayout->addWidget(label1);
       HLayout->addWidget(label2);

     QHBoxLayout *HLayout1 = new QHBoxLayout();
     HLayout->addWidget(availableBtn1);
     HLayout->addWidget(notavailableBtn1);

     QHBoxLayout *HLayout2 =new QHBoxLayout();
     HLayout->addWidget(availableBtn2);
     HLayout->addWidget(notavailableBtn2);

     QHBoxLayout *HLayout3 = new QHBoxLayout();
     HLayout->addWidget(availableBtn3);
     HLayout->addWidget(notavailableBtn3);

     QHBoxLayout *HLayout4 = new QHBoxLayout();
     HLayout->addWidget(availableBtn4);
     HLayout->addWidget(notavailableBtn4);



       QVBoxLayout *mainLayout = new QVBoxLayout();

       mainLayout->addWidget(label);
       mainLayout->addLayout(HLayout);
       mainLayout->addWidget(label2);
       mainLayout->addLayout(HLayout1);
       mainLayout->addLayout(HLayout2);
       mainLayout->addLayout(HLayout3);
       mainLayout->addLayout(HLayout4);

*/
    QHBoxLayout *HLayout1 = new QHBoxLayout();
    HLayout1->addWidget(addPackage);
    HLayout1->addWidget(label);
    HLayout1->addWidget(removePackage);

    QHBoxLayout *HLayout = new QHBoxLayout();
    //HLayout->addWidget(nolabel);
    HLayout->addWidget(label1);

    HLayout->addWidget(label2);

    QVBoxLayout *Vlayout1 = new QVBoxLayout();
    Vlayout1->addWidget(availableBtn1);
    Vlayout1->addWidget(availableBtn2);
    Vlayout1->addWidget(availableBtn3);
    Vlayout1->addWidget(availableBtn4);

    QVBoxLayout *Vlayout2 = new QVBoxLayout();
    Vlayout2->addWidget(notavailableBtn1);
    Vlayout2->addWidget(notavailableBtn2);
    Vlayout2->addWidget(notavailableBtn3);
    Vlayout2->addWidget(notavailableBtn4);

    QHBoxLayout *HLayout2 = new QHBoxLayout();
    HLayout2->addLayout(Vlayout1);
  //  HLayout2->addWidget(nolabel);
    HLayout2->addLayout(Vlayout2);

    QVBoxLayout *Vlayout= new QVBoxLayout();
    Vlayout->addLayout(HLayout1);
    Vlayout->addLayout(HLayout);
    Vlayout->addLayout(HLayout2);





    rightside->setLayout(Vlayout);
}
