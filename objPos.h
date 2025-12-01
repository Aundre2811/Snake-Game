#ifndef OBJPOS_H
#define OBJPOS_H

// Struct for x and y position coordinates
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos; // Pointer to Pos struct 
        char symbol; 

        objPos(); // Default Constructor
        objPos(int xPos, int yPos, char sym); // Constructor with allocated coordinates and symbol

        ~objPos(); // Destructor
        objPos(const objPos& o); // Copy Constructor (Deep Copy)
        objPos& operator= (const objPos& o); // Copy Assignment Operator (Deep Copy)
        
        void setObjPos(objPos o); // Set position of this pos as o struct object      
        void setObjPos(int xPos, int yPos, char sym); // Set this pos to allocated coordinates and symbol

        objPos getObjPos() const; // Returns copy of current pos struct object (read-only)
        char getSymbol() const; // Returns symbol of this pos (read-only)
        bool isPosEqual(const objPos* refPos) const; // Checks if this pos is equal to referenced pos (read-only)
        char getSymbolIfPosEqual(const objPos* refPos) const; // Receives symbol if this pos is equal to referenced pos (read-only)
};

#endif