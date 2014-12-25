#ifndef SIMPLEMOVE_H
#define SIMPLEMOVE_H

#include <QGraphicsScene>
#include "itankmoveable.h"
#include "basetank.h"

class SimpleMove : public ITankMoveable
{
public:
    explicit SimpleMove(BaseTank *tank = NULL);
    ~SimpleMove();

    void move(size_t newDirection);
};

#endif // SIMPLEMOVE_H
