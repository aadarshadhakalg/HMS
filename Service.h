#ifndef SERVICE_H
#define SERVICE_H

#include "QString"

class service{
protected:
    int price;
    QString details;
    bool available;
public:
    virtual void setDetails(QString) = 0;
    virtual void setPrice(int) = 0;
    virtual void setavailable(){this->available = true;}
    QString getDetails(){return this->details;}
    int getPrice(){return this->price;}
    bool isAvailable(){return this->available;}
};

#endif // SERVICE_H
