/**
 * chessConsole.h: Contrato consola del juego de ajedrez.
*/
#ifndef _CHESSCONSOLE_H_
#define _CHESSCONSOLE_H_
#include <chess.h>
#include <shell.h>
#include <stdlib.h>

#define MAX_WIDTH 300
#define PLAYER_LENGTH 7 * CHAR_WIDTH
#define LAST_LINE HEIGHT - 1 // Linea donde se ingresan comandos.
#define THRESHOLD (MAX_WIDTH - PLAYER_LENGTH) / CHAR_WIDTH

void initializeCursor();
void printIn(char *string, int x, int y, int color);
void printCommand(char *string);
void printPlayer(int number, int line);
void printLogLine(char *move, int player);
void clearLine(int y);
void addMoveToLog(char *move, int player);
void moveUpLog();
void updateTimerConsole(int time);
char *getNextMove(int i);
int getVerticalPixelPosition(int value);
int getHorizontalPixelPosition(int value);
void displayChar(char c); 
void printEntireLog();
void resetCursor();
void intializeLog();
#endif