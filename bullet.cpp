#include <bullet.h>

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>

Bullet::Bullet()
    : speed(0), damage(0), direction(0),
      x(0), y(0), color(qrand() % 256, qrand() % 256, qrand() % 256)
{}

Bullet::Bullet(qreal _speed, qreal _damage, qreal _direction,
               qreal _x, qreal _y, QColor _color)
    : speed(_speed), damage(_damage), direction(_direction),
      x(_x), y(_y), color(_color)
{}

QRectF Bullet::boundingRect()
{
    qreal adjust = 0.5;
    return QRectF(-5 - adjust, -5 - adjust,
                  10 + adjust, 10 + adjust);
}

QPainterPath Bullet::shape()
{

}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(color);
    painter->drawEllipse(-5, -5, 10, 10);

    QPainterPath path(QPointF(0, 20));
    path.cubicTo(-5, 22, -5, 22, 0, 25);
    path.cubicTo(5, 27, 5, 32, 0, 30);
    path.cubicTo(-5, 32, -5, 42, 0, 35);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
}
