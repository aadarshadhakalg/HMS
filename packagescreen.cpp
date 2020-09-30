#include"mainwindow.h"
#include <QProgressDialog>
#include <QDebug>
#include <QCheckBox>

void MainWindow::PackageScreen(){
    setWindowTitle("Packages");
    style();
    //rightside->setStyleSheet("*{background:green;}");


    QString StyleSheetBtns =   "QPushButton { color: white; background-color: #24510c; border: solid 5px white; font: 16pt 'Microsoft YaHei UI Light'; font-weight:bold; outline: none; } QPushButton:hover { background-color: #dc2525; border-style: solid; border-width: 3px; border-color: white; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";



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
//        availableview->hideColumn(0);
        availableview->hideColumn(5);
        availableview->setColumnWidth(3,170);



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
//         notavailableview->hideColumn(0);
         notavailableview->hideColumn(5);
         notavailableview->setColumnWidth(3,170);

         QHBoxLayout *HLayout2 = new QHBoxLayout();
         HLayout2->addWidget(availableview);
         HLayout2->addWidget(notavailableview);

    QVBoxLayout *Vlayout= new QVBoxLayout();
    Vlayout->addLayout(HLayout1);
    Vlayout->addLayout(HLayout);
    Vlayout->addLayout(HLayout2);


    rightside->setLayout(Vlayout);

    connect(addPackage,SIGNAL(clicked()), this, SLOT(addPackage()));
    connect(removePackage,SIGNAL(clicked()), this, SLOT(removePackage()));
}


void MainWindow::addPackage(){
    QWidget *window = new QWidget(this);
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");
        QVBoxLayout *main_layout =new QVBoxLayout();  //Defining Verticle Box Layour


        QLabel *label = new QLabel(window);
        label->setText("Package Information");
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QFont font("Helvetica",30,QFont::Bold);
        label->setFont(font);
        label->show();


        //Diaplays Login Form

        QWidget *packageForm = new QWidget(window);
        QGridLayout *formLayout = new QGridLayout(); // Defines grid layout for loginform
        formLayout->setColumnMinimumWidth(1,300);



        //Hint Text
        QLabel *idHint = new QLabel("Available");
        idHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

        QLabel *nameHint = new QLabel("Name");
        nameHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

        QLabel *companyHint = new QLabel("Company");
        companyHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

        QLabel *detailsHint = new QLabel("Details");
        detailsHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

        QLabel *priceHint = new QLabel("Price");
        priceHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");


        // Input Forms   
        this->package_name = new QLineEdit(); //this refers to the MainWindow class
        this->package_company = new QLineEdit();
        this->package_details = new QLineEdit();
        this->package_price = new QLineEdit();
        this->package_available = new QCheckBox();


        //font style

//         package_id->setFixedHeight(40);
//         package_id->setClearButtonEnabled(true);


        package_name->setFixedHeight(40);
        package_name->setClearButtonEnabled(true);

        package_company->setFixedHeight(40);
        package_company->setClearButtonEnabled(true);

        package_details->setFixedHeight(40);
        package_details->setClearButtonEnabled(true);

        package_price->setFixedHeight(40);
        package_price->setClearButtonEnabled(true);

        // Submit button

        QPushButton *submitButton = new QPushButton("Submit"); // Displays Login Button
        submitButton->setStyleSheet("*{background:green;height:30px;}");
        submitButton->setMaximumWidth(200);
        submitButton->setObjectName("theLoginButton");
        submitButton->adjustSize();

        connect(submitButton,SIGNAL(clicked(bool)),this,SLOT(sendAddRequest()));




        //Adding widgets in the userForm layout
        formLayout->addWidget(idHint,0,0);
        formLayout->addWidget(package_available,0,1);

        formLayout->addWidget(nameHint,1,0);
        formLayout->addWidget(package_name,1,1);

        formLayout->addWidget(companyHint,2,0);
        formLayout->addWidget(package_company,2,1);

        formLayout->addWidget(detailsHint,3,0);
        formLayout->addWidget(package_details,3,1);

        formLayout->addWidget(priceHint,4,0);
        formLayout->addWidget(package_price,4,1);

        formLayout->setColumnStretch(4,1);

        packageForm->setLayout(formLayout); //userForm layout set

        QPushButton *backButton = new QPushButton("Go Back");
        backButton->setStyleSheet("*{background:red;height:30px;}");
        backButton->adjustSize();
        connect(backButton,SIGNAL(clicked()),this,SLOT(PackageScreen()));

        //Adding widgets to main_layout
                   main_layout->addWidget(label);
                   main_layout->addWidget (packageForm);
                   main_layout->addWidget (submitButton);
                   main_layout->addWidget(backButton);

                   window->setLayout(main_layout);


  }

