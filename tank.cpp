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
    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Down || event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
           advance(event->key());
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

void Tank::rotateTank(int angle)
{
    this->setTransformOriginPoint(QPoint(this->rect().width()/2,this->rect().height()/2));
    setRotation(angle);
}

//! [4]
void Tank::advance(int r)
{
    connect(this, SIGNAL(position_tank(int,int,int*)), field, SLOT(checked_sten(int,int,int*)));
    static int dx = 0;
    static int dy = 0;
    int f = 0;
    int counter = 0;

    if((y()) < 600 && r == Qt::Key_Down)
    {
        dx = 0;
        dy = 1;
        f = 2;
    }
    else if((x()) > 0 && r == Qt::Key_Left)
    {
        dy = 0;
        dx = -1;
        f = 3;
    }
    else if(y()> 0 && r == Qt::Key_Up)
    {
        dx = 0;
        dy = -1;
        f = 0;
    }
    else if(x() < 600 && r == Qt::Key_Right)
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

    int* temp;
    temp = new int(1);

    if(f == this->angle)
    {
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
    else
        rotateTank(90*f);

    this->angle = f;
}

//! [11]

