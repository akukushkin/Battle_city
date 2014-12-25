#include "field.h"
#include "kirpich.h"
#include "metall.h"
#include "orel.h"
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
            switch(matrixField[i+j*w]){
            case 2:
                matrix.push_back(BasicElement::createElement(Kirpich_ID,j,i));
                scene->addItem(matrix.back());
                break;
            case 3:
                matrix.push_back(BasicElement::createElement(Metall_ID,j,i));
                scene->addItem(matrix.back());
                break;
            case 7:
                matrix.push_back(BasicElement::createElement(Orel_ID,j,i));
                scene->addItem(matrix.back());
                break;
            case 8:
                matrix.push_back(BasicElement::createElement(Bonus_ID,j,i));
                scene->addItem(matrix.back());
                break;
            default:
                matrix.push_back(NULL);
                break;
            }
       }
    }
}

Field::~Field()
{
    for (unsigned   int i=0; i < matrix.size(); i++ ){
        scene->removeItem(matrix[i]);
        delete matrix[i];
    }
}

size_t Field::check(int m, int k)
{
    if (matrixField[k+m*w] != 0){
        if (matrixField[k+m*w] == 8) {
            destroy(m,k);
            return 2;
        }
        return 0;
    }
    else
        return 1;
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
void Field::destroy(int i, int j){
    scene->removeItem(matrix[i+j*w]);
    delete matrix[i+j*w];
    matrix[i+j*w]=NULL;
    matrixField[j+i*w] = 0;
}
