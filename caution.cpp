#include "caution.h"
#include "ui_caution.h"

caution::caution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::caution)
{
    ui->setupUi(this);
}

caution::~caution()
{
    delete ui;
}
