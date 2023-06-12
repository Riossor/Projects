#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class bookstore;
}
QT_END_NAMESPACE
class bookstore : public QMainWindow
{
    Q_OBJECT

public:
    explicit bookstore(QWidget *parent = nullptr);
    ~bookstore();

private:
    Ui::bookstore *ui;
public slots:
void mainWindowLoad();
};

#endif // BOOKSTORE_H
