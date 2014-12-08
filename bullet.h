#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem {
    Q_OBJECT
private:
    size_t direction;
public:
    Bullet();
    Bullet(size_t _direction);
public slots:
    void move();
};

#endif // BULLET_H
