#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QVariant>
#include "package.h"
#include "guest.h"
#include "room.h"

class Database
{

private:
    QSqlDatabase db;
public:
            Database();
            void Database(){
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
            }

            bool connect(){
                if(db.open()){
                    return true;
                }else{
                    return false;
                }
            }

    Package inactivepackages[10];
    Package activepackages[10];

public:
    bool connectDB();
    QSqlDatabase getDB();
    void getAvailablePackages(Package activepackages[]);
    void getUnavailablePackages(Package inactivepackages[]);
    void addPackages(QString name, QString company, QString details, int price, bool available);
    void removePackages(int id);
    void makeAvailable(int id);
    void makeUnavailable(int id);
    void getRooms(Guest guests[]);
   // void getUsers(Room rooms[]);
};

#endif // DATABASE_H
