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
    //void createOwnerWindow();





private slots:
    void save();

    void contact();

    void question();

    private:
    /*//void makeReservation(int,int);
    //void createWindow();
    void createManagerWindow();
    void createCustomerWindow();
    //void bookWindow();
    void createActions();
    void createMenus();
    //void managerLogin();
    //void sunWindow();
    /void monWindow();
    void tueWindow();
    void wedWindow();
    void thuWindow();
    void friWindow();
    void satWindow();
    void combinationUtil(int arr[],int data[],int start,int end,int index, int r);
    void printCombinatin (int arr[], int n, int r);*/

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
   QLineEdit *msg;
   QLineEdit *name;
   QLineEdit *status;
   QLabel *time;
   QLineEdit *mobileNo;
   QLineEdit *username;
   QLineEdit *password;
   QLineEdit *tourName;
   QLineEdit *tourTeam;
   QLineEdit *tourGroup;
   QLineEdit *tourGoal;
   QLineEdit *homeGoal;
   QLineEdit *awayGoal;
   QLabel *homeTeamNo[120];
   QLabel *awayTeamNo[120];
   QLabel *homeScore[120];
   QLabel *awayScore[120];

   QLineEdit* tourDetail;
   QLineEdit *teamName[50];
   QLabel* teamnameLabel[50];
   QLabel* nameLabel[50];
   QLabel* homeLabel[50];
   QLabel* awayLabel[50];
   QLabel* versusLabel[50];
   QGroupBox *groupBox[10];
   QGridLayout *vbox[10];
   QHBoxLayout *loginLayout [3];
   QHBoxLayout *grpbox[10];

   QLabel*msgRec;
   QLabel *msgLabel;
   QPushButton *updateResult[120];
   int teamNo;
   int groups;
   int teams;
   std::string file5;
   std::string file6;

   QLabel *fixtureLabel[120];
   QLineEdit *fixtureResultNo;

};

#endif // MAINWINDOW_H
