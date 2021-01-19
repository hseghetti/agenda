#include "semantic.h"

void printSpaces ( int i )
{
  int c;
  for ( c = 0; c < i; c++ )
    printf ( " |" );
}

void printTree ( Node *node, int ident )
{
  int i;

  switch ( node -> name )
  {
    case VARNAME : printSpaces ( ident );
		   printf ( "Tipo -> VARNAME\n" );
		   printSpaces ( ident);
		   printf ( "Nome ->%s\n", getSymbolName ( node -> point.nameVar ));
		   printSpaces ( ident);
		   printf ( "Procno ->%i\n", node -> procno );
		   break;

    case FIELDS  : {
		     SymbolInfo *aux = node -> point.nameVar;

                     printSpaces ( ident );
		     printf ( "Tipo -> FIELDS\n" );
		     printSpaces ( ident );
		     printf ( "Nome ->" );
		     while ( aux != NULL )
		     {
		       if ( aux -> next == NULL )
			 printf ( "%s\n", getSymbolName ( aux ));
                       else
		         printf ( "%s.", getSymbolName ( aux )); 
                       aux = getSymbolNext ( aux );
                     }
		     printSpaces ( ident);
		     printf ( "Procno ->%i\n", node -> procno );
		     break;
		   }
    case NAMENODE : printSpaces ( ident );
		    printf ( "Tipo -> NAMENODE\n" );
		    printSpaces ( ident);
		    printf ( "Nome ->%s\n", getSymbolName ( node -> point.nameVar ));
		    break;
    case RETURNVALUE : printSpaces ( ident );
		       printf ( "Tipo -> RETURNVALUE\n" );
		       printSpaces ( ident);
		       printf ( "Nome ->%s\n", getSymbolName ( node -> point.nameVar ));
		       printSpaces ( ident);
		       printf ( "Procno ->%i\n", node -> procno );
		       break;
    case ASSIGNMENT : printSpaces ( ident );
		      printf ( "Tipo -> ASSIGNMENT\n" );
		      printSpaces ( ident);
		      printf ( "Numero de nos ->%i\n", node -> nNodes );
		      for ( i = 0; i < node -> nNodes; i++ )
			printTree ( ( node -> point.nodes) [ i ], ident + 1 );
		      break;
    case INTEGERNODE : printSpaces ( ident );
		       printf ( "Tipo -> INTEGERNODE\n" );
		       printSpaces ( ident);
		       printf ( "Valor ->%i\n", node -> nNodes );
		       break;
    case CHARNODE : printSpaces ( ident );
		    printf ( "Tipo -> CHARNODE\n" );
		    printSpaces ( ident);
		    printf ( "Valor ->%c\n", node -> nNodes );
		    break;
    case BOOLNODE : printSpaces ( ident );
		    printf ( "Tipo -> BOOLNODE\n" );
		    printSpaces ( ident);
	       	    printf ( "Valor ->%i\n", node -> nNodes );
		    break;
    case RELATION : printSpaces ( ident );
		    printf ( "Tipo -> RELATION\n" ); 
		    printSpaces ( ident);
		    printf ( "Relacao: %i\n", node -> procno );
		    printSpaces ( ident);
		    printf ( "Numero de nos ->%i\n", node -> nNodes );
		    for ( i = 0; i < node -> nNodes; i++ )
		      printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                    break;
    case BLOCK :  printSpaces ( ident );
		  printf ( "Tipo -> BLOCK\n" );
		  printSpaces ( ident);
	          printf ( "Numero de nos ->%i\n", node -> nNodes );
		  printSpaces ( ident);
	          printf ( "Numero do bloco ->%i\n", node -> procno );
		  for ( i = 0; i < node -> nNodes; i++ )
		    printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                  break;
    case EMPTY : printSpaces ( ident );
		 printf ( "Tipo -> EMPTY\n" );
		 break;
    case NEWLINE : printSpaces ( ident );
		   printf ( "Tipo -> NEWLINE\n" );
		   break;
    case FUNCPROC : printSpaces ( ident );
		    printf ( "Tipo -> PROCFUNC\n" );
		    printSpaces ( ident);
		    printf ( "Numero de procedimentos -> %i\n", node -> nNodes );
		    for ( i = 0; i < node -> nNodes; i++ )
		      printTree ( ( node -> point.nodes) [ i ], ident + 1 );
		    break;
    case FUNCNODE : printSpaces ( ident );
		    printf ( "Tipo -> FUNCNODE\n" );
		    printSpaces ( ident);
		    printf ( "Numero do procedimento -> %i\n", node -> procno );
		    for ( i = 0; i < node -> nNodes; i++ )
		      printTree ( ( node -> point.nodes) [ i ], ident + 1 );
		    break;
    case PROCNODE : printSpaces ( ident );
		    printf ( "Tipo -> PROCNODE\n" );
		    printSpaces ( ident);
		    printf ( "Numero do procedimento -> %i\n", node -> procno );
		    for ( i = 0; i < node -> nNodes; i++ )
		      printTree ( ( node -> point.nodes) [ i ], ident + 1 );
		    break;
    case PROCCALL : printSpaces ( ident );
		    printf ( "Tipo -> PROCCALL\n" );
		    printSpaces ( ident );
		    printf ( "Numero do procedimento -> %i\n", node -> procno );
		    for ( i = 0; i < node -> nNodes; i++ )
		      printTree ( ( node -> point.nodes) [ i ], ident + 1 );
		    break;
    case FUNCCALL : printSpaces ( ident );
		    printf ( "Tipo -> FUNCCALL\n" );
		    printSpaces ( ident );
		    printf ( "Numero do procedimento -> %i\n", node -> procno );
		    for ( i = 0; i < node -> nNodes; i++ )
		      printTree ( ( node -> point.nodes) [ i ], ident + 1 );
		    break;
    case NEGATIVENODE : printSpaces ( ident );
			printf ( "Tipo -> NEGATIVENODE\n" );
			printTree ( node -> point.nodes [ 0 ], ident + 1 );
			break;
    case OPERATION : printSpaces ( ident );
		     printf ( "Tipo -> OPERATION\n" ); 
		     printSpaces ( ident);
		     printf ( "Operacao: %i\n", node -> procno );
		     printSpaces ( ident);
		     printf ( "Numero de nos ->%i\n", node -> nNodes );
		     for ( i = 0; i < node -> nNodes; i++ )
		       printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                     break;
    case COMPOUND :  printSpaces ( ident );
		     printf ( "Tipo -> COMPOUND\n" );
		     printSpaces ( ident);
	             printf ( "Numero de nos ->%i\n", node -> nNodes );
		     for ( i = 0; i < node -> nNodes; i++ )
		       printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                     break;
    case IFNODE :  printSpaces ( ident );
	           printf ( "Tipo -> IFNODE\n" );
		   printSpaces ( ident);
	           printf ( "Numero de nos ->%i\n", node -> nNodes );
		   for ( i = 0; i < node -> nNodes; i++ )
		     printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                   break;
    case THENNODE :  printSpaces ( ident );
		     printf ( "Tipo -> THENNODE\n" );
		     printSpaces ( ident);
	             printf ( "Numero de nos ->%i\n", node -> nNodes );
		     for ( i = 0; i < node -> nNodes; i++ )
		       printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                     break;
    case ELSENODE :  printSpaces ( ident );
		     printf ( "Tipo -> ELSENODE\n" );
		     printSpaces ( ident);
	             printf ( "Numero de nos ->%i\n", node -> nNodes );
		     for ( i = 0; i < node -> nNodes; i++ )
		       printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                     break;
    case WHILENODE :  printSpaces ( ident );
	              printf ( "Tipo -> WHILENODE\n" );
		      printSpaces ( ident);
	              printf ( "Numero de nos ->%i\n", node -> nNodes );
		      for ( i = 0; i < node -> nNodes; i++ )
		        printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                      break;
    case CONSTNODE : printSpaces ( ident );
		     printf ( "Tipo -> CONSTNODE\n" );
		     printSpaces ( ident);
		     printf ( "Nome ->%s\n", getSymbolName ( node -> point.nameVar ));
		     printSpaces ( ident);
		     printf ( "Valor ->%i\n", node -> nNodes );
		     printSpaces ( ident);
		     printf ( "Procno ->%i\n", node -> procno );
		     break;
    case READNODE :  printSpaces ( ident );
	             printf ( "Tipo -> READ\n" );
	             printSpaces ( ident);
	             printf ( "Numero de nos ->%i\n", node -> nNodes );
	             for ( i = 0; i < node -> nNodes; i++ )
	               printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                     break;
    case WRITENODE :  printSpaces ( ident );
	              printf ( "Tipo -> WRITE\n" );
	              printSpaces ( ident);
	              printf ( "Numero de nos ->%i\n", node -> nNodes );
	              for ( i = 0; i < node -> nNodes; i++ )
	                printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                      break;
    case PRINTNODE :  printSpaces ( ident );
	              printf ( "Tipo -> PRINTNODE\n" );
	              printSpaces ( ident);
	              printf ( "Numero de nos ->%i\n", node -> nNodes );
	              for ( i = 0; i < node -> nNodes; i++ )
	                printTree ( ( node -> point.nodes) [ i ], ident + 1 );
                      break;
    case STRINGCTRLNODE : printSpaces ( ident );
		          printf ( "Tipo -> STRINGCTRLNODE\n" );
		          printSpaces ( ident);
	 	          printf ( "Valor -> %i\n", node -> nNodes );
                          break;
    case STRINGNODE : printSpaces ( ident );
	              printf ( "Tipo -> STRINGNODE\n" );
		      printSpaces ( ident);
	 	      printf ( "Valor -> %s\n", node -> point.nameVar );
                      break;
   default : printf ( "No desconhecido!!!!!!!!!!!!!!!!!\n" );
	     break;
  }
}

