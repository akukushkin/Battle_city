#ifndef OREL_H
#define OREL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <basic_element.h>
#define ELEMENT 50

class OrelField: public QObject, public BasicElement{
    Q_OBJECT
public:
    void info() {}
    OrelField(int i, int j);
};

#endif // OREL_H
