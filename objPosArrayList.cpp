#include "objPosArrayList.h"
#include <cstddef> 

// Default Constructor to initialize array size and list size
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; // Set capacity of maximum (200 elements) allocated in heap array
    listSize = 0; // valid list elements in list
    aList = new objPos[arrayCapacity]; // Pointer to start of objPos array list with 200 array size
}

// Destructor (deallocates heap data members and resets listSize and arrayCapacity)
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
    aList = NULL;
    
    listSize = 0;
    arrayCapacity = 0;

}

// Return size of list size
int objPosArrayList::getSize() const
{
    return listSize;
}

// Inserts new element at head of snake
void objPosArrayList::insertHead(objPos thisPos)
{
    
    // Checks if list size is bigger than array capacity (can't add head of this is the case)
    if (listSize >= arrayCapacity)
    {
        return;
    }

    // Moving every part of snake by one to make room
    for (int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1];
    }

    // Add at head of snake
    aList[0] = thisPos;

    // Increase size of snake
    listSize++;
}

// Add tail to snake; snake grows longer
void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity)
    {
        return;
    }

    // Adding at tail of snake
    aList[listSize] = thisPos;
    listSize++;
}

// Removing head of snake
void objPosArrayList::removeHead()
{
    if (listSize <= 0)
    {
        return;  
    }

    // Shifting parts of snake to take away room for snake head
    for (int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i + 1];
    }

    // Reduce size of list
    listSize--;
}

// Remove tail of snake
void objPosArrayList::removeTail()
{
    if (listSize <= 0)
    {
        return;
    }

    
    listSize--;
}

// Return element at head of snake
objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

// Return element at tail of snake
objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

// Return element at specified point of snake
objPos objPosArrayList::getElement(int index) const
{
    
    // If index being checked is not within size of snake, empty objPos
    if (index < 0 || index >= listSize)
    {
        
        objPos empty;
        return empty;
    }

    return aList[index];
}