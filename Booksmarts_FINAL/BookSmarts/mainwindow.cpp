#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "specs.h"
#include "aboutus.h"
#include "dbmanager.h"
#include "addbook.h"
#include "loginMenu.h"
#include "note.h"
#include "updateq.h"
#include "dbshoppers.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(ui->lblBookCount);
    ui->statusbar->addPermanentWidget(ui->lblBookCountNumber);

    dbShoppers dbs("shoppers.db");
    dbs.AddShopper("shoppers.db");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateDB()
{
    dbmanager db("books.db");
}

void MainWindow::CreateTable()
{
    dbmanager db("books.db");
    ui->statusbar->showMessage(QString::fromStdString(db.CreateDB("books.db")));
}

void MainWindow::ReadTable()
{
    ui->txtBookOutput->clear();
    dbmanager db("books.db");
    QVector<QVariant> ISBNs = db.ReadDB("books.db");

    for(unsigned short index = 0; index < ISBNs.size(); index++)
    {
        ui->txtBookOutput->append(ISBNs[index].toString());
    }

}

void MainWindow::BooksToCB()
{
    ui->comboBox->clear();
    dbmanager db("books.db");
    QVector<QVariant> Titles = db.BooksToCB("books.db");

    for(unsigned short index = 0; index < Titles.size(); index++)
    {
        ui->comboBox->addItem(Titles[index].toString());
    }
}

void MainWindow::comboBoxChange()
{
    ui->txtBookOutput->clear();
    dbmanager db("books.db");
    QString Title = ui->comboBox->currentText();
    QVector<QVariant> Info = db.ReadEntry("books.db", Title);

    for(unsigned short index = 0; index < Info.size(); index++)
    {
        ui->txtBookOutput->append(Info[index].toString());
    }
}

void MainWindow::aboutUsLoad()
{
    AboutUs about;
    about.exec();
}

void MainWindow::addbookLoad()
{
    addbook addbook;
    addbook.exec();
}

void MainWindow::displaySize()
{
    int size = 0;
    size = readSize();
    QString s = QString::number(size);
    ui->lblBookCountNumber->setText(s);
}

int MainWindow::readSize()
{
    int number = 0;
    dbmanager db("books.db");
    QVector<QVariant> Titles = db.BooksToCB("books.db");
    number = Titles.size();
    return number;
}

void MainWindow::specsLoad()
{
    specs specs;
    specs.exec();
}

void MainWindow::addBookToList() {
    ui->txtBookOutput->clear();
    dbmanager db("books.db");
    QString Title = ui->comboBox->currentText();
    QVector<QVariant> Info = db.ReadEntry("books.db", Title);
    for(unsigned short index = 0; index < Info.size(); index++)
    {
        checkOutList.append(Info[index]);
    }

    for(unsigned short index = 0; index < checkOutList.size(); index++)
    {
        ui->txtBookOutput->append(checkOutList[index].toString());
    }
}

void MainWindow::Checkout() {
    QFile file("CheckoutList.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            for(unsigned short index = 0; index < checkOutList.size(); index++) {
                out << checkOutList[index].toString() << (", ") << "\n";
            }

            file.close();
            qDebug() << "Checkout Successful";
        }

}

void MainWindow::noteLoad() {
    note note;
    note.exec();
}

void MainWindow::updateQLoad() {
    updateQ update;
    update.exec();
}

#import <QFileDialog>
#import <QMessageBox>

void MainWindow::exportList() {
    try {
        ui->txtBookOutput->clear();
        dbmanager db("books.db");
        QVector<QVariant> ISBNs = db.ReadDB("books.db");

        for (unsigned short index = 0; index < ISBNs.size(); index++) {
            ui->txtBookOutput->append(ISBNs[index].toString());
        }

        QString fileName = QFileDialog::getSaveFileName(this, "Save as", QString(), "Text Files (*.txt)");
        QFile file(fileName);

        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Error with saving file: " + file.errorString());
            return;
        }

        QTextStream out(&file);

        for (unsigned short index = 0; index < ISBNs.size(); index++) {
            out << ISBNs[index].toString() << "\n";
        }

        file.close();
        qDebug() << "File export successful";
    } catch (const std::exception& e) {
        QMessageBox::warning(this, tr("Failure"), tr("Failed to export file: ") + QString::fromStdString(e.what()));
    }
}

#import <QDesktopServices>

void MainWindow::wowPac() {
    QDesktopServices::openUrl(QUrl("https://gradecalculator.mes.fm/memes/pacman-pie-chart"));
}

void MainWindow::mostImportantButton() {
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=dQw4w9WgXcQ"));
}
