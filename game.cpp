#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->restart->setVisible(0);
    ui->backbuttom->setVisible(0);
    ui->exit->setVisible(0);
    ui->GG->setVisible(0);
    ui->WIN->setVisible(0);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                row[i][j]=0;
                column[i][j]=0;
                newRow[i][j]=0;
                newCol[i][j]=0;
            }
        }
    //for label to control
    block[0][0]=ui->num11;
    block[0][1]=ui->num12;
    block[0][2]=ui->num13;
    block[0][3]=ui->num14;
    block[1][0]=ui->num21;
    block[1][1]=ui->num22;
    block[1][2]=ui->num23;
    block[1][3]=ui->num24;
    block[2][0]=ui->num31;
    block[2][1]=ui->num32;
    block[2][2]=ui->num33;
    block[2][3]=ui->num34;
    block[3][0]=ui->num41;
    block[3][1]=ui->num42;
    block[3][2]=ui->num43;
    block[3][3]=ui->num44;
    ui->label->setVisible(0);//gameover's pic
    ui->win->setVisible(0);//win's pic
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            block[i][j]->setVisible(0);
        }
    }
    die=0;
    pixmap[0].load(":/blk/blk2");
    pixmap[1].load(":/blk/blk4");
    pixmap[2].load(":/blk/blk8");
    pixmap[3].load(":/blk/blk16");
    pixmap[4].load(":/blk/blk32");
    pixmap[5].load(":/blk/blk64");
    pixmap[6].load(":/blk/blk128");
    pixmap[7].load(":/blk/blk256");
    pixmap[8].load(":/blk/blk512");
    pixmap[9].load(":/blk/blk1024");
    pixmap[10].load(":/blk/blk2048");
    Intscore=0;
    ui->score->setVisible(1);
    ui->score->setAlignment(Qt::AlignCenter);
    ui->scorename->setAlignment(Qt::AlignCenter);
    str=QString::number(Intscore,10);//int to string
    ui->score->setText(str);
    upadd=0;
    downadd=0;
    leftadd=0;
    rightadd=0;
    countback=0;
}

Game::~Game()
{
    delete ui;
}
void Game::setthesame()
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            newRow[i][j]=row[i][j];
            newCol[i][j]=column[i][j];
        }
    }
}
void Game::checkSame()
{
    int a=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(row[i][j]!=newRow[i][j]&&row[i][j]!=0)
            {
                setImage(block[i][j],row[i][j]);
                block[i][j]->setVisible(1);
                a=1;
            }
            else if(row[i][j]!=newRow[i][j]&&row[i][j]==0)
            {
                block[i][j]->setVisible(0);
                a=1;
            }
        }
    }
    //everytime after blocks are calculated,check if it is as the previous, if not, call the new pic for the block
    if(a==1)Rand();
}


void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->type() == QKeyEvent::KeyPress)
    {
        switch (event->key()) {
        case Qt::Key_Left:
            countback=0;
            die=ifdie();
            gameover(die);
            setthesame();
            addLeftRow();
            checkSame();
            ui->score->setText(str);
            break;
        case Qt::Key_Right:
            countback=0;
            die=ifdie();
            gameover(die);
            setthesame();
            addRightRow();
            checkSame();
            ui->score->setText(str);
            break;
        case Qt::Key_Up:
            countback=0;
            die=ifdie();
            gameover(die);
            setthesame();
            addUpCol();
            checkSame();
            ui->score->setText(str);
            break;
        case Qt::Key_Down:
            countback=0;
            die=ifdie();
            gameover(die);
            setthesame();
            addDownCol();
            checkSame();
            ui->score->setText(str);
            break;
        }
    }
}

void Game::Rand()
{
    srand(time(NULL));
    int randi=(rand()%4);
    int randj=(rand()%4);
    while(row[randi][randj]!=0)
    {
        randi=(rand()%4);
        randj=(rand()%4);
    }
    row[randi][randj]=2;
    RowToCol();
    setImage(block[randi][randj],row[randi][randj]);
    block[randi][randj]->setVisible(1);
    ani= new QPropertyAnimation(block[randi][randj],"geometry",this);
    ani->setDuration(150);//rand's number will delay 0.15s to show
    ani->setStartValue(QRect(block[randi][randj]->x(),block[randi][randj]->y(), 0, 0));
    ani->setEndValue(QRect(block[randi][randj]->x(),block[randi][randj]->y(),block[randi][randj]->width(), block[randi][randj]->height()));
    ani->start();

}
void Game::RowToCol()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            column[i][j]=row[j][i];
        }
    }
}

void Game::ColToRow()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            row[i][j]=column[j][i];
        }
    }
}

