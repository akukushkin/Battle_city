#include "tank.h"
#include <math.h>
#include "field.h"
#include "kirpich.h"
#include "gamemanager.h"
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"

Tank::Tank() : BaseTank() {}

Tank::Tank(size_t x, size_t y) : BaseTank(x, y) {}

Tank::~Tank()
{
    delete this;
}

void Tank::keyPressEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Down || event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
           move(event->key());
   else if(event->key() == Qt::Key_Space)
   {
      shot();
   }
}

void Tank::move(int controlButton){
    int dx = 0;
    int dy = 0;
    switch (controlButton) {
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

    if (!this->checkPosition()) {
        setPos(x() + rect().width()*dx, y() + rect().height()*dy);
        counter++;
    }
}
