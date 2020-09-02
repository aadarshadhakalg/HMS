#include <QProgressDialog>
#include <iostream>
#include "database.h"
#include "room.h"
#include "mainwindow.h"
#define service_max 10

// Defining room booking screen //

void MainWindow::roombooking(){
    if (db.open()){
    QWidget *window = new QWidget(this);
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");
        QVBoxLayout *main_layout =new QVBoxLayout();  //Defining Vertical Box Layout

            //Displays User Details Text At Center
            QLabel *user_label = new QLabel(window);
            user_label->setText("User Details");
            user_label->setAlignment(Qt::AlignHCenter);
            QFont font("Helvetica",30,QFont::Bold);
            user_label->setFont(font);
            user_label->show();

            //Diaplays Name Form
            QWidget *userForm = new QWidget(window);
            QGridLayout *user_formLayout = new QGridLayout(); // Defines grid layout for name
            user_formLayout->setColumnMinimumWidth(1,300);

            // Form Fields Start
            //Hint Text
            QLabel *nameHint = new QLabel("Name");
            nameHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            QLabel *emailHint = new QLabel("Email");
            emailHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            QLabel *phoneHint = new QLabel("Phone No.");
            phoneHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            QLabel *addressHint = new QLabel("Address");
            addressHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            QLabel *nationalityHint = new QLabel("Nationality");
            nationalityHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            // Input Forms
            this->customer_name = new QLineEdit();    //this refers to the MainWindow class
            this->customer_email = new QLineEdit();
            this->customer_phone = new QLineEdit();
            this->customer_address = new QLineEdit();
            this->customer_nationality = new QLineEdit();

            //font style
            customer_name->setFixedHeight(40);
            customer_name->setClearButtonEnabled(true);

            customer_email->setFixedHeight(40);
            customer_email->setPlaceholderText("Active Email");
            customer_email->setClearButtonEnabled(true);

            customer_phone->setFixedHeight(40);
            customer_phone->setClearButtonEnabled(true);

            customer_address->setFixedHeight(40);
            customer_address->setClearButtonEnabled(true);
            customer_address->setPlaceholderText("Current Address");

            customer_nationality->setFixedHeight(40);
            customer_nationality->setClearButtonEnabled(true);

            //Adding widgets in the userForm layout
            user_formLayout->addWidget(nameHint,0,0);
            user_formLayout->addWidget(customer_name,0,1);

            user_formLayout->addWidget(emailHint,1,0);
            user_formLayout->addWidget(customer_email,1,1);

            user_formLayout->addWidget(phoneHint,2,0);
            user_formLayout->addWidget(customer_phone,2,1);

            user_formLayout->addWidget(addressHint,3,0);
            user_formLayout->addWidget(customer_address,3,1);

            user_formLayout->addWidget(nationalityHint,4,0);
            user_formLayout->addWidget(customer_nationality,4,1);

            user_formLayout->setColumnStretch(4,1);
            userForm->setLayout(user_formLayout); //userForm layout set

            //Diaplays Room details Form
            QWidget *room_form = new QWidget(window);
            QGridLayout *room_formLayout = new QGridLayout(); // Defines grid layout for name
            room_formLayout->setColumnMinimumWidth(1,300);

            //Room select
            QLabel *room_select = new QLabel("ROOM:");
            room_select->setStyleSheet("*{font-weight:bold;font-size:20px;padding:12px;}");

            //Room select check box
            QCheckBox *room1_checkbox = new QCheckBox("Room 1");
            QCheckBox *room2_checkbox = new QCheckBox("Room 2");
            QCheckBox *room3_checkbox = new QCheckBox("Room 3");
            QCheckBox *room4_checkbox = new QCheckBox("Room 4");
            QCheckBox *room5_checkbox = new QCheckBox("Room 5");
            QCheckBox *room6_checkbox = new QCheckBox("Room 6");
            QCheckBox *room7_checkbox = new QCheckBox("Room 7");
            QCheckBox *room8_checkbox = new QCheckBox("Room 8");

            //Additional service select
            QLabel *service_select = new QLabel("SERVICES:");
            service_select->setStyleSheet("*{font-weight:bold;font-size:20px;padding:12px;}");

            //Room select check box
            QCheckBox *dinner_checkbox = new QCheckBox("DINNER");
            QCheckBox *breakfast_checkbox = new QCheckBox("BREAKFAST");
            QCheckBox *lunch_checkbox = new QCheckBox("LUNCH");
            QCheckBox *transportation_checkbox = new QCheckBox("TRANSPORTATION");
            QCheckBox *sim_checkbox = new QCheckBox("SIM");
            QCheckBox *guide_checkbox = new QCheckBox("GUIDE");

            //for package selection
            QLabel *packageHint = new QLabel("Package Id");
            packageHint->setStyleSheet("*{font-weight:bold;font-size:18px;padding:10px;}");
            this->package_id = new QLineEdit();
            package_id->setFixedHeight(40);

            //Adding widgets in the room_FormLayout
            room_formLayout->addWidget(room_select,0,0);

            room_formLayout->addWidget(room1_checkbox,1,0);
            room_formLayout->addWidget(room2_checkbox,1,1);
            room_formLayout->addWidget(room3_checkbox,1,2);
            room_formLayout->addWidget(room4_checkbox,1,3);
            room_formLayout->addWidget(room5_checkbox,2,0);
            room_formLayout->addWidget(room6_checkbox,2,1);
            room_formLayout->addWidget(room7_checkbox,2,2);
            room_formLayout->addWidget(room8_checkbox,2,3);

            room_formLayout->addWidget(service_select,3,0);

            room_formLayout->addWidget(dinner_checkbox,4,0);
            room_formLayout->addWidget(breakfast_checkbox,4,1);
            room_formLayout->addWidget(lunch_checkbox,4,2);
            room_formLayout->addWidget(transportation_checkbox,5,0);
            room_formLayout->addWidget(sim_checkbox,5,1);
            room_formLayout->addWidget(guide_checkbox,5,2);
            room_formLayout->addWidget(packageHint,6,0);
            room_formLayout->addWidget(package_id,6,1);

            //Adding layout to room_form
            room_formLayout->setColumnStretch(6,3);
            room_form->setLayout(room_formLayout); //room_form layout set

            int room_price[8], i;
            QSqlQuery roomprice_qry(db);
            roomprice_qry.exec("SELECT room_price FROM room");
            for (i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}

            int service_charge[service_max];
            QSqlQuery serviceprice_qry(db);
            serviceprice_qry.exec("SELECT service_price FROM services");//Table name ra column name sacchhaune
            for(i=0;serviceprice_qry.next();i++){service_charge[i] = serviceprice_qry.value(0).toInt();}//database ko table aanusar serial wise data aaucha

            QSqlQuery roomavailability_qry(db);
            roomavailability_qry.exec("select room_status from room");
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room1_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room2_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room3_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room4_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room5_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room6_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room7_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room8_checkbox->setEnabled(false);}

            if(room1_checkbox->isChecked()) {totalprice_calculator(room_price[0]);}
            if(room2_checkbox->isChecked()) {totalprice_calculator(room_price[1]);}
            if(room3_checkbox->isChecked()) {totalprice_calculator(room_price[2]);}
            if(room4_checkbox->isChecked()) {totalprice_calculator(room_price[3]);}
            if(room5_checkbox->isChecked()) {totalprice_calculator(room_price[4]);}
            if(room6_checkbox->isChecked()) {totalprice_calculator(room_price[5]);}
            if(room7_checkbox->isChecked()) {totalprice_calculator(room_price[6]);}
            if(room8_checkbox->isChecked()) {totalprice_calculator(room_price[7]);}

            if(breakfast_checkbox->isChecked()) {totalprice_calculator(service_charge[0]);}
            if(dinner_checkbox->isChecked()) {totalprice_calculator(service_charge[1]);}
            if(lunch_checkbox->isChecked()) {totalprice_calculator(service_charge[2]);}
            if(transportation_checkbox->isChecked()) {totalprice_calculator(service_charge[3]);}
            if(sim_checkbox->isChecked()) {totalprice_calculator(service_charge[4]);}
            if(guide_checkbox->isChecked()) {totalprice_calculator(service_charge[5]);}

            //Layout for Buttons
            QWidget *Button_widget = new QWidget(window);
            QGridLayout *buttonLayout = new QGridLayout(); //Layout for back and book now button

            //Book now Button
            QPushButton *book_nowButton = new QPushButton("Book Now");
            book_nowButton->setStyleSheet("*{background:red;height:30px;}");

            // GO Back Button
            QPushButton *backButton = new QPushButton("Back");
            backButton->setStyleSheet("*{background:red;height:30px;}");
            backButton->adjustSize();
            connect(backButton,SIGNAL(clicked()),this,SLOT(Roommain()));

            //adding button widgets to buttonlayout
            buttonLayout->addWidget(backButton,0,0,Qt::AlignLeft);
            buttonLayout->addWidget(book_nowButton,0,3,Qt::AlignRight);
            buttonLayout->setColumnStretch(2,2);
            Button_widget->setLayout(buttonLayout); //Adding Layout to Button_widget

            //Adding widgets to main_layout
            main_layout->addWidget(user_label);
            main_layout->addWidget(userForm);
            main_layout->addWidget(room_form);           
            main_layout->addWidget(Button_widget);
            window->setLayout(main_layout);  //main_layout set to main window       

            connect(book_nowButton,SIGNAL(clicked(bool)),this,SLOT(bookButton_clicked())); // Calls bookButton_clicked method when button is clicked
        }
    else {QMessageBox::warning(window(),"Database Error 1","Not connected to database");}
}
