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

    QFont banner("Helvetica",30,QFont::Bold);
    QFont question("Helvetica",20,QFont::Bold);
    QFont ans("Helvetica",15,QFont::Bold);

   faq -> setAlignment(Qt::AlignCenter);
   // faq -> setAlignment(Qt::AlignLeft);
    faq ->setText(tr("FAQ" ));
     faq->setFont(banner);


   q1-> setAlignment(Qt::AlignLeft);
   q1->setText(tr("Q1) Why this Hotel?"));
   q1->setFont(question);

   ans1-> setAlignment(Qt::AlignLeft);
   ans1->setText(tr("Because this is the best"));
   ans1->setFont(ans);





    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(faq);
    layout->addWidget(q1);
    layout->addWidget(ans1);
    layout->addWidget(q2);
    layout->addWidget(ans2);



    widget->setLayout(layout);

}
