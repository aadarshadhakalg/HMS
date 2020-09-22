#include "room.h"
#include <QProgressDialog>
#include <iostream>
#include "mainwindow.h"
#include "database.h"
#include <QDateTime>
#include <QString>
using namespace std;

void MainWindow::packageprice_adder()
{
    std::string str = package_id->text().toStdString();
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

    Database db;
    for(int k = 0; k<count; k++){
        Package pkg = db.getPackageByID(*(array+k));
        packageprice += pkg.getPrice();
    }
    totalprice+=packageprice;
    display_price->clear();
    display_price->setText(QString::number(totalprice));

}
void MainWindow::packageprice_clearer(){
    totalprice-=packageprice;
    packageprice = 0;
    display_price->clear();
    display_price->setText(QString::number(totalprice));
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
    int pricepaid = price_paid->text().toInt();
    int dueamount = totalprice - pricepaid;

    QString a;
    QSqlQuery qry[8];

    if(room1_checkbox->isChecked()){
        a+="1,";
        qry[0].exec("update room set room_status = 'OCCUPIED' where room_no = 1");
    }
    if(room2_checkbox->isChecked()){
        a+="2,";
        qry[1].exec("update room set room_status = 'OCCUPIED' where room_no = 2");
    }
    if(room3_checkbox->isChecked()){
        a+="3,";
        qry[2].exec("update room set room_status = 'OCCUPIED' where room_no = 3");
    }
    if(room4_checkbox->isChecked()){
        a+="4,";
        qry[3].exec("update room set room_status = 'OCCUPIED' where room_no = 4");
    }
    if(room5_checkbox->isChecked()){
        a+="5,";
        qry[4].exec("update room set room_status = 'OCCUPIED' where room_no = 5");
    }
    if(room6_checkbox->isChecked()){
        a+="6,";
        qry[5].exec("update room set room_status = 'OCCUPIED' where room_no = 6");
    }
    if(room7_checkbox->isChecked()){
        a+="7,";
        qry[6].exec("update room set room_status = 'OCCUPIED' where room_no = 7");
    }
    if(room8_checkbox->isChecked()){
        a+="8,";
        qry[7].exec("update room set room_status = 'OCCUPIED' where room_no = 8");
    }
    a.chop(1);

    QSqlQuery query;
    query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
    query.addBindValue(a);
    query.addBindValue(name);
    query.addBindValue(email);
    query.addBindValue(phone);
    query.addBindValue(address);
    query.addBindValue(nationality);
    query.addBindValue(checkin);
    query.addBindValue(package);
    query.addBindValue(room[1]);
    query.addBindValue(totalprice);
    query.addBindValue(pricepaid);
    query.addBindValue(dueamount);

    if(!query.exec())
    {
        QMessageBox::warning(window(),"Database Error2","Not connected to database");
    } // Displays database error popup
    //value initializer for further use
    totalprice = 0;
    package_price = 0;
}

