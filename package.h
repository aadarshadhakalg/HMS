#ifndef PACKAGE_H
#define PACKAGE_H
#include <QSqlDatabase>

class Package
{

private:
    QString name;
    QString details;
    double price;
    QString company;
    bool available;
    QSqlDatabase db;

public:
    Package(QSqlDatabase db);

    QString getName();

    QString getDetails();

    double getPrice();

    QString getCompany();

    bool isAvailable();
};

#endif // PACKAGE_H
