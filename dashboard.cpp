#include "mainwindow.h"

void MainWindow::dashboard(){

    Action();
    MenuItem();
    setWindowTitle("Dashboard");

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *window = new QWidget;
       setCentralWidget(window);
       QPushButton *button1 = new QPushButton("Room");
       QPushButton *button2 = new QPushButton("Billing");
       QPushButton *button3 = new QPushButton("Customer Window");
       QPushButton *button4 = new QPushButton("example");


       QGridLayout *layyout = new QGridLayout;
       layyout->addWidget(button1, 20, 20);
       layyout->addWidget(button2, 20, 40);
       layyout->addWidget(button3, 1, 0, 1, 2);
       layyout->addWidget(button4, 2, 0);
       layyout->addWidget(topFiller);

       window->setLayout(layyout);
       window->show();
}
