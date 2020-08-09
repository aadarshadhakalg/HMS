#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include "package.h"
#include "guest.h"
#include "room.h"


class Database
{

private:
    QSqlDatabase db;

public:
    Database();
    bool connectDB();
    QSqlDatabase getDB();
    void getPackages(Package packages[]);
    void getRooms(Guest guests[]);
    void getUsers(Room rooms[]);
};

#endif // DATABASE_H
