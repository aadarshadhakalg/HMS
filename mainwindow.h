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
    void guesttable();
    void search();
    void editTable();
    void noEditTable();

// TO Fetch Line Text Data from another Function
private:
    QLineEdit *emailText;
    QLineEdit *passwordText;
    QLineEdit *searchField;
    QPushButton *editButton;
    QPushButton *noEditButton;
    void Action();
    void MenuItem();
    void Hotel();
    void Room();
    void Package();
    void Bill();
    void Customer();
    void Status();

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
