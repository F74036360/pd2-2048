#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QFileDialog>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <game.h>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    QPixmap pic;
};

#endif // FORM_H
