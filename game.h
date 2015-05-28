#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QMainWindow>
#include <QObject>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QString>
#include <QPropertyAnimation>
#include "caution.h"


namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    QPixmap pixmap[11];//set public to let user make their own 2048
    ~Game();
protected:
    virtual void keyPressEvent(QKeyEvent *event);



private slots:
    void on_pushButton_clicked();//start

    void on_restart_clicked();

    void on_backbuttom_clicked();

private:
    Ui::Game *ui;
    int i,j,die;
    int Intscore;
    int upadd,downadd,leftadd,rightadd;
    QString str;
   // QTimer *timer;
    QPropertyAnimation *ani;
    int countback;//count if player click backbutton continously
    QLabel *block[4][4];//contrl label on ui
    void RowToCol();
    void ColToRow();
    void addUpCol();
    void addDownCol();
    void addLeftRow();
    void addRightRow();
    void Rand();//get new 2
    void setImage(QLabel *block,int t);//test which pic should be shown on the block
    int ifdie();
    void gameover(int die);
    void setthesame();
    void checkSame();
    int row[4][4];
    int column[4][4];
    int newRow[4][4];
    int newCol[4][4];
    void ifwin();

};

#endif // GAME_H
