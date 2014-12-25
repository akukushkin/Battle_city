#include "supermove.h"
#include "simplemove.h"
#include "gamemanager.h"
#define TIMEOUT 5000

extern GameManager* game;

SuperMove::SuperMove(BaseTank *tank) : ITankMoveable(tank) , timeStart(QTime::currentTime())
{
}

SuperMove::~SuperMove()
{
}

void SuperMove::move(size_t newDirection)
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

    tank->setPos(tank->x() + tank->rect().width()*dx, tank->y() + tank->rect().height()*dy);

    if (timeStart.msecsTo(QTime::currentTime()) > TIMEOUT) {
        game->callField()->destroy(tank->y()/50, tank->x()/50);
        ITankMoveable* newMove = new SimpleMove(tank);
        tank->setMoveable(newMove);
        delete this;
    }
}
