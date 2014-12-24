#include "basetank.h"
#include "gamemanager.h"

extern GameManager* game;

BaseTank::BaseTank() :
    QObject(),
    direction(0),
    speed(0),
    moveable(NULL)
{
}

BaseTank::BaseTank(size_t x, size_t y):
    QObject(),
    direction(0),
    speed(0),
    moveable(NULL)
{
    setPos(x, y);
}

BaseTank::~BaseTank()
{
    delete moveable;
}

size_t BaseTank::getDirection() const
{
    return this->direction;
}

void BaseTank::setDirection(size_t new_direction)
{
    this->direction = new_direction;
}

bool BaseTank::checkPosition()
{
    int realX = x()+rect().width()/2;
    int realY = y()+rect().height()/2;

    int k = realX / rect().width();
    int m = realY / rect().height();
    switch (direction) {
    case 1:
        k++;
        break;
    case 2:
        m++;
        break;
    case 3:
        k--;
        break;
    default:
        m--;
        break;
    }
    return game->callField()->check(m,k);
}

void BaseTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->drawPixmap(0,0,50,50,QPixmap(":/images/tank.png"));
}

void BaseTank::move(int direction)
{
    moveable->move(direction);
}

void BaseTank::rotateTank(size_t newDirection)
{
    this->direction = newDirection;
    this->setTransformOriginPoint(QPoint(this->rect().width()/2,this->rect().height()/2));
    setRotation(newDirection*90);
}

void BaseTank::shot()
{
    Bullet* bullet = new Bullet(direction);
    int positionBulletX, positionBulletY;
    switch (direction) {
        case 2:
            positionBulletX = x() + this->rect().center().x() + bullet->rect().width()/2;
            positionBulletY = y() + this->rect().height() + bullet->rect().height();
            break;
        case 3:
            positionBulletX = x() - 2*bullet->rect().width();
            positionBulletY = y() + this->rect().center().y() + bullet->rect().width()/2;
            break;
        case 0:
            positionBulletX = x() + this->rect().center().x() - bullet->rect().width()/2;
            positionBulletY = y() - bullet->rect().height();
            break;
        case 1:
            positionBulletX = x() + this->rect().width() + bullet->rect().height();
            positionBulletY = y() + this->rect().center().y() - bullet->rect().width()/2;
            break;
    }
    bullet->setPos(positionBulletX, positionBulletY);
    scene()->addItem(bullet);
}
