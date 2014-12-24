#include "itankmoveable.h"

ITankMoveable::ITankMoveable(BaseTank* _tank): tank(_tank)
{
}

ITankMoveable::~ITankMoveable()
{
    tank = NULL;
}
