#ifndef NOMOVE_H
#define NOMOVE_H

#include "itankmoveable.h"
#include "basetank.h"
#include <QTime>

class NoMove : public ITankMoveable
{
private:
    QTime timeStart;
public:
    explicit NoMove(BaseTank* tank = NULL);
    ~NoMove();

    void move(size_t newDirection);
};

#endif // NOMOVE_H
