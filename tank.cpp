#include "tank.h"
#include <math.h>
#include "field.h"
extern Field* field;
Tank::Tank(size_t _x, size_t _y) : QObject()
{

      speed=1;
      angle = 0;
      setPos(_x, _y);
//      healthPoint=100;
}

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"

Tank::Tank()
    : QObject(),angle(0), speed(0), tankDirection(0)
{
    setRotation(0);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body

        painter->drawPixmap(0,0,50,50,QPixmap(":/images/tank.png"));

}

void Tank::keyPressEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_Up)
       advance(2);
   else if(event->key() == Qt::Key_Down)
       advance(0);
   else if(event->key() == Qt::Key_Left)
       advance(1);
   else if(event->key() == Qt::Key_Right)
       advance(3);
   else if(event->key() == Qt::Key_Space)
   {
       Bullet* bullet = new Bullet(angle);
       int positionBulletX = x() + this->rect().width()/2 - bullet->pixmap().width()/2;
       int positionBulletY = y() + this->rect().height()/2 - bullet->pixmap().height()/2;
       bullet->setPos(positionBulletX, positionBulletY);
       bullet->setRotation(90*this->angle);
       scene()->addItem(bullet);
   }
}
//! [3]

//! [4]
void Tank::advance(int r)
{
    connect(this, SIGNAL(position_tank(int,int,int*)), field, SLOT(checked_sten(int,int,int*)));
    static int dx = 0;
    static int dy = 0;
    int counter = 0;

    if((y()) < 600 && r == 0)
    {
        dx = 0;
        dy = 1;
        this->angle = 2;
    }
    else if((x()) > 0 && r == 1)
    {
        dy = 0;
        dx = -1;
        this->angle = 3;
    }
    else if(y()> 0 && r == 2)
    {
        dx = 0;
        dy = -1;
        this->angle = 0;
    }
    else if(x() < 600 && r == 3)
    {
        dx = 1;
        dy = 0;
        this->angle = 1;
    }
    else
    {
        dx = 0;
        dy = 0;
    }

    setRotation(90*this->angle);
    int* temp;
    temp = new int(1);
    while(counter < 25)
    {
        emit this->position_tank(x()+dx,y()+dy, temp);
        qDebug() << *temp;
        if (*temp){
        setPos(x() + dx, y() + dy);
        counter++;
        } else {
            return;
        }
    }
}

//! [11]

