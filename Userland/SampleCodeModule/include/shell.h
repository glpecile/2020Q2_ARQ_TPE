/**
 * shell.c: Contrato para interprete de comandos del usuario.
*/
#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdlib.h>
#include <chess.h>

/**
 * Decidimos usar defines para la resolución de la pantalla ya que una syscall es más costosa.
 */
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 16
#define WIDTH (1024 / CHAR_WIDTH)
#define HEIGHT (768 / CHAR_HEIGHT)

#define SECONDS 0
#define MINUTES 2
#define HOURS 4
#define DAY_OF_THE_WEEK 6
#define DAY_OF_THE_MONTH 7
#define MONTH 8
#define YEAR 9

typedef struct{
    void(*command)(int argSize, char *args[]);
    char *name;
    char *description;
}t_command;

extern void _setCursor(int x, int y);

extern void _drawSquare(unsigned int x, unsigned int y, int l, int color);

extern void _clearScreen();

extern void _drawFigure(char *toDraw, int x, int y, int size, int fgColor, int bgColor, int* sizeInfo); 
/**
 * Inicializa la estructura que ejecuta los programas del usuario.
*/
void intializeShell();
/**
 * Carga los camandos posibles para el usuario a traves de .
*/
void loadCommands();
/**
 * Actua de 
*/
void loadCommand(void (*fn)(), char *name, char *desc);

int readInput(char * inputBuffer, int maxSize, char token);
int processInput(char *inputBuffer);

/****************** COMANDOS ******************/
void printUser();
void help();
void inforeg(uint64_t *reg);
void printCurrentTime();
void printmem();
void invalidOpCodeException();
void invalidZeroDivisionException();
void chess(int argSize, char *args[]);

#endif