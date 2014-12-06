/*#include "field.h"

Field::Field(size_t _x, size_t _y): w(_x),h(_y)
{
    matrix = new size_t*[_x];
    for(int i=0; i< h; i++)
        matrix[i] = new size_t[w];
}
Field::~Field()
{
    for(int i=0; i< h; i++)
        delete[] matrix[i];
    delete[] matrix;
}
*/
