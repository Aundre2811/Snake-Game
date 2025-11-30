#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* mainGameMechs;
Player* player;
Food* food;









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

    // Food must exist before Player since Player stores a Food*
    food = new Food();
    player = new Player(mainGameMechs, food);

    // Generate the first food, blocking off the whole snake body
    objPosArrayList* bodyList = player->getPlayerPos();
    food->generateFood(bodyList,
                       mainGameMechs->getBoardSizeX(),
                       mainGameMechs->getBoardSizeY());
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

    player->updatePlayerDir();
    player->movePlayer();

    // Clear the stored input so we don't reuse the same key forever
    mainGameMechs->clearInput();

}


void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPos currentFoodPos = food->getFoodPos();
    objPosArrayList* bodyList = player->getPlayerPos();

    for (int i = 0; i < mainGameMechs->getBoardSizeY(); i++)
    {
        for (int j = 0; j < mainGameMechs->getBoardSizeX(); j++)
        {
            bool printed = false;

            // 1) Borders
            if (j == 0 || j == mainGameMechs->getBoardSizeX() - 1 ||
                i == 0 || i == mainGameMechs->getBoardSizeY() - 1)
            {
                MacUILib_printf("#");
                printed = true;
            }
            else
            {
                // 2) Snake body – check every segment
                for (int k = 0; k < bodyList->getSize(); k++)
                {
                    objPos segment = bodyList->getElement(k);

                    if (j == segment.getObjPos().pos->x &&
                        i == segment.getObjPos().pos->y)
                    {
                        MacUILib_printf("%c", segment.symbol);
                        printed = true;
                        break;
                    }
                }

                // 3) Food (if no snake printed here)
                if (!printed &&
                    j == currentFoodPos.getObjPos().pos->x &&
                    i == currentFoodPos.getObjPos().pos->y)
                {
                    MacUILib_printf("%c", currentFoodPos.symbol);
                    printed = true;
                }
            }

            // 4) Empty space
            if (!printed)
            {
                MacUILib_printf(" ");
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
    delete player;
    delete food;
}

