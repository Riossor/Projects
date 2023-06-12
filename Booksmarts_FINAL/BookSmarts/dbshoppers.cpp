#include "dbshoppers.h"

#include <QString>
#include <QMessageBox>

dbShoppers::dbShoppers(const QString& path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    //Checks to see if database is open
    if (!db.open())
    {
        qDebug() << "Error: connection with database failed";
        QMessageBox msgBox;
        msgBox.setText("Error: connection with database failed");
        msgBox.exec();
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    db.close();
}

std::string dbShoppers::AddShopper(const QString& path) {
    try {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);

        QSysInfo *sysInfo = new QSysInfo();
        int shopper = (sysInfo->machineUniqueId()).toInt();

        QSqlQuery InsertQuery;
        bool success = false;

        //Checks to see if database is open
        if (!db.open())
        {
            qDebug() << "Error: connection with database failed";
            QMessageBox msgBox;
            msgBox.setText("Error: connection with database failed");
            msgBox.exec();
        }
        else
        {
            qDebug() << "Database: connection ok";
        }

        //Creation Query
        InsertQuery.prepare("INSERT INTO SHOPPERTABLE(SHOPPERID) VALUES (:shopper)");
        InsertQuery.bindValue(":shopper", shopper);

        //Check if creation is a success
        if(InsertQuery.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "Insert table error:"
                     << InsertQuery.lastError();
        }

        //Close database
        db.close();

        if(success == true)
            return "Shopper Inserted into Database";
        else
            return "Failed";
    } catch (...) {
        return "Shopper in database";
    }

}


std::string dbShoppers::CreateDB(const QString& path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    QSqlQuery CreateQuery;
    bool success = false;

    //Checks to see if database is open
    if (!db.open())
    {
        qDebug() << "Error: connection with database failed";
        QMessageBox msgBox;
        msgBox.setText("Error: connection with database failed");
        msgBox.exec();
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    //Creation Query
    CreateQuery.prepare("CREATE TABLE SHOPPERTABLE (SHOPPERID INTEGER PRIMARY KEY UNIQUE)");
    //Check if creation is a success
    if(CreateQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Create table error:"
                 << CreateQuery.lastError();
    }

    //Close database
    db.close();

    if(success == true)
        return "Created table";
    else
        return "Failed";
}


