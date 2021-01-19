#include "lib.h"

void writeInteger ( int i, int n )
{
  char aux [ 15 ];

  sprintf ( aux, "%%%ii", n );
  if ( n < 0 )
    n = 0;
  printf ( aux, i );
}

void writeBoolean ( char c, int n )
{
  char aux [ 15 ];

  sprintf ( aux, "%%%is", n );
  if ( c == 0 )
    printf ( aux, "FALSE" );
  else
    printf ( aux, "TRUE" );
}

void writeChar ( char c, int n )
{
  char aux [ 7 ];

  sprintf ( aux, "%%%ic", n );
  printf ( aux, c );
}

void writeString ( char *str, int n )
{
  char *aux = ( char * ) malloc ( strlen ( str ) + 7 );

  sprintf ( aux, "%%%is", n );
  printf ( aux, str );
}

void writeNewline ( void )
{
  printf ( "\n" );
}

char readChar ()
{
  char c;

  return getchar ();
}

char readBoolean ()
{
  char c;

  do
  {
    c = getchar ();
  }
  while (( c == ' ' ) || ( c == '\n' ) || ( c == '\t' ));
  if ( toupper ( c ) == 'T' )
  {
    c = getchar ();
    if ( toupper ( c ) == 'R' )
    {
      c = getchar ();
      if ( toupper ( c ) == 'U' )
      {
	c = getchar ();
	if ( toupper ( c ) == 'E' )
	  return 255;
        else
	{
	   printf ( "Erro ao ler booleano\n" );
	   return 0;
	}
      }
      else
      {
	 printf ( "Erro ao ler booleano\n" );
	 return 0;
      }
    }
    else
    {
       printf ( "Erro ao ler booleano\n" );
       return 0;
    }
  }
  else
    if ( toupper ( c ) == 'F' )
    {
      c = getchar ();
      if ( toupper ( c ) == 'A' )
      { 
        c = getchar ();
        if ( toupper ( c ) == 'L' )
        {
	  c = getchar ();
	  if ( toupper ( c ) == 'S' )
	  {
	    c = getchar ();
	    if ( toupper ( c ) == 'E' )
	      return 0;
            else
	    {
	      printf ( "Erro ao ler booleano\n" );
	      return 0;
	    }
          }
          else
	  {
	    printf ( "Erro ao ler booleano\n" );
	   return 0;
	  }
        }
        else
        {
	  printf ( "Erro ao ler booleano\n" );
	  return 0;
        }
      }
      else
      {
        printf ( "Erro ao ler booleano\n" );
        return 0;
      }
    }
    else
    {
      printf ( "Erro ao ler booleano\n" );
      return 0;
    }
}

int readInteger ()
{
  char c;
  int result = 0;

  do
  {
    c = getchar ();
  }
  while (( c == ' ' ) || ( c == '\n' ) || ( c == '\t' ));
  while (( c >= '0' ) && ( c <= '9' )) 
  {
    result = result * 10 + ( c - '0' );
    c = getchar ();
  }
  if (( c != ' ' ) && ( c != '\n' ) && ( c != '\t' ))
  {
    printf ( "Erro ao ler inteiro\n" );
    return 0;
  }
  return result;
}
