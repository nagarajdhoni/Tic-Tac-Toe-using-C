#include"header.h"


void saveGameData(char *playerName)
{
    FILE *file = fopen("game_data.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(file, "Player: %s | Date: %d-%02d-%02d %02d:%02d:%02d | Wins: %d | Losses: %d | Draws: %d\n",
            playerName, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,
            playerWins, computerWins, draws);

    fclose(file);
}

void loadGameData(char *playerName)
{
    FILE *file = fopen("game_data.txt", "r");
    if (file == NULL)
    {
        printf("No previous game data found.\n");
        return;
    }

    char line[100];
    printf("\nPrevious Game Data for %s:\n", playerName);
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, playerName))
        {
            printf("%s", line);
        }
    }
    fclose(file);
}
