#include "mainwindow.h"
#include <QProgressDialog>
#include "package.h"


QString Package::getName(){
    return this->name;
}

QString Package::getDetails(){
    return details;
}

double Package::getPrice(){
    return price;
}

QString Package::getCompany(){
    return company;
}

bool Package::isAvailable(){
    return available;
}

void Package::setName(QString name){
    this->name = name;
}

void Package::setDetails(QString details){
    this->details = details;
}
void Package::setCompany(QString company){
    this->company = company;
}
void Package::setPrice(int price){
    this->price = price;
}
void Package::setavailable(bool available){
    this->available = available;
}
