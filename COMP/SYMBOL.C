#include "symbol.h"


int updateOffset( int offset, int update )
{
  if ( update == 1 )
    return offset;
  else 
    if ( offset % 2 )
      return ++offset;
    else
      return offset;
}


SymbolInfo *makeSymbolInfo( char *name, int proc, char type, void *more )
{
  SymbolInfo *aux = ( SymbolInfo * ) malloc( sizeof( SymbolInfo ));

  aux->name = name;
  aux->proc = proc;
  aux->type = type;
  aux->depth = 0;
  aux->param = FALSE;
  aux->byref = FALSE;
  aux->offs = 0;
  aux->used = NULL;
  aux->more = more;
  aux->next = NULL;
  return aux;
}


char *getSymbolName( SymbolInfo *symbol )
{
  return symbol->name;
}


int getSymbolProc( SymbolInfo *symbol )
{
  return symbol->proc;
}


char getSymbolType( SymbolInfo *symbol )
{
  return symbol->type;
}


int getSymbolDepth( SymbolInfo *symbol )
{
  return symbol->depth;
}


void setSymbolDepth( SymbolInfo *symbol, int depth )
{
  symbol->depth = depth;
}


char getSymbolParam( SymbolInfo *symbol )
{
  return symbol->param;
}


void setSymbolParam( SymbolInfo *symbol, char param )
{
  symbol->param = param;
}


char getSymbolByref( SymbolInfo *symbol )
{
  return symbol->byref;
}


void setSymbolByref( SymbolInfo *symbol, char byref )
{
  symbol->byref = byref;
}


int getSymbolOffs( SymbolInfo *symbol )
{
  return symbol->offs;
}


void setSymbolOffs( SymbolInfo *symbol, int offset )
{
  symbol->offs = offset;
}


void setSymbolUsed( SymbolInfo *symbol, int line )
{
  Line *new = ( Line * ) malloc( sizeof( Line ));

  new->line = line;
  new->next = symbol->used;
  symbol->used = new;
}


void *getSymbolMore( SymbolInfo *symbol )
{
  return symbol->more;
}


SymbolInfo *setSymbolNext( SymbolInfo *symbol, SymbolInfo *next )
{
  symbol->next = next;
  return symbol;
}


SymbolInfo *getSymbolNext( SymbolInfo *symbol )
{
  return symbol->next;
}


ConstInfo *makeConstInfo( char type, int value )
{
  ConstInfo *aux = ( ConstInfo * ) malloc( sizeof( ConstInfo ));

  aux->type = type;
  aux->value = value;
  return aux;
}


char getConstType( ConstInfo *constant )
{
  return constant->type;
}


int getConstValue( ConstInfo *constant )
{
  return constant->value;
}


RecordInfo *makeRecordInfo( SymbolInfo *fields )
{
  RecordInfo *aux1 = ( RecordInfo * ) malloc( sizeof( RecordInfo ));
  SymbolInfo *aux2;

  aux1->fields = fields;
  aux1->size = 0;
  for ( aux2 = aux1->fields; aux2 != NULL; aux2 = getSymbolNext( aux2 )) {
    unsigned size = getTypeSize( aux2 );

    setSymbolOffs( aux2, aux1->size = updateOffset( aux1->size, size ));
    aux1->size += size;
  }
  aux1->size = updateOffset( aux1->size, INTEGERSIZE );
  return aux1;
}


SymbolInfo *getRecordFields( RecordInfo *record )
{
  return record->fields;
}


unsigned int getRecordSize( RecordInfo *record )
{
  return record->size;
}


unsigned int getTypeSize( SymbolInfo *symbol )
{
  switch ( getSymbolType( symbol )) {
    case CONST:
      switch ( getConstType(( ConstInfo * ) getSymbolMore( symbol ))) {
	case CHAR:
          return CHARSIZE;
        case INTEGER:
          return INTEGERSIZE;
        case BOOLEAN:
          return BOOLEANSIZE;
      }
    case CHAR:
      return CHARSIZE;
    case INTEGER:
      return INTEGERSIZE;
    case BOOLEAN:
      return BOOLEANSIZE;
    case RECORD:
      return getRecordSize(( RecordInfo * ) getSymbolMore( symbol ));
    case TYPE:
      return getTypeSize(( SymbolInfo * ) getSymbolMore(( SymbolInfo * ) getSymbolMore( symbol )));
  }
  return 0;
}


ParameterInfo *makeParameterInfo( SymbolInfo *param, unsigned int byref )
{
  ParameterInfo *aux = ( ParameterInfo * ) malloc( sizeof( ParameterInfo ));

  aux->param = param;
  aux->byref = byref;
  return aux;
}


SymbolInfo *getParameterParam( ParameterInfo *parameter )
{
  return parameter->param;
}


unsigned int getParameterByref( ParameterInfo *parameter )
{
  return parameter->byref;
}


SubprogramInfo *makeSubprogramInfo( ParameterInfo *args,
                                    char narg,
                                    char type )
{
  SubprogramInfo *aux = ( SubprogramInfo * ) malloc( sizeof( SubprogramInfo ));

  aux->args = args;
  aux->narg = narg;
  aux->type = type;
  aux->rets = FALSE;
  return aux;
}


ParameterInfo *getSubprogramArgs( SubprogramInfo *subprogram )
{
  return subprogram->args;
}


char getSubprogramNarg( SubprogramInfo *subprogram )
{
  return subprogram->narg;
}


char getSubprogramType( SubprogramInfo *subprogram )
{
  return subprogram->type;
}


char getSubprogramRets( SubprogramInfo *subprogram )
{
  return subprogram->rets;
}


void setSubprogramRets( SubprogramInfo *subprogram, char returns )
{
  subprogram->rets = returns;
}
