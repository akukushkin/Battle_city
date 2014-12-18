#include "field.h"
#include "kirpich.h"
#include "metall.h"
#include <QGraphicsScene>
#include <QDebug>
extern QGraphicsScene *scene;
int MatrixField[12][12]={{0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,2,2,2,2,2,2,2,2,2,0},
                        {0,2,0,0,0,0,0,0,0,0,0,0},
                        {0,2,0,0,0,0,0,0,0,0,0,0},
                        {0,2,0,0,0,3,3,3,0,0,0,0},
                        {0,2,0,3,0,0,0,0,0,0,0,0},
                        {0,2,0,3,0,0,0,0,0,0,2,0},
                        {0,2,0,0,0,0,0,0,0,0,2,0},
                        {0,2,0,0,2,2,2,2,0,0,2,0},
                        {0,2,0,0,2,0,0,2,0,0,2,0},
                        {0,2,0,0,2,0,0,2,0,0,2,0},};
Field::Field(): QObject(), h(12), w(12) {
    for(int i=0; i < h;i++) {
         for (int j = 0; j < w;j++)
             matrixField.push_back(MatrixField[i][j]);
    }
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
    if (matrixField[m+k*12] != 0)
        return true;
    else
        return false;
}

void Field::destroy(BasicElement* element)
{
    for(int i = 0 ; i < h; i++)
        for (int j = 0; j < w; j++){
            if (matrix[i+j*12] == element){
                scene->removeItem(matrix[i+j*12]);
                delete matrix[i+j*12];
                matrix[i+j*12]=NULL;
                matrixField[j+i*12] = 0;
            }
        }
}
