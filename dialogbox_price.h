#ifndef DIALOGBOX_PRICE_H
#define DIALOGBOX_PRICE_H
#include <QDialog>
#include <QLineEdit>
#include "mainwindow.h"
class QLabel;
class QPushButton;

class dialogbox_price : public QDialog
{
    Q_OBJECT
public:
    dialogbox_price(MainWindow);
private:
    QLabel* label11;
    QLabel* label12;
    QLabel* label2;
    QLineEdit* paying_price;
    QPushButton* Book;
};

#endif // DIALOGBOX_PRICE_H
