#ifndef CLASS_ROOM_H
#define CLASS_ROOM_H
#include <QSqlDatabase>
#include <QString>
class Room
{
public:
    Room();
    bool IsUnOccupied() ;
private:
     QString type;
    int no_of_beds;
    bool wifi,tv,couple_friendly;
    QString details;
    double price;
    QSqlDatabase db;
    bool available;
    // Database Current_Guest;

};

#endif // CLASS_ROOM_H
