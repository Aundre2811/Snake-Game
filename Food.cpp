#include "Food.h"

Food::Food()
{
    srand(time(NULL));
    foodPos.setObjPos(-1, -1, 'F');
}

Food::~Food()
{
}

void Food::generateFood(objPosArrayList* blockOffList, int boardSizeX, int boardSizeY) 
{
    objPos newPos;
    bool overlap;

    do
    {
        int randNumX = 1 + rand() % (boardSizeX - 2);
        int randNumY = 1 + rand() % (boardSizeY - 2);
        newPos.setObjPos(randNumX, randNumY, 'F');

        // assume no overlap until we find one
        overlap = false;

        if (blockOffList != NULL)
        {
            for (int i = 0; i < blockOffList->getSize(); i++)
            {
                objPos segment = blockOffList->getElement(i);

                if (newPos.isPosEqual(&segment))
                {
                    overlap = true;   // bad position, try again
                    break;
                }
            }
        }

    } while (overlap);  // keep re-rolling while overlapping

    foodPos = newPos;
}

objPos Food::getFoodPos() const
{
    return foodPos;
}
