#include "room.h"
#include <QProgressDialog>
#include <iostream>
#include "mainwindow.h"
#include "database.h"
#include <QDateTime>
using namespace std;

void MainWindow::package_price_adder(string str)
{
    str += ',';
    int count = 0;
    for(char i : str){
        if(i == ',') {
            count++;
        }
    }
    int* array = new int[count];
    int arraypos = 0;
    unsigned int values = 0 ,pos = 0;

    for(char i : str){
        if(i == ','){
            string numb = str.substr(values);
            array[arraypos] = stoi(numb);
            values = pos+1;
            arraypos++;
        }
        pos++;
    }
    QSqlQuery package_price_query(db);
    for(int k = 0; k<count; k++){
        package_price_query.exec("SELECT price FROM hms.packages WHERE id = ?");
        package_price_query.addBindValue(array[k]);
        package_price_query.next();
        totalprice_calculator(package_price_query.value(0).toInt());
    }
    delete [] array;
}


// Defining //

void MainWindow::bookButton_clicked(){

    QString name,email,address,nationality,phone,date,package;
    email = MainWindow::customer_email->text(); // fetch input text from email input field of loginscreen
    name = MainWindow::customer_name->text();  // fetch input text from password input field of loginscreen
    address = MainWindow::customer_address->text();
    nationality = MainWindow::customer_nationality->text();
    phone = MainWindow::customer_phone->text();
    date = QDate::currentDate().toString("dd.mm.yyyy");
    QDateTime checkin = QDateTime::currentDateTime();
    package = MainWindow::package_id->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO hms.guests (name, email, contact, address, identity, checkin, packages, room_type)"
                "VALUES (?,?,?,?,?,?,?,?);");
    qry.addBindValue(name);
    qry.addBindValue(email);
    qry.addBindValue(phone);
    qry.addBindValue(address);
    qry.addBindValue(nationality);
    qry.addBindValue(checkin);
    qry.addBindValue(package);
    qry.addBindValue(room[1]);

    if(!qry.exec())
    {
        QMessageBox::warning(window(),"Database Error2","Not connected to database");
    } // Displays database error popup    
}

void MainWindow::totalprice_display(int price){
    totalprice += price;
    display_price = new QLineEdit();
    display_price->clear();
    display_price->setText(QString::number(totalprice));
}

void MainWindow::totalprice_calculator(int price){

    totalprice += price;
    display_price = new QLineEdit();
    display_price->setText(QString::number(totalprice));
    display_price->textChanged(QString::number(totalprice));
 }//total price ani paid amount/due amount bhanne book button click garisakepachi dialog box ma aaune banaune