void Game::addUpCol()
{
    downadd=0;
    leftadd=0;
    rightadd=0;
    upadd=0;
    //set to up site
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(column[i][j]==0)
            {
                int t=j+1;
                while(t<=3)
                {
                    if(column[i][t]!=0)
                    {
                        column[i][j]=column[i][t];
                        column[i][t]=0;
                        break;
                    }
                    else t=t+1;
                }
            }
        }
    }
    //if same,add them together and the lower become 0
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(column[i][j]!=0)
            {
                if(j<3)
                {
                    if(column[i][j+1]==column[i][j])
                    {
                        column[i][j]=column[i][j+1]+column[i][j];
                        upadd=upadd+column[i][j];
                        column[i][j+1]=0;
                    }
                }
            }
        }
    }
    Intscore=Intscore+upadd;
    str=QString::number(Intscore,10);
    //up again
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(column[i][j]==0)
            {
                int t=j+1;
                while(t<=3)
                {
                    if(column[i][t]!=0)
                    {
                        column[i][j]=column[i][t];
                        column[i][t]=0;
                        break;
                    }
                    else t=t+1;
                }
            }
        }
    }
    ColToRow();
}

void Game::addDownCol()
{
    downadd=0;
    leftadd=0;
    rightadd=0;
    upadd=0;
    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        {
            if(column[i][j]==0)
            {
                int t=j-1;
                while(t>=0)
                {
                    if(column[i][t]!=0)
                    {
                        column[i][j]=column[i][t];
                        column[i][t]=0;
                        break;
                    }
                    else t=t-1;
                }
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        {
            if(column[i][j]!=0)
            {
                if(j>=1)
                {
                    if(column[i][j-1]==column[i][j])
                    {
                        column[i][j]=column[i][j-1]+column[i][j];
                        downadd=downadd+column[i][j];
                        column[i][j-1]=0;
                    }
                }
            }
        }
    }
    Intscore=Intscore+downadd;
    str=QString::number(Intscore,10);
    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        {
            if(column[i][j]==0)
            {
                int t=j-1;
                while(t>=0)
                {
                    if(column[i][t]!=0)
                    {
                        column[i][j]=column[i][t];
                        column[i][t]=0;
                        break;
                    }
                    else t=t-1;
                }
            }
        }
    }
    ColToRow();
}

void Game::addLeftRow()
{
    downadd=0;
    leftadd=0;
    rightadd=0;
    upadd=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(row[i][j]==0)
            {
                int t=j+1;
                while(t<=3)
                {
                    if(row[i][t]!=0)
                    {
                        row[i][j]=row[i][t];
                        row[i][t]=0;
                        break;
                    }
                    else t=t+1;
                }
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(row[i][j]!=0)
            {
                if(j<3)
                {
                    if(row[i][j+1]==row[i][j])
                    {
                        row[i][j]=row[i][j+1]+row[i][j];
                        leftadd=leftadd+row[i][j];
                        row[i][j+1]=0;
                    }
                }
            }
        }
    }
    Intscore=Intscore+leftadd;
    str=QString::number(Intscore,10);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(row[i][j]==0)
            {
                int t=j+1;
                while(t<=3)
                {
                    if(row[i][t]!=0)
                    {
                        row[i][j]=row[i][t];
                        row[i][t]=0;
                        break;
                    }
                    else t=t+1;
                }
            }
        }
    }
    RowToCol();
}

void Game::addRightRow()
{
    downadd=0;
    leftadd=0;
    rightadd=0;
    upadd=0;
    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        {
            if(row[i][j]==0)
            {
                int t=j-1;
                while(t>=0)
                {
                    if(row[i][t]!=0)
                    {
                        row[i][j]=row[i][t];
                        row[i][t]=0;
                        break;
                    }
                    else t=t-1;
                }
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        {
            if(row[i][j]!=0)
            {
                if(j>=1)
                {
                    if(row[i][j-1]==row[i][j])
                    {
                        row[i][j]=row[i][j-1]+row[i][j];
                        rightadd=rightadd+row[i][j];
                        row[i][j-1]=0;
                    }
                }
            }
        }
    }
    Intscore=Intscore+rightadd;
    str=QString::number(Intscore,10);
    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        {
            if(row[i][j]==0)
            {
                int t=j-1;
                while(t>=0)
                {
                    if(row[i][t]!=0)
                    {
                        row[i][j]=row[i][t];
                        row[i][t]=0;
                        break;
                    }
                    else t=t-1;
                }
            }
        }
    }
    RowToCol();
}

