#ifndef KIRPICH_H
#define KIRPICH_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <basic_element.h>
#define ELEMENT 50
#include <QDebug>
class KirpichField: public QObject, public BasicElement{
    Q_OBJECT
public:
    void info() {qDebug() << "Kirpich";}
    KirpichField(int i, int j);
};


#endif // KIRPICH_H
