#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    int startPosX = mainGameMechsRef->getBoardSizeX()/2; //Using -> since pointer
    int startPosY = mainGameMechsRef->getBoardSizeY()/2;

    playerPos = objPos(startPosX, startPosY, '*');

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here   (ADD AFTER ALLOCATING SOMETHING TO HEAP)
}

void Player::getPlayerPos(objPos &returnPos) const
{
    // return the reference to the playerPos array list

    returnPos = playerPos; //Checking what the current playerpos is (since void function, defining playerPos as variable in check)

}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
        
        switch (mainGameMechsRef->getInput())
        {
            case mainGameMechsRef->setExitTrue():
                exitFlag;
                break;

            case LEFT:
                if (dir != RIGHT)
                {
                    dir = LEFT;
                }
                break;

            case RIGHT:
                if (dir != LEFT)
                {
                    dir = RIGHT;
                }  
                break;
            
            case UP:
                if (dir != DOWN)
                {
                    dir = UP;
                }
                break;

            case DOWN:
                if (dir != UP)
                {
                    dir = DOWN;
                }
                break;
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added
