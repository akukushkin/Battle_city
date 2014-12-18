#include "basic_element.h"
#include "kirpich.h"
#include "metall.h"
BasicElement *BasicElement::createElement(BasicElement_ID id,int i, int j)
{
        BasicElement *p;
        switch (id) {
        case Kirpich_ID:
            p = new KirpichField(i,j);
            break;
        case Metall_ID:
            p = new MetallField(i,j);
            break;
        default:
            break;
        }
        return p;
}
