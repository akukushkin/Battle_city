#ifndef METALL_H
#define METALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <basic_element.h>
#include <QDebug>

#define ELEMENT 50

class MetallField: public QObject, public BasicElement{
    Q_OBJECT
public:
    void info() {qDebug() << "Metall";}
    MetallField(int i, int j);
};

#endif // METALL_H