void MainWindow::totalprice_display1(){
    int room_price[8]; //euta lai matra banauna parne int
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room");
    for (int i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}
        if(room_1){
            if(room1_checkbox->isChecked()){
                totalprice += room_price[0];
                room_1=false;
            }
        }
        else{
            totalprice -= room_price[0];
            room_1=true;
    }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display2(){
    int room_price[8];
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room");
    for (int i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}
        if(room_2){
            if(room2_checkbox->isChecked()){
                totalprice += room_price[1];
                room_2=false;
            }
        }
        else{
            totalprice -= room_price[1];
            room_2=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display3(){
    int room_price[8];
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room");
    for (int i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}
        if(room_3){
            if(room3_checkbox->isChecked()){
                totalprice += room_price[2];
                room_3=false;
            }
        }
        else{
            totalprice -= room_price[2];
            room_3=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display4(){
    int room_price[8];
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room");
    for (int i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}
        if(room_4){
            if(room4_checkbox->isChecked()){
                totalprice += room_price[3];
                room_4=false;
            }
        }
        else{
            totalprice -= room_price[3];
            room_4=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display5(){
    int room_price[8];
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room");
    for (int i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}
        if(room_5){
            if(room5_checkbox->isChecked()){
                totalprice += room_price[4];
                room_5=false;
            }
        }
        else{
            totalprice -= room_price[4];
            room_5=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display6(){
    int room_price[8];
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room");
    for (int i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}
        if(room_6){
            if(room6_checkbox->isChecked()){
                totalprice += room_price[5];
                room_6=false;
            }
        }
        else{
            totalprice -= room_price[5];
            room_6=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display7(){
    int room_price[8];
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room");
    for (int i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}
        if(room_7){
            if(room7_checkbox->isChecked()){
                totalprice += room_price[6];
                room_7=false;
            }
        }
        else{
            totalprice -= room_price[6];
            room_7=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display8(){
    int room_price[8];
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room");
    for (int i=0;roomprice_qry.next();i++){room_price[i] =roomprice_qry.value(0).toInt();}
        if(room_8){
            if(room8_checkbox->isChecked()){
                totalprice += room_price[7];
                room_8=false;
            }
        }
        else{
            totalprice -= room_price[7];
            room_8=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display9(){
        int service_charge[6];
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price");
        for(int i=0;serviceprice_qry.next();i++){service_charge[i] = serviceprice_qry.value(0).toInt();}//database ko table aanusar serial wise data aaucha

        if(breakfast){
            if(breakfast_checkbox->isChecked()){
                totalprice += service_charge[0];
                breakfast=false;
            }
        }
        else{
            totalprice -= service_charge[0];
            breakfast=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display10(){
        int service_charge[6];
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price");
        for(int i=0;serviceprice_qry.next();i++){service_charge[i] = serviceprice_qry.value(0).toInt();}//database ko table aanusar serial wise data aaucha
        if(dinner){
            if(dinner_checkbox->isChecked()){
                totalprice += service_charge[1];
                dinner=false;
            }
        }
        else{
            totalprice -= service_charge[1];
            dinner=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display11(){
        int service_charge[6];
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price");
        for(int i=0;serviceprice_qry.next();i++){service_charge[i] = serviceprice_qry.value(0).toInt();}//database ko table aanusar serial wise data aaucha

        if(lunch){
            if(lunch_checkbox->isChecked()){
                totalprice += service_charge[2];
                lunch=false;
            }
        }
        else{
            totalprice -= service_charge[2];
            lunch=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display12(){
        int service_charge[6];
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price");
        for(int i=0;serviceprice_qry.next();i++){service_charge[i] = serviceprice_qry.value(0).toInt();}//database ko table aanusar serial wise data aaucha

        if(transportation){
            if(transportation_checkbox->isChecked()){
                totalprice += service_charge[3];
                transportation=false;
            }
        }
        else{
            totalprice -= service_charge[3];
            transportation=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display13(){
        int service_charge[6];
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price");
        for(int i=0;serviceprice_qry.next();i++){service_charge[i] = serviceprice_qry.value(0).toInt();}//database ko table aanusar serial wise data aaucha

        if(sim){
            if(sim_checkbox->isChecked()){
                totalprice += service_charge[4];
                sim=false;
            }
        }
        else{
            totalprice -= service_charge[4];
            sim=true;
        }

        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display14(){
        int service_charge[6];
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price");
        for(int i=0;serviceprice_qry.next();i++){service_charge[i] = serviceprice_qry.value(0).toInt();}//database ko table aanusar serial wise data aaucha

        if(guide){
            if(guide_checkbox->isChecked()){
                totalprice += service_charge[5];
                guide=false;
            }
        }
        else{
            totalprice -= service_charge[5];
            guide=true;
        }


    display_price->clear();
    display_price->setText(QString::number(totalprice));
}
