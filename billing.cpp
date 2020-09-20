#include "mainwindow.h"

QWidget * MainWindow::showbill(){


    QWidget *table = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

        QWidget *header = new QWidget(this);
        header->setFixedHeight(50);
        QHBoxLayout *headerlayout = new QHBoxLayout();

            searchField = new QLineEdit();
            searchField->setPlaceholderText("Search");
            searchField->setFixedWidth(300);
            searchField->setClearButtonEnabled(true);

            QPushButton *searchButton = new QPushButton();
            searchButton->setText("Search");






            QLabel *statusLabel = new QLabel("Status");
            QComboBox *status = new QComboBox();
            status->addItem("Active");
            status->addItem("Inactive");


        headerlayout->addWidget(searchField);
        headerlayout->addWidget(searchButton);
        headerlayout->addStretch(1);

        headerlayout->addWidget(statusLabel);
        headerlayout->addWidget(status);
        header->setLayout(headerlayout);


        QVBoxLayout  *billlayout = new QVBoxLayout();




//        model = new QSqlTableModel();
//        model->setTable("guests");
//        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//        model->setParent(this);
// //       model->select();
//        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
//        model->setHeaderData(1, Qt::Horizontal, tr("Room No"));
//        model->setHeaderData(2, Qt::Horizontal, tr("Name"));
//        model->setHeaderData(3, Qt::Horizontal, tr("Email"));
//        model->setHeaderData(4, Qt::Horizontal, tr("Contact"));

//        model->setHeaderData(10, Qt::Horizontal, tr("Total"));
//        model->setHeaderData(11, Qt::Horizontal, tr("Paid"));
//        model->setHeaderData(12, Qt::Horizontal, tr("Due"));



        connect(searchButton,SIGNAL(clicked(bool)),this,SLOT(searchroom()));
        connect(searchField,SIGNAL(returnPressed()),this,SLOT(searchroom()));
        connect(searchField,SIGNAL(editingFinished()),this,SLOT(searchroom()));



//        connect(status, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
//            [=](int index){
////            model->setFilterCol
//            switch (index){
//            case 0:
//                model->setFilter("status='Active'");
//                model->select();
//                break;
//            case 1:
//                model->setFilter("status='InActive'");
//                model->select();
//                break;
////            default:
////                model->select();
////                break;
//            }

//        });

//        QTableView *view = new QTableView();
//        view->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
//        view->setModel(model);
//        view->hideColumn(0);

    layout->addWidget(header);
    //layout->addWidget(view);
    table->setLayout(layout);
    table ->setLayout(billlayout);
//    table->show();

    return table;
}


void MainWindow::searchroom(){
     QString (query) = searchField->text();
     int choice;
     choice = query.toInt();
     QString StyleSheetBtns = "QPushButton { color: white; background-color: #1c2c3c; border: solid 5px white; font: 16pt 'Microsoft YaHei UI Light'; font-weight:bold; outline: none; } QPushButton:hover { background-color: #dc2525; border-style: solid; border-width: 3px; border-color: white; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";

     QPushButton* room1Btn = new QPushButton("Room 1");
     QPushButton* room2Btn = new QPushButton("Room 2");
     QPushButton* room3Btn = new QPushButton("Room 3");
     QPushButton* room4Btn = new QPushButton("Room 4");
     QPushButton* room5Btn = new QPushButton("Room 5");
     QPushButton* room6Btn = new QPushButton("Room 6");
     QPushButton* room7Btn = new QPushButton("Room 7");
     QPushButton* room8Btn = new QPushButton("Room 8");


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

     connect(room1Btn,SIGNAL(clicked()), this, SLOT(room()));
     connect(room2Btn,SIGNAL(clicked()), this, SLOT(room()));
     connect(room3Btn,SIGNAL(clicked()), this, SLOT(room()));
     connect(room4Btn,SIGNAL(clicked()), this, SLOT(room()));
     connect(room5Btn,SIGNAL(clicked()), this, SLOT(room()));
     connect(room6Btn,SIGNAL(clicked()), this, SLOT(room()));
     connect(room7Btn,SIGNAL(clicked()), this, SLOT(room()));
     connect(room8Btn,SIGNAL(clicked()), this, SLOT(room()));

    if(query!= NULL){
        switch (choice){
        case 1:
            billlayout->addWidget(room1Btn);
            break;

        case 2:
            billlayout->addWidget(room2Btn);
            break;

        case 3:
            billlayout->addWidget(room3Btn);
            break;

        case 4:
            billlayout->addWidget(room4Btn);
            break;

        case 5:
            billlayout->addWidget(room5Btn);
            break;

        case 6:
            billlayout->addWidget(room6Btn);
            break;

        case 7:
            billlayout->addWidget(room7Btn);
            break;

        case 8:
            billlayout->addWidget(room8Btn);
            break;


        }

}
}
