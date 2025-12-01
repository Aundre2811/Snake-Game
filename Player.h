#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        // Enumeration with directions snake can move with corresponding key presses
        enum Dir 
        {
            UP = 'w', 
            DOWN = 's', 
            LEFT = 'a', 
            RIGHT = 'd', 
            STOP
        };

        Player(GameMechs* thisGMRef, Food* thisFoodRef); // Constructor - Initializes player with GameMechs and Food references
        ~Player(); // Deallocates heap memory

        objPosArrayList* getPlayerPos() const; // Returns pointer to player position list

        void updatePlayerDir(); // Updates player movement direction
        void movePlayer(); // Player position update algorithm

    private:
        objPosArrayList* playerPosList; // Snake body list
        Dir myDir; // Direction of player created from Dir enum

        GameMechs* mainGameMechsRef; // Pointer to GameMechs class
        Food* foodRef; // Pointer to Food class
};

#endif
