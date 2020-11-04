/**
 * syscallDispatcher.c: Recibe los llamados a las system calls usadas en Userland.
 * Preservamos syscalls similares o inspiradas en las existentes de Linux.
*/
#include <keyboardDriver.h>
#include <rtcDriver.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>

uint64_t syscallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9, uint64_t r10)
{
    // int jjj[] = {1,1};
    // int kkk[] = {14,14};
    switch (rdi)
    {
        case 0:
            return sTicksElapsed();
        case 1:
            return getTime(rsi);
        case 2:
            // drawFigure(char *toDraw, int color, int size, int x, int y);
            drawFigure((char *)rsi, rdx, rcx, r8, r9);
            return 1;
        case 3:
            // uint64_t sWrite(char *buffer, int size, int color);
            return sWrite((char *)rsi, rdx, rcx);
        case 4:
            return sGetChar();
        case 5:
            // setCursor(unsigned int new_x, unsigned int new_y);
            setCursor(rsi,rdx);
            return 1;
        case 6:
            // void drawSquare(unsigned int x, unsigned int y, int l, int color);
            drawSquare(rsi, rdx, rcx, r8);
            return 1;
        case 7:
            clearScreen();
            return 1;
        default:
            break;
    }
    return 0;
}