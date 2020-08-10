#ifndef CLASS_ROOM_H
#define CLASS_ROOM_H

#include <iostream>

class class_room
{
public:
    class_room();
    void Checkin() ;
    void Checkout() ;
    void IsUnOccupied() ;
    void roomdetail();


private:
    std::string type;
    int no_of_beds;
    bool wifi,tv,couple_friendly;
    std::string details;
    double price;
    // Database Current_Guest;

};

#endif // CLASS_ROOM_H
