#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

#include <cstdlib>
#include <time.h>

class Food
{
    private:
        objPos foodPos;

    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff, int boardSizeX, int boardSizeY);
        objPos getFoodPos() const;
};

#endif