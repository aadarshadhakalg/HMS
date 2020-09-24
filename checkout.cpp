#include"mainwindow.h"
#include <QProgressDialog>
#include <QDebug>
#include <QCheckBox>


void MainWindow::checkout(int room){
    setWindowTitle("Billings");
    style();

    QWidget *widget = new QWidget;
    setCentralWidget(widget);
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

    QLabel *TotalPayHint = new QLabel("Total Amount");
    nationalityHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

    QLabel *PaidPayHint = new QLabel("Paid Amount");
    nationalityHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

    QLabel *DuePayHint = new QLabel("Due Amount");
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
    widget->setLayout(user_formLayout);
}
