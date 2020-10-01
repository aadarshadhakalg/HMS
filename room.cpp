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
void MainWindow::daysstayed_priceadder(){
    if(daysprice_addable == true){
        totalprice-=packageprice;
        totalprice*=days_staying->text().toInt();
        totalprice+=packageprice;
        display_price->clear();
        display_price->setText(QString::number(totalprice));
        daysprice_addable = false;
    }
}
void MainWindow::daysstayed_priceclearer(){
    if(daysprice_addable == false){
        totalprice-=packageprice;
        totalprice/=days_staying->text().toInt();
        totalprice+=packageprice;
        display_price->clear();
        display_price->setText(QString::number(totalprice));
        daysprice_addable = true;
    }
}


// Defining //

void MainWindow::bookButton_clicked(){

    QString name,email,address,nationality,phone,package;
    email = MainWindow::customer_email->text(); // fetch input text from email input field of loginscreen
    phone = MainWindow::customer_phone->text();
    bool email_check = false, phone_check = false;

    QRegularExpression emailrx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+.[A-Z]{2,4}\\b",
                               QRegularExpression::CaseInsensitiveOption);

    QRegularExpression phonerx("^[0-9]{10}$",
                               QRegularExpression::CaseInsensitiveOption);

    if(!emailrx.match(email).hasMatch()){
        QMessageBox::warning(this,"Invalid Email","OOPS! Email address is not valid");
        email_check = true;
    } else if(!phonerx.match(phone).hasMatch()){
        QMessageBox::warning(this,"Invalid Phone","OOPS! Input valid phone number!");
        phone_check = true;
    } else {

//    if(){
//
        name = MainWindow::customer_name->text();  // fetch input text from password input field of loginscreen
        address = MainWindow::customer_address->text();
        nationality = MainWindow::customer_nationality->text();
        QDateTime checkin = QDateTime::currentDateTime();
        package = MainWindow::package_id->text();
        int pricepaid = price_paid->text().toInt();
        int dueamount = totalprice - pricepaid;

        QSqlQuery room_qry;
        room_qry.exec("select room_type from room");
        room_qry.next();
        QString room_type[8];
        for (int i=0; i<8; i++){
            room_type[i] = room_qry.value(0).toString();
            room_qry.next();
        }

        if(room1_checkbox->isChecked()){
            QSqlQuery query,qry;
            query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                        "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
            query.addBindValue(1);
            query.addBindValue(name);
            query.addBindValue(email);
            query.addBindValue(phone);
            query.addBindValue(address);
            query.addBindValue(nationality);
            query.addBindValue(checkin);
            query.addBindValue(package);
            query.addBindValue(room_type[0]);
            query.addBindValue(totalprice);
            query.addBindValue(pricepaid);
            query.addBindValue(dueamount);
            query.exec();
            qry.exec("update room set room_status = 'OCCUPIED' where room_no = 1");
        }
        if(room2_checkbox->isChecked()){
            QSqlQuery query,qry;
            query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                        "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
            query.addBindValue(2);
            query.addBindValue(name);
            query.addBindValue(email);
            query.addBindValue(phone);
            query.addBindValue(address);
            query.addBindValue(nationality);
            query.addBindValue(checkin);
            query.addBindValue(package);
            query.addBindValue(room_type[1]);
            query.addBindValue(totalprice);
            query.addBindValue(pricepaid);
            query.addBindValue(dueamount);
            query.exec();
            qry.exec("update room set room_status = 'OCCUPIED' where room_no = 2");
        }
        if(room3_checkbox->isChecked()){
            QSqlQuery query,qry;
            query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                        "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
            query.addBindValue(3);
            query.addBindValue(name);
            query.addBindValue(email);
            query.addBindValue(phone);
            query.addBindValue(address);
            query.addBindValue(nationality);
            query.addBindValue(checkin);
            query.addBindValue(package);
            query.addBindValue(room_type[2]);
            query.addBindValue(totalprice);
            query.addBindValue(pricepaid);
            query.addBindValue(dueamount);
            query.exec();
            qry.exec("update room set room_status = 'OCCUPIED' where room_no = 3");
        }
        if(room4_checkbox->isChecked()){
            QSqlQuery query,qry;
            query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                        "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
            query.addBindValue(4);
            query.addBindValue(name);
            query.addBindValue(email);
            query.addBindValue(phone);
            query.addBindValue(address);
            query.addBindValue(nationality);
            query.addBindValue(checkin);
            query.addBindValue(package);
            query.addBindValue(room_type[3]);
            query.addBindValue(totalprice);
            query.addBindValue(pricepaid);
            query.addBindValue(dueamount);
            query.exec();
            qry.exec("update room set room_status = 'OCCUPIED' where room_no = 4");
        }
        if(room5_checkbox->isChecked()){
            QSqlQuery query,qry;
            query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                        "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
            query.addBindValue(5);
            query.addBindValue(name);
            query.addBindValue(email);
            query.addBindValue(phone);
            query.addBindValue(address);
            query.addBindValue(nationality);
            query.addBindValue(checkin);
            query.addBindValue(package);
            query.addBindValue(room_type[4]);
            query.addBindValue(totalprice);
            query.addBindValue(pricepaid);
            query.addBindValue(dueamount);
            query.exec();
            qry.exec("update room set room_status = 'OCCUPIED' where room_no = 5");
        }
        if(room6_checkbox->isChecked()){
            QSqlQuery query,qry;
            query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                        "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
            query.addBindValue(6);
            query.addBindValue(name);
            query.addBindValue(email);
            query.addBindValue(phone);
            query.addBindValue(address);
            query.addBindValue(nationality);
            query.addBindValue(checkin);
            query.addBindValue(package);
            query.addBindValue(room_type[5]);
            query.addBindValue(totalprice);
            query.addBindValue(pricepaid);
            query.addBindValue(dueamount);
            query.exec();
            qry.exec("update room set room_status = 'OCCUPIED' where room_no = 6");
        }
        if(room7_checkbox->isChecked()){
            QSqlQuery query,qry;
            query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                        "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
            query.addBindValue(7);
            query.addBindValue(name);
            query.addBindValue(email);
            query.addBindValue(phone);
            query.addBindValue(address);
            query.addBindValue(nationality);
            query.addBindValue(checkin);
            query.addBindValue(package);
            query.addBindValue(room_type[6]);
            query.addBindValue(totalprice);
            query.addBindValue(pricepaid);
            query.addBindValue(dueamount);
            query.exec();
            qry.exec("update room set room_status = 'OCCUPIED' where room_no = 7");
        }
        if(room8_checkbox->isChecked()){
            QSqlQuery query,qry;
            query.prepare("INSERT INTO hms.guests (room_no, name, email, contact, address, identity, checkin, packages, room_type, total_amount, paid_amount, due_amount)"
                        "VALUES (?,?,?,?,?,?,?,?,?,?,?,?);");
            query.addBindValue(8);
            query.addBindValue(name);
            query.addBindValue(email);
            query.addBindValue(phone);
            query.addBindValue(address);
            query.addBindValue(nationality);
            query.addBindValue(checkin);
            query.addBindValue(package);
            query.addBindValue(room_type[7]);
            query.addBindValue(totalprice);
            query.addBindValue(pricepaid);
            query.addBindValue(dueamount);
            query.exec();
            qry.exec("update room set room_status = 'OCCUPIED' where room_no = 8");
        }
        totalprice = 0;
        package_price = 0;
        QMessageBox msgBox;
        msgBox.setText("Room booked successfully");
        connect(this,SIGNAL(bookingSuccess()),this,SLOT(Roommain()));
        emit bookingSuccess();
        email_check = false;
        phone_check = false;
    }
