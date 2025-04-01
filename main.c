#include <stdio.h>
#include <string.h>
#include "colors.h"

void flushBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayBoard(char board[][4])
{
    printf("\n%s           COLUMN%s\n", COLOR_WHITEBOLD, COLOR_RESET);
     printf("%s    -------------------%s\n", COLOR_GRAY, COLOR_RESET);
    printf("%s         1   2   3   4%s\n", COLOR_WHITEBOLD, COLOR_RESET);
    printf("%s    -------------------%s\n", COLOR_GRAY, COLOR_RESET);

    for (int i = 0; i < 4; i++)
    {
        printf("%sROW %d %s%s|%s ", COLOR_WHITEBOLD, i + 1, COLOR_RESET, COLOR_GRAY, COLOR_RESET);
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == '-')
                printf("%s[-] %s", COLOR_BLUE, COLOR_RESET);
            else if (board[i][j] == '+')
                printf("%s[+] %s", COLOR_ORANGE, COLOR_RESET);
            else
                printf("[ ] ");
        }
        printf("\n");
    }
    printf("\n");
}

void moveUnoTres(char board[][4], int *playerCount, char player)
{
    int x, y, nValid;

    if (player == '-')  
        printf("Turn of %sUno[-]%s\n", COLOR_BLUE, COLOR_RESET);
    else  
        printf("Turn of %sTres[+]%s\n", COLOR_ORANGE, COLOR_RESET);

    do {
        do {
            printf("%sInput row number (1-4):%s\n", COLOR_GREEN, COLOR_RESET);
            nValid = scanf("%d", &x);
            flushBuffer();
            
            if (nValid != 1 || x < 1 || x > 4)
                printf("%sError: Invalid row number. Try again.%s\n", COLOR_REDBOLD, COLOR_RESET);
        } while (nValid != 1 || x < 1 || x > 4);
        
        do {
            printf("%sInput column number (1-4):%s\n", COLOR_GREEN, COLOR_RESET);
            nValid = scanf("%d", &y);
            flushBuffer();
            
            if (nValid != 1 || y < 1 || y > 4)
                printf("%sError: Invalid column number. Try again.%s\n", COLOR_REDBOLD, COLOR_RESET);
        } while (nValid != 1 || y < 1 || y > 4);
        
        if (board[x-1][y-1] != '\0')
            printf("%sError: Position occupied. Try again.%s\n", COLOR_REDBOLD, COLOR_RESET);
    } while (board[x-1][y-1] != '\0');

    (*playerCount)++;
    board[x-1][y-1] = player;
}

void dosMove(char board[][4], int *unoCount, int *tresCount)
{
    int x, y, nValid;
    printf("Turn of %sDos%s\n", COLOR_YELLOW, COLOR_RESET);

    do {
        do {
            printf("%sInput row number (1-4):%s\n", COLOR_GREEN, COLOR_RESET);
            nValid = scanf("%d", &x);
            flushBuffer();

            if (nValid != 1 || x < 1 || x > 4)
                printf("%sError: Invalid row number. Try again.%s\n", COLOR_REDBOLD, COLOR_RESET);
        } while (nValid != 1 || x < 1 || x > 4);

        do {
            printf("%sInput column number (1-4):%s\n", COLOR_GREEN, COLOR_RESET);
            nValid = scanf("%d", &y);
            flushBuffer();

            if (nValid != 1 || y < 1 || y > 4)
                printf("%sError: Invalid column number. Try again.%s\n", COLOR_REDBOLD, COLOR_RESET);
        } while (nValid != 1 || y < 1 || y > 4);

        if (board[x-1][y-1] != '-' && board[x-1][y-1] != '+') {
            printf("%sError: No player piece at that position. Try again.%s\n", COLOR_REDBOLD, COLOR_RESET);
        }
    } while (board[x-1][y-1] != '-' && board[x-1][y-1] != '+');

    if (board[x-1][y-1] == '-') {
        (*unoCount)--;
    } else {
        (*tresCount)--;
    }

    board[x-1][y-1] = '\0';
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
                y++;
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
    int unoCount = 0, // number of positions of Uno
		tresCount = 0, // number of positions of Tres
		unoWin = 0, 
		tresWin = 0, 
		turn = 1, 
		go = 0,
		i,j;
  	
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
        displayBoard(board);

        if (turn && go)
        {
            moveUnoTres(board, &unoCount, '-');
            unoWin = checkWin(board, unoCount, '-');
            turn = 0;
            go = 0;
        }
        else if (!turn && !unoWin)
        {
            dosMove(board, &unoCount, &tresCount);
            unoWin = checkWin(board, unoCount, '-');
            tresWin = checkWin(board, tresCount, '+');
            turn = 1;
        }
        else if (turn && !go && !unoWin && !tresWin)
        {
            moveUnoTres(board, &tresCount, '+');
            tresWin = checkWin(board, tresCount, '+');
            go = 1;
        }
    }

    displayBoard(board);

    if (unoCount + tresCount == 16)
        printf("Dos wins!\n");
    else if (unoWin)
        printf("Uno wins!\n");
    else if (tresWin)
        printf("Tres wins!\n");

    return 0;
}

