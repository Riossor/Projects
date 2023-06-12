#ifndef UPDATEQ_H
#define UPDATEQ_H

#include <QDialog>

namespace Ui {
class updateQ;
}

class updateQ : public QDialog
{
    Q_OBJECT

public:
    explicit updateQ(QWidget *parent = nullptr);
    ~updateQ();

private:
    Ui::updateQ *ui;

public slots:
    void updatebtn();
};

#endif // UPDATEQ_H
