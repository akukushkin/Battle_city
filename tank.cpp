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
    : QObject(), angle(0), speed(0), tankDirection(0)
{
    setRotation(0);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->drawPixmap(0, 0, 50, 50, QPixmap(":/images/tank.png"));
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

void Tank::rotateTank(int angle)
{
    this->setTransformOriginPoint(QPoint(this->rect().width()/2,this->rect().height()/2));
    setRotation(angle);
}

void Tank::advance(int r)
{
    static int dx = 0;
    static int dy = 0;

    switch (r) {
    case Qt::Key_Down:
        if (this->angle != 2) {
            this->angle = 2;
            rotateTank(this->angle*90);
            return;
        } else if (y() < (scene()->height() - this->rect().height())) {
            dx = 0;
            dy = 1;
        } else
            return;
        break;
    case Qt::Key_Left:
        if (this->angle != 3) {
            this->angle = 3;
            rotateTank(this->angle*90);
            return;
        } else if (x() > 0) {
            dx = -1;
            dy = 0;
        } else
            return;
        break;
    case Qt::Key_Up:
        if (this->angle != 0) {
            this->angle = 0;
            rotateTank(this->angle*90);
            return;
        } else if (y() > 0) {
            dx = 0;
            dy = -1;
        } else
            return;
        break;
    case Qt::Key_Right:
        if (this->angle != 1) {
            this->angle = 1;
            rotateTank(this->angle*90);
            return;
        } else if (x() < (scene()->width() - this->rect().width())) {
            dx = 1;
            dy = 0;
        } else
            return;
        break;
    }

    int counter = 0;
    while(counter < this->rect().width()/2) {
        setPos(x() + dx, y() + dy);
        counter++;
    }
}

