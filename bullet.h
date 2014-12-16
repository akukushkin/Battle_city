#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>
class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    QTimer* timer;
    size_t direction;
public:
    Bullet();
    Bullet(size_t _direction);
public slots:
    void move();
    void bullet_delete();
signals:
    void position_bullet(int x, int y);
};

#endif // BULLET_H
