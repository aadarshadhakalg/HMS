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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// SLOTS
private slots:
    void loginScreen();
    void homeScreen();
    void loginButton_clicked();
    void roombooking();

// TO Fetch Line Text Data from another Function
private:
    QLineEdit *emailText;
    QLineEdit *passwordText;


};
#endif // MAINWINDOW_H
