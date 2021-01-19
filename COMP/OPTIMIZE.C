#include "optimize.h"

void optimizeTree ( Node *node )
{
  int i;

  switch ( node -> name )
  {
    case BLOCK :
    case ASSIGNMENT :
    case FUNCPROC :
    case PROCNODE :
    case PROCCALL :
    case NEGATIVENODE :
    case IFNODE :
    case COMPOUND :
    case THENNODE :
    case ELSENODE:
    case WHILENODE:
    case FUNCNODE :
    case PRINTNODE :
    case WRITENODE :
    case STRINGCTRLNODE:
    case FUNCCALL : for ( i = 0; i < node -> nNodes; i++ )
		      optimizeTree ( node -> point.nodes [ i ] );
		    break;
    case OPERATION : optimizeTree ( node -> point.nodes [ 0 ] );
		     optimizeTree ( node -> point.nodes [ 1 ] );
		     if ( constantNode ( node -> point.nodes [ 0 ] ) &&
			  constantNode ( node -> point.nodes [ 1 ] ))
		     {
		       InfoType *type = getExpressionType ( node -> point.nodes [ 0 ] );
		       int result, x, y;

		       switch ( type -> type )
		       {
			 case INTEGER : changeNodeName ( node, INTEGERNODE );
					break;
			 case BOOLEAN : changeNodeName ( node, BOOLNODE );
					break;
			 case CHAR    : changeNodeName ( node, CHARNODE );
					break;
		       }
		       x = node -> point.nodes [ 0 ] -> nNodes;
		       y = node -> point.nodes [ 1 ] -> nNodes;
		       switch ( node -> procno )
		       {
			 case ADD : result = x + y;
				    break;
			 case SUB : result = x - y;
				    break;
			 case MUL : result = x * y;
				    break;
			 case DIV : result = x / y;
				    break;
			 case MOD : result = x % y;
				    break;
		       }
		       node -> nNodes = result;
		       free ( node -> point.nodes [ 0 ] );
		       free ( node -> point.nodes [ 1 ] );
		     }
		     break;
    case RELATION : optimizeTree ( node -> point.nodes [ 0 ] );
		    if ( node -> procno != NOT )
		      optimizeTree ( node -> point.nodes [ 1 ] );
		    if ( constantNode ( node -> point.nodes [ 0 ] ) &&
			( constantNode ( node -> point.nodes [ 1 ] ) || ( node -> procno == NOT )))
		    {
		      int result, x, y;

		      changeNodeName ( node, BOOLNODE );
		      x = node -> point.nodes [ 0 ] -> nNodes;
		      if ( node -> procno != NOT )
		      {
			y = node -> point.nodes [ 1 ] -> nNodes;
			free ( node -> point.nodes [ 1 ] );
		      }
		      free ( node -> point.nodes [ 0 ] );
		      switch ( node -> procno )
		      {
			case EQUAL        : result = x == y;
					    break;
			case DIFERENT     : result = x != y;
					    break;
			case SMALLER      : result = x < y;
					    break;
			case GREATER      : result = x > y;
					    break;
			case SMALLEREQUAL : result = x <= y;
					    break;
			case GREATEREQUAL : result = x >= y;
					    break;
			case AND          : result = x && y;
					    break;
			case OR           : result = x || y;
					    break;
			case NOT          : result = !x;
					    break;
		      }
		      if ( result )
			result = 255;
		      node -> nNodes = result;
		    }
		    break;
  }
}

int constantNode ( Node *node )
{
  switch ( node -> name )
  {
    case INTEGERNODE :
    case BOOLNODE :
    case CHARNODE : return TRUE;
		    break;
    default : return FALSE;
	      break;

  }
  return FALSE;
}
