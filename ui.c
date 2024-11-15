#include"header.h"

// Declare as extern in ui.c
extern int playerWins;
extern int computerWins;
extern int draws;
extern int difficultyLevel;

void printBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == PLAYER)
            {
                printf(COLOR_PLAYER " %c " COLOR_RESET, board[i][j]);
            }
            else if (board[i][j] == COMPUTER)
            {
                printf(COLOR_COMPUTER " %c " COLOR_RESET, board[i][j]);
            }
            else
            {
                printf(" %c ", board[i][j]);
            }
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf(COLOR_WIN "YOU WIN!\n" COLOR_RESET);
        playerWins++;
    }
    else if (winner == COMPUTER)
    {
        printf(COLOR_WIN "YOU LOSE!\n" COLOR_RESET);
        computerWins++;
    }
    else
    {
        printf(COLOR_WIN "IT'S A TIE!\n" COLOR_RESET);
        draws++;
    }

    printf(COLOR_PROMPT "\nPlayer Wins: %d | Computer Wins: %d | Draws: %d\n" COLOR_RESET, playerWins, computerWins, draws);
}

void displayPositionGuide()
{
    printf(COLOR_PROMPT "\nPosition Guide:\n" COLOR_RESET);
    printf(" 1 | 2 | 3 \n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9 \n\n");
    printf("Enter the corresponding number to place your move in the desired position.\n");
}