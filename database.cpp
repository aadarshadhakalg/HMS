#include "database.h"

Database::Database()
{

}

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