int simpleType ( InfoType *type )
{
  int result;

  switch ( type -> type )
  {
    case BOOLEAN :
    case INTEGER :
    case CHAR : return type -> type; 
                break;
    default : return FALSE;
	      break;
  }
  return FALSE;
}

InfoType *getType ( InfoType *type )
{
  if ( type -> type == TYPEDEF )
  {
    InfoType *result = ( InfoType * ) malloc ( sizeof ( InfoType ));

    result -> type = getSymbolType ( type -> more );
    result -> more = getSymbolMore ( type -> more );
    return result;
  }
  else
    return type;
}

int ValidIOVariable ( Node *node )
{
  InfoType *aux = getExpressionType ( node );

  if (( aux -> type == INTEGER ) || ( aux -> type == CHAR ) || ( aux -> type == BOOLEAN ))
    return TRUE;
  else 
    return FALSE;
}

int VerifyReadParameters ( Node *node )
{
  int i;

  for ( i = 0; i < node -> nNodes; i++ )
    if ( !ValidIOVariable (( node -> point.nodes) [ i ] ))
    {
      fprintf ( stderr, "Identificador de tipo invalido numa funcao de input/output, linha %i\n", lineno );
      exit ( 0 );
    }
  return TRUE;
}

int VerifyWriteParameters ( Node *node )
{
  int i;

  for ( i = 0; i < node -> nNodes; i++ )
    if ( node -> point.nodes [ i ] -> name != NEWLINE )
      switch ( node -> point.nodes [ i ] -> point.nodes [ 0 ]-> name )
      {
        case VARNAME : 
        case FIELDS  : if ( !ValidIOVariable (( node -> point.nodes ) [ i ] -> point.nodes [ 0 ] ))
                       {
                         fprintf ( stderr, "Variavel de tipo invalido numa funcao de input/output, linha %i\n", lineno );
                         exit ( 0 );
                       }
        case STRINGNODE :
        case INTEGERNODE :
        case BOOLNODE :
        case CONSTNODE :
	case OPERATION :
	case RELATION :
        case CHARNODE : break;
        default       : fprintf ( stderr, "Identificador invalido numa funcao de input/output, linha %i\n", lineno );
                        exit ( 0 );
      }     
   return TRUE;
}

