#include"header.h"

int main()
{
    srand(time(0));

    printf(COLOR_PROMPT "Enter your name: " COLOR_RESET);
    fgets(playerName, 50, stdin);
    playerName[strcspn(playerName, "\n")] = '\0';

    loadGameData(playerName);
    setDifficultyLevel();

    char response;
    do
    {
        displayPositionGuide();
        playTicTacToe();
        saveGameData(playerName);
        printf("\n" COLOR_PROMPT "Would you like to play again? (Y/N): " COLOR_RESET);
        getchar();
        response = getchar();
        response = toupper(response);
    } while (response == 'Y');

    printf(COLOR_PROMPT "Thanks for playing!\n" COLOR_RESET);
    return 0;
}
