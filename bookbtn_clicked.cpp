#include "mainwindow.h"
#include <QProgressDialog>
#include <iostream>


// Defining loginScreen //

void MainWindow::bookButton_clicked(){
    QString name,email,address,nationality;
    int phone;
    email = MainWindow::customer_email->text(); // fetch input text from email input field of loginscreen
    name = MainWindow::customer_name->text();  // fetch input text from password input field of loginscreen
    address = MainWindow::customer_address->text();
    nationality = MainWindow::customer_nationality->text();
    phone = MainWindow::customer_phone->text().toInt();

    QSqlQuery qry;
    qry.prepare("INSERT INTO guests ("
                "name,"
                "email"
                "contact"
                "address"
                "identity)"
                "VALUES (?,?,?,?,?);");
    qry.addBindValue(name);
    qry.addBindValue(email);
    qry.addBindValue(phone);
    qry.addBindValue(address);
    qry.addBindValue(nationality);

    if(!qry.exec())
    {
        QMessageBox::warning(window(),"Database Error","Not connected to database");
    } // Displays database error popup

}

void MainWindow::totalprice_calculator(){

 }