void MainWindow::removePackage(){
    QWidget *window = new QWidget(this);
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");
        QVBoxLayout *main_layout =new QVBoxLayout();  //Defining Verticle Box Layour


        QLabel *label = new QLabel(window);
        label->setText("Which Package you want to remove? ");
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QFont font("Helvetica",30,QFont::Bold);
        label->setFont(font);
        label->show();


        QWidget *packageForm = new QWidget(window);
        QGridLayout *formLayout = new QGridLayout(); // Defines grid layout for loginform
        formLayout->setColumnMinimumWidth(1,300);



        //Hint Text
        QLabel *idHint = new QLabel("ID");
        idHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

        // Input Forms
        this->package_id = new QLineEdit();    //this refers to the MainWindow class

        //font style

         package_id->setFixedHeight(40);
         package_id->setClearButtonEnabled(true);

        // Submit button
        QPushButton *loginButton = new QPushButton("Submit"); // Displays Login Button
        loginButton->setStyleSheet("*{background:green;height:30px;}");
        loginButton->setMaximumWidth(200);
        loginButton->setObjectName("theLoginButton");
        loginButton->adjustSize();

        connect(loginButton,SIGNAL(clicked(bool)),this,SLOT(sendRemoveRequest()));

        //Adding widgets in the userForm layout
        formLayout->addWidget(idHint,0,0);
        formLayout->addWidget(package_id,0,1);

         formLayout->setColumnStretch(4,1);

        packageForm->setLayout(formLayout); //userForm layout set


        QPushButton *backButton = new QPushButton("Go Back");
        backButton->setStyleSheet("*{background:red;height:30px;}");
        backButton->adjustSize();
        connect(backButton,SIGNAL(clicked()),this,SLOT(PackageScreen()));

        //Adding widgets to main_layout
                   main_layout->addWidget(label);
                   main_layout->addWidget (packageForm);
                   main_layout->addWidget (loginButton);
                   main_layout->addWidget(backButton);

                   window->setLayout(main_layout);



}

void MainWindow::sendAddRequest(){
    Database database;
    bool ok;
    int num = package_price->text().toInt(&ok);
    if (ok) {
      database.addPackages(package_name->text(),package_company->text(),package_details->text(),num,package_available->isChecked());
      package_name->clear();
      package_price->clear();
      package_company->clear();
      package_details->clear();
      package_available->setChecked(0);
      QMessageBox::information(this,"Successfull!","Package Added Success Fully");
    }else {
    QMessageBox::warning(this,"Unsuccessfull!","Can't add packages, Please check you have filled every field correctly");
    }

}

void MainWindow::sendRemoveRequest(){
    Database database;
    bool ok;
    int num = package_id->text().toInt(&ok);
    if(ok){
        if(database.removePackages(num)){
         QMessageBox::information(this,"Successfull!","Package Removed Successfully");
        }else {
            QMessageBox::warning(this,"Unsuccessfull!","Can't connect to database! Check Internet connection and Try Again!");
            }
    }else{
    QMessageBox::warning(this,"Invalid Package ID!","Please enter valid package ID!");
    }
}
