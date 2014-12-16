#ifndef ELEMENT_FIELD_H
#define ELEMENT_FIELD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <basic_element.h>
#define ELEMENT 50
#include <QDebug>
class ElementField: public QObject, public BasicElement{
    Q_OBJECT
public:
    void abst() {return ;}
    ElementField(int i, int j);
private:
    int x;
    int y;
};

#endif // ELEMENT_FIELD_H
