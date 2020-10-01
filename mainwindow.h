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
#include <sstream>
#include <string>
#include <vector>

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

    int totalprice = 0;
    int pricepaid = 0;
    QLineEdit* display_price;
    QString room[5];//for room details
    QLineEdit* price_paid;
    int roomBtn_select;//for room details showing
    int packageprice = 0;
    bool daysprice_addable = true;
    void checkout(int);
    int Guest_id_cout ;
    int Guest_room_cout ;
    int guestPaid;
    bool unavailable_room1, unavailable_room2, unavailable_room3, unavailable_room4, unavailable_room5, unavailable_room6, unavailable_room7, unavailable_room8;
    bool book_successful = false;

signals:
    void loggedIn();
    void dbready();
    void bookingSuccess();

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
    void room_details();
    void totalprice_display1();
    void totalprice_display2();
    void totalprice_display3();
    void totalprice_display4();
    void totalprice_display5();
    void totalprice_display6();
    void totalprice_display7();
    void totalprice_display8();
    void totalprice_display9();
    void totalprice_display10();
    void totalprice_display11();
    void totalprice_display12();
    void totalprice_display13();
    void totalprice_display14();
    void packageprice_adder();
    void packageprice_clearer();
    void daysstayed_priceadder();
    void daysstayed_priceclearer();
    void checkout_now();
//    void room();
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

    QCheckBox *room1_checkbox;
    QCheckBox *room2_checkbox;
    QCheckBox *room3_checkbox;
    QCheckBox *room4_checkbox;
    QCheckBox *room5_checkbox;
    QCheckBox *room6_checkbox;
    QCheckBox *room7_checkbox;
    QCheckBox *room8_checkbox;
    QCheckBox *sim_checkbox;
    QCheckBox *guide_checkbox;
    QCheckBox *transportation_checkbox;
    QCheckBox *lunch_checkbox;
    QCheckBox *dinner_checkbox;
    QCheckBox *breakfast_checkbox;

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

    QLineEdit *days_staying;//for total days stayed

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
