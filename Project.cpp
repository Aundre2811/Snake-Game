#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

//Added from Player.h File
#include "GameMechs.h" 
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* mainGameMechs;




class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir 
        {
            UP = 'w', 
            DOWN = 's', 
            LEFT = 'a', 
            RIGHT = 'd', 
            STOP
        };  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPos &returnPos) const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here

    private:
        objPos playerPos; // Upgrade this in iteration 3. //Holds player position and ASCII symbol
        enum Dir myDir; // myDir declared as variable of type enum Dir (up, down, left, right, stop)

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef; //Creates pointer (reference) to GameMechs class to utilize it

        // Pass any new classes references into Player object (same thing as with GameMechs)
};





Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    int startPosX = mainGameMechsRef->getBoardSizeX()/2; //Using -> since pointer
    int startPosY = mainGameMechsRef->getBoardSizeY()/2;

    playerPos = objPos(startPosX, startPosY, '*');

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here   (ADD AFTER ALLOCATING SOMETHING TO HEAP)
}

void Player::getPlayerPos(objPos &returnPos) const
{
    // return the reference to the playerPos array list

    returnPos = playerPos; //Checking what the current playerpos is (since void function, defining playerPos as variable in check)

}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
        
        switch (mainGameMechsRef->getInput())
        {
            case 27:
                mainGameMechsRef->setExitTrue();
                break;

            case LEFT:
                if (myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;

            case RIGHT:
                if (myDir != LEFT)
                {
                    myDir = RIGHT;
                }  
                break;
            
            case UP:
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

            case DOWN:
                if (myDir != UP)
                {
                    myDir = DOWN;
                }
                break;
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}









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

            else if (j == playerPos.pos->x && i == playerPos.pos->y)
            {
                MacUILib_printf("%c", playerPos.symbol);
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

