#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
   // Game *game=new Game;
    QString fileName = QFileDialog::getOpenFileName(this);
    pic.load(fileName);
    //game->pixmap[0].load(fileName);
    QIcon buttonicon(pic);
    ui->pushButton->setIcon(buttonicon);
    ui->pushButton->setIconSize(ui->pushButton->size());

}
