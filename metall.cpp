#include "metall.h"
#include <QGraphicsScene>
#include <QList>
#include "basic_element.h"
#include <QDebug>

MetallField::MetallField(int i, int j)
{
    setPos(j*ELEMENT,i*ELEMENT);
    setPixmap(QPixmap(":/images/metall.png"));
}

