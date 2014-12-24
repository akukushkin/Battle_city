#include "bonus.h"


BonusField::BonusField(int i, int j)
{
    setPos(j*ELEMENT,i*ELEMENT);
    setPixmap(QPixmap(":/images/bonus.png"));
}
