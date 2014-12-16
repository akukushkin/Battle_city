#include "field.h"
#include "element_field.h"
#include "kirpich.h"
#include <QGraphicsScene>
#include <QDebug>
extern QGraphicsScene *scene;
int MatrixField[12][12]={{0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,2,2,2,2,2,2,2,2,2,0},
                        {0,2,0,0,0,0,0,0,0,0,0,0},
                        {0,2,0,0,0,0,0,0,0,0,0,0},
                        {0,2,0,0,0,0,0,0,0,0,0,0},
                        {0,2,0,0,0,0,0,0,0,0,0,0},
                        {0,2,0,0,0,0,0,0,0,0,2,0},
                        {0,2,0,0,0,0,0,0,0,0,2,0},
                        {0,2,0,0,2,2,2,2,0,0,2,0},
                        {0,2,0,0,2,0,0,2,0,0,2,0},
                        {0,2,0,0,2,0,0,2,0,0,2,0},};
Field::Field(): QObject(), h(12), w(12) {


    KirpichField* kirpich;
    for(int i=0; i < h;i++){
        for (int j = 0; j < w;j++){
            if (MatrixField[i][j] == 2){
                kirpich= new KirpichField(i,j);
                scene->addItem(kirpich);
                matrix.push_back(kirpich);
            } else
                matrix.push_back(NULL);
        }
    }
}

void Field::checked_map(int x, int y)
{
    int k = x/50;
    int m = y/50;
    qDebug() << k << m;
    if (k > 11 || m > 11)
        return;
    if (MatrixField[m][k] != 0){
        MatrixField[m][k] = 0;
        scene->removeItem(matrix[k+12*m]);
        delete matrix[k+12*m];
        emit obj_delete();
        return;
    }
    return;
}

void Field::checked_sten(int x, int y, int* temp)
{
    int k = x/50;
    int m = y/50;
    //qDebug() << k << m;
    if (k > 11 || m > 11)
        return;
    if (MatrixField[m][k] != 0){
        *temp = 0;
    }
    else *temp = 1;
    return ;
}
