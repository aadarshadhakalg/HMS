#include "room.h"

Room::Room()
{


}


void Room::Checkin()
{

}

void Room::Checkout()
{

}

bool Room::IsUnOccupied()
{
    return available;

}




QString Room::getRooms(){
    return type;
    return details;
    QString room_price;
    room_price =this->price;
    return room_price;

}
QString Room:: getName(){
    //return getguest.name();
}

QString Room:: getDetails() {
    if(wifi)
    {

    }
    if(tv)
    {

    }

    if(couple_friendly)
    {

    }
    return details;
}
