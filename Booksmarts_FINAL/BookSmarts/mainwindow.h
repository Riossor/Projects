#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int readSize();
    QVector<QVariant> checkOutList;

private:
    Ui::MainWindow *ui;

public slots:
    void CreateDB();
    void CreateTable();
    void ReadTable();
    void BooksToCB();
    void comboBoxChange();
    void aboutUsLoad();
    void displaySize();
    void specsLoad();
    void addbookLoad();
    void addBookToList();
    void Checkout();
    void noteLoad();
    void updateQLoad();
    void exportList();
    void wowPac();
    void mostImportantButton();
};

#endif // MAINWINDOW_H
