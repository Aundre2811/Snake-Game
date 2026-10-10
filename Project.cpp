#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

// Pointers to allocated classes
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

    // Game runs while not exiting
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

    mainGameMechs = new GameMechs(20, 10); // Using GameMechs default constructor to create 20 x 10 board

    food = new Food(); // Creates food object
    player = new Player(mainGameMechs, food); // Creates player object

    // Generate food which does not touch snake body
    objPosArrayList* bodyList = player->getPlayerPos();
    food->generateFood(bodyList, mainGameMechs->getBoardSizeX(), mainGameMechs->getBoardSizeY());
}


void GetInput(void)
{
    // Check if a key was pressed
    if (MacUILib_hasChar())
    {
        char c = MacUILib_getChar(); // Read the key pressed
        mainGameMechs->setInput(c); // Store key pressed inside GameMechs
    }
}


void RunLogic(void)
{
    char c = mainGameMechs->getInput(); // Get the last key pressed

    // Exit when 'x' or 'X' pressed
    if (c == 'x' || c == 'X')
    {
        mainGameMechs->setExitTrue();
    }

    // Update player direction and move snake
    player->updatePlayerDir();
    player->movePlayer();

    mainGameMechs->clearInput(); // Clear the stored input so we don't reuse the same key forever

}


void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPosArrayList* foodList = food->getFoodPos(); // Checking current food position
    objPosArrayList* bodyList = player->getPlayerPos(); // Checking position of player

    // Nested loop which goes through every section of board dimensions
    for (int i = 0; i < mainGameMechs->getBoardSizeY(); i++)
    {
        for (int j = 0; j < mainGameMechs->getBoardSizeX(); j++)
        {
            bool printed = false; // Nothing printed

            // Board borders
            if (j == 0 || j == mainGameMechs->getBoardSizeX() - 1 || i == 0 || i == mainGameMechs->getBoardSizeY() - 1)
            {
                MacUILib_printf("#");
                printed = true;
            }

            else
            {
                // Checks every segment of snake body
                for (int k = 0; k < bodyList->getSize(); k++)
                {
                    objPos segment = bodyList->getElement(k);

                    // Printing body of snake at position it's located
                    if (j == segment.getObjPos().pos->x && i == segment.getObjPos().pos->y)
                    {
                        MacUILib_printf("%c", segment.symbol);
                        printed = true;
                        break;
                    }
                }

                // Food printed (if no snake printed here)
                if(!printed)
                {
                    // Checking if food exists at current spot on board and drawing it
                    for (int foodCheck = 0; foodCheck < foodList->getSize(); foodCheck++)
                    {
                        objPos currentFoodPos = foodList->getElement(foodCheck);

                        if(i == currentFoodPos.getObjPos().pos->y && j == currentFoodPos.getObjPos().pos->x)
                        {
                            MacUILib_printf("%c", currentFoodPos.symbol);
                            printed = true;
                            break;
                        }
                    }
                }
            }

            // Empty space
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

    // Message printed depending on loseFlag

    if (mainGameMechs->getLoseFlagStatus())
    {
        std::cout << "You lost! Final score: " << mainGameMechs->getScore() << std::endl;
    }
    else // If player manually exited game
    {
        std::cout << "Game exited. Final score: " << mainGameMechs->getScore() << std::endl;
    }

    MacUILib_uninit();

    // Deallocate heap members
    delete mainGameMechs;
    delete player;
    delete food;
}

