#include "guest.h"

Guest::Guest()
{
}


/////////////////////////////////////////
/// GETTERS
////////////////////////////////////////////
/// ////////////////////////////////////////
/// ///////////////////////////////////////
///

QString Guest::getName(){
    return this->name;
}
QString Guest::getEmail(){
    return this->email;
}
QString Guest::getContact(){
    return this->contact;
}
QString Guest::getAddress(){
    return this->address;
}
QString Guest::getCheckin(){
    return this->checkin;
}
QString Guest::getCheckout(){
    return this->checkout;
}
QString Guest::getIdentity(){
    return this->identity;
}
QString Guest::getRoomType(){
    return this->room_type;
}
QString Guest::getStatus(){
    return this->status;
}
QString Guest::getPackages(){
    return this->packages;
}
int Guest::getTotalAmount(){
    return this->total_amount;
}
int Guest::getPaidAmount(){
    return this->paid_amount;
}
int Guest::getDueAmount(){
    return this->due_amount;
}

int Guest::getID(){
    return this->id;
}

int Guest::getRoomNo(){
    return this->room_no;
}

///////////////////////////////////////////////////
/// SETTERS
////////////////////////////////////////////////////
/// /////////////////////////////////////////////////.


void Guest::setName(QString name){
    this->name = name;
}

void Guest::setEmail(QString email){
    this->email = email;
}

void Guest::setContact(QString contact){
    this->contact = contact;
}

void Guest::setAddress(QString address){
    this->address = address;
}

void Guest::setCheckin(QString checkin){
    this->checkin = checkin;
}

void Guest::setCheckout(QString checkout){
    this->checkout = checkout;
}

void Guest::setIdentity(QString identity){
    this->identity = identity;
}

void Guest::setRoomType(QString room_type){
    this->room_type = room_type;
}

void Guest::setStatus(QString status){
    this->status = status;
}

void Guest::setPackages(QString packages){
    this->packages = packages;
}

void Guest::setTotalAmount(int total_amount){
    this->total_amount = total_amount;
}

void Guest::setPaidAmount(int amt){
    this->paid_amount = amt;
}

void Guest::setDueAmount(int amt){
    this->due_amount = amt;
}

void Guest::setID(int id){
    this->id = id;
}

void Guest::setRoomNo(int room_no){
    this->room_no = room_no;
}
