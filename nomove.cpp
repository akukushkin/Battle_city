#include "nomove.h"
#include "simplemove.h"
#define TIMEOUT 5000

NoMove::NoMove(BaseTank *tank) : ITankMoveable(tank), timeStart(QTime::currentTime())
{
}

NoMove::~NoMove()
{
}

void NoMove::move(size_t newDirection)
{
    if (tank->getDirection()!= newDirection) {
        tank->rotateTank(newDirection);
        return;
    }

    if (timeStart.msecsTo(QTime::currentTime()) > TIMEOUT) {
        ITankMoveable* newMove = new SimpleMove(tank);
        tank->setMoveable(newMove);
        delete this;
    }
}
