#include "database.h"
#include "QDebug"
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

//void Database::getAvailablePackages(Package packages[]){
//    QSqlQuery query;
//    if(query.exec("SELECT * FROM packages WHERE available = 1")){
//        for(int i = 0; query.next(); i++){
//            Package pkg;
//            pkg.setName(query.value(1).toString());
//            pkg.setCompany(query.value(2).toString());
//            pkg.setDetails(query.value(3).toString());
//            pkg.setPrice(query.value(4).toInt());
//            pkg.setavailable(true);
//            packages[i] = pkg;
//        }
//    }
//}



//void Database::getUnavailablePackages(Package packages[]){
//    QSqlQuery query;
//    if(query.exec("SELECT * FROM packages WHERE available = 0")){
//        for(int i = 0; query.next(); i++){
//            Package pkg;
//            pkg.setName(query.value(1).toString());
//            pkg.setCompany(query.value(2).toString());
//            pkg.setDetails(query.value(3).toString());
//            pkg.setPrice(query.value(4).toInt());
//            pkg.setavailable(false);
//            packages[i] = pkg;
//        }
//    }
//}

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

bool Database::removePackages(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM packages WHERE id=:id");
    query.bindValue(":id", id);
    if(query.exec()){
        return true;
    }else {
    return false;
}
}

Package Database::getPackageByID(int id){
    Package pkg;
    QSqlQuery query;
    query.prepare("SELECT * FROM packages WHERE id=:id");
    query.bindValue(":id", id);
    if(query.exec()){
            query.next();
            pkg.setName(query.value(1).toString());
            pkg.setCompany(query.value(2).toString());
            pkg.setDetails(query.value(3).toString());
            pkg.setPrice(query.value(4).toInt());
            pkg.setavailable(false);
    }
    return pkg;
}


// TO Get Package Price
// Create Database instance          Database db;
// Get Package,                      Package pkg = db.getPackageByID(PASS ID OF PACKAGE YOU WANT TO GET DETAIL);
// This returns package and saves it in pkg variable
// Get package details by tapping in to packages methods like :

// pkg.getName;   Returns Qstring;
// pkg.getDetails; Returns Qstring;
// pkg.getPrice; Returns double;
// pkg.isAvailable; Returns bool;
// pkg.setCompany; Returns Qstring;





Guest Database::getGuestDetailByRoomNo(int no){
    Guest guest;
    QSqlQuery query;
    query.prepare("SELECT * FROM guests WHERE room_no=:no and status='Active'");
    query.bindValue(":no", no);
    if(query.exec()){
        guest.setID(query.value(0).toInt());
        guest.setRoomNo(query.value(1).toInt());
        guest.setName(query.value(2).toString());
        guest.setEmail(query.value(3).toString());
        guest.setContact(query.value(4).toString());
        guest.setAddress(query.value(5).toString());
        guest.setCheckin(query.value(6).toString());
        guest.setCheckout(query.value(7).toString());
        guest.setIdentity(query.value(8).toString());
        guest.setRoomType(query.value(9).toString());
        guest.setTotalAmount(query.value(10).toInt());
        guest.setPaidAmount(query.value(11).toInt());
        guest.setDueAmount(query.value(12).toInt());
        guest.setStatus(query.value(13).toString());
        guest.setPackages(query.value(14).toString());

    }
    return guest;
}

// Database db;
// Guest guest = db.getGuestDetailByRoomNo(room_no);
//
// guest.getName()           returns guest name
// guest.getEmail()          for email
// guest.getAddress          for Address
// and similarly other

bool Database::guestCheckOut(int id){
    QSqlQuery query;
    query.prepare("UPDATE guests SET status='InActive' WHERE id=:id");
    query.bindValue(":id",id);
    if(query.exec()){
        return true;
    }else {
        return false;
    }
}

// Database db;
// db.guestCheckOut(guest_id);

bool Database::isCheckOutAble(int id){
    QSqlQuery query;
    query.prepare("SELECT due_amount FROM guests where if=:id");
    query.bindValue(":id",id);
    if(query.exec()){
        int da = query.value(0).toInt();
        if(da == 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// Database db;
// db.isCheckOutAble(guest_id);


bool Database::payAmount(int amount, int id){
    QSqlQuery query;
    int ta, pa, da;
    query.prepare("SELECT * FROM guests where id=:id");
    query.bindValue(":id",id);
    if(query.exec()){
        ta = query.value(10).toInt();
        pa = query.value(11).toInt();
        da = query.value(12).toInt();

        if((pa + amount) > ta){
            return false;
        }else{
            query.prepare("UPDATE guests SET paid_amount=:npa and due_amount=:nda WHERE id=:id");
            query.bindValue(":npa",pa+amount);
            query.bindValue(":nda",da-amount);
            query.bindValue(":id",id);
            if(query.exec()){
                return true;
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
}

// Database db;
// db.payAmount(amount to pay);

