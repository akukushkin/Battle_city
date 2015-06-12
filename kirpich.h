#ifndef KIRPICH_H
#define KIRPICH_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <basic_element.h>
#include <QDebug>

#define ELEMENT 50

class KirpichField: public QObject, public BasicElement{
    Q_OBJECT
public:
    void info() {qDebug() << "Kirpich";}
    KirpichField(int i, int j);
};

#endif // KIRPICH_H