SymbolInfo *removeFirstField ( SymbolInfo *list, char *name, char type )
{
  SymbolInfo *aux = list; 

  if (( !strcmp ( getSymbolName ( list ), name )) && ( getSymbolType ( list ) == type ))
    return list -> next;
  while ( list -> next != NULL )
  {
    if (( !strcmp ( getSymbolName ( list -> next ), name )) && ( getSymbolType ( list -> next ) == type ))
    {
      list -> next = list -> next -> next;
      return aux;
    }
    list = list -> next;
  }
  return aux;
}

int VerifyTwoRecords ( RecordInfo *record1, RecordInfo *record2 )
{
  SymbolInfo *fields1 = record1 -> fields;
  SymbolInfo *fields2 = record2 -> fields;
  SymbolInfo *aux = NULL;
  int found = FALSE;

  while ( fields1 != NULL ) 
  {
    aux = fields2;
    while ( aux != NULL )
    {
      if ( getSymbolType ( fields1 ) == getSymbolType ( aux ))
      {
        if ( getSymbolType ( fields1 ) == RECORD )
	  found = VerifyTwoRecords ( getSymbolMore ( fields1 ), getSymbolMore ( aux ));
	else
  	  found = TRUE;
        fields2 = removeFirstField ( fields2, getSymbolName ( aux ), getSymbolType ( aux ));
      }
      aux = aux -> next;
    }
    fields1 = fields1 -> next;
  }
  return found;
}

int CompatibleTypes ( InfoType *Type1, InfoType *Type2 )
{
  if (( Type1 == NULL ) || ( Type2 == NULL ))
    return FALSE;
  if ( Type1 -> type == CONST )
  {
    Type1 -> type = getConstType ( Type1 -> more );
    Type1 -> more = ( void * ) getConstValue ( Type1 -> more );
  }
  if ( Type2 -> type == CONST )
  {
    Type2 -> type = getConstType ( Type2 -> more );
    Type2 -> more = ( void * ) getConstValue ( Type2 -> more );
  }
  if ( Type1 -> type == Type2 -> type )
  {
    if ( Type1 -> type == RECORD )
      return VerifyTwoRecords ( Type1 -> more, Type2 -> more );
    return TRUE;
  }
  else 
    return FALSE;
}

