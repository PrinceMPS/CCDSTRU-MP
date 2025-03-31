#include <stdio.h>
#include "colors.h"

typedef struct
{
    int x;
    int y;
} posType; //struct for positions on the board

typedef struct 
{
    posType position[16];
    int     numPositions;
} playerType; //struct for UNO and TRES

typedef playerType winType[4]; //struct array for win conditions

/*FUNCTION PROTOTYPES*/

void initializeWin(winType W);
int searchPosition();
int checkWin();
void deletePosition();

/*FUNCTION DEFINITIONS*/
void initializeWin(winType W)
{
    int i, j;

    // Win condition 1: Top rows
    for(i = 1; i <= 4; i++)
    {
        W[0].numPositions = 4;
        W[0].position[i-1].x = 1;
        W[0].position[i-1].y = i;
    }
    // Win condition 2: Top left to bottom right
    for(i = 1; i <= 4; i++)
    {
        W[1].numPositions = 4;
        W[1].position[i-1].x = i;
        W[1].position[i-1].y = i;
    }
    // Win condition 3: Top right to bottom left
    for(i = 1, j = 4; i <= 4; i++, j--)
    {
        W[2].numPositions = 4;
        W[2].position[i-1].x = i;
        W[2].position[i-1].y = j;
    }
    // Win condition 4: Bottom rows
    for(i = 1; i <= 4; i++)
    {
        W[3].numPositions = 4;
        W[3].position[i-1].x = 4;
        W[3].position[i-1].y = i;
    }
}

int main()
{
    playerType UNO,
               TRES;
    posType    pos; // inputted position will be placed here first for checking before being assigned to a player
    winType    W; // Win conditions
    int        turn = 1; // True
    int        go = 0; // False

    UNO.numPositions = 0;
    TRES.numPositions = 0;

    initializeWin(W);

    return 0;
}