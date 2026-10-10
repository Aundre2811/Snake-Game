#include "Player.h"

// Constructor which initializes player at center of board
Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef; // Pointer to GameMechs Class
    foodRef = thisFoodRef; // Pointer to Food Class
    myDir = STOP; // Player starts with no movement

    // Player positioned at centre of board
    int startPosX = mainGameMechsRef->getBoardSizeX() / 2;
    int startPosY = mainGameMechsRef->getBoardSizeY() / 2;

    // Create the snake body list on the heap
    playerPosList = new objPosArrayList();

    // Start with a single head segment
    objPos head(startPosX, startPosY, '*');
    playerPosList->insertHead(head);
}

// Destructor
Player::~Player()
{
    // Clean up heap memory
    delete playerPosList;
    playerPosList = NULL;
}

// Return pointer to player position list
objPosArrayList* Player::getPlayerPos() const
{
    // return the list so other code (draw, food) can see all segments
    return playerPosList;
}

// Update the direction the player is moving in
void Player::updatePlayerDir()
{
    // Receives input from player and checks corresponding direction
    switch (mainGameMechsRef->getInput())
    {
        // Move left if character is not initially moving to the right
        case LEFT:
            if (myDir != RIGHT)  
            {
                myDir = LEFT;
            }
            break;

        // Move right if character is not initially moving to the left
        case RIGHT:
            if (myDir != LEFT) 
            {  
                myDir = RIGHT;
            }
            break;

        // Move up if character is not initially moving down
        case UP:
            if (myDir != DOWN)   
            {
                myDir = UP;
            }
            break;

        // Move down if character is not initially moving up
        case DOWN:
            if (myDir != UP)     
            {
                myDir = DOWN;
            }
            break;

        // Break if none of above conditions met
        default:
            break;
    }
}

// Player position update algorithm
void Player::movePlayer()
{
    // If we haven't started moving, do nothing
    if (myDir == STOP)
    {
        return;
    }

    // Get current head position
    objPos head = playerPosList->getHeadElement();
    int newX = head.getObjPos().pos->x;
    int newY = head.getObjPos().pos->y;

    // Compute new position with use of wraparound logic
    switch (myDir)
    {
        // Moves to the left, updating player position
        case LEFT:
            newX--;
            if (newX == 0) // If player hits border
            {
                newX = mainGameMechsRef->getBoardSizeX() - 2; // Relocate player to other side of board
            }
            break;

        // Moves to the right
        case RIGHT:
            newX++;
            if (newX == mainGameMechsRef->getBoardSizeX() - 1)
            {
                newX = 1;
            }
            break;

        // Moves up
        case UP:
            newY--;
            if (newY == 0)
            {
                newY = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;

        // Moves down
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

    // Create the new head of snake
    objPos newHead(newX, newY, head.getSymbol());

    // Insert new head
    playerPosList->insertHead(newHead);

    // Loops through each element of snake to check if head hits any part of its body
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        objPos elementCheck = playerPosList->getElement(i); // Variable of objPos class created to hold element being checked
        if (newHead.isPosEqual(&elementCheck)) // Checks if head is equal to position of element on snake body being checked (if head hits body)
        {
            // Player loses and exits game
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

    // Checks if this new head position collides with the food
    objPosArrayList* foodList = foodRef->getFoodPos();

    bool ateFood = false; // Food is not eaten

    // Looping through all food that can possibly be eaten
    for (int foodCheck = 0; foodCheck < foodList->getSize(); foodCheck++)
    {
        objPos currentFoodPos = foodList->getElement(foodCheck); // Gets food item from foodlist

        // Checks if snake head collides with food
        if (newHead.isPosEqual(&currentFoodPos))
        {
            ateFood = true;

            if(currentFoodPos.getSymbol() == 'F') // Checking if special food collided with
            {
                // Increase score by 10
                mainGameMechsRef->incrementScore(10);
            }

            else 
            {
                // Increase score by 1
                mainGameMechsRef->incrementScore(1);
            }

            // Generate new food that avoids the snake body
            foodRef->generateFood(playerPosList, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY());
            break;
        }
    }


    if (!ateFood)
    {
        // Remove tail from snake
        playerPosList->removeTail();   
    }

    
}
