#include "tank.h"
#include <math.h>

Tank::Tank(size_t _x, size_t _y)
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
    : angle(0), speed(0), tankDirection(0),
      color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    setRotation(0);
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
       bullet->setPos(x(), y());
       scene()->addItem(bullet);
   }
}
//! [3]

//! [4]
void Tank::advance(int r)
{
    static int dx = 0;
    static int dy = 0;
    int counter = 0;

    if((y() + 20) <= 600 && r == 0)
    {
        dx = 0;
        dy = 1;
        this->angle = 2;
    }
    else if(x() - 20 >= 0 && r == 1)
    {
        dy = 0;
        dx = -1;
        this->angle = 3;
    }
    else if(y() - 20 >= 0 && r == 2)
    {
        dx = 0;
        dy = -1;
        this->angle = 0;
    }
    else if(x() + 20 <= 800 && r == 3)
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

    while(counter < 20)
    {
        setPos(x() + dx, y() + dy);
        counter++;
    }
}
//! [11]

