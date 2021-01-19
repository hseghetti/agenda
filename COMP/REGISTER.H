#ifndef _REGISTER_H
#define _REGISTER_H

#include "symbol.h"
#include "string.h"

#define BITS8  1
#define BITS16 2

#define NUMPARTS     3

#define NUMREGISTERS 4

#define AX         0
#define AH         1
#define AL         2
#define BX         3
#define BH         4
#define BL         5
#define CX         6
#define CH         7
#define CL         8
#define DX         9
#define DH        10
#define DL        11
#define ANYTHING 255

#define FULL 0
#define HIGH 1
#define LOW  2

typedef struct 
{
  SymbolInfo *parts [ 3 ];
  int        lastUsed [ 3 ];
} RegisterInfo;

extern RegisterInfo registers [];

int   findRegister ( SymbolInfo *, int, char * );
char *giveRegisterName ( int );
int   giveAgeOfYounger ( int * );
void  cleanRegister ( char * );
void  cleanRegisters ( void );

#endif _REGISTER_H
