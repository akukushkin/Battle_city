#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

#include <QDebug>

Bullet::Bullet() {}

Bullet::Bullet(size_t _direction): direction(_direction)
{
    setPixmap(QPixmap(":/images/bullet.png"));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
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
    emit this->position_bullet(this->x(),this->y());

    if (pos().y() < 0 || pos().y() > scene()->height() ||
            pos().x() < 0 || pos().x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";
    }
}

void Bullet::bullet_delete()
{
    //scene()->removeItem(this);
    //disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
    //disconnect(this,SIGNAL(position_bullet(int,int)),this,SLOT(move()));
    //scene()->removeItem(this);
    //delete this;
    qDebug() << "Bullet deleted!";
}

