#include "Food.h"

Food::Food()
{
    srand(time(NULL));
    
    foodPos.setObjPos(-1, -1, 'F');
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff, int boardSizeX, int boardSizeY) 
{
    objPos newPos;

    do
    {
        int randNumX = 1 + rand() % (boardSizeX - 2);
        int randNumY = 1 + rand() % (boardSizeY - 2);
        newPos.setObjPos(randNumX, randNumY, 'F');
    } while (newPos.isPosEqual(&blockOff));

    foodPos = newPos; // Uses objPos copy assignment operator to define foodPos as newPos

}

objPos Food::getFoodPos() const
{
    return foodPos;
}