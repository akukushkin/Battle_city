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

Tank::Tank() : BaseTank()
{
    moveable = new SimpleMove(this);
}

Tank::Tank(size_t x, size_t y) : BaseTank(x, y)
{
    moveable = new SimpleMove(this);
}

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
