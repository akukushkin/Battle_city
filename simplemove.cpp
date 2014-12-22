#include "simplemove.h"

SimpleMove::SimpleMove(BaseTank *tank) : ITankMoveable(tank)
{
}

void SimpleMove::move(int controlButton)
{
    int dx = 0;
    int dy = 0;
    switch (controlButton) {
        case Qt::Key_Down:
        if (tank->getDirection()!= 2) {
             tank->setDirection(2);
             tank->rotateTank(tank->getDirection()*90);
            return;
        } else if (tank->y() < (tank->scene()->height() - tank->rect().height())) {
            dx = 0;
            dy = 1;
        } else
            return;
            break;
        case Qt::Key_Left:
             if (tank->getDirection() != 3) {
                  tank->setDirection(3);
                  tank->rotateTank(tank->getDirection()*90);
                  return;
        } else if (tank->x() > 0) {
                   dx = -1;
                   dy = 0;
        } else
                   return;
                   break;
        case Qt::Key_Up:
            if (tank->getDirection() != 0) {
                tank->setDirection(0);
                tank->rotateTank(tank->getDirection()*90);
                return;
        } else if (tank->y() > 0) {
                dx = 0;
                dy = -1;
        } else
                return;
                break;
        case Qt::Key_Right:
                if (tank->getDirection() != 1) {
                    tank->setDirection(1);
                    tank->rotateTank(tank->getDirection()*90);
                    return;
        } else if (tank->x() < (tank->scene()->width() - tank->rect().width())) {
                     dx = 1;
                    dy = 0;
        } else
                return;
        break;
    }

    int counter = 0;

    if (!tank->checkPosition()) {
        tank->setPos(tank->x() + tank->rect().width()*dx, tank->y() + tank->rect().height()*dy);
        counter++;
    }
}
