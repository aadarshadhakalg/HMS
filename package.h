#ifndef PACKAGE_H
#define PACKAGE_H
#include <QSqlDatabase>
#include "Service.h"

class Package:public service
{

private:
    QString name;
    QString company;
    QSqlDatabase db;

public:
    QString getName();
    //QString getDetails();
    //int getPrice();
    QString getCompany();
    //bool isAvailable();

    void setName(QString name);
    void setDetails(QString details);
    void setCompany(QString company);
    void setPrice(int price);
    void setavailable(bool available);
};

#endif // PACKAGE_H
