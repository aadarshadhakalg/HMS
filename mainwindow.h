#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QtWidgets>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();



private:
    void Action();
    void MenuItem();





private slots:
    void save();

    void contact();

    void question();

    private:


    QMenu *file;
    QMenu *help;
    QMenu *about;

    QAction *saveAct;
    QAction *contactAct;
    QAction *QuesAct;




   QLabel *infoLabel;

};

#endif // MAINWINDOW_H
