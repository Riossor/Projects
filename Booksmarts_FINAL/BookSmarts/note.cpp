#include "note.h"
#include "ui_note.h"

#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

note::note(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::note)
{
    ui->setupUi(this);
}

note::~note()
{
    delete ui;
}

void note::saveNote()
{
    try {
        QString fileName = QFileDialog::getSaveFileName(this, "Save as", QString(), "Text Files (*.txt)");
        QFile file(fileName);

        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "Error with saving file: " + file.errorString());
            return;
        } else
        {

        }
        QString ongoingFile = fileName;
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
        qDebug() << "Note Add Success";
    } catch (...) {
        QMessageBox::warning(this, tr("Failure"), tr("Did not create note."));
        close();
    }


}
