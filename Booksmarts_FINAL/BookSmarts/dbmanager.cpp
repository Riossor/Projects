#include "dbmanager.h"
#include <QString>
#include <QMessageBox>

dbmanager::dbmanager(const QString& path)
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

std::string dbmanager::CreateDB(const QString& path)
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
    CreateQuery.prepare("CREATE TABLE BOOK(ISBN INTEGER PRIMARY KEY UNIQUE, TITLE STRING, PUBLISHED INTEGER, QUANTITY INTEGER)");
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

    QSqlQuery InsertQuery;
    //Insert Query
    InsertQuery.prepare("INSERT INTO BOOK (ISBN, TITLE, PUBLISHED, QUANTITY) VALUES (:ISBN, 'Clara Callan', 2001, 2)");
    InsertQuery.bindValue(":ISBN", 2005018);
    //Check if insert is a success
    if(InsertQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Create table error:"
                 << InsertQuery.lastError();
    }

    //Insert Query
    InsertQuery.prepare("INSERT INTO BOOK (ISBN, TITLE, PUBLISHED, QUANTITY) VALUES (:ISBN, 'Decision in Normandy', 1991, 1)");
    InsertQuery.bindValue(":ISBN", 60973129);
    //Check if insert is a success
    if(InsertQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Create table error:"
                 << InsertQuery.lastError();
    }

    //Insert Query
    InsertQuery.prepare("INSERT INTO BOOK (ISBN, TITLE, PUBLISHED, QUANTITY) VALUES (:ISBN, 'The Mummies of Urumchi', 1999, 1)");
    InsertQuery.bindValue(":ISBN", 393045218);
    //Check if insert is a success
    if(InsertQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Create table error:"
                 << InsertQuery.lastError();
    }
    //Close database
    db.close();

    if(success == true)
        return "Created table";
    else
        return "Failed";

}

QVector<QVariant> dbmanager::ReadDB(const QString& path)
{
    QVector<QVariant> ISBN;
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

    //Select Query
    QSqlQuery query("SELECT * FROM BOOK");
    int idISBN = query.record().indexOf("ISBN");
    int idPublish = query.record().indexOf("PUBLISHED");
    int idQuantity = query.record().indexOf("QUANTITY");
            while (query.next())
            {
                ISBN.push_back("Title:");
                ISBN.push_back(query.value(1));
                ISBN.push_back("ISBN:");
                ISBN.push_back(query.value(idISBN));
                ISBN.push_back("Year Published:");
                ISBN.push_back(query.value(idPublish));
                ISBN.push_back("Quantity:");
                ISBN.push_back(query.value(idQuantity));
                ISBN.push_back(" ");
            }

    db.close();

    return ISBN;
}

QVector<QVariant> dbmanager::BooksToCB(const QString& path)
{
    QVector<QVariant> Titles;
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

    //Select Query
    QSqlQuery query("SELECT TITLE FROM BOOK");
            while (query.next())
            {
                Titles.push_back( query.value(0));
            }

    db.close();

    return Titles;
}

QVector<QVariant> dbmanager::ReadEntry(const QString& path, const QString& Title)
{
    QVector<QVariant> Info;
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

    //Select Query
    QSqlQuery query("SELECT * FROM BOOK WHERE TITLE = \""+Title+"\"");
    int idISBN = query.record().indexOf("ISBN");
    int idPublish = query.record().indexOf("PUBLISHED");
    int idQuantity = query.record().indexOf("QUANTITY");

    while (query.next()) {
        Info.push_back("Title:");
        Info.push_back(query.value(1));
        Info.push_back("ISBN:");
        Info.push_back(query.value(idISBN));
        Info.push_back("Year Published:");
        Info.push_back(query.value(idPublish));
        Info.push_back("Quantity:");
        Info.push_back(query.value(idQuantity));
        Info.push_back(" ");
    }
    db.close();

    return Info;
}

QVector<QVariant> dbmanager::UpdateQuantity(const QString& path, const QString& Title, const int& Quantity) {
    QVector<QVariant> result;

    // open the database connection
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()) {
        // handle connection error
        qDebug() << "Error: connection with database failed";
        QMessageBox msgBox;
        msgBox.setText("Error: connection with database failed");
        msgBox.exec();
    } else {
        qDebug() << "Database: connection ok";

        // prepare and execute the update query
        QSqlQuery query;
        query.prepare("UPDATE BOOK SET QUANTITY=:QUANTITY WHERE TITLE=:TITLE");
        query.bindValue(":TITLE", Title);
        query.bindValue(":QUANTITY", Quantity);
        query.exec();

        // add the query result to the result vector
        while (query.next()) {
            for (int i = 0; i < query.record().count(); ++i) {
                result.append(query.value(i));
            }
        }
    }

    // close the database connection
    db.close();

    return result;
}

QVector<QVariant> dbmanager::AddBook(const QString& path, const QString& Title, const int& ISBN, const int& Pub, const int& Quantity) {
    QVector<QVariant> result;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    QSqlQuery InsertQuery;
    //Insert Query
    InsertQuery.prepare("INSERT INTO BOOK (ISBN, TITLE, PUBLISHED, QUANTITY) VALUES (:ISBN, :TITLE, :PUBLISHED, :QUANTITY)");
    InsertQuery.bindValue(":ISBN", ISBN);
    InsertQuery.bindValue(":TITLE", Title);
    InsertQuery.bindValue(":PUBLISHED", Pub);
    InsertQuery.bindValue(":QUANTITY", Quantity);
    //Check if insert is a success
    if(InsertQuery.exec())
    {
        qDebug() << "success";
        QMessageBox msgBox;
        msgBox.setText("success");
    }
    else
    {
        qDebug() << "Create table error:"
                 << InsertQuery.lastError();
    }
    db.close();
    return result;
}
