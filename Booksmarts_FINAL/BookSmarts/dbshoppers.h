#ifndef DBSHOPPERS_H
#define DBSHOPPERS_H

#include <QtSql/QtSql>
#include <QVector>

class dbShoppers
{
public:
    dbShoppers(const QString& path);
    std::string CreateDB(const QString& path);
    std::string AddShopper(const QString& path);
private:
    QSqlDatabase db;
};

#endif // DBSHOPPERS_H
