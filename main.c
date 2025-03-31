#include <stdio.h>
#include "colors.h"

void moveUnoTres(char board[][4], int *playerCount, char player)
{
    int     x,
            y,
            nValid = 0;
    
    do {
        printf("Input coordinate or smth\n");
        scanf("%d,%d", &x, &y);
        if (board[x-1][y-1] == '\0')
        {
            nValid = 1;
            (*playerCount)++;
            board[x-1][y-1] = player;
            break;
        }
        else
        {
            printf("Try again bobo\n");
        }

    }while (nValid == 0);

}


void dosMove(char board[][4], int *unoCount, int *tresCount)
{
    int x,
        y,
        nValid = 0;
        do 
        {
            printf("Input coordinate or smth\n");
            scanf("%d,%d", &x, &y);
            if (board[x-1][y-1] == '1' || board[x-1][y-1] == '3')
            {
                nValid = 1;
                if (board[x-1][y-1] == '1')
                {
                    (*unoCount)--;
                }
                else
                {
                    (*tresCount)--;
                }
                board[x-1][y-1] = '\0';
                break;
            }
            else
            {
                printf("Try again bobo\n");
            }
    
        }while (nValid == 0);
}

void checkWin()
{

}

int main()
{
    int     i,
            j,
            unoCount = 0,
            tresCount = 0,
            turn = 1,
            go = 0;

    char board[4][4];

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            board[i][j] = '\0';
        }
    }
    while (unoCount + tresCount != 16)
    {
        moveUnoTres(board, &tresCount, '3');
        moveUnoTres(board, &unoCount, '1');
        dosMove(board, &unoCount, &tresCount);
    }

    return 0;
}