#ifndef SIMPLEMOVE_H
#define SIMPLEMOVE_H

#include <QGraphicsScene>
#include "itankmoveable.h"
#include "basetank.h"

class SimpleMove : public ITankMoveable
{
public:
    explicit SimpleMove(BaseTank *tank = NULL);

    void move(int direction);
};

#endif // SIMPLEMOVE_H
