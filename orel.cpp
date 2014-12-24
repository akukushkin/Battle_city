
#include "orel.h"

OrelField::OrelField(int i, int j)
{
    setPos(j*ELEMENT,i*ELEMENT);
    setPixmap(QPixmap(":/images/orel.png"));
}