void BuildConst ( char *name, Node *constant, int procno )
{
  SymbolInfo *aux = lookupSymbol ( name ), *aux2;
  InfoType *type = getExpressionType ( constant );
  int negative = FALSE;
  Node *auxNode = constant;

  if ( constant -> name == NEGATIVENODE )
  {
    negative = TRUE;
    constant = constant -> point.nodes [ 0 ];
    free ( auxNode );
    auxNode = constant;
  }
  switch ( constant -> name )
  {
    case BOOLNODE    : type -> more = ( void * ) constant -> nNodes;
		       break;
    case INTEGERNODE : if ( negative )
			 constant -> nNodes = -constant -> nNodes;
		       type -> more = ( void * ) constant -> nNodes;
		       break;
    case CHARNODE    : type -> more = ( void * ) constant -> nNodes;
		       break;
    case VARNAME     : aux2 = lookupSymbol ( constant -> point.nameVar );
		       if ( aux2 == NULL )
		       {
			 fprintf ( stderr, "Constante nao definida, linha %i\n", lineno );
			 exit ( 0 );
                       }
                       if ( getSymbolType ( aux2 ) != CONST )
		       {
			 fprintf ( stderr, "Tipo invalido para constante, linha %i\n", lineno );
			 exit ( 0 );
		       }
                       type -> type = getConstType (( ConstInfo * )  getSymbolMore ( aux2 )); 
                       type -> more = ( void * ) getConstValue (( ConstInfo * ) getSymbolMore ( aux2 )); 
		       break;
    default          : fprintf ( stderr, "Tipo invalido para constante, linha %i\n", lineno );
		       exit ( 0 );
  }
  free ( auxNode );
  if (( aux != NULL ) && ( aux -> proc == procno ))
  {
    fprintf ( stderr, "Redeclaracao de %s, linha %i\n", name, lineno );
    exit ( 0 );
  } 
  insertSymbol ( makeSymbolInfo ( name, procno, CONST, ( void * ) makeConstInfo ( type -> type, ( int ) type -> more )));
}

void BuildType ( char *name, InfoType *type, int procno )
{
  SymbolInfo *aux = lookupSymbol ( name );

  if (( aux != NULL ) && ( aux -> proc == procno ))
  {
    fprintf ( stderr, "Redeclaracao de %s, linha %i\n", name, lineno );
    exit ( 0 );
  } 
  insertSymbol ( makeSymbolInfo ( name, procno, TYPEDEF, ( SymbolInfo * ) makeSymbolInfo ( NULL, 0, type -> type, type -> more )));
}

InfoType *VerifyType ( char *name )
{
  InfoType *auxType = ( InfoType * ) malloc ( sizeof ( InfoType ));
  SymbolInfo *auxSymbol = lookupSymbol ( name );

  if (( auxSymbol == NULL ) || ( getSymbolType ( auxSymbol ) != TYPEDEF ))
  {
    fprintf ( stderr, "Tipo invalido, linha %i\n", lineno );
    exit ( 0 );
  }
  auxType -> type = getSymbolType ( getSymbolMore ( auxSymbol ));
  auxType -> more = getSymbolMore ( getSymbolMore ( auxSymbol ));
  return auxType;
}

Node *VerifyProcFuncCall ( char *nameProc, Node *nodeExpressions, int ProcedureFunction )
{
  SubprogramInfo *infoParams;
  SymbolInfo *infoProc;
  int nParam = 0, i;
  Node *node, *procNode;
  InfoType *typeParamActual, *typeParamFormal = ( InfoType * ) malloc ( sizeof ( InfoType ));

  infoProc = lookupSymbol ( nameProc );
  if (( infoProc == NULL ) || (( getSymbolType ( infoProc ) != PROCEDURE ) && ( getSymbolType ( infoProc ) != FUNCTION )))
  {
    fprintf ( stderr, "Chamada a procedimento/funcao nao definido, linha %i\n", lineno );
    programWithErrors = TRUE;
    return makeNode ( EMPTY, NULL, 0, 0, NODES );
  }
  if ( getSymbolType ( infoProc ) != ProcedureFunction )
  {
    fprintf ( stderr, "Chamada ao procedimento/funcao %s em local invalido, linha %i\n", nameProc, lineno );
    exit ( 0 );
  }
  infoParams = ( SubprogramInfo * ) getSymbolMore ( infoProc );
  if ( getSymbolType ( infoProc ) == PROCEDURE )
    procNode = makeNode ( PROCCALL, NULL, 0, getSymbolProc ( infoProc ), NODES );
  else
    procNode = makeNode ( FUNCCALL, NULL, 0, getSymbolProc ( infoProc ), NODES );
  addNode ( procNode, makeNode ( NAMENODE, ( void * ) infoProc, 0, 0, NAME ));
  if (( nodeExpressions == NULL ) && ( getSubprogramNarg ( infoParams ) != 0 ))
  {
    fprintf ( stderr, "Numero de parametros diferente da declaracao do procedimento/funcao %s, linha %i\n", nameProc, lineno );
    exit ( 0 );
  }
  if ( nodeExpressions != NULL )
  {
    if ( nodeExpressions -> nNodes != getSubprogramNarg ( infoParams ))
    {
      fprintf ( stderr, "Numero de parametros diferente da declaracao do procedimento/funcao %s, linha %i\n", nameProc, lineno );
      exit ( 0 );
    }
    for ( i = 0; i < nodeExpressions -> nNodes; i++ )
    {
      node = nodeExpressions -> point.nodes [ i ]; 
      if ( infoParams -> args [ nParam ].byref )
      {
        if ( !variableNode ( node ))
        {
          fprintf ( stderr, "Parametro %i tem de ser uma variavel.\nNa chamada ao procedimento/funcao %s, parametro %s, linha %i\n", nParam + 1, nameProc, getSymbolName ( infoParams -> args [ nParam ].param ), lineno );
          exit ( 0 );
        }
	setSymbolUsed( node->point.nameVar, lineno );
      }
      typeParamFormal -> type = getSymbolType ( infoParams -> args [ nParam ].param );
      typeParamFormal -> more = getSymbolMore ( infoParams -> args [ nParam ].param );
      typeParamActual = getExpressionType ( node );
      if ( !CompatibleTypes ( typeParamFormal, typeParamActual ))
      {
        fprintf ( stderr, "Tipo do parametro %i nao corresponde a definicao da funcao\nNa chamada ao procedimento/funcao %s, parametro %s, linha %i\n", nParam + 1, nameProc, getSymbolName ( infoParams -> args [ nParam ].param ), lineno );
        exit ( 0 );
      }
      addNode ( procNode, node );
      nParam++;
    }
  }
  return procNode;
}

