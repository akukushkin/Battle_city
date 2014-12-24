#include "bullet.h"
#include "kirpich.h"
#include "metall.h"
#include "field.h"
#include "orel.h"
#include "gamemanager.h"
#include <QTimer>
#include <QPainter>
#include <QGraphicsScene>
#include <typeinfo>

extern GameManager* game;
Bullet::Bullet() {}

Bullet::Bullet(size_t _direction): direction(_direction)
{
    this->setRotation(90*direction);
    setRect(0, 0, 9, 20);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(15);
}
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(0, 0, 9, 20, QPixmap(":/images/bullet.png"));
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(KirpichField) || typeid(*(colliding_items[i])) == typeid(BonusField) ) {
            game->callField()->destroy(dynamic_cast<BasicElement*>(colliding_items[i]));
            scene()->removeItem(this);
            delete this;
            return;
        } else if (typeid(*(colliding_items[i])) == typeid(OrelField)){
            delete game;
        } else if (typeid(*(colliding_items[i])) == typeid(MetallField)){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

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
    if (pos().y() < 0 || pos().y() > scene()->height() ||
            pos().x() < 0 || pos().x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
    }
 }