//    else{
//        book_successful = false;
//    }
}

void MainWindow::totalprice_display1(){
    int room_price;
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room where room_no = 1");
    roomprice_qry.first();
    room_price =roomprice_qry.value(0).toInt();
            if(room1_checkbox->isChecked()){
                totalprice += room_price;
                room2_checkbox->setEnabled(false);
                room3_checkbox->setEnabled(false);
                room4_checkbox->setEnabled(false);
                room5_checkbox->setEnabled(false);
                room6_checkbox->setEnabled(false);
                room7_checkbox->setEnabled(false);
                room8_checkbox->setEnabled(false);
            }
        else{
                if(!unavailable_room2){room2_checkbox->setEnabled(true);}
                if(!unavailable_room3){room3_checkbox->setEnabled(true);}
                if(!unavailable_room4){room4_checkbox->setEnabled(true);}
                if(!unavailable_room5){room5_checkbox->setEnabled(true);}
                if(!unavailable_room6){room6_checkbox->setEnabled(true);}
                if(!unavailable_room7){room7_checkbox->setEnabled(true);}
                if(!unavailable_room8){room8_checkbox->setEnabled(true);}
            totalprice -= room_price;
    }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display2(){
    int room_price;
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room where room_no = 2");
    roomprice_qry.first();
    room_price =roomprice_qry.value(0).toInt();
            if(room2_checkbox->isChecked()){
                totalprice += room_price;
                room1_checkbox->setEnabled(false);
                room3_checkbox->setEnabled(false);
                room4_checkbox->setEnabled(false);
                room5_checkbox->setEnabled(false);
                room6_checkbox->setEnabled(false);
                room7_checkbox->setEnabled(false);
                room8_checkbox->setEnabled(false);
            }
        else{
            totalprice -= room_price;
            if(!unavailable_room1){room1_checkbox->setEnabled(true);}
            if(!unavailable_room3){room3_checkbox->setEnabled(true);}
            if(!unavailable_room4){room4_checkbox->setEnabled(true);}
            if(!unavailable_room5){room5_checkbox->setEnabled(true);}
            if(!unavailable_room6){room6_checkbox->setEnabled(true);}
            if(!unavailable_room7){room7_checkbox->setEnabled(true);}
            if(!unavailable_room8){room8_checkbox->setEnabled(true);}
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display3(){
    int room_price;
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room where room_no = 3");
    roomprice_qry.first();
    room_price =roomprice_qry.value(0).toInt();
            if(room3_checkbox->isChecked()){
                totalprice += room_price;
                room1_checkbox->setEnabled(false);
                room2_checkbox->setEnabled(false);
                room4_checkbox->setEnabled(false);
                room5_checkbox->setEnabled(false);
                room6_checkbox->setEnabled(false);
                room7_checkbox->setEnabled(false);
                room8_checkbox->setEnabled(false);
            }
        else{
            totalprice -= room_price;
            if(!unavailable_room1){room1_checkbox->setEnabled(true);}
            if(!unavailable_room2){room2_checkbox->setEnabled(true);}
            if(!unavailable_room4){room4_checkbox->setEnabled(true);}
            if(!unavailable_room5){room5_checkbox->setEnabled(true);}
            if(!unavailable_room6){room6_checkbox->setEnabled(true);}
            if(!unavailable_room7){room7_checkbox->setEnabled(true);}
            if(!unavailable_room8){room8_checkbox->setEnabled(true);}
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display4(){
    int room_price;
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room where room_no = 4");
    roomprice_qry.first();
    room_price =roomprice_qry.value(0).toInt();
            if(room4_checkbox->isChecked()){
                totalprice += room_price;
                room1_checkbox->setEnabled(false);
                room2_checkbox->setEnabled(false);
                room3_checkbox->setEnabled(false);
                room5_checkbox->setEnabled(false);
                room6_checkbox->setEnabled(false);
                room7_checkbox->setEnabled(false);
                room8_checkbox->setEnabled(false);
            }
        else{
            totalprice -= room_price;
            if(!unavailable_room1){room1_checkbox->setEnabled(true);}
            if(!unavailable_room2){room2_checkbox->setEnabled(true);}
            if(!unavailable_room3){room3_checkbox->setEnabled(true);}
            if(!unavailable_room5){room5_checkbox->setEnabled(true);}
            if(!unavailable_room6){room6_checkbox->setEnabled(true);}
            if(!unavailable_room7){room7_checkbox->setEnabled(true);}
            if(!unavailable_room8){room8_checkbox->setEnabled(true);}
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display5(){
    int room_price;
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room where room_no = 5");
    roomprice_qry.first();
    room_price =roomprice_qry.value(0).toInt();
            if(room5_checkbox->isChecked()){
                totalprice += room_price;
                room1_checkbox->setEnabled(false);
                room2_checkbox->setEnabled(false);
                room3_checkbox->setEnabled(false);
                room4_checkbox->setEnabled(false);
                room6_checkbox->setEnabled(false);
                room7_checkbox->setEnabled(false);
                room8_checkbox->setEnabled(false);
            }
        else{
            totalprice -= room_price;
            if(!unavailable_room1){room1_checkbox->setEnabled(true);}
            if(!unavailable_room2){room2_checkbox->setEnabled(true);}
            if(!unavailable_room3){room3_checkbox->setEnabled(true);}
            if(!unavailable_room4){room4_checkbox->setEnabled(true);}
            if(!unavailable_room6){room6_checkbox->setEnabled(true);}
            if(!unavailable_room7){room7_checkbox->setEnabled(true);}
            if(!unavailable_room8){room8_checkbox->setEnabled(true);}
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display6(){
    int room_price;
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room where room_no = 6");
    roomprice_qry.first();
    room_price =roomprice_qry.value(0).toInt();
            if(room6_checkbox->isChecked()){
                totalprice += room_price;
                room1_checkbox->setEnabled(false);
                room2_checkbox->setEnabled(false);
                room3_checkbox->setEnabled(false);
                room4_checkbox->setEnabled(false);
                room5_checkbox->setEnabled(false);
                room7_checkbox->setEnabled(false);
                room8_checkbox->setEnabled(false);
            }
        else{
            totalprice -= room_price;
            if(!unavailable_room1){room1_checkbox->setEnabled(true);}
            if(!unavailable_room2){room2_checkbox->setEnabled(true);}
            if(!unavailable_room3){room3_checkbox->setEnabled(true);}
            if(!unavailable_room4){room4_checkbox->setEnabled(true);}
            if(!unavailable_room5){room5_checkbox->setEnabled(true);}
            if(!unavailable_room7){room7_checkbox->setEnabled(true);}
            if(!unavailable_room8){room8_checkbox->setEnabled(true);}
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display7(){
    int room_price;
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room where room_no = 7");
    roomprice_qry.first();
    room_price =roomprice_qry.value(0).toInt();
            if(room7_checkbox->isChecked()){
                totalprice += room_price;
                room1_checkbox->setEnabled(false);
                room2_checkbox->setEnabled(false);
                room3_checkbox->setEnabled(false);
                room4_checkbox->setEnabled(false);
                room5_checkbox->setEnabled(false);
                room6_checkbox->setEnabled(false);
                room8_checkbox->setEnabled(false);
            }
        else{
            totalprice -= room_price;
            if(!unavailable_room1){room1_checkbox->setEnabled(true);}
            if(!unavailable_room2){room2_checkbox->setEnabled(true);}
            if(!unavailable_room3){room3_checkbox->setEnabled(true);}
            if(!unavailable_room4){room4_checkbox->setEnabled(true);}
            if(!unavailable_room5){room5_checkbox->setEnabled(true);}
            if(!unavailable_room6){room6_checkbox->setEnabled(true);}
            if(!unavailable_room8){room8_checkbox->setEnabled(true);}
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display8(){
    int room_price;
    QSqlQuery roomprice_qry(db);
    roomprice_qry.exec("SELECT room_price FROM room where room_no =8");
    roomprice_qry.first();
    room_price =roomprice_qry.value(0).toInt();
            if(room8_checkbox->isChecked()){
                totalprice += room_price;
                room1_checkbox->setEnabled(false);
                room2_checkbox->setEnabled(false);
                room3_checkbox->setEnabled(false);
                room4_checkbox->setEnabled(false);
                room5_checkbox->setEnabled(false);
                room6_checkbox->setEnabled(false);
                room7_checkbox->setEnabled(false);
        }
        else{
            totalprice -= room_price;
            if(!unavailable_room1){room1_checkbox->setEnabled(true);}
            if(!unavailable_room2){room2_checkbox->setEnabled(true);}
            if(!unavailable_room3){room3_checkbox->setEnabled(true);}
            if(!unavailable_room4){room4_checkbox->setEnabled(true);}
            if(!unavailable_room5){room5_checkbox->setEnabled(true);}
            if(!unavailable_room6){room6_checkbox->setEnabled(true);}
            if(!unavailable_room7){room7_checkbox->setEnabled(true);}
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display9(){
        int service_charge;
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price where services = 'breakfast'");
        serviceprice_qry.first();
        service_charge = serviceprice_qry.value(0).toInt();
            if(breakfast_checkbox->isChecked()){
                totalprice += service_charge;
            }
        else{
            totalprice -= service_charge;
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display10(){
        int service_charge;
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price where services = 'dinner'");
        serviceprice_qry.first();
        service_charge = serviceprice_qry.value(0).toInt();
            if(dinner_checkbox->isChecked()){
                totalprice += service_charge;
            }
        else{
            totalprice -= service_charge;
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display11(){
        int service_charge;
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price where services = 'lunch'");
        serviceprice_qry.first();
        service_charge = serviceprice_qry.value(0).toInt();
            if(lunch_checkbox->isChecked()){
                totalprice += service_charge;
            }
        else{
            totalprice -= service_charge;
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display12(){
        int service_charge;
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price where services = 'transportation'");
        serviceprice_qry.first();
        service_charge = serviceprice_qry.value(0).toInt();
        if(transportation_checkbox->isChecked()){
            totalprice += service_charge;
        }
        else{
            totalprice -= service_charge;
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display13(){
        int service_charge;
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price where services = 'sim'");
        service_charge = serviceprice_qry.value(0).toInt();
            if(sim_checkbox->isChecked()){
                totalprice += service_charge;
            }
        else{
            totalprice -= service_charge;
        }
        display_price->clear();
        display_price->setText(QString::number(totalprice));
}
void MainWindow::totalprice_display14(){
        int service_charge;
        QSqlQuery serviceprice_qry(db);
        serviceprice_qry.exec("SELECT price FROM service_price where services = 'guide'");
        service_charge = serviceprice_qry.value(0).toInt();
            if(guide_checkbox->isChecked()){
                totalprice += service_charge;
            }
        else{
            totalprice -= service_charge;
        }
    display_price->clear();
    display_price->setText(QString::number(totalprice));
}
