#include "Food.h"

// Default Constructor (Defines food to go on board) 
Food::Food()
{
    srand(time(NULL)); // Random number generator
    foodBucket = new objPosArrayList();
}

// Destructor
Food::~Food()
{
    delete foodBucket; // Deallocates foodBucket on heap
    foodBucket = NULL;
}

// Food generation function
void Food::generateFood(objPosArrayList* blockOffList, int boardSizeX, int boardSizeY) 
{
    // Removes food currently on board when function called upon
    while(foodBucket->getSize() > 0)
    {
        foodBucket->removeTail();
    }

    // Loops through all the food generations on board
    for (int foodNumber = 0; foodNumber < FOOD_MAX; foodNumber++)
    {
        objPos newPos; // Defines new position of food in objPos class
        bool overlap; // Boolean value to check if there is overlap between food and player
        char symbol; // Symbol of food

        do
        {
            // Random generation of food on board
            int randNumX = 1 + rand() % (boardSizeX - 2);
            int randNumY = 1 + rand() % (boardSizeY - 2);

            // Generating 3 regular food on board
            if (foodNumber < 3)
            {
                symbol = 'f';
            }

            // Generating 2 special food on board
            else
            {
                symbol = 'F';
            }

            newPos.setObjPos(randNumX, randNumY, symbol); // Sets food to specified spot on board

            // assume no overlap until we find one
            overlap = false;

            // Checks if food being generated is overlapping with player
            if (blockOffList != NULL)
            {
                for (int snakeLength = 0; snakeLength < blockOffList->getSize(); snakeLength++) // Loop runs for length of snake
                {
                    objPos snakeSegment = blockOffList->getElement(snakeLength); // Running through each element of the snake

                    if (newPos.isPosEqual(&snakeSegment)) // Checks if element of snake being checked is in the same position as randomly generated food
                    {
                        overlap = true;   // bad position, try again
                        break;
                    }
                }
            }

            // Checks if food overlaps with another piece of food generated already
            if (!overlap)
            {
                for(int foodCheck = 0; foodCheck < foodNumber; foodCheck++) // Loops through all food generated already
                {
                    objPos existingFood = foodBucket->getElement(foodCheck); // Creates copy of food position from foodBucket

                    // Checks if current food position being checked is equal to position of any previously generated food
                    if (newPos.isPosEqual(&existingFood))
                    {
                        overlap = true;
                        break;
                    }
                }
            }

        } while (overlap);  // keep re-rolling while overlapping

        foodBucket->insertTail(newPos); // Adds food to board
    }
}

// Checks position of food on board
objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}
