#ifndef CLASS_ROOM_H
#define CLASS_ROOM_H
#include <QSqlDatabase>
#include <QString>
#include "Service.h"

class Room: public service
{
public:
    Room(int);
    int number;
    QString type;
    //QString details;
    //int price;
    //bool available;
    void setType(QString);
    void setDetails(QString);
    void setPrice(int);
    void setavailable(QString);
    int operator +(int*);

};

#endif // CLASS_ROOM_H
