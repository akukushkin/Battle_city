#ifndef ENEMYTANK_H
#define ENEMYTANK_H

#include <unistd.h>
#include <QGraphicsRectItem>
#include <QObject>
#include "basetank.h"
#include <QTimer>

class EnemyTank : public BaseTank
{
    Q_OBJECT
private:
    QTimer* enemyTimer;
public:
    explicit EnemyTank();
    explicit EnemyTank(size_t x, size_t y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~EnemyTank();
public slots:
    // Algorith for enemytank's random moving
    void randomMove();

};

#endif // ENEMYTANK_H
