#include "game.h"
#include "start.h"
#include <QApplication>
//static const QSize resultSize(800, 600);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*Game w;
    w.setMaximumSize(800,600);
    w.setMinimumSize(800,600);
    w.show();*/
    start s;
    s.show();

    return a.exec();
}
