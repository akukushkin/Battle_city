#ifndef ITANKMOVEABLE_H
#define ITANKMOVEABLE_H

#include "basetank.h"

class BaseTank;

class ITankMoveable
{
public:
    explicit ITankMoveable(BaseTank* tank = NULL);

    void virtual move(int direction) = 0;
protected:
    BaseTank* tank;
};

#endif // ITANKMOVEABLE_H
