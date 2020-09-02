#include "room.h"
#include <QProgressDialog>
#include <iostream>
#include "mainwindow.h"
#include "database.h"
#include <QDateTime>


// Defining //

void MainWindow::bookButton_clicked(){

    QString name,email,address,nationality,phone,date;
    email = MainWindow::customer_email->text(); // fetch input text from email input field of loginscreen
    name = MainWindow::customer_name->text();  // fetch input text from password input field of loginscreen
    address = MainWindow::customer_address->text();
    nationality = MainWindow::customer_nationality->text();
    phone = MainWindow::customer_phone->text();
    date = QDate::currentDate().toString("dd.mm.yyyy");
    QDateTime checkin = QDateTime::currentDateTime();


    QSqlQuery qry;
    qry.prepare("INSERT INTO hms.guests (name, email, contact, address, identity, checkin)"
                "VALUES (?,?,?,?,?,?);");
    qry.addBindValue(name);
    qry.addBindValue(email);
    qry.addBindValue(phone);
    qry.addBindValue(address);
    qry.addBindValue(nationality);
    qry.addBindValue(checkin);
    qry.exec();

    if(!qry.exec())
    {
        QMessageBox::warning(window(),"Database Error2","Not connected to database");
    } // Displays database error popup
}



void MainWindow::totalprice_calculator(int price){
    totalprice += price;
    display_price->setText(QString::number(totalprice));
    display_price->textChanged(QString::number(totalprice));
 }//total price ani paid amount/due amount bhanne book button click garisakepachi dialog box ma aaune banaune

/*void package_getter(){
    int i = 0,j=0, k[10];
    k[0] = 0;
    for(//QLineEdit ko text purai samma loop){
        i++;
        QString a = a + QString b //yesma operator overloading garna milcha.. duita qstring + garda qstring jodera int return garne
        if(//comma ayo bhane){      //jasti QString a = '1' QString b = '2' then a + b = 12
        k[j+1] = i;
        j++;
        }
    }
    for(i=0;i<j+1;i++){
           for(l=0;l<k[j+1];l++){}
    }
}*/

