#include "addbook.h"
#include "ui_addbook.h"
#include "dbmanager.h"
#include <QMessageBox>
addbook::addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbook)
{
    ui->setupUi(this);
}

addbook::~addbook()
{
    delete ui;
}

void addbook::addbookbtn() {
    try {
        dbmanager db("books.db");
        QString Title =  ui->addTitle->text();
        int Quantity = (ui->addISBN->text()).toInt();
        int ISBN = (ui->addPubDate->text()).toInt();
        int pubDate = (ui->addQuantity->text()).toInt();
        db.AddBook("books.db", Title, ISBN, pubDate, Quantity);

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