void verifyIfFunctionReturnsValue ( SymbolInfo *symbol )
{
  if ( !getSubprogramRets ( getSymbolMore ( symbol )))
  {
    fprintf ( stderr, "A funcao %s precisa de retornar um valor, linha %i\n", getSymbolName ( symbol ), lineno );
    exit ( 0 );
  }
}

static Parameters *param = NULL;
static int nParam = 0;

Node *buildProcedureFunction ( char *name, int procno, InfoType *type )
{
  int i;
  SymbolInfo *info;
  ParameterInfo *args;
  Parameters *aux;
  Node *auxNode;

  args = ( ParameterInfo * ) malloc ( sizeof ( ParameterInfo ) * nParam );
  for ( i = 0; i < nParam; i++ )
  {
    args [ nParam - 1 - i ] = *( makeParameterInfo (
			info = makeSymbolInfo ( param -> name, procno, param -> type -> type, param -> type -> more ),
		        param -> byref ));
    setSymbolUsed ( info, lineno );
    setSymbolParam ( info, TRUE );
    if ( param->byref )
      setSymbolByref( info, TRUE );
    aux = param;
    param = param -> next;
    free ( aux );
  }  
  i = top () -> proc;
  if ( type == ( InfoType * ) VOID )
  {
    insertSymbol ( info = makeSymbolInfo ( name,  procno, PROCEDURE, ( void * ) makeSubprogramInfo ( args, nParam, VOID )));
    nParam = 0;
    auxNode = makeNode ( PROCNODE, NULL, 0, i, NODES );
    addNode ( auxNode, makeNode ( NAMENODE, info, 0, 0, NAME ));
    return auxNode;
  }
  if ( !( type -> type = simpleType ( type )))
  {
    fprintf ( stderr, "Tipo invalido para retorno de funcao, funcao %s, linha %i\n", name, lineno );
    exit ( 0 );
  }
  insertSymbol ( info = makeSymbolInfo ( name,  procno, FUNCTION, ( void * ) makeSubprogramInfo ( args, nParam, type -> type )));
  nParam = 0;
  auxNode = makeNode ( FUNCNODE, NULL, 0, i, NODES );
  addNode ( auxNode, makeNode ( NAMENODE, info, 0, 0, NAME ));
  return auxNode;
}

InfoType *buildFormalParameter ( char *name, InfoType *type, unsigned int byref )
{
  Parameters *auxParam;

  auxParam = param;
  while ( auxParam != NULL )
  {
    if ( !strcmp ( auxParam -> name, name ))
    {
      fprintf ( stderr, "Nome de parametro duplicado, linha %i\n", lineno );
      exit ( 0 );
    }
    auxParam = auxParam -> next;
  }
  auxParam = ( Parameters * ) malloc ( sizeof ( Parameters ));
  auxParam -> name = name;
  auxParam -> type = type;
  auxParam -> byref = byref;
  auxParam -> next = param;
  param = auxParam;
  ++nParam;
  return type;
}


InfoType *buildDeclaration ( char *name, char proc, InfoType *type )
{
  SymbolInfo *aux = lookupSymbol ( name );

  if ( !aux || ( aux && ( aux->proc != proc )))
    insertSymbol ( aux = makeSymbolInfo ( name, proc, type -> type, type -> more ));
  else {
    fprintf( stderr, "Redeclaracao de %s, linha %i.\n", name, lineno );
    exit ( 0 );
  }
  setSymbolUsed ( aux, lineno );
  return type;
}

static int auxiliarType;
static IdList *match = NULL;
static SymbolInfo *symbolsList = NULL;

