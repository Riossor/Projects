#ifndef LOGINMENU_H
#define LOGINMENU_H

#include <QDialog>

namespace Ui {
class loginMenu;
}

class loginMenu : public QDialog
{
    Q_OBJECT

public:
    explicit loginMenu(QWidget *parent = nullptr);
    ~loginMenu();

private:
    Ui::loginMenu *ui;

public slots:
    void login();
    void loadusers();
};

#endif // LOGINMENU_H