void Game::setImage(QLabel *block,int t)
{

   switch (t) {
    case 2:
        block->setPixmap(pixmap[0]);
        break;
    case 4:
        block->setPixmap(pixmap[1]);
        break;
    case 8:
        block->setPixmap(pixmap[2]);
        break;
    case 16:
        block->setPixmap(pixmap[3]);
        break;
    case 32:
        block->setPixmap(pixmap[4]);
        break;
    case 64:
        block->setPixmap(pixmap[5]);
        break;
    case 128:
        block->setPixmap(pixmap[6]);
        break;
    case 256:
        block->setPixmap(pixmap[7]);
        break;
    case 512:
        block->setPixmap(pixmap[8]);
        break;
    case 1024:
        block->setPixmap(pixmap[9]);
        break;
   case 2048:
       block->setPixmap(pixmap[10]);
       ui->win->setVisible(1);
       ani= new QPropertyAnimation(ui->win,"geometry",this);
       ani->setDuration(300);
       ani->setStartValue(QRect(0,0, 0, 0));
       ani->setEndValue(QRect(0,0,600, 600));
       ui->WIN->setVisible(1);
       ani= new QPropertyAnimation(ui->WIN,"geometry",this);
       ani->setDuration(300);
       ani->setStartValue(QRect(0,0, 0, 0));
       ani->setEndValue(QRect(200,40,211, 101));
       ui->backbuttom->setVisible(0);
       ui->exit->setVisible(1);
       for(i=0;i<4;i++)
       {
           for(j=0;j<4;j++)
           {
               row[i][j]=0;
               column[i][j]=0;
               newCol[i][j]=0;
               newRow[i][j]=0;
           }
       }
       break;
    }

}




void Game::on_pushButton_clicked()
{
    ui->label->setVisible(0);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            row[i][j]=0;
            column[i][j]=0;
            newRow[i][j]=0;
            newCol[i][j]=0;
            block[i][j]->setVisible(0);
        }
    }
    Intscore=0;
    str=QString::number(Intscore,10);
    ui->score->setText(str);
    Rand();
}

void Game::on_restart_clicked()
{

    ui->WIN->setVisible(0);
    ui->win->setVisible(0);
    ui->label->setVisible(0);
    ui->GG->setVisible(0);
    ui->exit->setVisible(0);
    ui->backbuttom->setVisible(1);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            row[i][j]=0;
            column[i][j]=0;
            newRow[i][j]=0;
            newCol[i][j]=0;
            block[i][j]->setVisible(0);
        }
    }
    Intscore=0;
    downadd=0;
    leftadd=0;
    rightadd=0;
    upadd=0;
    str=QString::number(Intscore,10);
    ui->score->setText(str);
    Rand();
}
int Game::ifdie()
{

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(row[i][j]==0)return 0;
            int tempm=j+1;
            if(tempm<4)
            {
                if(row[i][tempm]==row[i][j])return 0;
                else if(column[i][tempm]==column[i][j])return 0;
            }
            int tempM=j-1;
            if(tempM>=0)
            {
                if(row[i][tempM]==row[i][j])return 0;
                else if(column[i][tempM]==column[i][j])return 0;
            }

        }
    }
    return 1;
}
void Game::gameover(int die)
{
    if(die==1)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                row[i][j]=0;
            }
        }
        RowToCol();
        ui->label->setVisible(1);
        ui->GG->setVisible(1);
        QPropertyAnimation *nani= new QPropertyAnimation(ui->label,"geometry",this);
        nani->setDuration(300);
        nani->setStartValue(QRect(0,0, 0, 0));
        nani->setEndValue(QRect(0,0,600, 600));
        ani= new QPropertyAnimation(ui->GG,"geometry",this);
        ani->setDuration(300);
        ani->setStartValue(QRect(300 ,0, 0, 0));
        ani->setEndValue(QRect(480,360,111, 141));
        ani->start();
        ui->backbuttom->setVisible(0);
        ui->exit->setVisible(1);
    }
}

void Game::on_backbuttom_clicked()
{
    Intscore=Intscore-upadd-downadd-leftadd-rightadd;
    str=QString::number(Intscore,10);
    ui->score->setText(str);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                row[i][j]=newRow[i][j];
                column[i][j]=newCol[i][j];
                if(row[i][j]!=0)
                {
                    setImage(block[i][j],row[i][j]);
                    block[i][j]->setVisible(1);
                }
                else if(row[i][j]==0)block[i][j]->setVisible(0);
            }
        }

    downadd=0;
    leftadd=0;
    rightadd=0;
    upadd=0;
    countback=countback+1;
    if(countback!=1)
    {
        caution *a=new caution;
        a->setWindowTitle("Caution");
        a->show();
    }
}
