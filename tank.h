#ifndef TANK_H
#define TANK_H

#include <unistd.h>
#include <QGraphicsRectItem>
#include <QObject>
#include "basetank.h"

class Tank : public BaseTank
{
    Q_OBJECT
public:
    explicit Tank();
    explicit Tank(size_t x, size_t y);
    void keyPressEvent(QKeyEvent *event);
protected:
    void move(int direction);
};

#endif

