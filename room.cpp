#include "room.h"
#include <QProgressDialog>
#include <iostream>
#include "mainwindow.h"
#include "database.h"
#include <QDateTime>
#include <QString>
using namespace std;

Room::Room(int n){
    this->number = n;
    QSqlQuery query;
    query.prepare("SELECT * FROM room WHERE room_no=:id");
    query.bindValue(":id", n);
    if(query.exec()){
            query.first();
            this->setType(query.value(1).toString());
            this->setDetails(query.value(2).toString());
            this->setPrice(query.value(3).toInt());
            this->setavailable(query.value(4).toString());
    }
}

void Room::setType(QString t){
    this->type = t;
}

void Room::setPrice(int i){
    this->price = i;
}

void Room::setDetails(QString d){
    this->details = d;
}

void Room::setavailable(QString a){
    if(a == "OCCUPIED"){
        this->available = false;
    }
    else{
        this->available = true;
    }
}

int Room::operator+(int* i){
    return (*i)+=this->price;
}
