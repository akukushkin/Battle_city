#ifndef BASETANK_H
#define BASETANK_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <unistd.h>
#include "bullet.h"

class BaseTank : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit BaseTank();
    explicit BaseTank(size_t x, size_t y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    size_t direction;
    qreal speed;

    void virtual move(int direction) = 0;
    void rotateTank(int angle);
    void shot();
    bool checkPosition();
};

#endif // BASETANK_H
