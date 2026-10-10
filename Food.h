#ifndef FOOD_H
#define FOOD_H

#define FOOD_MAX 5

#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

#include <cstdlib>
#include <time.h>

class Food
{
private:
    objPosArrayList* foodBucket; // Defining position of food through objPos class

public:
    Food(); // Constructor
    ~Food(); // Destructor

    // Now takes the whole snake body list so we can avoid all segments
    void generateFood(objPosArrayList* blockOffList, int boardSizeX, int boardSizeY);

    objPosArrayList* getFoodPos() const; // Returns pointer to foodlist
};

#endif