Node *VariableVerify ( char *name, IdList *list, int couldBeFunction )
{
  SymbolInfo *info;
  Node *aux;

  info = lookupSymbol ( name );
  if ( info == NULL )
  {
    fprintf ( stderr, "Variavel nao declarada, linha %i\n", lineno );
    exit ( 0 );
  }
  switch ( getSymbolType ( info ))
  {
    case CONST     : aux = makeNode ( CONSTNODE, ( void * ) info, ( int ) getConstValue ( getSymbolMore ( info )), getSymbolProc ( info ), NAME );
		     break;
    case TYPEDEF   : aux = makeNode ( TYPEDEFNODE, ( void * ) info, 0, getSymbolProc ( info ), NAME );
		     break;
    case PROCEDURE : aux = makeNode ( PROCCALL, ( void * ) info, 0, getSymbolProc ( info ), NAME );
		     break;
    case FUNCTION  : if ( couldBeFunction )
		     {
		       aux = makeNode ( RETURNVALUE, ( void * ) info, 0, getSymbolProc ( info ), NAME );
		       setSubprogramRets ( getSymbolMore ( info ), TRUE );
                     }
		     else
		       aux = VerifyProcFuncCall ( name, NULL, FUNCTION );
		     break;
    case RECORD    :{
		      RecordInfo *auxInfo = ( RecordInfo * ) getSymbolMore ( info );

		      if ( list != NULL ) 
		      {
			match = NULL;
			if ( !matchFields ( list, auxInfo -> fields ))
			{
                          fprintf ( stderr, "Variavel do tipo Record com campos nao declarados, linha %i\n", lineno );
                          exit ( 0 );
			}
                        else
			{
                          SymbolInfo *auxSymbols = makeSymbolInfo ( getSymbolName ( info ), getSymbolProc ( info ), getSymbolType ( info ), getSymbolMore ( info ));

                          setSymbolDepth ( auxSymbols, getSymbolDepth ( info ));
                          setSymbolOffs ( auxSymbols, getSymbolOffs ( info ));
                          symbolsList = NULL;
			  buildFieldsList ( transformList ( list ), getRecordFields (( RecordInfo * ) getSymbolMore ( info )));
	                  auxSymbols -> next = symbolsList; 		
	 	          aux = makeNode ( FIELDS, ( void * ) auxSymbols, auxiliarType, getSymbolProc ( info ), NAME );
		        }
                      }
		      else
		        aux = makeNode ( VARNAME, ( void * ) info, 0, getSymbolProc ( info ), NAME );
		      break;
		    }  
    default        : aux = makeNode ( VARNAME, ( void * ) info, 0, getSymbolProc ( info ), NAME );
		     break;
  }
  return aux;
}

IdList *transformList ( IdList *list )
{
  IdList *aux1 = NULL, *aux2 = NULL;

  while ( list != NULL )
  {
    aux2 = ( IdList * ) malloc ( sizeof ( IdList ));
    aux2 -> identifier = ( char * ) malloc ( strlen ( list -> identifier ) + 1 );
    strcpy ( aux2 -> identifier, list -> identifier );
    aux2 -> next = aux1;
    aux1 = aux2;
    list = list -> next;
  }
  return aux1;
}

void buildFieldsList ( IdList *list, SymbolInfo *fields )
{
  while (( list != NULL ) && ( fields != NULL ))
  {
    if ( !strcmp ( getSymbolName ( fields ), list -> identifier ))  
    {
      SymbolInfo *aux2 = makeSymbolInfo ( getSymbolName ( fields ), getSymbolProc ( fields ), getSymbolType ( fields ), getSymbolMore ( fields ));

      setSymbolDepth ( aux2, getSymbolDepth ( fields ));
      setSymbolOffs ( aux2, getSymbolOffs ( fields ));
      aux2 -> next = NULL;
      if ( symbolsList == NULL )
	symbolsList = aux2; 
      else
      {
	SymbolInfo *aux1 = symbolsList; 

	while ( symbolsList -> next != NULL )
	  symbolsList = symbolsList -> next;
        symbolsList -> next = aux2;
	symbolsList = aux1;
      }
      if ( getSymbolType ( fields ) == RECORD )
      {
	list = list -> next;
	buildFieldsList ( list, getRecordFields (( RecordInfo * ) getSymbolMore ( fields )));
      }
    }
    fields = getSymbolNext ( fields );
  }
}

int matchList ( IdList *list1, IdList *list2 )
{
  while (( list1 != NULL ) && ( list2 != NULL ))
  {
    if ( strcmp ( list1 -> identifier, list2 -> identifier ))
      return FALSE;
    list1 = list1 -> next;
    list2 = list2 -> next;
    if ((( list1 == NULL ) && ( list2 != NULL )) || (( list1 != NULL ) && ( list2 == NULL )))
      return FALSE;
  }
  return TRUE;
}

int matchFields ( IdList *list, SymbolInfo *fields )
{
  while ( fields != NULL )
  {
    match = addId ( match, getSymbolName ( fields ));
    if ( matchList ( list, match )) 
    {
      auxiliarType = getSymbolType ( fields );
      return TRUE;
    } 
    if ( getSymbolType ( fields ) == RECORD )
    {
      RecordInfo *auxInfo = ( RecordInfo * ) getSymbolMore ( fields );

      if ( matchFields ( list, getRecordFields ( auxInfo ))) 
	return TRUE; 
    }
    match = match -> next;
    fields = getSymbolNext ( fields );
  }
  return FALSE;
}

