#include "mainwindow.h"

QWidget * MainWindow::guesttable(){
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

            editButton = new QPushButton();
            editButton->setText("Edit");

            noEditButton = new QPushButton();
            noEditButton->setText("Stop Editing");
            noEditButton->adjustSize();
            noEditButton->hide();

            QLabel *sortlabel = new QLabel("Sort By");
            QComboBox *sortby = new QComboBox();
            sortby->addItem("Name");
            sortby->addItem("Check-in");
            sortby->addItem("Check-out");

            QComboBox *order = new QComboBox();
            order->addItem("Ascending");
            order->addItem("Descending");

            QLabel *statusLabel = new QLabel("Status");
            QComboBox *status = new QComboBox();
            status->addItem("Active");
            status->addItem("Inactive");


        headerlayout->addWidget(searchField);
        headerlayout->addWidget(searchButton);
        headerlayout->addWidget(editButton);
        headerlayout->addWidget(noEditButton);
        headerlayout->addStretch(1);
        headerlayout->addWidget(sortlabel);
        headerlayout->addWidget(sortby);
        headerlayout->addWidget(order);
        headerlayout->addWidget(statusLabel);
        headerlayout->addWidget(status);
        header->setLayout(headerlayout);


        model = new QSqlTableModel();
        model->setTable("guests");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->setParent(this);
        model->select();
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Room No"));
        model->setHeaderData(2, Qt::Horizontal, tr("Name"));
        model->setHeaderData(3, Qt::Horizontal, tr("Email"));
        model->setHeaderData(4, Qt::Horizontal, tr("Contact"));
        model->setHeaderData(5, Qt::Horizontal, tr("Address"));
        model->setHeaderData(6, Qt::Horizontal, tr("Checkin"));
        model->setHeaderData(7, Qt::Horizontal, tr("Checkout"));
        model->setHeaderData(8, Qt::Horizontal, tr("Identity"));
        model->setHeaderData(9, Qt::Horizontal, tr("Room Type"));
        model->setHeaderData(10, Qt::Horizontal, tr("Total"));
        model->setHeaderData(11, Qt::Horizontal, tr("Paid"));
        model->setHeaderData(12, Qt::Horizontal, tr("Due"));
        model->setHeaderData(13, Qt::Horizontal, tr("Status"));
        model->setHeaderData(14, Qt::Horizontal, tr("Packages"));

        connect(sortby, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            [=](int index){
            switch (index){
            case 0:
                model->setSort(2,Qt::AscendingOrder);
                model->select();
                break;
            case 1:
                model->setSort(6,Qt::AscendingOrder);
                model->select();
                break;
            case 2:
                model->setSort(7,Qt::AscendingOrder);
                model->select();
                break;
            case 6:
                model->setSort(6,Qt::AscendingOrder);
                model->select();
                break;
            case 7:
                model->setSort(7,Qt::AscendingOrder);
                model->select();
                break;
            default:
                model->select();
                break;
            }

        });

        connect(searchButton,SIGNAL(clicked(bool)),this,SLOT(search()));
        connect(searchField,SIGNAL(returnPressed()),this,SLOT(search()));
        connect(searchField,SIGNAL(editingFinished()),this,SLOT(search()));


        connect(editButton,SIGNAL(clicked()),this,SLOT(editTable()));
        connect(noEditButton,SIGNAL(clicked()),this,SLOT(noEditTable()));

        connect(order, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            [=](int index){
            int sortIndex = sortby->currentIndex();
            switch (index){
            case 0:
                model->setSort(sortIndex,Qt::AscendingOrder);
                model->select();
                break;
            case 1:
                model->setSort(sortIndex,Qt::DescendingOrder);
                model->select();
                break;
            default:
                model->select();
                break;
            }

        });

        connect(status, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            [=](int index){
//            model->setFilterCol
            switch (index){
            case 0:
                model->setFilter("status='Active'");
                model->select();
                break;
            case 1:
                model->setFilter("status='InActive'");
                model->select();
                break;
            default:
                model->select();
                break;
            }

        });

        QTableView *view = new QTableView();
        view->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        view->setModel(model);
        view->hideColumn(0);

    layout->addWidget(header);
    layout->addWidget(view);
    table->setLayout(layout);
//    table->show();

    return table;
}

void MainWindow::search(){
    QString query = searchField->text();
    if(query!= NULL){
    model->setFilter("name='"+query+"' or contact='"+query+"' or address='"+query+"' or email='"+query+"' or room_no ='"+query+"'");
    model->select();
    }else{
    model->setFilter(NULL);
    model->select();
    }
}


void MainWindow::editTable(){
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    QMessageBox::warning(this->searchField,"Edit Enabled","Edit mode is enabled, operate carefully.");
    editButton->hide();
    noEditButton->show();
}

void MainWindow::noEditTable(){
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QMessageBox::information(this->searchField,"Edit Enabled","Edit Mode Is Enabled, operate carefully.");
    QMessageBox::information(this->searchField,"Edit Disabled","Edit mode is disabled, All Changes are saved.");
    noEditButton->hide();
    editButton->show();
}
