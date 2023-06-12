#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QtSql>
#include <QVector>

class dbmanager
{
public:
    dbmanager(const QString& path);
    std::string CreateDB(const QString& path);
    QVector<QVariant> ReadDB(const QString& path);
    QVector<QVariant> BooksToCB(const QString& path);
    QVector<QVariant> ReadEntry(const QString& path, const QString& Title);
    QVector<QVariant> UpdateQuantity(const QString& path, const QString& Title, const int& Quantity);
    QVector<QVariant> AddBook(const QString& path, const QString& Title, const int& ISBN, const int& Pub, const int& Quantity);
private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
