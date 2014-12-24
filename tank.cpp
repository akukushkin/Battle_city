#include "tank.h"
#include <QKeyEvent>
#include "simplemove.h"
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
