
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
    infoLabel->setText(tr("Saved"));

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
   //faq->setFixedHeight(40);
   faq->adjustSize();



   q1-> setAlignment(Qt::AlignLeft);
  // q1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
   q1->setText(tr("Q1) What is this software used for?"));
   q1->setFont(question);
   //q1->setFixedHeight(40);
   q1->adjustSize();

   ans1-> setAlignment(Qt::AlignLeft);
   //ans1->setFrameStyle(QFrame::Panel );
   //ans1->setFixedHeight(100);
   ans1->setText("Ans) This hotel management software is used to keep all the recording of the datas of the costumers and enables to the smooth running of \n"
                    "the hotel. It is basically used to digitize the record keeping of the hotel.");
   ans1->setFont(ans);
   ans1->adjustSize();


   q2-> setAlignment(Qt::AlignLeft);
  // q1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
   q2->setText(tr("Q2) How do I login to the software?"));
   q2->setFont(question);
   //q2->setFixedHeight(40);
   q2->adjustSize();



   ans2-> setAlignment(Qt::AlignLeft);
   //ans1->setFrameStyle(QFrame::Panel );
  // ans2->setFixedHeight(60);
   ans2->setText("Ans) To login to the software you need to be the employee of the hotel and you need to have your login id and password provided to\n you by the hotel.");
   ans2->setFont(ans);
   ans2->adjustSize();


   q3-> setAlignment(Qt::AlignLeft);
  // q1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
   q3->setText(tr("Q3) How do I keep the datas of the guest?"));
   q3->setFont(question);
   //q3->setFixedHeight(40);
   q3->adjustSize();

   ans3-> setAlignment(Qt::AlignLeft);
   //ans1->setFrameStyle(QFrame::Panel );
   //ans3->setFixedHeight(60);
   ans3->setText("Ans) To input the datas of the guest, click on the rooms button and then select the preferred room by thr guest them a form pops up\n in the screen and then fill the information of the guest");
   ans3->setFont(ans);
   ans3->adjustSize();

   QPushButton *backButton = new QPushButton("Back");
   backButton->setStyleSheet("*{background:blue;height:30px;}");
   backButton->adjustSize();
   connect(backButton,SIGNAL(clicked()),this,SLOT(dashboard()));


    QVBoxLayout *layout = new QVBoxLayout;


    layout->addWidget(faq);
    layout->addWidget(q1);
    layout->addWidget(ans1);
    layout->addWidget(q2);
    layout->addWidget(ans2);
    layout->addWidget(q3);
    layout->addWidget(ans3);
    layout->addWidget(backButton);
                                                                   // Navigates to the loginScreen.





     widget->setLayout(layout);

}
