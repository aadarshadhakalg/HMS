#include "mainwindow.h"

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
    infoLabel->setText(tr("Number k ho"));

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(infoLabel);
    widget->setLayout(layout);

}
void MainWindow::question()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QLabel *faq = new QLabel();
    QLabel *q1 = new QLabel();
    QLabel *ans1 = new QLabel();
    QLabel *q2 = new QLabel();
    QLabel *ans2 = new QLabel();
    QLabel *q3 = new QLabel();
    QLabel *ans3 = new QLabel();


    //setting font for the questions and answers
    QFont banner("Helvetica",30,QFont::ExtraBold);
    QFont question("Helvetica",20,QFont::Black);
    QFont ans("Helvetica",15,QFont::ExtraLight);

   faq -> setAlignment(Qt::AlignCenter);
   faq ->setText(tr("FAQ" ));
   faq->setFont(banner);
   faq->setFixedHeight(50);


   q1-> setAlignment(Qt::AlignLeft);
   //q1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

   // q1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
   q1->setText(tr("Q1) What is this software used for?"));
   q1->setFont(question);
   q1->setFixedHeight(50);

   ans1-> setAlignment(Qt::AlignLeft);
   //ans1->setFrameStyle(QFrame::Panel );
   ans1->setFixedHeight(70);
   ans1->setText("Ans) This hotel management software is used to keep all the recording of the datas of the costumers and enables to the smooth running of \n"
                    "the hotel. It is basically used to digitize the record keeping of the hotel.");
   ans1->setFont(ans);


   q2-> setAlignment(Qt::AlignLeft);
  // q1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
   q2->setText(tr("Q2) How do I login to the software?"));
   q2->setFont(question);
   q2->setFixedHeight(50);



   ans2-> setAlignment(Qt::AlignLeft);
   //ans1->setFrameStyle(QFrame::Panel );
   ans2->setFixedHeight(100);
   ans2->setText("Ans) To login to the software you need to be the employee of the hotel and you need to have your login id and password provided to\n you by the hotel.");
   ans2->setFont(ans);


   q3-> setAlignment(Qt::AlignLeft);
  // q1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
   q3->setText(tr("Q3) How do I keep the datas of the guest?"));
   q3->setFont(question);
   q3->setFixedHeight(50);

   ans3-> setAlignment(Qt::AlignLeft);
   //ans1->setFrameStyle(QFrame::Panel );
   ans3->setFixedHeight(100);
   ans3->setText("Ans) To input the datas of the guest, click on the rooms button and then select the preferred room by thr guest them a form pops up\n in the screen and then fill the information of the guest");
   ans3->setFont(ans);




    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(faq);
    layout->addWidget(q1);
    layout->addWidget(ans1);
    layout->addWidget(q2);
    layout->addWidget(ans2);
    layout->addWidget(q3);
    layout->addWidget(ans3);



    widget->setLayout(layout);

}
