#include <QString>

#ifndef GUEST_H
#define GUEST_H


class Guest
{
public:
    Guest();
    QString getName();
    QString getEmail();
    QString getContact();
    QString getAddress();
    QString getCheckin();
    QString getCheckout();
    QString getIdentity();
    QString getRoomType();
    QString getStatus();
    QString getPackages();
    int getTotalAmount();
    int getPaidAmount();
    int getDueAmount();
    int getRoomNo();
    int getID();

    void setName(QString name);
    void setEmail(QString email);
    void setContact(QString contact);
    void setAddress(QString address);
    void setCheckin(QString checkin);
    void setCheckout(QString checkout);
    void setIdentity(QString identity);
    void setRoomType(QString room_type);
    void setStatus(QString status);
    void setPackages(QString packages);
    void setTotalAmount(int total_amount);
    void setPaidAmount(int paid_amount);
    void setDueAmount(int due_amount);
    void setRoomNo(int room_no);
    void setID(int id);


private:
    int id;
    int room_no;
    QString name;
    QString email;
    QString contact;
    QString address;
    QString checkin;
    QString checkout;
    QString identity;
    QString room_type;
    int total_amount;
    int paid_amount;
    int due_amount;
    QString status;
    QString packages;
};

#endif // GUEST_H
