#ifndef _LIB_H
#define _LIB_H

#include <stdio.h>
#include <string.h>
#include <alloc.h>
#include <ctype.h>

void writeInteger ( int, int );
void writeBoolean ( char, int );
void writeChar ( char, int );
void writeString ( char *, int );
void writeNewline ( void );
char readChar ();
char readBoolean ();
int readInteger ();

#endif
