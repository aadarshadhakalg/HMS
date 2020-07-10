#include <QtWidgets>

#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <iostream>
#include <fstream>
#include <sstream>
#include<QtGui>



MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    Action();
    MenuItem();

   /* infoLabel = new QLabel();
    infoLabel -> setAlignment(Qt::AlignCenter);
    infoLabel->setText ("Welcome");
    infoLabel ->setStyleSheet("QLabel{color:black;font-weight:bold;font:35pt 'Microsoft YaHei UI Heavy';");

    QVBoxLayout *layout = new QVBoxLayout;
    layout ->addWidget(infoLabel);
    widget-> setLayout(layout);*/

    setWindowTitle(tr("Hotel Management System"));

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QWidget *window = new QWidget;
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

    setFixedHeight(750);
    setFixedWidth(1400);
}



void MainWindow::Action()
{
    saveAct = new QAction(tr("&Save"), this);
    saveAct->setStatusTip(tr("Saving"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    contactAct = new QAction(tr("&Contact us"), this);
    contactAct->setStatusTip(tr("Opening contact page"));
    connect(contactAct, &QAction::triggered, this, &MainWindow::contact);

    QuesAct = new QAction(tr("Ask us"), this);
    QuesAct->setStatusTip(tr("Question portal"));
    connect(QuesAct, &QAction::triggered, this, &MainWindow::question);


}
void MainWindow::MenuItem()
{
file = menuBar()->addMenu(tr("&File"));
file->addAction(saveAct);




help = menuBar()->addMenu(tr("&Help"));
help->addAction(QuesAct);

about= menuBar()->addMenu(tr("&contact us"));
about->addAction(contactAct);
}


void MainWindow::save()
{

    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    infoLabel = new QLabel();
    infoLabel -> setAlignment(Qt::AlignCenter);
    infoLabel->setText(tr("Saving"));

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(infoLabel);
    widget->setLayout(layout);



}
void MainWindow::contact()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    infoLabel = new QLabel();
    infoLabel -> setAlignment(Qt::AlignCenter);
    infoLabel->setText(tr("Number"));

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(infoLabel);
    widget->setLayout(layout);

}
void MainWindow::question()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    infoLabel = new QLabel();
    infoLabel -> setAlignment(Qt::AlignCenter);

    infoLabel->setText(tr("Querry?"));
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(infoLabel);
    widget->setLayout(layout);

}
/*void MainWindow::createOwnerWindow(){
    QWidget *widget = new QWidget;
    setCentralWidget(widget);


    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel();
    infoLabel->setAlignment(Qt::AlignCenter);


    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);

    widget->setLayout(layout);

//                setWindowTitle(tr("Owner Portal"));

    setFixedHeight(705);
    setFixedWidth(1370);
}*/
