#include "GameMechs.h"

// Default constructor (board 20x10)
GameMechs::GameMechs()
{
    boardSizeX = 20;   
    boardSizeY = 10;

    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

// Constructor with custom board size
GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

// Destructor (No dynamic memory to delete)
GameMechs::~GameMechs()
{

}

// Checks exit flag status (whether exiting game or not)
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

// Exit game (set exit flag to true)
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

// Checks lose flag status (whether player lost or not)
bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}

// Player loses (Set lose flag as true)
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

// Receives input of ASCII input character from user
char GameMechs::getInput() const
{
    return input;
}

// Sets input
void GameMechs::setInput(char this_input)
{
    input = this_input;
}

// Clears input to ensure no double input processed
void GameMechs::clearInput()
{
    input = 0;
}

// Receives length of board x direction
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

// Receives length of board in y direction
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

// Checks user score
int GameMechs::getScore() const
{
    return score;
}

// Adds to user score with customizable score
void GameMechs::incrementScore(int scoreAdder)
{
    score += scoreAdder;
}