Node *AssignmentVerify ( Node *variable, Node *expression )
{
  Node *auxNode;
  InfoType *typeExpression, *typeVar;
  SymbolInfo *info;

  if (( variable -> name != VARNAME ) && ( variable -> name != FIELDS ) && ( variable -> name != RETURNVALUE ))
  {
    fprintf ( stderr, "Lado esquerdo da atribuicao invalido, linha %i\n", lineno );
    programWithErrors = TRUE;
    return makeNode ( EMPTY, NULL, 0, 0, NODES );
  }
  info = variable -> point.nameVar;
  if ( variable -> name == RETURNVALUE )
  {
    if ( top () -> proc != getSymbolProc ( info ))
    {
      fprintf ( stderr, "Lado esquerdo da atribuicao invalido, linha %i\n", lineno );
      exit ( 0 );
    }
    else
    {
      typeVar = ( InfoType * ) malloc ( sizeof ( InfoType ));
      typeVar -> type = getSubprogramType ( getSymbolMore ( info ));
    }
  }
  else
    if ( variable -> name != FIELDS ) 
    {
      typeVar = ( InfoType * ) malloc ( sizeof ( InfoType ));
      typeVar -> type = getSymbolType ( info );
      typeVar -> more = getSymbolMore ( info );
      typeVar = getType ( typeVar );
    }
    else 
      typeVar = getExpressionType ( variable );
  typeExpression = getExpressionType ( expression );
  if ( !CompatibleTypes ( typeExpression , typeVar ))
  {
    fprintf ( stderr, "Lado esquerdo da atribuicao, e o lado direito tem tipos diferentes, linha %i\n", lineno );
    exit ( 0 );
  }
  setSymbolUsed( info, lineno );
  auxNode = makeNode ( ASSIGNMENT, NULL, 0, 0, NODES );
  addNode ( auxNode, variable );
  addNode ( auxNode, expression );
  return auxNode;
}

Node *CharVerify ( char *charValue )
{
  Node *auxNode;
  int c;

  if (( c = strlen ( charValue )) == 1 )
    auxNode = makeNode ( CHARNODE, NULL, charValue [ 0 ], 0, NAME );
  else 
  { 
    char *aux = ( char * ) malloc ( c + 1 );

    strcpy ( aux, charValue );
    auxNode = makeNode ( STRINGNODE, ( void * ) aux, 0, 0, NAME );
  }
  return auxNode;
}

Node *RelationVerify ( Node *left, Node *right, int relation )
{ 
  Node *auxNode;
  InfoType *typeLeft, *typeRight;

  typeLeft = getExpressionType ( left ),
  typeRight = getExpressionType ( right );
  if (( relation == AND ) || ( relation == OR ) || ( relation == NOT ))
    if (( typeLeft -> type != BOOLEAN ) || (( relation != NOT ) && ( typeRight -> type != BOOLEAN )))
    {
      fprintf ( stderr, "Operadores booleanos necessitam que os seus operandos sejam do tipo BOOLEAN, linha %i\n", lineno );
      exit ( 0 );
    }
  if ( !CompatibleTypes ( typeLeft, typeRight ) && ( relation != NOT ))
  {
    fprintf ( stderr, "Lado esquerdo da relacao, e o lado direito tem tipos diferentes, linha %i\n", lineno );
    exit ( 0 );
  }
  auxNode = makeNode ( RELATION, NULL, 0, relation, NAME );
  addNode ( auxNode, left );
  if ( relation != NOT )
    addNode ( auxNode, right );
  return auxNode;
}
 

Node *OperationVerify ( Node *left, Node *right, int operation )
{
  Node *auxNode;
  InfoType *typeRight = getExpressionType ( right ),
           *typeLeft = getExpressionType ( left );

  if (( typeRight -> type != INTEGER ) || ( typeLeft -> type != INTEGER ))
  {
    fprintf ( stderr, "Tipo invalido de operando, linha %i", lineno );
    exit ( 0 );
  }
  if ( !CompatibleTypes ( typeLeft, typeRight ))
  {
    fprintf ( stderr, "Lado esquerdo da operacao, e o lado direito tem tipos diferentes, linha %i\n", lineno );
    exit ( 0 );
  }
  auxNode = makeNode ( OPERATION, NULL, 0, operation, NAME );
  addNode ( auxNode, left );
  addNode ( auxNode, right );
  return auxNode;
}  

Node *buildIfInstruction ( Node *expression, Node *thenInst, Node *elseInst )
{
  Node *auxNode, *auxNode2, *auxNode3;
  InfoType *auxType = getExpressionType ( expression );

  if ( auxType -> type != BOOLEAN )
  { 
    fprintf ( stderr, "O teste da instrucao if tem de ser do tipo BOOLEAN, linha %i\n", lineno );
    exit ( 0 );
  }
  auxNode = makeNode ( IFNODE, NULL, 0, 0, NODES );
  addNode ( auxNode, expression );
  auxNode2 = makeNode ( THENNODE, NULL, 0, 0, NODES );
  addNode ( auxNode2, thenInst );
  addNode ( auxNode, auxNode2 );
  if ( elseInst != NULL )
  {
    auxNode3 = makeNode ( ELSENODE, NULL, 0, 0, NODES );
    addNode ( auxNode3, elseInst );
    addNode ( auxNode, auxNode3 );
  }
  return auxNode;
}

Node *buildWhileInstruction ( Node *expression, Node *body )
{
  Node *auxNode;
  InfoType *auxType = getExpressionType ( expression );

  if ( auxType -> type != BOOLEAN )
  { 
    fprintf ( stderr, "O teste da instrucao while tem de ser do tipo BOOLEAN, linha %i\n", lineno );
    exit ( 0 );
  }
  auxNode = makeNode ( WHILENODE, NULL, 0, 0, NODES );
  addNode ( auxNode, expression );
  addNode ( auxNode, body );
  return auxNode;
}

