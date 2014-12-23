#ifndef ITANKMOVEABLE_H
#define ITANKMOVEABLE_H

#include "basetank.h"

class BaseTank;

class ITankMoveable
{
public:
    explicit ITankMoveable(BaseTank* tank = NULL);
    virtual ~ITankMoveable();

    void virtual move(int newDirection) = 0;
protected:
    BaseTank* tank;
};

#endif // ITANKMOVEABLE_H
