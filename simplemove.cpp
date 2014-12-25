#include "simplemove.h"
#include "nomove.h"
#include "supermove.h"
#include "boost/random.hpp"
#include <ctime>

SimpleMove::SimpleMove(BaseTank *tank) : ITankMoveable(tank)
{
}

SimpleMove::~SimpleMove()
{
}

void SimpleMove::move(size_t newDirection)
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

    size_t cheked = tank->checkPosition();
    static int i = 0;
    const int rangeMin = 0;
    const int rangeMax = 1;
    typedef boost::uniform_int<> NumberDistribution;
    typedef boost::mt19937 RandomNumberGenerator;
    typedef boost::variate_generator<RandomNumberGenerator&,
                                     NumberDistribution> Generator;

    NumberDistribution distribution(rangeMin, rangeMax);
    RandomNumberGenerator generator;
    Generator numberGenerator(generator, distribution);
    generator.seed(std::time(0)+i++);

    if (cheked) {
        tank->setPos(tank->x() + tank->rect().width()*dx, tank->y() + tank->rect().height()*dy);
        if (cheked == 2) {
            ITankMoveable* newMove = NULL;
            if (numberGenerator())
                newMove = new SuperMove(tank);
            else
                newMove = new NoMove(tank);

            tank->setMoveable(newMove);
            delete this;
        }
    }
}
