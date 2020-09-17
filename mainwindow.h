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

    void package_price_adder(std::string);
    void totalprice_calculator(int);
    int totalprice = 0;
    QLineEdit* display_price;
    int roomBtn_select;//for room details showing
    QString room[5];

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
    void room_details();

    void totalprice_display(int);
    //slots for room details
    void room1();
    void room2();
    void room3();
    void room4();
    void room5();
    void room6();
    void room7();
    void room8();
private:
    //for room booking
    QLineEdit *customer_name;
    QLineEdit *customer_email;
    QLineEdit *customer_phone;
    QLineEdit *customer_address;
    QLineEdit *customer_nationality;
    QLineEdit *package_id;
    QSqlTableModel *qrymodel;

    QCheckBox *room1_checkbox;
    QCheckBox *room2_checkbox;
    QCheckBox *room3_checkbox;
    QCheckBox *room4_checkbox;
    QCheckBox *room5_checkbox;
    QCheckBox *room6_checkbox;
    QCheckBox *room7_checkbox;
    QCheckBox *room8_checkbox;

    //for master control
    QLineEdit *emailText;
    QLineEdit *passwordText;
    QWidget *rightside;
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
};

#endif // MAINWINDOW_H
