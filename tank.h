#ifndef TANK_H
#define TANK_H

#include <unistd.h>
#include <QGraphicsRectItem>
#include <QObject>
class Tank : public QObject ,public QGraphicsRectItem
{
    Q_OBJECT
private:
    size_t direction;
    qreal speed;
    qreal tankDirection;
public:
    Tank();
    Tank(size_t _x, size_t _y);
    bool checkPosition();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void keyPressEvent(QKeyEvent *event);

protected:
    void move(int step);
    void rotateTank(int angle);
    void shot();

};
#endif

