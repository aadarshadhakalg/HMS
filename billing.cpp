#include "mainwindow.h"


void MainWindow::Bill(){
    setWindowTitle("Billings");
    style();

    QVBoxLayout *main_layout = new QVBoxLayout();
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


        connect(selectRoom, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            [=](int index){
            switch (index){
            case 0:
                break;
            case 1:
                checkoutSelectedRoomID->setText("Room 1 Selected");
                break;
            case 2:
                checkoutSelectedRoomID->setText("Room 2 Selected");
                break;
            case 3:
                checkoutSelectedRoomID->setText("Room 3 Selected");
                break;
            case 4:
                checkoutSelectedRoomID->setText("Room 4 Selected");
                break;
            case 5:
                checkoutSelectedRoomID->setText("Room 5 Selected");
                break;
            case 6:
                checkoutSelectedRoomID->setText("Room 6 Selected");
                break;
            case 7:
                checkoutSelectedRoomID->setText("Room 7 Selected");
                break;
            case 8:
                checkoutSelectedRoomID->setText("Room 8 Selected");
                break;
            default:
                break;
            }
        });
        //////////////////////////////////////
        /// La dost baki timi gara hai
        ////////////////////////////
        /// /////////////////////////

        QVBoxLayout *bottom_layout = new QVBoxLayout();
           checkoutSelectedRoomID = new QLabel();
        bottom_layout->addWidget(checkoutSelectedRoomID);


    main_layout->addLayout(top_layout);
    main_layout->addLayout(bottom_layout);

    rightside->setLayout(main_layout);
>>>>>>> 2902ec9d0a393e6929b98c23dd91fe8c2452fbd5
}
