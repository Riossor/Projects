#include "specs.h"
#include "./ui_specs.h"
#include "mainwindow.h"

#include <QSysInfo>

specs::specs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::specs)
{
    QSysInfo *sysInfo = new QSysInfo();
    ui->setupUi(this);

    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("Property"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("Value"));

    QString buildApi = sysInfo->buildAbi();
    QRegularExpression rx("[-]");
    QStringList list = buildApi.split(rx);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setItem(1,0, new QTableWidgetItem("Archatecuture"));
    ui->tableWidget->setItem(1,1, new QTableWidgetItem(list[0]));

    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setItem(2,0, new QTableWidgetItem("Endianness"));
    ui->tableWidget->setItem(2,1, new QTableWidgetItem(list[1]));

    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setItem(3,0, new QTableWidgetItem("Product Version"));
    ui->tableWidget->setItem(3,1, new QTableWidgetItem(sysInfo->productVersion()));

    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setItem(4,0, new QTableWidgetItem("Product Type"));
    ui->tableWidget->setItem(4,1, new QTableWidgetItem(sysInfo->productType()));

    ui->tableWidget->setRowCount(6);
    ui->tableWidget->setItem(5,0, new QTableWidgetItem("Unique Machine ID"));
    ui->tableWidget->setItem(5,1, new QTableWidgetItem(sysInfo->machineUniqueId()));

    ui->tableWidget->setRowCount(7);
    ui->tableWidget->setItem(6,0, new QTableWidgetItem("Machine Host Name"));
    ui->tableWidget->setItem(6,1, new QTableWidgetItem(sysInfo->machineHostName()));
}

specs::~specs()
{
    delete ui;
}
