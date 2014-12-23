#ifndef BASETANK_H
#define BASETANK_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <unistd.h>
#include "bullet.h"
#include "itankmoveable.h"

class ITankMoveable;

class BaseTank : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit BaseTank();
    explicit BaseTank(size_t x, size_t y);
    virtual ~BaseTank();

    size_t getDirection() const;
    void setDirection(size_t new_direction);

    void rotateTank(size_t newDirection);
    void shot();
    bool checkPosition();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    size_t direction;
    qreal speed;

    // Interface for moving tank. Pattern strategy
    ITankMoveable* moveable;

    // Moving tank
    void move(int direction);
};

#endif // BASETANK_H
