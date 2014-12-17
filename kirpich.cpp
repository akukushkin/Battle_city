#include "kirpich.h"
#include <QGraphicsScene>
#include <QList>

#include <QDebug>

KirpichField::KirpichField(int i, int j)
{
    setPos(j*ELEMENT,i*ELEMENT);
    setPixmap(QPixmap(":/images/4.png"));
}
