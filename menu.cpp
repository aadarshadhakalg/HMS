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
