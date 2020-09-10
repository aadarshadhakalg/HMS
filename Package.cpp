#include"mainwindow.h"

void MainWindow::PackageScreen(){
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
    QFont banner1("Helvetica",20,QFont::Bold);
    label1->setFont(banner1);
    label1->setFixedHeight(90);
    label1->adjustSize();
    label1 -> setAlignment(Qt::AlignCenter);


    QLabel *label2 = new QLabel();
    label2->setText("Not Available");
    label2->setFont(banner1);
    label2->setFixedHeight(90);
    label2->adjustSize();
    label2 -> setAlignment(Qt::AlignCenter);



    QPushButton* addPackage = new QPushButton("Add Package");
    QPushButton* removePackage = new QPushButton("Remove Package");



    addPackage->setStyleSheet(StyleSheetBtns);
   removePackage->setStyleSheet(StyleSheetBtns);

    addPackage->setFixedSize(300,60);
    removePackage->setFixedSize(300,60);

    addPackage->adjustSize();
    removePackage->adjustSize();



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
    HLayout->addWidget(label1);
    HLayout->addWidget(label2);


       QSqlTableModel * amodel = new QSqlTableModel();
        amodel->setTable("packages");
        amodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        amodel->setParent(this);
        amodel->select();
        amodel->setHeaderData(0, Qt::Horizontal, tr("ID"));
        amodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
        amodel->setHeaderData(2, Qt::Horizontal, tr("Company"));
        amodel->setHeaderData(3, Qt::Horizontal, tr("Details"));
        amodel->setHeaderData(4, Qt::Horizontal, tr("Price"));
        amodel->setFilter("available = 1");
        QTableView *availableview = new QTableView();
        availableview->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        availableview->setModel(amodel);
        availableview->hideColumn(0);
        availableview->hideColumn(5);
        availableview->setColumnWidth(3,200);



        QSqlTableModel * nmodel = new QSqlTableModel();
         nmodel->setTable("packages");
         nmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
         nmodel->setParent(this);
         nmodel->select();
         nmodel->setHeaderData(0, Qt::Horizontal, tr("ID"));
         nmodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
         nmodel->setHeaderData(2, Qt::Horizontal, tr("Company"));
         nmodel->setHeaderData(3, Qt::Horizontal, tr("Details"));
         nmodel->setHeaderData(4, Qt::Horizontal, tr("Price"));
         nmodel->setFilter("available = 0");
         QTableView *notavailableview = new QTableView();
         notavailableview->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
         notavailableview->setModel(nmodel);
         notavailableview->hideColumn(0);
         notavailableview->hideColumn(5);
         notavailableview->setColumnWidth(3,200);

         QHBoxLayout *HLayout2 = new QHBoxLayout();
         HLayout2->addWidget(availableview);
         HLayout2->addWidget(notavailableview);

    QVBoxLayout *Vlayout= new QVBoxLayout();
    Vlayout->addLayout(HLayout1);
    Vlayout->addLayout(HLayout);
    Vlayout->addLayout(HLayout2);


    rightside->setLayout(Vlayout);
}
