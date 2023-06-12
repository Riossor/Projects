#ifndef NOTE_H
#define NOTE_H

#include <QDialog>

namespace Ui {
class note;
}

class note : public QDialog
{
    Q_OBJECT

public:
    explicit note(QWidget *parent = nullptr);
    ~note();

private:
    Ui::note *ui;

public slots:
    void saveNote();
};

#endif // NOTE_H
