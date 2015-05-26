#ifndef CAUTION_H
#define CAUTION_H

#include <QWidget>

namespace Ui {
class caution;
}

class caution : public QWidget
{
    Q_OBJECT

public:
    explicit caution(QWidget *parent = 0);
    ~caution();

private:
    Ui::caution *ui;
};

#endif // CAUTION_H
