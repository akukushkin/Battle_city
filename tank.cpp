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
    if (event->key() == Qt::Key_Up)
        move(0);
    else if (event->key() == Qt::Key_Left)
        move(3);
    else if (event->key() == Qt::Key_Down)
        move(2);
    else if (event->key() == Qt::Key_Right)
        move(1);
    else if (event->key() == Qt::Key_Space)
        shot();
}
