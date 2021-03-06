#ifndef FIELD_H
#define FIELD_H

#include <unistd.h>
#include <basic_element.h>
#include <vector>
#include <QObject>
#include "tank.h"

class Field : public QObject{
Q_OBJECT
private:
    std::vector<BasicElement*> matrix;
    std::vector<int> matrixField;
    int w;
    int h;
public:
    Field(int,int,std::vector<int>);
    ~Field();
    size_t check(int m,int k);
    void destroy(BasicElement* element);
    void destroy(int i, int j);
signals:
    void obj_delete();
};

#endif // FIELD_H
