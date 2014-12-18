#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "kirpich.h"
#include <typeinfo>

#include <QDebug>

Bullet::Bullet() {}

Bullet::Bullet(size_t _direction): direction(_direction)
{
    setPixmap(QPixmap(":/images/bullet.png"));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(15);
}

void Bullet::move()
{
    // if bullet collies with block or enemy tank, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(KirpichField)) {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet
    switch (direction) {
    case 0:
        setPos(x(), y() - 10);
        break;
    case 1:
        setPos(x() + 10, y());
        break;
    case 2:
        setPos(x(), y() + 10);
        break;
    case 3:
        setPos(x() - 10, y());
        break;
    }

    // if bullet go out abroad, destroy it
    if (pos().y() < 0 || pos().y() > scene()->height() ||
            pos().x() < 0 || pos().x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
    }
}

