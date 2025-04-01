#include <stdio.h>
#include <string.h>
#include "colors.h"

/* 
    flushBuffer clears the input buffer
*/
void flushBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
    displayTitle displays the title card
*/
void displayTitle()
{
    char cStart;

    printf("*======================================*\n");
    printf("|    %s  _______     %s ______             %s|\n", COLOR_BLUE, COLOR_ORANGE, COLOR_RESET);
    printf("|    %s /_  __(_)___ %s/_  __/__ _____     %s|\n", COLOR_BLUE, COLOR_ORANGE, COLOR_RESET);
    printf("|    %s  / / / / __/ %s / / / _ `/ __/     %s|\n", COLOR_BLUE, COLOR_ORANGE, COLOR_RESET);
    printf("|    %s /_/ /_/\\__/ %s /_/  \\_,_/\\__/      %s|\n", COLOR_BLUE, COLOR_ORANGE, COLOR_RESET);
    printf("|    %s   ____  __       _  __     __    %s|\n", COLOR_YELLOW, COLOR_RESET);
    printf("|    %s  / __ \\/ /      / |/ /__  / /    %s|\n", COLOR_YELLOW, COLOR_RESET);
    printf("|    %s / /_/ / _ \\    /    / _ \\/_/     %s|\n", COLOR_YELLOW, COLOR_RESET);
    printf("|    %s \\____/_//_/   /_/|_/\\___(_)      %s|\n", COLOR_YELLOW, COLOR_RESET);
    printf("*======================================*\n");
    printf("         Press [Enter] to start");
    scanf("%c", &cStart);
}

/*
    displayTutorial displays the tutorial menu
*/
void displayTutorial()
{
    char cProceed;
    
printf("       *================================================================*\n");
printf("       |                        %sTIC TAC OH NO!%s                          |\n", COLOR_VIOLET, COLOR_RESET);
printf("       *================================================================*\n");

    
printf("       *================================================================*\n"); 
printf("       |                          %sGAME SETUP%s                            |\n", COLOR_GREEN, COLOR_RESET);
printf("       *================================================================*\n"); 
printf("       | 1. The game is played on a 4x4 grid.                           |\n");
printf("       | 2. There are three players:                                    |\n");
printf("       |    > %sTres (+)%s: Places [+] marks on the grid.                   |\n", COLOR_ORANGE, COLOR_RESET);
printf("       |    > %sUno (-)%s: Places [-] marks on the grid.                    |\n", COLOR_BLUE, COLOR_RESET);
printf("       |    > %sDos %s: Can remove a [+] or [-] mark from the grid.         |\n", COLOR_YELLOW, COLOR_RESET);
printf("       *================================================================*\n\n"); 
   
printf("       *================================================================*\n");
printf("       |                          %sGAME RULES%s                            |\n", COLOR_GREEN, COLOR_RESET);
printf("       *================================================================*\n");
printf("       | 1. The turn order is as follows:                               |\n");
printf("       | 	%s>Tres -> Uno -> Dos%s                                     |\n", COLOR_GREEN, COLOR_RESET);
printf("       | 2. Tres and Uno take turns placing their marks                 |\n");
printf("       | 3. Dos's move is to remove any mark ([+] or [-]) from the grid |\n");
printf("       *================================================================*\n\n"); 


   
printf("       *================================================================*\n");
printf("       |                      %sWINNING CONDITIONS%s                        |\n", COLOR_GREEN, COLOR_RESET);
printf("       *================================================================*\n");
printf("       |  1. %sTres%s and %sUno%s wins if they:                                 |  \n",COLOR_ORANGE, COLOR_RESET,COLOR_BLUE, COLOR_RESET);
printf("       | 	> Occupy the topmost or bottommost row                  |\n");
printf("       | 		(without having marks in any other tile)        |\n");
printf("       | 	> Occupy a full diagonal line                           |\n");
printf("       | 		(without having marks in any other tile)        |\n");
printf("       | 2. %sDos %s wins if the grid is filled and no one has won          |\n",COLOR_YELLOW, COLOR_RESET);
printf("       *================================================================*\n\n");

    
   
printf("       *================================================================*\n");
printf("       |                         %sGAME CONTROLS%s                          |\n", COLOR_GREEN, COLOR_RESET);
printf("       *================================================================*\n");
printf("       | 1. %sTres%s: Enter coordinates to place %s[+]%s                        |\n",COLOR_ORANGE,COLOR_RESET,COLOR_ORANGE,COLOR_RESET);
printf("       | 2. %sUno%s: Enter coordinates to place %s[-]%s                         |\n",COLOR_BLUE,COLOR_RESET,COLOR_BLUE,COLOR_RESET);
printf("       | 3. %sDos%s: Enter coordinates to remove a mark                     |\n",COLOR_YELLOW,COLOR_RESET);
printf("       *================================================================*\n\n");
    
    printf("Press [Enter] to return to the main menu...");
    scanf("%c", &cProceed);
}

