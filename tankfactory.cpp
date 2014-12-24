#include "tankfactory.h"
#include "basetank.h"
#include "enemytank.h"
#include "tank.h"

BaseTank* TankFactory::createTank(TID tank_id)
{
    if(tank_id == ePl)
        return new EnemyTank();
    else if(tank_id == hPl)
        return new Tank();
    else
        return NULL;
}
