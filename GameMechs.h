#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private:
        char input; // Input from user
        bool exitFlag; // Exiting game or not
        bool loseFlag; // Loss or no loss
        int score; // Game score

        int boardSizeX; // Length of board size in x direction
        int boardSizeY; // Length of board size in y direction

    public:
        GameMechs(); // Default constructor of game
        GameMechs(int boardX, int boardY); // Constructor with custom board size
        ~GameMechs(); // Deallocates memory on heap
        
        bool getExitFlagStatus() const; // Check whether game exit or not (read-only)
        void setExitTrue(); // Set as game exits 
        bool getLoseFlagStatus() const; // Check whether player lost or not (read-only)
        void setLoseFlag(); // Sets as player lost

        char getInput() const; // Receive ASCII input from user (read-only)
        void setInput(char this_input); // Sets input character
        void clearInput(); // Clears input

        int getBoardSizeX() const; // Check board length in x direction (read-only)
        int getBoardSizeY() const; // Check board length in y direction (read-only)
        
        int getScore() const; // Return score of player (read-only)
        void incrementScore(int scoreAdder); // Add to player score
        
};

#endif