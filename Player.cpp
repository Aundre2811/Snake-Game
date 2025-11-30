#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;
    myDir = STOP;

    int startPosX = mainGameMechsRef->getBoardSizeX() / 2;
    int startPosY = mainGameMechsRef->getBoardSizeY() / 2;

    // Create the snake body list on the heap
    playerPosList = new objPosArrayList();

    // Start with a single head segment
    objPos head(startPosX, startPosY, '*');
    playerPosList->insertHead(head);
}

Player::~Player()
{
    // Clean up heap memory
    delete playerPosList;
    playerPosList = NULL;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the list so other code (draw, food) can see all segments
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // Same FSM you already had :contentReference[oaicite:2]{index=2}
    switch (mainGameMechsRef->getInput())
    {
        case LEFT:
            if (myDir != RIGHT)  myDir = LEFT;
            break;

        case RIGHT:
            if (myDir != LEFT)   myDir = RIGHT;
            break;

        case UP:
            if (myDir != DOWN)   myDir = UP;
            break;

        case DOWN:
            if (myDir != UP)     myDir = DOWN;
            break;

        default:
            break;
    }
}

void Player::movePlayer()
{
    // If we haven't started moving, do nothing
    if (myDir == STOP)
    {
        return;
    }

    // ----- 1. Get current head position -----
    objPos head = playerPosList->getHeadElement();
    int newX = head.getObjPos().pos->x;
    int newY = head.getObjPos().pos->y;

    // ----- 2. Compute new position with wraparound (same logic as before) -----
    switch (myDir)
    {
        case LEFT:
            newX--;
            if (newX == 0)
            {
                newX = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;

        case RIGHT:
            newX++;
            if (newX == mainGameMechsRef->getBoardSizeX() - 1)
            {
                newX = 1;
            }
            break;

        case UP:
            newY--;
            if (newY == 0)
            {
                newY = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;

        case DOWN:
            newY++;
            if (newY == mainGameMechsRef->getBoardSizeY() - 1)
            {
                newY = 1;
            }
            break;

        default:
            break;
    }

    // ----- 3. Create the new head segment -----
    objPos newHead(newX, newY, head.getSymbol());

    // ----- 4. Check if this new position hits the food -----
    objPos currentFoodPos = foodRef->getFoodPos();
    bool ateFood =
        (newX == currentFoodPos.getObjPos().pos->x) &&
        (newY == currentFoodPos.getObjPos().pos->y);

    // ----- 5. Insert new head -----
    playerPosList->insertHead(newHead);


    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        objPos elementCheck = playerPosList->getElement(i);
        if (newHead.isPosEqual(&elementCheck))
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

    if(ateFood)
    {
        // Ate food:
        //  - DO NOT remove tail  -> snake grows by 1
        //  - Increase score
        //  - Generate new food that avoids the snake body
        mainGameMechsRef->incrementScore();

        foodRef->generateFood(
            playerPosList,
            mainGameMechsRef->getBoardSizeX(),
            mainGameMechsRef->getBoardSizeY()
        );
    }


    else
    {
        // Normal movement: remove tail (length stays same)
        playerPosList->removeTail();   
    }

    
}
