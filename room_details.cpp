#include "mainwindow.h"
#include <QMessageBox>
#include <iostream>


// Defining room booking screen //

void MainWindow::room(){
    if(db.open()){
    QWidget* window = new QWidget();
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");
        QVBoxLayout *room_layout =new QVBoxLayout();  //Defining vertical Box Layout

            //Displays Room Details Text At Center

            QLabel *room_label = new QLabel(window);
            room_label->setText("Room Details");
            room_label->setAlignment(Qt::AlignHCenter);
            QFont font("Helvetica",30,QFont::Bold);
            room_label->setFont(font);
            room_label->setFixedHeight(100);
            room_label->show();

            QString room[5];
            QSqlQuery room_query(db);
            int i;

            if(roomBtn_select == 1){ //yo connect bhako chaina hola
            room_query.prepare("SELECT * FROM room WHERE room_no = 1"); //milecha ki chaina check garna parcha
            room_query.exec();
            room_query.next();
            for(i=0;i<5;i++){room[i] = room_query.value(i).toString();}
           }
            if(roomBtn_select == 2){
            room_query.exec("SELECT * FROM room WHERE room_no = 2"); //milecha ki chaina check garna parcha
            room_query.next();
            for(i=0;i<5;i++){room[i] = room_query.value(i).toString();}
           }

            if(roomBtn_select == 3){
            room_query.exec("SELECT * FROM room WHERE room_no = 3"); //milecha ki chaina check garna parcha
            room_query.next();
            for(i=0;i<5;i++){room[i] = room_query.value(i).toString();}
            }

            if(roomBtn_select == 4){
            room_query.exec("SELECT * FROM room WHERE room_no = 4"); //milecha ki chaina check garna parcha
            room_query.next();
            for(i=0;i<5;i++){room[i] = room_query.value(i).toString();}
           }

            if(roomBtn_select == 5){
            room_query.exec("SELECT * FROM room WHERE room_no = 5"); //milecha ki chaina check garna parcha
            room_query.next();
            for(i=0;i<5;i++){room[i] = room_query.value(i).toString();}
            }

            if(roomBtn_select == 6){
            room_query.exec("SELECT * FROM room WHERE room_no = 6"); //milecha ki chaina check garna parcha
            room_query.next();
            for(i=0;i<5;i++){room[i] = room_query.value(i).toString();}
           }

            if(roomBtn_select == 7){
            room_query.exec("SELECT * FROM room WHERE room_no = 7"); //milecha ki chaina check garna parcha
            room_query.next();
            for(i=0;i<5;i++){room[i] = room_query.value(i).toString();}
           }

            if(roomBtn_select == 8){
            room_query.exec("SELECT * FROM room WHERE room_no = 8"); //milecha ki chaina check garna parcha
            room_query.next();
            for(i=0;i<5;i++){room[i] = room_query.value(i).toString();}
            }

            QWidget *room_details_form = new QWidget(window);
            QGridLayout *room_details_formLayout = new QGridLayout(); // Defines grid layout for name
            room_details_formLayout->setColumnMinimumWidth(1,100);

            // Form Fields Start
            //Hint Text
            QLabel *room_num = new QLabel("Room Number:");
            room_num->setStyleSheet("*{font-weight:bold;font-size:20px;padding:10px;}");
            QLabel *room_num_is = new QLabel(room[0]);
            room_num_is->setStyleSheet("*{font-size:20px;padding:10px;}");

            QLabel *room_typ = new QLabel("Room Type:");
            room_typ->setStyleSheet("*{font-weight:bold;font-size:20px;padding:10px;}");
            QLabel *room_type_is = new QLabel(room[1]);
            room_type_is->setStyleSheet("*{font-size:20px;padding:10px;}");

            QLabel *room_detail = new QLabel("Details:");
            room_detail->setStyleSheet("*{font-weight:bold;font-size:20px;padding:10px;}");
            QLabel *details = new QLabel(room[2]);
            details->setStyleSheet("*{font-size:20px;padding:10px;}");

            QLabel *room_prc = new QLabel("Price:");
            room_prc->setStyleSheet("*{font-weight:bold;font-size:20px;padding:10px;}");
            QLabel *price = new QLabel(room[3]);
            price->setStyleSheet("*{font-size:20px;padding:10px;}");


            QLabel *room_available = new QLabel("Availability:");
            room_available->setStyleSheet("*{font-weight:bold;font-size:20px;padding:10px;}");
            QLabel *availability = new QLabel(room[4]);
            availability->setStyleSheet("*{font-size:20px;padding:10px;}");


            //adding label to layout
            room_details_formLayout->addWidget(room_num,0,0,1,1);
            room_details_formLayout->addWidget(room_num_is,0,1,1,1);
            room_details_formLayout->addWidget(room_typ,1,0,1,1);
            room_details_formLayout->addWidget(room_type_is,1,1);
            room_details_formLayout->addWidget(room_detail,2,0);
            room_details_formLayout->addWidget(details,2,1);
            room_details_formLayout->addWidget(room_prc,3,0);
            room_details_formLayout->addWidget(price,3,1);
            room_details_formLayout->addWidget(room_available,4,0);
            room_details_formLayout->addWidget(availability,4,1);

            room_details_formLayout->setColumnStretch(4,1);
            room_details_form->setLayout(room_details_formLayout); //room_details_form layout set

            // GO Back Button
            QPushButton *backButton = new QPushButton("Back");
            backButton->setStyleSheet("*{background:red;height:30px;}");
            backButton->adjustSize();
            connect(backButton,SIGNAL(clicked()),this,SLOT(Roommain()));

            //Adding widgets to room_layout
            room_layout->addWidget(room_label);
            room_layout->addWidget(room_details_form);
            room_layout->addWidget(backButton);
            window->setLayout(room_layout);  //room_layout set to main window
    }
    else{QMessageBox::warning(window(),"Database Error 1","Not connected to database");}
}
