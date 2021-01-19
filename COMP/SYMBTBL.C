#include "symbTbl.h"
#include <stdio.h>


extern int depth;
extern Bucket *hashTable[]; /* Para tirar. */
SymbolInfo **procTable = NULL;
unsigned int procTableSize = 0;


void insertSymbol( SymbolInfo *info )
{
  unsigned size;
  Scope *scope = top();

  setSymbolNext( info, scope->link );
  scope->link = info;
  insert( getSymbolName( info ), ( void * ) info );
  switch ( getSymbolType( info )) {
    case PROCEDURE:
    case FUNCTION:
      push( makeScope( getSymbolProc( info )));
      {
	char narg = getSubprogramNarg(( SubprogramInfo * ) getSymbolMore( info ));

        if ( narg ) {
          ParameterInfo *aux;

          for ( aux = getSubprogramArgs(( SubprogramInfo * ) getSymbolMore( info ));
                narg != 0;
                aux++, narg-- )
            insertSymbol( getParameterParam( aux ));
	}
      }
      break;
    default:
      break;
  }
  setSymbolDepth( info, depth );
}


SymbolInfo *lookupSymbol( char *name )
{
  return ( SymbolInfo * ) lookup( name );
}


void deleteSymbols( void )
{
  Scope      *scp = pop();
  SymbolInfo *aux;

  if ( !procTable ) {
    procTable = ( SymbolInfo ** )
		calloc( sizeof( SymbolInfo * ), CHUNK );
    procTableSize += CHUNK;
  }
  while ( scp->proc > procTableSize ) {
    procTable = ( SymbolInfo ** ) realloc( procTable,
			sizeof( procTable ) + sizeof( SymbolInfo * ) * CHUNK );
    procTableSize += CHUNK;
  }
  procTable[ scp->proc ] = scp->link;
  for ( aux = scp->link; aux != NULL; aux = aux->next )
    delete( aux->name );
  freeScope( scp );
}


/* Para tirar.
	|
	|
	|
	|
	|
	V	*/

void dumpSymbol( SymbolInfo *info )
{
  Line *aux;

  printf ( "Nome: %s Proc: %i Offset: %i Linhas: ",
	   info->name, info->proc, info->offs );
  for ( aux = info->used; aux != NULL; aux = aux->next )
    printf( " %i,", aux->line );
  printf( " Tipo: " );
  switch ( info->type ) {
    case CONST:
      printf ( "CONST " );
      printf( "Tipo: %i Valor: %i.\n", 
	getConstType(( ConstInfo * ) getSymbolMore( info )),
	getConstValue(( ConstInfo * ) getSymbolMore( info ))); 
      break;
    case CHAR:
      printf ( "CHAR\n" );
      break;
    case INTEGER:
      printf ( "INTEGER\n" );
      break;
    case BOOLEAN:
      printf ( "BOOLEAN\n" );
      break;
    case RECORD:
      printf ( "RECORD\n" );
      dumpRecord ( info, 0 );
      break; 
    case TYPEDEF:
      printf ( "TYPEDEF\n" );
      break;
    case TYPE:
      printf ( "TYPE\n" );
      break;
    case PROCEDURE:
      printf ( "PROCEDURE\n" );
      break;
    case FUNCTION:
      printf ( "FUNCTION\n" );
      break;
  }
}


void dump( void )
{
  int	  idx;
  Bucket *aux;

  for ( idx = 0; idx < TBLSIZE; idx++ )
    for ( aux = hashTable[ idx ]; 
	  aux != NULL;
	  aux = aux->next )
      dumpSymbol(( SymbolInfo * ) aux->info );
}


void dumpRecord ( SymbolInfo *Record, int ident )
{
  extern void printSpaces( int );
  SymbolInfo *auxRecord = getRecordFields (( RecordInfo *) getSymbolMore ( Record ));

  printSpaces ( ident );
  printf ( "Campos:\n" );
  while ( auxRecord != NULL )
  {
    if ( auxRecord -> type != RECORD )
    {
      printSpaces ( ident );
      printf ( "%s: tipo %i\n", auxRecord -> name, auxRecord -> type );
    }
    else
    {
      printSpaces ( ident );
      printf ( "%s: RECORD\n", auxRecord -> name );     
      dumpRecord ( auxRecord, ident + 1 );
    }
    auxRecord = auxRecord -> next;
  }
}

void dumpProcTable( void )
{
  int		 idx;
  SymbolInfo	*aux;

  for ( idx = 0; idx < procTableSize; idx++ )
    if ( procTable [ idx ] != NULL ) {
      printf ( "Procedimento: %i\n", idx );
      for ( aux = procTable[ idx ]; 
	    aux != NULL;
	    aux = aux->next ) 
        dumpSymbol( aux );
    }
}
