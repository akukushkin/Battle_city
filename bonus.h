#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <basic_element.h>
#define ELEMENT 50
#include <QDebug>

class BonusField: public QObject, public BasicElement{
    Q_OBJECT
public:
    void info() {qDebug() << "Bonus";}
    BonusField(int i, int j);
};

#endif // BONUS_H
