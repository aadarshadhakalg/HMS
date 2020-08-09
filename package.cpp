#include "package.h"

Package::Package(QSqlDatabase db)
{
    this->db = db;
}


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
