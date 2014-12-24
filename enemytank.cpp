#include "enemytank.h"
#include "simplemove.h"

EnemyTank::EnemyTank() : BaseTank()
{
    moveable = new SimpleMove(this);
}

EnemyTank::EnemyTank(size_t x, size_t y) : BaseTank(x, y)
{
    moveable = new SimpleMove(this);
}

EnemyTank::~EnemyTank()
{
}
