#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>

class Bullet: public QObject, public QGraphicsRectItem {
    Q_OBJECT
private:
    QTimer* timer;
    size_t direction;
public:
    Bullet();
    Bullet(size_t _direction);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
    QWidget *widget);
    public slots:
    void move();
};

#endif // BULLET_H
