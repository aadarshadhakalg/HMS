#include "dialogbox_price.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialogButtonBox>
#include "mainwindow.h"


dialogbox_price::dialogbox_price(MainWindow) :
    QDialog(this)
{
    label11 = new QLabel(this);
    label11->setText("Total price: ");
}
