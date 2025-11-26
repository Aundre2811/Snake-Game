#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* mainGameMechs;

objPos char1(3, 3, 'A');
objPos char2(4, 4, 'B');
objPos char3(5, 5, 'C');

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(mainGameMechs->getExitFlagStatus() == false) 
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    mainGameMechs = new GameMechs(20, 10);
}

void GetInput(void)
{
    // Check if a key was pressed
    if (MacUILib_hasChar())
    {
        char c = MacUILib_getChar();   // read the key
        mainGameMechs->setInput(c);    // store it inside GameMechs
    }
}


void RunLogic(void)
{
    char c = mainGameMechs->getInput();   // get the last key pressed

    // If the user presses 'x' or 'X', exit the game
    if (c == 'x' || c == 'X')
    {
        mainGameMechs->setExitTrue();
    }

    // If the user presses 'p' or 'P', increase the score (for testing)
    if (c == 'p' || c == 'P')
    {
        mainGameMechs->incrementScore();
    }

    // If the user presses 'l' or 'L', mark as lost and exit (for testing)
    if (c == 'l' || c == 'L')
    {
        mainGameMechs->setLoseFlag();
        mainGameMechs->setExitTrue();
    }

    // Clear the stored input so we don't reuse the same key forever
    mainGameMechs->clearInput();
}


void DrawScreen(void)
{
    MacUILib_clearScreen();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (j == 0 || j == 19 || i == 0 || i == 9)
            {
                MacUILib_printf("%s", "#");
            }

            else if (j == char1.pos->x && i == char1.pos->y)
            {
                MacUILib_printf("%c", char1.symbol);
            }

            else if (j == char2.pos->x && i == char2.pos->y)
            {
                MacUILib_printf("%c", char2.symbol);
            }

            else if (j == char3.pos->x && i == char3.pos->y)
            {
                MacUILib_printf("%c", char3.symbol);
            }

            else
            {
                MacUILib_printf("%s", " ");
            }

        

        }
        MacUILib_printf("\n");
    }

    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    // Print a simple message depending on loseFlag
    if (mainGameMechs->getLoseFlagStatus())
    {
        std::cout << "You lost! Final score: " << mainGameMechs->getScore() << std::endl;
    }
    else
    {
        std::cout << "Game exited. Final score: " << mainGameMechs->getScore() << std::endl;
    }

    MacUILib_uninit();

    delete mainGameMechs;
}

