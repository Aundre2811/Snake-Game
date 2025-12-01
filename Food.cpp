#include "Food.h"

// Default Constructor (Defines food outside board) 
Food::Food()
{
    srand(time(NULL)); // Random number generator
    foodPos.setObjPos(-1, -1, 'F');
}

// Destructor
Food::~Food()
{
    // No allocation to heap so no delete needed
}

// Food generation function
void Food::generateFood(objPosArrayList* blockOffList, int boardSizeX, int boardSizeY) 
{
    objPos newPos; // Defines new position of food in objPos class
    bool overlap; // Boolean value to check if there is overlap between food and player

    do
    {
        // Random generation of food on board
        int randNumX = 1 + rand() % (boardSizeX - 2);
        int randNumY = 1 + rand() % (boardSizeY - 2);
        newPos.setObjPos(randNumX, randNumY, 'F');

        // assume no overlap until we find one
        overlap = false;

        // Checks if food being generated is overlapping with player
        if (blockOffList != NULL)
        {
            for (int i = 0; i < blockOffList->getSize(); i++) // Loop runs for length of snake
            {
                objPos segment = blockOffList->getElement(i); // Running through each element of the snake

                if (newPos.isPosEqual(&segment)) // Checks if element of snake being checked is in the same position as randomly generated food
                {
                    overlap = true;   // bad position, try again
                    break;
                }
            }
        }

    } while (overlap);  // keep re-rolling while overlapping

    foodPos = newPos;
}

// Checks position of food on board
objPos Food::getFoodPos() const
{
    return foodPos;
}
