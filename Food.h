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
    objPos foodPos;

public:
    Food();
    ~Food();

    // Now takes the whole snake body list so we can avoid all segments
    void generateFood(objPosArrayList* blockOffList, int boardSizeX, int boardSizeY);

    objPos getFoodPos() const;
};

#endif
