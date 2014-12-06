#include "tank.h"
#include <math.h>

Tank::Tank(size_t _x, size_t _y):x(_x),y(_y)
{
      speed=1;
      angle = 0;
      setPos(x, y);
//      healthPoint=100;
}

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>

Tank::Tank()
    : angle(0), speed(0), tankDirection(0),
      color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    setRotation(0);
}

QRectF Tank::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
//! [1]

//! [2]
QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}
//! [2]

//! [3]
void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->setBrush(color);
    painter->drawEllipse(-10, -20, 20, 40);

    // Eyes
    painter->setBrush(Qt::white);
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);

    // Nose
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(-2, -22, 4, 4));

    // Pupils
    painter->drawEllipse(QRectF(-8.0 + tankDirection, -17, 4, 4));
    painter->drawEllipse(QRectF(4.0 + tankDirection, -17, 4, 4));

    // Ears
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
    painter->drawEllipse(-17, -12, 16, 16);
    painter->drawEllipse(1, -12, 16, 16);

    // Tail
    QPainterPath path(QPointF(0, 20));
    path.cubicTo(-5, 22, -5, 22, 0, 25);
    path.cubicTo(5, 27, 5, 32, 0, 30);
    path.cubicTo(-5, 32, -5, 42, 0, 35);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
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
}
//! [3]

//! [4]
void Tank::advance(int r)
{
    static int dx = 1;
    static int dy = 0;
    int counter = 0;

    qDebug() << "Going to the run " << r;

    if(y + 20*dy <= -300 || r == 0)//(x == 20 && y == -20)
    {
        dx = 0;
        dy = 1;
        this->angle = 2;
    }
    else if(x + 20*dx >= 300 || r == 1)//(x == 20 && y == 20)
    {
        dy = 0;
        dx = -1;
        this->angle = 3;
    }
    else if(y + 20*dy >= 250 || r == 2)//(x == -20 && y == 20)
    {
        dx = 0;
        dy = -1;
        this->angle = 0;
    }
    else if(x + 20*dx <= -250 || r == 3)//(x == -20 && y == -20)
    {
        dx = 1;
        dy = 0;
        this->angle = 1;
    }

    setRotation(90*this->angle);

    while(counter < 20)
    {
        x += dx;
        y += dy;
        setPos(x, y);
        counter++;
    }
}
//! [11]