/*
    displayMainMenu displays the main menu
*/
char displayMainMenu()
{
    char cOption;

    printf("\n       *========================*\n");
    printf("       |        %sMAIN MENU%s       |\n", COLOR_YELLOW, COLOR_RESET);
    printf("       *========================*\n");
    printf("       |   [1]   Play           |\n");
    printf("       |   [2]   Tutorial       |\n");
    printf("       |   [0]   Quit           |\n");
    printf("       *========================*\n");

    do
    {
        printf("       %sEnter Option: %s", COLOR_GREEN, COLOR_RESET);
        scanf(" %c", &cOption);
        if(cOption < '0' || cOption > '2')
            printf("       %sError: Invalid input. Try again.%s\n", COLOR_RED, COLOR_RESET);
    } while(cOption < '0' || cOption > '2');
    
    // Call the Tutorial function if option 2 is selected
    if (cOption == '2') {
        displayTutorial();  // This will now handle the tutorial selection
    }

    return cOption;
}

/*
    initializeBoard fill the board with '\0'
    @param board [][] - 2d array to be initialized to '\0'
*/
void initializeBoard(char board[][4])
{
    int i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            board[i][j] = '\0';
}

/*
    displayBoard will display the board with all of the moves that have been previously made
    @param board [][] - 2d array to be displayed'
*/
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

/*
    moveUnoTres will prompt players Uno or Tres to input coordinates of where they wish to claim their spot.
    @param board [][] - 2d array where all the moves are stored
    @param *playerCount - the amount of pieces player has on the board
    @param player - the number of the player (Uno or Tres)
*/
void moveUnoTres(char board[][4], int *playerCount, char player)
{
    int x, y, nValid;

    printf("*========================*\n");
    if (player == '-')  
        printf("%sTurn of %sUno[-]%s\n", COLOR_WHITEBOLD, COLOR_BLUE, COLOR_RESET);
    else  
        printf("%sTurn of %sTres[+]%s\n", COLOR_WHITEBOLD, COLOR_ORANGE, COLOR_RESET);

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
    printf("*========================*\n");

    (*playerCount)++;
    board[x-1][y-1] = player;
}

/*
    dosMove will prompt Dos to input coordinates of where they wish to remove a claimed spot.
    @param board [][] - 2d array where all the moves are stored
    @param *UnoCount - the amount of pieces Uno has on the board
    @param *tresCount - the number of the player (Uno or Tres)
*/
void dosMove(char board[][4], int *unoCount, int *tresCount)
{
    int x, y, nValid;
    printf("%sTurn of %sDos%s\n", COLOR_WHITEBOLD, COLOR_YELLOW, COLOR_RESET);

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

/*
    checkWin will check whether Uno or Tres has met one of the win conditions of the game
    @param board [][] - 2d array where all the moves are stored
    @param playerCount - the amount of pieces player has on the board
    @param player - the amount of pieces Tres has on the board
*/
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
    int  unoCount, // number of positions of Uno
		 tresCount, // number of positions of Tres
		 unoWin, 
		 tresWin, 
		 turn, 
		 go;
  	char board[4][4],
         cOption;

    displayTitle();

    do 
    {
        cOption = displayMainMenu();

        if(cOption == '1')
        {
            // initialization
            unoCount = 0;
		    tresCount = 0;
		    unoWin = 0;
		    tresWin = 0;
		    turn = 1;
		    go = 0;

            initializeBoard(board);

            while (unoCount + tresCount < 16 && // if positions add to 16, board is full
                  !unoWin && 
                  !tresWin)
            {
                displayBoard(board);

                if (turn && go)
                {
                    moveUnoTres(board, &unoCount, '-');
                    turn = 0;
                    go = 0;
                }
                else if (!turn)
                {
                    dosMove(board, &unoCount, &tresCount);
                    turn = 1;
                }
                else if (turn && !go)
                {
                    moveUnoTres(board, &tresCount, '+');
                    go = 1;
                }

                // check winning conditions
                unoWin = checkWin(board, unoCount, '-');
                tresWin = checkWin(board, tresCount, '+');
            }

            displayBoard(board);

            if (unoCount + tresCount == 16)
                printf("Dos wins!\n");
            else if (unoWin)
                printf("Uno wins!\n");
            else if (tresWin)
                printf("Tres wins!\n");
        }

    } while(cOption != '0');

    return 0;
}
