#include "mainwindow.h"
#include <QProgressDialog>
#include <iostream>


// Defining room booking screen //

void MainWindow::roombooking(){

    if( ){                                    // Correction needed

    QWidget *window = new QWidget(this);
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");
        QHBoxLayout *layout =new QHBoxLayout();  //Defining Horizontal Box Layout

            //Displays User Details Text At Center

            QLabel *label = new QLabel(window);
            label->setText("User Details");
            label->setAlignment(Qt::AlignHCenter);
            QFont font("Helvetica",30,QFont::Bold);
            label->setFont(font);
            label->show();

            //Diaplays Name Form

            QWidget *nameForm = new QWidget(window);
            QGridLayout *formLayout = new QGridLayout(); // Defines grid layout for name
            formLayout->setColumnMinimumWidth(1,300);

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
}
}
