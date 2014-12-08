#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

#include <QDebug>

Bullet::Bullet() {}

Bullet::Bullet(size_t _direction): direction(_direction)
{
    setRect(0, 0, 10, 10);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    switch (direction) {
    case 0:
        setPos(x(), y() + 10);
        break;
    case 1:
        setPos(x() - 10, y());
        break;
    case 2:
        setPos(x(), y() - 10);
        break;
    case 3:
        setPos(x() + 10, y());
        break;
    }

    if (pos().y() < 0 || pos().y() > scene()->height() ||
            pos().x() < 0 || pos().x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";
    }
}
