#include "field.h"
#include "kirpich.h"
#include "metall.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QtXml>
#include <cstdlib>

extern QGraphicsScene* scene;
extern QGraphicsView* view;

Field::Field(int _w, int _h, std::vector<int> mtr): QObject(), w(_w),h(_h) {
   matrixField = mtr;
   for(int i=0; i < h;i++){
        for (int j = 0; j < w;j++){
            if (matrixField[i+j*w] == 2){
                matrix.push_back(BasicElement::createElement(Kirpich_ID,j,i));
                scene->addItem(matrix.back());
            } else if (matrixField[i+j*w] == 3){
                matrix.push_back(BasicElement::createElement(Metall_ID,j,i));
                scene->addItem(matrix.back());
            } else
                matrix.push_back(NULL);
        }
    }
}

bool Field::check(int m, int k)
{
    qDebug() << "check";
    if (matrixField[m+k*w] != 0)
        return true;
    else
        return false;
}

void Field::destroy(BasicElement* element)
{
    for(int i = 0 ; i < h; i++)
        for (int j = 0; j < w; j++){
            if (matrix[i+j*w] == element){
                scene->removeItem(matrix[i+j*w]);
                delete matrix[i+j*w];
                matrix[i+j*w]=NULL;
                matrixField[j+i*w] = 0;
            }
        }
}
