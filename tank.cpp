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
   if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Down || event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
       advance(event->key());
   else if(event->key() == Qt::Key_Space)
   {
       Bullet* bullet = new Bullet(angle);
       bullet->setPos(mapToScene(this->rect().width()/2, this->rect().height()/2));
       scene()->addItem(bullet);
   }
}
//! [3]

//! [4]
void Tank::rotateTank(int angle)
{
    this->setTransformOriginPoint(QPoint(this->rect().width()/2,this->rect().height()/2));
    setRotation(angle);
}

void Tank::advance(int r)
{
    static int dx = 0;
    static int dy = 0;
    int f = 0;
    int counter = 0;

    if((y() + 20) <= 600 && r == Qt::Key_Down)
    {
        dx = 0;
        dy = 1;
        f = 2;
    }
    else if(x() - 20 >= 0 && r == Qt::Key_Left)
    {
        dy = 0;
        dx = -1;
        f = 3;
    }
    else if(y() - 20 >= 0 && r == Qt::Key_Up)
    {
        dx = 0;
        dy = -1;
        f = 0;
    }
    else if(x() + 20 <= 800 && r == Qt::Key_Right)
    {
        dx = 1;
        dy = 0;
        f = 1;
    }
    else
    {
        dx = 0;
        dy = 0;
    }

    if(f == this->angle)
    {
        while(counter < 20)
        {
            setPos(x() + dx, y() + dy);
            counter++;
        }
    }
    else
        rotateTank(90*f);

    this->angle = f;
}
//! [11]

