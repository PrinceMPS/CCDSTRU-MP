#include <stdio.h>
#include "colors.h"

void flushBuffer()
{
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
}

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
        printf("%s%s%s", COLOR_GREEN, "Input the coordinates\n", COLOR_RESET);
        nValid = scanf("%d,%d", &x, &y);
        flushBuffer();
        if (nValid != 2 || x > 4 || x < 0 || y > 4 || y < 0)
        {
            printf("%s%s%s", COLOR_REDBOLD, "Error: One of the coordinates are invalid. Please Try again\n", COLOR_RESET);
        }
    }
    while (nValid != 2 || x > 4 || x < 0 || y > 4 || y < 0);
    if (board[x-1][y-1] == '\0')
    {
        nValid = 1;
        (*playerCount)++;
        board[x-1][y-1] = player;
    }
}


void dosMove(char board[][4], int *unoCount, int *tresCount)
{
    int x,
        y,
        nValid = 0;
        
    do {
        printf("%s%s%s", COLOR_GREEN, "Input the coordinates\n", COLOR_RESET);
        nValid = scanf("%d,%d", &x, &y);
        flushBuffer();
        if (nValid != 2 || x > 4 || x < 0 || y > 4 || y < 0)
        {
            printf("%s%s%s", COLOR_REDBOLD, "Error: One of the coordinates are invalid. Please Try again\n", COLOR_RESET);
        }
    }
    while (nValid != 2 || x > 4 || x < 0 || y > 4 || y < 0);

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
            unoCount = 0, // number of positions of Uno
            tresCount = 0, // number of positions of Tres
            unoWin = 0,
            tresWin = 0,
            turn = 1,
            go = 0;

    char board[4][4];

    // initialize board
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            board[i][j] = '\0';
        }
    }

    while (unoCount + tresCount != 16 && // if positions add to 16, board is full
          !unoWin && 
          !tresWin)
    {
        if(turn && go)
        {
            moveUnoTres(board, &unoCount, '1');
            unoWin = checkWin(board, unoCount, '1');
            turn = !turn;
            go = !go;
        }
        else if(!turn && !unoWin)
        {
            dosMove(board, &unoCount, &tresCount);
            unoWin = checkWin(board, unoCount, '1');
            tresWin = checkWin(board, tresCount, '3');
            turn = !turn;
        }
        else if(turn && !go && !unoWin && !tresWin)
        {
            moveUnoTres(board, &tresCount, '3');
            tresWin = checkWin(board, tresCount, '3');
            go = !go;
        } 
    }

    if(unoCount + tresCount == 16)
        printf("dos win\n");
    else if(unoWin)
        printf("uno win\n");
    else if(tresWin)
        printf("tres win\n");

    return 0;
}