#include"header.h"




void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

int checkFreeSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
                freeSpaces--;
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int move;
    while (1)
    {
        printf(COLOR_PROMPT "Enter a position (1-9) for your move: " COLOR_RESET);
        if (scanf("%d", &move) != 1 || move < 1 || move > 9)
        {
            printf("Invalid input! Enter a number between 1 and 9.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        // Map move to row and column
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] != ' ')
        {
            printf("Invalid move! Spot is already taken.\n");
        }
        else
        {
            board[row][col] = PLAYER;
            break;
        }
    }
}

int minimax(int depth, int isMaximizing)
{
    char result = checkWinner();
    if (result == COMPUTER)
        return 10 - depth;
    if (result == PLAYER)
        return depth - 10;
    if (checkFreeSpaces() == 0)
        return 0;

    if (isMaximizing)
    {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = COMPUTER;
                    int score = minimax(depth + 1, 0);
                    board[i][j] = ' ';
                    bestScore = (score > bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = PLAYER;
                    int score = minimax(depth + 1, 1);
                    board[i][j] = ' ';
                    bestScore = (score < bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
}

void computerMove()
{
    if (difficultyLevel == 1)
    { // Easy level - Random moves
        int x, y;
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else if (difficultyLevel == 2)
    { // Medium level - Random with chance of optimal move
        if (rand() % 2 == 0)
        { // 50% chance of using minimax
            int bestScore = -1000;
            int moveX = 0, moveY = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == ' ')
                    {
                        board[i][j] = COMPUTER;
                        int score = minimax(0, 0);
                        board[i][j] = ' ';
                        if (score > bestScore)
                        {
                            bestScore = score;
                            moveX = i;
                            moveY = j;
                        }
                    }
                }
            }
            board[moveX][moveY] = COMPUTER;
        }
        else
        { // Random move
            int x, y;
            do
            {
                x = rand() % 3;
                y = rand() % 3;
            } while (board[x][y] != ' ');
            board[x][y] = COMPUTER;
        }
    }
    else
    { // Hard level - Full minimax (Optimal play)
        int bestScore = -1000;
        int moveX = 0, moveY = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = COMPUTER;
                    int score = minimax(0, 0);
                    board[i][j] = ' ';
                    if (score > bestScore)
                    {
                        bestScore = score;
                        moveX = i;
                        moveY = j;
                    }
                }
            }
        }
        board[moveX][moveY] = COMPUTER;
    }
}

char checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

void playTicTacToe()
{
    char winner = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpaces() > 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
            break;

        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
            break;
    }

    printBoard();
    printWinner(winner);
}

void setDifficultyLevel()
{
    printf("\nChoose Difficulty Level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Enter choice: ");
    while (scanf("%d", &difficultyLevel) != 1 || difficultyLevel < 1 || difficultyLevel > 3)
    {
        printf("Invalid input! Enter a number between 1 and 3: ");
        while (getchar() != '\n')
            ;
    }
}
