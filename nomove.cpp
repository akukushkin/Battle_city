#include "nomove.h"

NoMove::NoMove(BaseTank *tank) : ITankMoveable(tank)
{
}

NoMove::~NoMove()
{
}

void NoMove::move(int newDirection)
{
    switch (newDirection) {
        case Qt::Key_Down:
            if (tank->getDirection() != 2) {
                tank->rotateTank(2);
                    return;
            }
            break;
        case Qt::Key_Left:
            if (tank->getDirection() != 3) {
                tank->rotateTank(3);
                return;
            }
            break;
        case Qt::Key_Up:
            if (tank->getDirection() != 0) {
                tank->rotateTank(0);
                return;
            }
            break;
        case Qt::Key_Right:
            if (tank->getDirection() != 1) {
                tank->rotateTank(1);
                return;
            }
            break;
    }
}
