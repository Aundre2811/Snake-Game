#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

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

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
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
        
    }

    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
