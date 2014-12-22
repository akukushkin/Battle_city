#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "field.h"
#include "tank.h"

class GameManager {
private:
    Field* field;
    Tank* playerTank;
public:
    Field* callField() {return field;}
    Tank* callPlayerTank() {return playerTank;}
    GameManager(char* str);
    ~GameManager();
};

#endif // GAMEMANAGER_H*/
