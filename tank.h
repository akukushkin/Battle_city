#ifndef TANK_H
#define TANK_H

#include <unistd.h>
#include <QGraphicsItem>

class Tank : public QGraphicsRectItem
{
private:
    size_t angle;
    qreal speed;
    qreal tankDirection;
    QColor color;
    int x;
    int y;
public:
    size_t getX() {return x;}
    size_t getY() {return y;}
    void setX(size_t x) {this->x = x;}
    void setY(size_t y) {this->y = y;}
    Tank();
    Tank(size_t _x, size_t _y);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void keyPressEvent(QKeyEvent *event);

protected:
    void advance(int step);
};
#endif

