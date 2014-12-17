#ifndef TANK_H
#define TANK_H

#include <unistd.h>
#include <QGraphicsRectItem>

class Tank : public QGraphicsRectItem
{
private:
    size_t angle;
    qreal speed;
    qreal tankDirection;
    QColor color;
public:
    Tank();
    Tank(size_t _x, size_t _y);

    void keyPressEvent(QKeyEvent *event);

protected:
    void advance(int key);
    void rotateTank(int angle);
};
#endif

