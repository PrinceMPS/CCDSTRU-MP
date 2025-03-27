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

int main()
{
    playerType UNO,
               TRES;
    int        turn = 1; // True
    int        go = 0; // False

    return 0;
}