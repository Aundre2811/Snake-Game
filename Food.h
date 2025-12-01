#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

#include <cstdlib>
#include <time.h>

class Food
{
private:
    objPos foodPos; // Defining position of food through objPos class

public:
    Food(); // Constructor
    ~Food(); // Destructor

    // Now takes the whole snake body list so we can avoid all segments
    void generateFood(objPosArrayList* blockOffList, int boardSizeX, int boardSizeY);

    objPos getFoodPos() const; // Checks position of food
};

#endif
