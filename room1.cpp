#include "mainwindow.h"
#include <QProgressDialog>
#include <iostream>

// Defining room booking screen //

void MainWindow::room1(){
    QWidget *window = new QWidget();
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");
        QVBoxLayout *room1_layout =new QVBoxLayout();  //Defining Vertical Box Layout

            //Displays User Details Text At Center

            QLabel *room1_label = new QLabel(window);
            room1_label->setText("Room 1 Details");
            room1_label->setAlignment(Qt::AlignHCenter);
            QFont font("Helvetica",30,QFont::Bold);
            room1_label->setFont(font);
            room1_label->setFixedHeight(100);
            room1_label->show();

            QWidget *room1_details_form = new QWidget(window);
            QGridLayout *room1_details_formLayout = new QGridLayout(); // Defines grid layout for name
            room1_details_formLayout->setColumnMinimumWidth(1,100);

            // Form Fields Start

            //Hint Text

            QLabel *room1_details = new QLabel("Details:");
            room1_details->setStyleSheet("*{font-weight:bold;font-size:20px;padding:10px;}");
            room1_details->setFixedSize(100,100);

            QString roomdetail = "All the rooms are very beautiful. THANK YOU!"; //Room details (After adding add button it has to be modified as roomdetail = MainWindow::details->text();

            QLabel *details = new QLabel(QString(roomdetail));
            details->setStyleSheet("*{font-size:20px;padding:10px;}");

            QLabel *room1_type = new QLabel("Room Type:");
            room1_type->setStyleSheet("*{font-weight:bold;font-size:20px;padding:10px;}");

            QString room1type = "All the rooms are deluxe. THANK YOU!"; //Room type (After adding add button it has to be modified as roomdetail = MainWindow::details->text();

            QLabel *room1_type_is = new QLabel(QString(room1type));
            room1_type_is->setStyleSheet("*{font-size:20px;padding:10px;}");

            //adding label to layout
            room1_details_formLayout->addWidget(room1_details,0,0,1,1);
            room1_details_formLayout->addWidget(details,0,1,1,1);
            room1_details_formLayout->addWidget(room1_type,1,0,1,1);
            room1_details_formLayout->addWidget(room1_type_is,1,1);

            room1_details_formLayout->setColumnStretch(0,1);
            room1_details_form->setLayout(room1_details_formLayout); //room1_details_form layout set

            //Adding widgets to room1_layout
            room1_layout->addWidget(room1_label);
            room1_layout->addWidget(room1_details_form);
            window->setLayout(room1_layout);  //room1_layout set to main window
}
