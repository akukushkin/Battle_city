#include "tank.h"
#include <math.h>
#include "field.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"

extern Field* field;

Tank::Tank()
    : QObject(), direction(0), speed(0)
{
    setRotation(0);
}

Tank::Tank(size_t _x, size_t _y)
    : QObject()
{
      speed=1;
      direction = 0;
      setPos(_x, _y);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    // Body
    painter->drawPixmap(0, 0, 50, 50, QPixmap(":/images/tank.png"));
}

void Tank::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Down || event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
           advance(event->key());
   else if(event->key() == Qt::Key_Space)
   {
       Bullet* bullet = new Bullet(direction);
       int positionBulletX = x() + this->rect().width()/2 - bullet->pixmap().width()/2;
       int positionBulletY = y() + this->rect().height()/2 - bullet->pixmap().height()/2;
       bullet->setPos(positionBulletX, positionBulletY);
       bullet->setRotation(90*this->direction);
       scene()->addItem(bullet);
   }
}

void Tank::rotateTank(int angle) {
    this->setTransformOriginPoint(QPoint(this->rect().width()/2,this->rect().height()/2));
    setRotation(angle);
}

void Tank::advance(int r) {
    int dx = 0;
    int dy = 0;

    switch (r) {
    case Qt::Key_Down:
        if (this->direction != 2) {
            this->direction = 2;
            rotateTank(this->direction*90);
            return;
        } else if (y() < (scene()->height() - this->rect().height())) {
            dx = 0;
            dy = 1;
        } else
            return;
        break;
    case Qt::Key_Left:
        if (this->direction != 3) {
            this->direction = 3;
            rotateTank(this->direction*90);
            return;
        } else if (x() > 0) {
            dx = -1;
            dy = 0;
        } else
            return;
        break;
    case Qt::Key_Up:
        if (this->direction != 0) {
            this->direction = 0;
            rotateTank(this->direction*90);
            return;
        } else if (y() > 0) {
            dx = 0;
            dy = -1;
        } else
            return;
        break;
    case Qt::Key_Right:
        if (this->direction != 1) {
            this->direction = 1;
            rotateTank(this->direction*90);
            return;
        } else if (x() < (scene()->width() - this->rect().width())) {
            dx = 1;
            dy = 0;
        } else
            return;
        break;
    }

    int counter = 0;
    while(counter < this->rect().width()) {
        setPos(x() + dx, y() + dy);
        counter++;
    }
}

