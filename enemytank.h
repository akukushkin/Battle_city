#ifndef ENEMYTANK_H
#define ENEMYTANK_H

#include <QObject>
#include "basetank.h"

class EnemyTank : BaseTank
{
public:
    explicit EnemyTank();
    explicit EnemyTank(size_t x, size_t y);
    ~EnemyTank();
};

#endif // ENEMYTANK_H
