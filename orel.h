#ifndef OREL_H
#define OREL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <basic_element.h>
#define ELEMENT 50
#include <QDebug>
class OrelField: public QObject, public BasicElement{
    Q_OBJECT
public:
    void info() {qDebug() << "OREL!";}
    OrelField(int i, int j);
};

#endif // OREL_H
