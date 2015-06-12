#ifndef BASETANK_H
#define BASETANK_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <unistd.h>
#include "bullet.h"
#include "itankmoveable.h"

class BaseTank : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit BaseTank();
    explicit BaseTank(size_t x, size_t y);
    virtual ~BaseTank();

    size_t getDirection() const;
    void rotateTank(size_t newDirection);
    void shot();
    // Return type cell
    size_t checkPosition();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void setMoveable(ITankMoveable *newMoveable);

protected:
    size_t direction;
    qreal speed;

    // Interface for moving tank. Pattern state
    ITankMoveable* moveable;

    // Moving tank
    void move(size_t direction);
};

#endif // BASETANK_H
