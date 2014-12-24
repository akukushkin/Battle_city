#include "simplemove.h"

SimpleMove::SimpleMove(BaseTank *tank) : ITankMoveable(tank)
{
}

SimpleMove::~SimpleMove()
{
}

void SimpleMove::move(int newDirection)
{
    int dx = 0;
    int dy = 0;

    if (tank->getDirection()!= newDirection) {
        tank->rotateTank(newDirection);
        return;
    }

    switch (newDirection) {
    case 2:
        if (tank->y() < (tank->scene()->height() - tank->rect().height())) {
            dx = 0;
            dy = 1;
        } else
        return;
        break;
    case 3:
        if (tank->x() > 0) {
            dx = -1;
            dy = 0;
        } else
        return;
        break;
    case 0:
        if (tank->y() > 0) {
            dx = 0;
            dy = -1;
        } else
        return;
        break;
    case 1:
        if (tank->x() < (tank->scene()->width() - tank->rect().width())) {
            dx = 1;
            dy = 0;
        } else
        return;
        break;
    }

    int counter = 0;

    if (tank->checkPosition()) {
        tank->setPos(tank->x() + tank->rect().width()*dx, tank->y() + tank->rect().height()*dy);
        counter++;
    }
}
