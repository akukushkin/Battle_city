#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "field.h"
#include "tank.h"
#include "bonus.h"

class GameManager {
private:
    Field* field;
    Tank* playerTank;
    BonusField* bonus;
public:
    Field* callField() {return field;}
    Tank* callPlayerTank() {return playerTank;}
    BonusField* callBonus() {return bonus;}
    GameManager(char* str);
    ~GameManager();
};

#endif // GAMEMANAGER_H*/
