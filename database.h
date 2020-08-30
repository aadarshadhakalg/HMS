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
    void getUsers(Room rooms[]);
};

#endif // DATABASE_H
