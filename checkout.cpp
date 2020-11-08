#include"mainwindow.h"
#include <QProgressDialog>
#include <QDebug>
#include <QCheckBox>


void MainWindow::checkout(int room){

    QVBoxLayout *layout = new QVBoxLayout;
    Database db;
    Guest guest = db.getGuestDetailByRoomNo(room);
    Guest_id_cout = guest.getID();
    Guest_room_cout = guest.getRoomNo();
    if(guest.getID() == NULL)
    {   infoLabel = new QLabel();
        infoLabel->setText("No user");
    }
    else{
        infoLabel = new QLabel();
        infoLabel->setText("Bill  For HMS");
    }

    infoLabel->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *userForm = new QWidget(bottom_half); // QWidget(widget)
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
    TotalPayHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

    QLabel *PaidPayHint = new QLabel("Paid Amount");
    PaidPayHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

    QLabel *DuePayHint = new QLabel("Due Amount");
    DuePayHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    QLabel *PayHint = new QLabel("Pay:");
    PayHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    // Input Forms
    QLabel *custo_name = new QLabel();//this refers to the MainWindow class
    QLabel *custo_email = new QLabel();
    QLabel *custo_phone = new QLabel();
    QLabel *custo_address = new QLabel();
    QLabel *custo_nationality = new QLabel();
    QLabel *Total = new QLabel();
    Paid = new QLabel();
    Due = new QLabel();

   Pay_amount = new QLineEdit();
   Pay_amount->setFixedHeight(40);
   Pay_amount->setClearButtonEnabled(true);
   Pay_amount->setPlaceholderText("Pay Here");

    custo_name->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    custo_email->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    custo_phone->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    custo_address->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    custo_nationality->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    Total->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    Paid->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
    Due->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");



    custo_name->setText(guest.getName());
    custo_email->setText(guest.getEmail());
    custo_phone->setText(guest.getContact());
    custo_address->setText(guest.getAddress());
    custo_nationality->setText(guest.getIdentity());
    Total->setNum(guest.getTotalAmount());
    Paid->setNum(guest.getPaidAmount());
    Due->setNum(guest.getDueAmount());


    //Adding widgets in the userForm layout
    user_formLayout-> setHorizontalSpacing(30);
    user_formLayout->addWidget(nameHint,0,0);
    user_formLayout->addWidget(custo_name,0,1);

    user_formLayout->addWidget(emailHint,1,0);
    user_formLayout->addWidget(custo_email,1,1);

    user_formLayout->addWidget(phoneHint,2,0);
    user_formLayout->addWidget(custo_phone,2,1);

    user_formLayout->addWidget(addressHint,3,0);
    user_formLayout->addWidget(custo_address,3,1);

    user_formLayout->addWidget(nationalityHint,4,0);
    user_formLayout->addWidget(custo_nationality,4,1);
    user_formLayout->addWidget(TotalPayHint,5,0);
    user_formLayout->addWidget(Total,5,1);

    user_formLayout->addWidget(PaidPayHint,6,0);
    user_formLayout->addWidget(Paid,6,1);

    user_formLayout->addWidget(DuePayHint,7,0);
    user_formLayout->addWidget(Due,7,1);

    user_formLayout->addWidget(PayHint,8,0);
    user_formLayout->addWidget(Pay_amount,8,1);


    user_formLayout->setColumnStretch(8,1);
     userForm->setLayout(user_formLayout);

    QWidget *Button_widget = new QWidget(bottom_half); //QWidget(widget)
    QGridLayout *buttonLayout = new QGridLayout();

    QPushButton *checkout_nowButton = new QPushButton("Check out");
    checkout_nowButton->setStyleSheet("*{background:red;height:30px;}");
    connect(checkout_nowButton,SIGNAL(clicked(bool)),this,SLOT(checkout_now()));
    connect(checkout_nowButton,SIGNAL(clicked(bool)),this,SLOT(dashboard()));
    // GO Back Button
    QPushButton *BackButton = new QPushButton("Back");
    BackButton->setStyleSheet("*{background:red;height:30px;}");
    BackButton->adjustSize();
    connect(BackButton,SIGNAL(clicked()),this,SLOT(Bill()));

    QPushButton *PayButton = new QPushButton("Pay");
    PayButton->setStyleSheet("*{background:red;height:30px;}");
    PayButton->adjustSize();
    connect(PayButton,SIGNAL(clicked()),this,SLOT(payNow()));

    //adding button widgets to buttonlayout
    buttonLayout->addWidget(BackButton,0,0,Qt::AlignLeft);
    buttonLayout->addWidget(PayButton,0,1,Qt::AlignLeft);
    buttonLayout->addWidget(checkout_nowButton,0,3,Qt::AlignRight);
    buttonLayout->setColumnStretch(2,2);
    Button_widget->setLayout(buttonLayout);


   layout->addWidget(infoLabel);
   layout->addWidget(userForm);
   layout->addWidget(Button_widget);
   bottom_half->setLayout(layout);

}

void MainWindow::checkout_now(){
    Database db;
        QMessageBox msgBox;
    if (db.isCheckOutAble(Guest_id_cout))
    {
        db.guestCheckOut(Guest_id_cout, Guest_room_cout);
        msgBox.setText("Check Out successful");

    }
    else
    {
        msgBox.setText("Please check your amount and try again");
    }

    msgBox.exec();

}

void MainWindow::payNow(){
    Database db;
    if(db.payAmount(Pay_amount->text().toInt(), Guest_id_cout)){
    QMessageBox msgBox;
    msgBox.setText("Amount Paid successfully");
    msgBox.exec();
    Guest guest = db.getGuestDetailByID(Guest_id_cout);
    Due->setNum(guest.getDueAmount());
    Paid->setNum(guest.getPaidAmount());
    }else{
        QMessageBox msgBox;
        msgBox.setText("Error has occured");
        msgBox.exec();
    }
}
