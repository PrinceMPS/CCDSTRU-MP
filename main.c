#include <stdio.h>
#include "colors.h"

/*  Asks for input from the player and adds their position to the board if its valid
    @param board - 2d array containing the positions of UNO and TRES
    @param playerCount - address of the number of positions occupied by the player
    @param player - the character representing the player
    @return void
*/
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
        }
        else
        {
            printf("Try again bobo\n");
        }

    }while (nValid == 0);
}

int checkWin(char board[][4], int playerCount, char player)
{
    int x, y, // indices of the board
        playerWin = 0; // to check if player positions match one of the win conditions

    if(playerCount == 4)
    {
        // Check top row
        y = 0;
        while(board[0][y] == player && y < 4)
        {
            y++;
            playerWin++;
        }

        // Check top left to bottom right
        if(playerWin < 4)
        {   
            playerWin = 0;
            x = 0; 
            y = 0;
            while (board[x][y] == player && x < 4 && y < 4)
            {
                x++;
                y++;
                playerWin++;
            }  
        }

        // Check top right to bottom left
        if(playerWin < 4)
        {   
            playerWin = 0;
            x = 0; 
            y = 3;
            while (board[x][y] == player && x < 4 && y >= 0)
            {
                x++;
                y--;
                playerWin++;
            }    
        }
        
        // Check bottom row
        if(playerWin < 4)
        {   
            playerWin = 0; 
            y = 0;
            while (board[3][y] == player && y < 4)
            {
                x++;
                y--;
                playerWin++;
            }    
        }
    }

    if(playerWin == 4)
        return 1;
    else
        return 0;
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