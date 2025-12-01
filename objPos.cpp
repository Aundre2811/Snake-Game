#include "objPos.h"
#include <cstddef> 

// Default Constructor for object position and symbol set at 0
objPos::objPos()
{
    pos = new Pos; // Creating Pos struct object on heap
    pos->x = 0; // Set x coordinate as 0 (Accessed through pointer from Pos struct)
    pos->y = 0; // Set y coordinate as 0 (Accessed through pointer from Pos struct)
    symbol = 0; // Symbol defined as NULL
}

// Constructor with allocated position and symbol
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//Destructor deleting Pos struct allocated on heap
objPos::~objPos()
{
    delete pos; // Free heap memory
    pos = NULL; // Prevent pointer left behind
}

//Copy Constructor
objPos::objPos(const objPos& o)
{
    pos = new Pos;

    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//Copy Assignment Operator
objPos& objPos::operator= (const objPos& o)
{
    if (this != &o) // Check for self assignment
    {
        // Checks if this pos isn't a struct object
        if(this->pos == NULL)
        {
            this->pos = new Pos; // Defines this pos as a struct object
        }

        // Copies from o Pos struct object to this Pos struct objects
        pos->x = o.pos->x;
        pos->y = o.pos->y;
        symbol = o.symbol;
    }
    return *this; //Dereferenced pointer to return this object

}

// Setting this pos as o struct object
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

// Setting this pos with allocated symbol and x,y, coordinates
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Returns copy of current pos struct object
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

// Returns symbol
char objPos::getSymbol() const
{
    return symbol;
}

// Checks if this pos position is equal to refPos position
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

// Return symbol of this pos if pos position is equal to refPos position
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0; // Returns 0 if they're not equal
}
