#include "scope.h"


static Level *stack = NULL;
int depth = -1;
int maxDepth = -1;


void push( Scope *info )
{
  Level *aux = ( Level * ) malloc( sizeof( Level ));

  aux->info = info;
  if ( stack == NULL )
    aux->next = NULL;
  else
    aux->next = stack;
  stack = aux;
  if ( ++depth > maxDepth )
    maxDepth = depth;
}


Scope *pop( void )
{
  if ( stack == NULL )
    return NULL;
  else {
    Level *l = stack;
    Scope *s = stack->info;

    stack = stack->next;
    free( l );
    return s;

    depth--;
  }
}


Scope *top( void )
{
  if ( stack == NULL )
    return NULL;
  else
    return stack->info;
}


Scope *makeScope ( int proc )
{
  Scope *aux = ( Scope * ) malloc ( sizeof ( Scope ));

  aux -> proc = proc;
  aux -> link = NULL;

  return aux;
}


void freeScope( Scope *scope )
{
  scope->link = NULL;
  free( scope );
}
