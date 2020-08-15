#include "database.h"

//Database::Database()
//{

//}

bool Database::connectDB(){
    // Setting up connection to MYSQL Database on Cloud
    //
    // Database configuration details
    // hostname: hms.cxsp6l8xtyqr.us-east-1.rds.amazonaws.com,
    // Port: 3306,
    // Database Name : hms,
    // Database Username: hms,
    // Database Password: password

    db = QSqlDatabase::addDatabase("QMYSQL"); // Initializing Database, QMYSQL is MySQL database driver for QT.
    db.setHostName("hms.cxsp6l8xtyqr.us-east-1.rds.amazonaws.com"); // Setting hostname
    db.setPort(3306); // setting port
    db.setDatabaseName("hms"); // setting database name
    db.setUserName("hms"); //setting username
    db.setPassword("password"); //setting password
    if(db.open()){
        return true;
    }else{ // If database connection is not established
        return false;
    }
}


QSqlDatabase Database::getDB(){
    return db;
}

void Database::getAvailablePackages(Package packages[]){
    QSqlQuery query;
    if(query.exec("SELECT * FROM packages WHERE available = 1")){
        for(int i = 0; query.next(); i++){
            Package pkg;
            pkg.setName(query.value(1).toString());
            pkg.setCompany(query.value(2).toString());
            pkg.setDetails(query.value(3).toString());
            pkg.setPrice(query.value(4).toInt());
            pkg.setavailable(true);
            packages[i] = pkg;
        }
    }
}



void Database::getUnavailablePackages(Package packages[]){
    QSqlQuery query;
    if(query.exec("SELECT * FROM packages WHERE available = 0")){
        for(int i = 0; query.next(); i++){
            Package pkg;
            pkg.setName(query.value(1).toString());
            pkg.setCompany(query.value(2).toString());
            pkg.setDetails(query.value(3).toString());
            pkg.setPrice(query.value(4).toInt());
            pkg.setavailable(false);
            packages[i] = pkg;
        }
    }
}

void Database::addPackages(QString name, QString company, QString details, int price, bool available){
    QSqlQuery query;
    int avail = available ? 1 : 0;
    query.prepare("INSERT INTO packages(name,company,details,price,available) "
                      "VALUES (:name, :company, :details, :price, :available)");
    query.bindValue(":name", name);
    query.bindValue(":company", company);
    query.bindValue(":details", details);
    query.bindValue(":price", price);
    query.bindValue(":available",avail);
    query.exec();
}
