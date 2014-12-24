#ifndef TANKFACTORY_H
#define TANKFACTORY_H
#include <basetank.h>

enum TID {hPl, ePl};

class TankFactory
{
public:
    static BaseTank* createTank(TID tank_id);
};

#endif // TANKFACTORY_H
