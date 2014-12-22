#ifndef BASIC_ELEMENT_H
#define BASIC_ELEMENT_H

#include <QGraphicsItem>

enum BasicElement_ID {Kirpich_ID,Metall_ID};

class BasicElement : public QGraphicsPixmapItem {
public:
    virtual void info() = 0;
    virtual ~BasicElement() {};
    static BasicElement* createElement(BasicElement_ID id,int i, int j);
};

#endif // BASIC_ELEMENT_H
