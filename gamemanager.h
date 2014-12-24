#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "field.h"
#include "tank.h"
#include "bonus.h"
#include <vector>
#include "enemytank.h"

class GameManager {
private:
    Field* field;
    Tank* playerTank;
    std::vector<EnemyTank*> enemyPlayers;
    BonusField* bonus;
public:
    Field* callField() {return field;}
    Tank* callPlayerTank() {return playerTank;}
    BonusField* callBonus() {return bonus;}
    GameManager(char* str);
    ~GameManager();
    void destroyEnemyTank(BaseTank*);
};

#endif // GAMEMANAGER_H*/
