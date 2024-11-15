#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

// Define constants for players
#define PLAYER 'X'
#define COMPUTER 'O'

// ANSI color codes for better UI
#define COLOR_RESET "\033[0m"
#define COLOR_PLAYER "\033[1;34m"   // Blue for Player
#define COLOR_COMPUTER "\033[1;31m" // Red for Computer
#define COLOR_PROMPT "\033[1;32m"   // Green for Prompts
#define COLOR_WIN "\033[1;33m"      // Yellow for Win/Draw messages

// Define all global variables here
extern char board[3][3];
extern char playerName[50];
extern int playerWins;
extern int computerWins;
extern int draws;
extern int difficultyLevel;

// Function declarations
extern void resetBoard();
extern void printBoard();
extern int checkFreeSpaces();
extern void playerMove();
extern void computerMove();
extern char checkWinner();
extern void printWinner(char);
extern int minimax(int depth, int isMaximizing);
extern void saveGameData(char *playerName);
extern void loadGameData(char *playerName);
extern void playTicTacToe();
extern void setDifficultyLevel();
extern void displayPositionGuide();


#endif