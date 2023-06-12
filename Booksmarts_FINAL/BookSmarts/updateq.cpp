#include "updateq.h"
#include "ui_updateq.h"
#include "dbmanager.h"
#include "mainwindow.h"

#include <QMessageBox>

updateQ::updateQ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateQ)
{
    ui->setupUi(this);

    ui->comboBox->clear();
    dbmanager db("books.db");
    QVector<QVariant> Titles = db.BooksToCB("books.db");

    for(unsigned short index = 0; index < Titles.size(); index++)
    {
        ui->comboBox->addItem(Titles[index].toString());
    }
}

updateQ::~updateQ()
{
    delete ui;
}

void updateQ::updatebtn() {
    try {
        dbmanager db("books.db");
        QString Title = ui->comboBox->currentText();
        QString Quantity = ui->newQuantity->text();
        db.UpdateQuantity("books.db", Title, Quantity.toInt());

        QMessageBox msgBox;
        msgBox.setText("Success!");
        msgBox.exec();

        close();
    } catch (...) {
        QMessageBox msgBox;
        msgBox.setText("Failed!");
        msgBox.exec();

        close();
    }

}
