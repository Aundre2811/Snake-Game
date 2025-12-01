#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200 // Max capacity for objPos array list

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList; // Pointer to array of objPos class objects
        int listSize; // Current number of elements in list
        int arrayCapacity; // Max possible size of allocated array

    public:
        objPosArrayList(); // Constructor - initializes empty list
        ~objPosArrayList(); // Destructor - deallocates anything on heap memory

        int getSize() const; // Returns size of snake (current number of elements)
        void insertHead(objPos thisPos); // Adds element at beginning of list
        void insertTail(objPos thisPos); // Adds element at end of list
        void removeHead(); // Removes element at beginning of list
        void removeTail(); // Removes element at end of list
        
        objPos getHeadElement() const; // Returns element at head of snake (read-only)
        objPos getTailElement() const; // Returns element at tail of snake (read-only)
        objPos getElement(int index) const; // Returns element at chosen index of list/snake (read-only)
};

#endif