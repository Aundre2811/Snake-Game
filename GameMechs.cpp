#include "GameMechs.h"

// Default constructor (board 30x15)
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

// Destructor (not needed to delete anything yet)
GameMechs::~GameMechs()
{
    // No dynamic memory allocated, nothing to delete
}

// ---------------------- FLAG GETTERS/SETTERS ----------------------

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

// ---------------------- INPUT GET/SET ----------------------

char GameMechs::getInput() const
{
    return input;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// ---------------------- BOARD SIZE ----------------------

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

// ---------------------- SCORE ----------------------

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}
