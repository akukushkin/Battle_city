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
    int h;
    int w;
public:
    Field();
    bool check(int m,int k);
    void destroy(BasicElement* element);
signals:
    void obj_delete();
};
#endif // FIELD_H
