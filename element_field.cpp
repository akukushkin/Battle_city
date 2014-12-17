#include "element_field.h"
#include <QGraphicsScene>
#include <QList>

#include <QDebug>

ElementField::ElementField(int i, int j): x(j), y(i)
{
    setPos(j*ELEMENT,i*ELEMENT);
    setPixmap(QPixmap(":/images/1.jpg"));
}
