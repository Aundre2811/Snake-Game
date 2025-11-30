#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"          // so Player can talk to Food

class Player
{
public:
    enum Dir 
    {
        UP = 'w', 
        DOWN = 's', 
        LEFT = 'a', 
        RIGHT = 'd', 
        STOP
    };

    // NOTE: now also gets a Food pointer
    Player(GameMechs* thisGMRef, Food* thisFoodRef);
    ~Player();

    // Iteration 3: now returns the WHOLE list
    objPosArrayList* getPlayerPos() const;

    void updatePlayerDir();
    void movePlayer();

private:
    objPosArrayList* playerPosList;   // snake body list
    Dir myDir;

    GameMechs* mainGameMechsRef;      // game settings, score, etc.
    Food* foodRef;                    // to check / regenerate food
};

#endif
