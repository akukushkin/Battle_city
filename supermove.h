#ifndef SUPERMOVE_H
#define SUPERMOVE_H

#include <QGraphicsScene>
#include "itankmoveable.h"
#include "basetank.h"
#include <QTime>

class SuperMove : public ITankMoveable
{
private:
    QTime timeStart;
public:
    explicit SuperMove(BaseTank *tank = NULL);
    ~SuperMove();

    void move(size_t newDirection);
};

#endif // SUPERMOVE_H
