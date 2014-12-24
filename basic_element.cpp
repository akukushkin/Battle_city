#include "basic_element.h"
#include "kirpich.h"
#include "metall.h"
#include "orel.h"
#include "bonus.h"
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
        case Orel_ID:
            p = new OrelField(i,j);
            break;
        case Bonus_ID:
            p = new BonusField(i,j);
            break;
        default:
            break;
        }
        return p;
}
