#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>

namespace Ui {
class addbook;
}

class addbook : public QDialog
{
    Q_OBJECT

public:
    explicit addbook(QWidget *parent = nullptr);
    ~addbook();
    QVector<QVariant> AddBook(const QString& path, const QString& Title, const int& ISBN, const int& Pub, const int& Quantity);
private:
    Ui::addbook *ui;
public slots:
    void addbookbtn();
};

#endif // ADDBOOK_H
