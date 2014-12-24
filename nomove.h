#ifndef NOMOVE_H
#define NOMOVE_H

#include "itankmoveable.h"
#include "basetank.h"

class NoMove : public ITankMoveable
{
public:
    explicit NoMove(BaseTank* tank = NULL);
    ~NoMove();

    void move(int newDirection);
};

#endif // NOMOVE_H