static FieldsStack *RecordFields = NULL;


int emptyStack ()
{
  if ( RecordFields == NULL )
    return TRUE;
  return FALSE;
}

void pushFieldsStack ()
{ 
  FieldsStack *aux = ( FieldsStack * ) malloc ( sizeof ( FieldsStack ));

  aux -> fields = NULL;
  aux -> next = RecordFields;
  RecordFields = aux;
}

SymbolInfo *popFieldsStack ()
{
  SymbolInfo *aux = RecordFields -> fields;

  RecordFields = RecordFields -> next;
  return aux;
}
 
InfoType *buildRecord ( SymbolInfo *fieldsList )
{
  InfoType *aux = ( InfoType * ) malloc ( sizeof ( InfoType )); 

  aux -> type = RECORD;
  aux -> more = makeRecordInfo ( fieldsList );
  return aux;
}


int existsField ( char *id )
{
  SymbolInfo *aux = RecordFields -> fields;

  while ( aux != NULL )
  {
    if ( !strcmp ( aux -> name, id ))
      return TRUE;
    aux = aux -> next;
  }
  return FALSE; 
}

InfoType *buildRecordFields ( char *field, InfoType *type, int proc )
{
  if ( existsField ( field ))
  {
    fprintf ( stderr, "Duplicacao de um nome nos campos do record, linha %i\n", lineno );
    exit ( 0 );
  }
  else
  {
    RecordFields -> fields = setSymbolNext ( makeSymbolInfo ( field, proc, type -> type, type -> more ), RecordFields -> fields );
  }
  return type;
}

RecordInfo *findRecord ( char *fieldRecord, SymbolInfo *fields )
{
  while ( fields != NULL )
  {
    if ( !strcmp ( fields -> name, fieldRecord ))
      return ( RecordInfo * ) getSymbolMore ( fields );
    if ( fields -> type == RECORD )
      return findRecord ( fieldRecord, getRecordFields (( RecordInfo * ) getSymbolMore ( fields )));
    fields = fields -> next;
  } 
  return NULL;
}
 

InfoType *getExpressionType ( Node *expression )
{
  InfoType *auxType;
  SymbolInfo *auxSymbol;

  if ( expression == NULL )
    return NULL;
  auxType = ( InfoType * ) malloc ( sizeof ( InfoType ));
  switch ( expression -> name )
  {
    case INTEGERNODE  : auxType -> type = INTEGER;
			break;
    case CHARNODE     : auxType -> type = CHAR;
			break;
    case BOOLNODE     : auxType -> type = BOOLEAN;
			break;
    case RELATION     : auxType -> type = BOOLEAN;
			break;
    case FUNCCALL     : auxType -> type = getSubprogramType ( getSymbolMore ( expression -> point.nodes [ 0 ] -> point.nameVar ));
			break;
    case OPERATION    : auxType = getExpressionType ( expression -> point.nodes [ 0 ] );
			break;
    case STRINGNODE   : auxType -> type = ARRAY;
			break;
    case FIELDS       : auxType -> type = expression -> nNodes;
			if ( expression -> nNodes == RECORD )
			{
			  SymbolInfo *aux1 = expression -> point.nameVar;
                          
			  while ( aux1 -> next != NULL )
			    aux1 =  aux1 -> next;
			  auxType -> more = getSymbolMore ( aux1 );
                        }
                        else 
		          auxType -> more = ( void * ) expression -> point.nameVar;
			break;
    case VARNAME      : auxType -> type = getSymbolType ( auxSymbol = expression -> point.nameVar );
		        auxType -> more = getSymbolMore ( auxSymbol );
			auxType = getType ( auxType );
			break;
    case NEGATIVENODE : auxType = getExpressionType ( expression -> point.nodes [ 0 ] );
			break;
    case CONSTNODE    : auxType -> type = getConstType ( getSymbolMore ( auxSymbol = expression -> point.nameVar ));
			auxType -> more = ( void * ) getConstValue ( getSymbolMore ( auxSymbol ));
			break;
    default           : auxType -> type = 255;
			break;
  }
  return auxType;
}

IdList *addId ( IdList *list, char *id )
{
  if ( !list ) 
  {
    list = ( IdList * ) malloc ( sizeof ( IdList ));

    list -> identifier = ( char * ) malloc ( sizeof ( id ) + 1 );
    strcpy ( list -> identifier, id );
    list -> next = NULL;
  }
  else 
  {
    IdList *aux = ( IdList * ) malloc ( sizeof ( IdList ));

    aux -> identifier = ( char * ) malloc ( strlen ( id ) + 1 );
    strcpy ( aux -> identifier, id );
    aux -> next = list;
    list = aux;
  };
  return list;
}

void freeIdList ( IdList **list )
{ 
  IdList *aux = *list;

  while ( aux != NULL )
  {
    free ( aux );
    aux = aux -> next;
  };
  *list = NULL;
}
