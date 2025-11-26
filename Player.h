#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir 
        {
            UP = 'w', 
            DOWN = 's', 
            LEFT = 'a', 
            RIGHT = 'd', 
            STOP
        };  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPos &returnPos) const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here

    private:
        objPos playerPos; // Upgrade this in iteration 3. //Holds player position and ASCII symbol
        enum Dir myDir; // myDir declared as variable of type enum Dir (up, down, left, right, stop)

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef; //Creates pointer (reference) to GameMechs class to utilize it

        // Pass any new classes references into Player object (same thing as with GameMechs)
};

#endif