#ifndef SCOPE_H
#define SCOPE_H
#include <stdlib.h>
#include "symbol.h"


typedef struct _Scope {
	int proc;
	SymbolInfo *link;
} Scope;


typedef struct _Level {
	Scope *info;
	struct _Level *next;
} Level;


Scope *makeScope( int );
void   freeScope( Scope * );


void push( Scope * );
Scope *pop( void );
Scope *top( void );


#endif
