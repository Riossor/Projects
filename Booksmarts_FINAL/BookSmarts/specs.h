#ifndef SPECS_H
#define SPECS_H

#include <QDialog>

namespace Ui {
class specs;
}

class specs : public QDialog
{
    Q_OBJECT

public:
    explicit specs(QWidget *parent = nullptr);
    ~specs();

private:
    Ui::specs *ui;
};

#endif // SPECS_H
