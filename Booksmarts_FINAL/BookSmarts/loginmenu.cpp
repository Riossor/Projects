#include "loginmenu.h"
#include "ui_loginmenu.h"

#include <QMessageBox>

loginMenu::loginMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginMenu)
{
    ui->setupUi(this);
}

loginMenu::~loginMenu()
{
    delete ui;
}

void loginMenu::loadusers() {

}

void loginMenu::login() {
    loginMenu loginmenu;

    QString username = ui->usernameInput->text();
    QString pass = ui->passwordInput->text();
    if (username == "username" && pass == "password") {
        accept();
    } else {
        QMessageBox::warning(this, tr("Login Error"), tr("Invalid username or password."));
    }
}
