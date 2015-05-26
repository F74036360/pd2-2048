#ifndef START_H
#define START_H

#include <QWidget>
#include "game.h"
namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_14_clicked();



    void on_blk2_clicked();

    void on_blk4_clicked();

    void on_blk8_clicked();

    void on_blk16_clicked();

    void on_blk256_clicked();

    void on_blk32_clicked();

    void on_blk64_clicked();

    void on_blk128_clicked();

    void on_blk512_clicked();

    void on_blk1024_clicked();

    void on_blk2048_clicked();

private:
    Ui::start *ui;
    Game *g;
};

#endif // START_H
