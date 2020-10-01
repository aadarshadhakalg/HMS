
#include "mainwindow.h"

void MainWindow::Action()
{
    saveAct = new QAction(tr("&Lock"), this);
    saveAct->setStatusTip(tr("Logout"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::loginScreen);

    contactAct = new QAction(tr("&Contact us"), this);
    contactAct->setStatusTip(tr("Opening contact page"));
    connect(contactAct, &QAction::triggered, this, &MainWindow::contact);

    QuesAct = new QAction(tr("Ask us"), this);
    QuesAct->setStatusTip(tr("Question portal"));
    connect(QuesAct, &QAction::triggered, this, &MainWindow::question);


}
void MainWindow::MenuItem()
{
menuBar()->clear();
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

   QLabel *title = new QLabel();
   QLabel *subtitle1 = new QLabel();
   QLabel *ssubtitle1 = new QLabel();
   QLabel *subtitle2 = new QLabel();
   QLabel *ssubtitle2 = new QLabel();
   QLabel *subtitle3 = new QLabel();
   QLabel *ssubtitle3 = new QLabel();

   QFont banner("Helvetica",30,QFont::ExtraBold);
   QFont question("Helvetica",20,QFont::Black);
   QFont ans("Helvetica",15,QFont::ExtraLight);

  title -> setAlignment(Qt::AlignCenter);
  title ->setText(tr("CONTACT US" ));
  title->setFont(banner);
  //faq->setFixedHeight(40);
  title->adjustSize();



  subtitle1-> setAlignment(Qt::AlignLeft);

  subtitle1->setText(tr("Contact Company"));
  subtitle1->setFont(question);
  subtitle1->adjustSize();

  ssubtitle1-> setAlignment(Qt::AlignLeft);
  ssubtitle1->setText("This project is brought to you by student of Kathmandu University.\n"
                   "You can contact us at : sanohotel@gmail.com.");
  ssubtitle1->setFont(ans);
  ssubtitle1->adjustSize();


  subtitle2-> setAlignment(Qt::AlignLeft);
  subtitle2->setText(tr("About Developers"));
  subtitle2->setFont(question);
  subtitle2->adjustSize();



  ssubtitle2-> setAlignment(Qt::AlignLeft);

  ssubtitle2->setText("The developers of this application are\n"
                "Aadarsha Dhakal \n"
                "Ayush Paudel \n"
                "Ayush Aryal \n"
                "Sushant Adhikari");
  ssubtitle2->setFont(ans);
  ssubtitle2->adjustSize();


  subtitle3-> setAlignment(Qt::AlignLeft);
  subtitle3->setText(tr("HELP US GROW"));
  subtitle3->setFont(question);
  subtitle3->adjustSize();

  ssubtitle3-> setAlignment(Qt::AlignLeft);

  ssubtitle3->setText("You can help us by funding our work");
  ssubtitle3->setFont(ans);
  ssubtitle3->adjustSize();

  QPushButton *backButton = new QPushButton("Back");
  backButton->setStyleSheet("*{background:blue;height:30px;}");
  //backButton->adjustSize();
  connect(backButton,SIGNAL(clicked()),this,SLOT(dashboard()));


   QVBoxLayout *layout = new QVBoxLayout;


   layout->addWidget(title);
   layout->addWidget(subtitle1);
   layout->addWidget(ssubtitle1);
   layout->addWidget(subtitle2);
   layout->addWidget(ssubtitle2);
   layout->addWidget(subtitle3);
   layout->addWidget(ssubtitle3);
   layout->addWidget(backButton);

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
   //q1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

   // q1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
   q1->setText(tr("Q1) What is this software used for?"));
   q1->setFont(question);
   //q1->setFixedHeight(40);
   q1->adjustSize();

   ans1-> setAlignment(Qt::AlignLeft);
   //ans1->setFrameStyle(QFrame::Panel );
   //ans1->setFixedHeight(100);
   ans1->setText("Ans) This hotel management software is used to keep all the recording of the datas of\n"
                      "the costumers and enables to the smooth running of the hotel. It is basically used\n"
                      "to digitize the record keeping of the hotel.");
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
   ans2->setText("Ans) To login to the software you need to be the employee of the hotel and you need to\n"
                    "have your login id and password provided to you by the hotel.");
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
   ans3->setText("Ans) To input the datas of the guest, click on the rooms button and then select the\n"
                 "preferred room by thr guest them a form pops up in the screen and then fill the\n information of the guest");
   ans3->setFont(ans);
   ans3->adjustSize();

   QPushButton *backButton = new QPushButton("Back");
   backButton->setStyleSheet("*{background:blue;height:30px;}");
   //backButton->adjustSize();
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

     widget->setLayout(layout);

}
