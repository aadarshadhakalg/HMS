#ifndef PACKAGE_H
#define PACKAGE_H
#include <QSqlDatabase>

class Package
{

private:
    QString name;
    QString details;
    int price;
    QString company;
    bool available;
    QSqlDatabase db;

public:
    QString getName();
    QString getDetails();
    int getPrice();
    QString getCompany();
    bool isAvailable();

    void setName(QString name);
    void setDetails(QString details);
    void setCompany(QString company);
    void setPrice(int price);
    void setavailable(bool available);
};

#endif // PACKAGE_H
