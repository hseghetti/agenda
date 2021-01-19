#ifndef SYMBTBL_H
#define SYMBTBL_H
#define CHUNK	25
#include "hashTbl.h"
#include "symbol.h"
#include "scope.h"


extern SymbolInfo **procTable;
extern unsigned int procTableSize;

void        insertSymbol( SymbolInfo * );
SymbolInfo *lookupSymbol( char * );
void        deleteSymbols( void );
void        dump ();
void        dumpRecord ( SymbolInfo *, int );


#endif
