#include "start.h"
#include "ui_start.h"

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    g=new Game;
    ui->blk2->hide();
    ui->blk4->hide();
    ui->blk8->hide();
    ui->blk16->hide();
    ui->blk32->hide();
    ui->blk64->hide();
    ui->blk128->hide();
    ui->blk256->hide();
    ui->blk512->hide();
    ui->blk1024->hide();
    ui->blk2048->hide();
    ui->pushButton_14->hide();
}

start::~start()
{
    delete ui;
}

void start::on_pushButton_clicked()
{
    Game *game=new Game;
    game->show();
    game->setMaximumSize(800,600);
    game->setMinimumSize(800,600);
}



void start::on_pushButton_14_clicked()
{
    g->show();
    g->setMaximumSize(800,600);
    g->setMinimumSize(800,600);
}


void start::on_blk2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[0].load(fileName);
    QIcon buttonicon(pic);
    ui->blk2->setIcon(buttonicon);
    ui->blk2->setIconSize(ui->pushButton->size());
}


void start::on_blk4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[1].load(fileName);
    QIcon buttonicon(pic);
    ui->blk4->setIcon(buttonicon);
    ui->blk4->setIconSize(ui->pushButton->size());
}


void start::on_blk8_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[2].load(fileName);
    QIcon buttonicon(pic);
    ui->blk8->setIcon(buttonicon);
    ui->blk8->setIconSize(ui->pushButton->size());
}

void start::on_blk16_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[3].load(fileName);
    QIcon buttonicon(pic);
    ui->blk16->setIcon(buttonicon);
    ui->blk16->setIconSize(ui->pushButton->size());
}

void start::on_blk256_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[7].load(fileName);
    QIcon buttonicon(pic);
    ui->blk256->setIcon(buttonicon);
    ui->blk256->setIconSize(ui->pushButton->size());
}

void start::on_blk32_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[4].load(fileName);
    QIcon buttonicon(pic);
    ui->blk32->setIcon(buttonicon);
    ui->blk32->setIconSize(ui->pushButton->size());
}

void start::on_blk64_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[5].load(fileName);
    QIcon buttonicon(pic);
    ui->blk64->setIcon(buttonicon);
    ui->blk64->setIconSize(ui->pushButton->size());
}

void start::on_blk128_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[6].load(fileName);
    QIcon buttonicon(pic);
    ui->blk128->setIcon(buttonicon);
    ui->blk128->setIconSize(ui->pushButton->size());
}


void start::on_blk512_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[8].load(fileName);
    QIcon buttonicon(pic);
    ui->blk512->setIcon(buttonicon);
    ui->blk512->setIconSize(ui->pushButton->size());
}

void start::on_blk1024_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[9].load(fileName);
    QIcon buttonicon(pic);
    ui->blk1024->setIcon(buttonicon);
    ui->blk1024->setIconSize(ui->pushButton->size());
}

void start::on_blk2048_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QPixmap pic;
    pic.load(fileName);
    g->pixmap[10].load(fileName);
    QIcon buttonicon(pic);
    ui->blk2048->setIcon(buttonicon);
    ui->blk2048->setIconSize(ui->pushButton->size());
}
