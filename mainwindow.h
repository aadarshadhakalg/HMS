#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QString>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QLayout>
#include <QBoxLayout>
#include <QLineEdit>
#include <QMovie>
#include <QtWidgets>
#include <QSizePolicy>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QComboBox>
#include "package.h"
#include "database.h"

class QAction;
class QActionGroup;
class QLabel;
class QMenu;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int Guest_id_cout ;
    int Guest_room_cout ;
    void totalprice_calculator(int);
    int totalprice = 0 ;
    QLineEdit* display_price;
    int roomBtn_select;
    void checkout(int);
    int guestPaid;

signals:
    void loggedIn();
    void dbready();

// SLOTS
private slots:
    void loginScreen();
    void homeScreen();
    void dashboard();
    void loginButton_clicked();
    void save();
    void contact();
    void question();
    void style();
    void search();
    void editTable();
    void noEditTable();
    void Bill();
    void Customer();
    void PackageScreen();
    void roombooking();
    void Roommain();
    void bookButton_clicked();
    void checkout_now();
    void room();
    void payNow();
    //slots for room details
    void room1();
    void room2();
    void room3();
    void room4();
    void room5();
    void room6();
    void room7();
    void room8();
    void addPackage();
    void removePackage();
    void sendAddRequest();
    void sendRemoveRequest();

private:
    //for room booking
    QLineEdit *customer_name;
    QLineEdit *customer_email;
    QLineEdit *customer_phone;
    QLineEdit *customer_address;
    QLineEdit *customer_nationality;
    QSqlTableModel *qrymodel;

    //for master control
    QLineEdit *emailText;
    QLineEdit *passwordText;
    QWidget *rightside;
    QWidget *bottom_half;
    QLineEdit *searchField;
    QPushButton *editButton;
    QPushButton *noEditButton;
    QWidget *guesttable();
    void Action();
    void MenuItem();
    QMenu *file;
    QMenu *help;
    QMenu *about;
    QAction *saveAct;
    QAction *contactAct;
    QAction *QuesAct;
    QFormLayout *main_layout ;
    QLabel *managerLabel;
    QLabel *infoLabel;
    QPushButton *managerBtn ;
    QLabel *label;
    QSqlDatabase db;
    QSqlTableModel *model;

    //for adding package
    QLineEdit *package_id;
    QCheckBox *package_available;
    QLineEdit *package_name;
    QLineEdit *package_company;
    QLineEdit *package_details;
    QLineEdit *package_price;
    QLineEdit *package_edit;

    //checkOut Screen ( To get selected room ID )
    QLabel *checkoutSelectedRoomID;
//    QVBoxLayout *billlayout;
    QLineEdit *Pay_amount;
    QLabel *Paid;
    QLabel *Due;
};

#endif // MAINWINDOW_H
