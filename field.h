#ifndef FIELD_H
#define FIELD_H
#include <unistd.h>
#include <basic_element.h>
#include <vector>
#include <QObject>

class Field : public QObject{
Q_OBJECT
private:
    std::vector<BasicElement*> matrix;
    int h;
    int w;
public:
    Field();
signals:
    void obj_delete();
public slots:
    void checked_map(int x, int y);
    void checked_sten(int x, int y,int* temp);
};

#endif // FIELD_H
