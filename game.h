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
    int row[4][4];
    int column[4][4];
    int newRow[4][4];
    int newCol[4][4];
    QPixmap pixmap[11];
    void RowToCol();
    void ColToRow();
    void addUpCol();
    void addDownCol();
    void addLeftRow();
    void addRightRow();
    void Rand();
    //void setforUi();
    void setImage(QLabel *block,int t);
    int ifdie();
    void gameover(int die);
    void setthesame();
    void checkSame();
    ~Game();
protected:
    virtual void keyPressEvent(QKeyEvent *event);



private slots:
    void on_pushButton_clicked();

    void on_restart_clicked();

    void on_backbuttom_clicked();

private:
    Ui::Game *ui;
    QLabel *block[4][4];
    int i,j,die;
    int Intscore;
    int upadd,downadd,leftadd,rightadd;
    QString str;
    QTimer *timer;
    QPropertyAnimation *ani;
    int countback;
};

#endif // GAME_H
