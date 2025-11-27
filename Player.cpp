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
            case LEFT:
                if (myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;

            case RIGHT:
                if (myDir != LEFT)
                {
                    myDir = RIGHT;
                }  
                break;
            
            case UP:
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

            case DOWN:
                if (myDir != UP)
                {
                    myDir = DOWN;
                }
                break;
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    int currentX = playerPos.getObjPos().pos->x;
    int currentY = playerPos.getObjPos().pos->y;

    switch(myDir)
    {
        case LEFT:
            currentX--;  

            if(currentX == 0)
                {
                    currentX = mainGameMechsRef->getBoardSizeX() - 2;
                }

            break;
        
        case RIGHT:
            currentX++;

            if (currentX == mainGameMechsRef->getBoardSizeX() - 1)
                {
                    currentX = 1;
                }

            break;

        case UP:
            currentY--;

            if(currentY == 0)
            {
                currentY = mainGameMechsRef->getBoardSizeY() - 2;
            }

            break;

        case DOWN:
            currentY++;

            if(currentY == mainGameMechsRef->getBoardSizeY() - 1)
            {
                currentY = 1;
            }

            break;

    }
    playerPos.setObjPos(currentX, currentY, playerPos.getSymbol());
}
