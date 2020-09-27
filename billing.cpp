#include "mainwindow.h"

void MainWindow::Bill(){
//    QWidget *parent = new QWidget; // parent widget
    QVBoxLayout *main_layout = new QVBoxLayout();
    setWindowTitle("Billings");
    style();
    rightside->setLayout(main_layout);

    QWidget *tophalf = new QWidget;
   // QVBoxLayout *main_layout = new QVBoxLayout();
        QHBoxLayout *top_layout = new QHBoxLayout();
            QLabel *selectRoomLabel = new QLabel("Select A Room");
            QComboBox *selectRoom = new QComboBox();
            selectRoom->addItem("Please select a Room");
            selectRoom->addItem("Room 1 ( Common )");
            selectRoom->addItem("Room 2 ( Common )");
            selectRoom->addItem("Room 3 ( Common )");
            selectRoom->addItem("Room 4 ( Common )");
            selectRoom->addItem("Room 5 ( Deluxe )");
            selectRoom->addItem("Room 6 ( Deluxe )");
            selectRoom->addItem("Room 7 ( Deluxe )");
            selectRoom->addItem("Room 8 ( Deluxe )");

        top_layout->addWidget(selectRoomLabel);
        top_layout->addWidget(selectRoom);
        tophalf->setLayout(top_layout);


        connect(selectRoom, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            [=](int index){
            switch (index){
            case 0:
                break;
            case 1:
                checkout(1);
                break;
            case 2:
                checkout(2);
                break;
            case 3:
                 checkout(3);
                 break;
            case 4:
                 checkout(4);
                 break;
            case 5:
                 checkout(5);
                break;
            case 6:
                 checkout(6);
                break;
            case 7:
                 checkout(7);
                break;
            case 8:
                 checkout(8);
                break;
            default:
                break;
            }
        });
        //////////////////////////////////////
        /// La dost baki timi gara hai
        ////////////////////////////
        /// /////////////////////////


    bottom_half = new QWidget();
    main_layout->addWidget(tophalf);
    main_layout->addWidget(bottom_half);
}
