%start start

%{
#include <stdlib.h>
#include "trees.h"
#include "semantic.h"
#include "types.h"
#include "hashTbl.h"    /* PARA TIRAR */
#include "symbol.h"
#include "generate.h"
#include "optimize.h"

IdList *IdsFieldsList = NULL;
int programWithErrors = FALSE;
int whatsBeingDeclared, byrefFlag;
Node *tree;

%}

%union
{
  int intval;
  char *strval;
  double realval;
  Node *nodeval;
  InfoType *typeval;
}

%token _AND _ARRAY _BEGIN _CASE _CONST _DIV _DO _DOWNTO _ELSE _END _FILE _FOR
%token _FUNCTION _GOTO _IF _IN _LABEL _MOD _NIL _NOT _OF _OR _PACKED
%token _PROCEDURE _PROGRAM _RECORD _REPEAT _SET _THEN _TO _TYPE _UNTIL _VAR
%token _WHILE _WITH _FORWARD

%nonassoc _THEN
%nonassoc _ELSE
%right _PVIRG
%left _EQL _DIF _SML _SEQL _GEQL _GRT _IN
%left _ADD _SUB _OR
%left _MUL _FRAC _DIV _MOD _AND
%left _NOT

%token _PARESQ _PARDIR _RECESQ _RECDIR
%token _ATR _POINT _VIRG _DOISP _PONPON _CHAP

%token _MAXINT _FALSE _TRUE
%token _INPUT _OUTPUT

%token _BOOLEAN _CHAR _INTEGER _REAL _TEXT

%token _WRITE _WRITELN _READ _READLN

%token <strval> _IDENT
%token <intval> _INT 
%token <realval> _NUM
%token <strval> _STRING
%token <intval> _CAR

%type <nodeval> bloco def_funcao def_procedimento cab_procedimento instrucao conj_instrucoes inst_atribuicao expressao
%type <nodeval> exp_simples seq_termos seq_factores factor const_s_sinal_2 variavel constante inst_procedimental inst_write
%type <nodeval> seq_param_actuais factor_s_sinal inst_if inst_while const_s_sinal seq_variaveis inst_read corpo_write
%type <nodeval> corpo_writeln seq_exp_write exp_write cab_funcao variavel_2 dec_funcoes inst_composta seq_instrucoes programa start

%type <typeval> tipo_base tipo_escalar tipo_elementar tipo tipo_def_user
%type <typeval> tipo_estruturado tipo_record seq_def_variaveis

%%
start : programa 
	{
	  $$ = $1;
	};

programa : { push ( makeScope ( 0 )); }
	   _PROGRAM _IDENT prog_parametros _PVIRG bloco _POINT
	   {
	     SymbolInfo *info; 

             info = makeSymbolInfo ( "main", 0, PROCEDURE, NULL );
	     tree = makeNode ( PROCNODE, NULL, 0, 0, NODES );
	     addNode ( tree, makeNode ( NAMENODE, info, 0, 0, NAME ));
	     addNode ( tree, $6 );
	   };

prog_parametros : 
		| _PARESQ seq_identificadores _PARDIR ;

seq_identificadores : _IDENT
		    | seq_identificadores _VIRG _IDENT
		    ;

bloco : dec_etiquetas dec_constantes dec_tipos dec_variaveis
	dec_funcoes
	inst_composta
	{
	  $$ = makeNode ( BLOCK, NULL, 0, procno, NODES );
	  addNode ( $$, $5 );
	  addNode ( $$, $6 );
	  deleteSymbols ();
	};

dec_etiquetas :
	      | _LABEL def_etiquetas _PVIRG ;

def_etiquetas : _INT 
    	      | def_etiquetas _VIRG _INT ;

dec_constantes :
	       | _CONST def_constantes _PVIRG; 

def_constantes : def_constantes _PVIRG 
		 {
		   yyerrok;
                 }
		 constantes 
               | error
               | constantes;

constantes : _IDENT _EQL constante
	     { 
	       BuildConst ( $1, $3, procno ); 
	     };

dec_tipos :
	  | _TYPE def_tipos _PVIRG
	    {
	      yyerrok;
	    };

def_tipos : def_tipos _PVIRG 
	    {
	      yyerrok; 
            }
	    tipos
          | error
	  | tipos; 

tipos : _IDENT _EQL tipo
	{
	  BuildType ( $1, $3, procno );
        };

dec_variaveis :
	      | _VAR
		{
		  whatsBeingDeclared = VARIABLEDECLARATION;
		}
		def_variaveis _PVIRG
		{
		  yyerrok;
                }

def_variaveis : seq_def_variaveis
	      | def_variaveis _PVIRG 
		{
		  yyerrok;
                }
		seq_def_variaveis;

seq_def_variaveis : _IDENT _DOISP tipo
		    {
		      switch ( whatsBeingDeclared )
		      {

			case RECORDDECLARATION : $$ = buildRecordFields ( $1, $3, procno );
						 break;
			case VARIABLEDECLARATION : $$ = buildDeclaration ( $1, procno, $3 );
						   break;
			case PROCFUNCDECLARATION : $$ = buildFormalParameter ( $1, $3, byrefFlag );
						   break;
		      }
		    }
		  | _IDENT _VIRG seq_def_variaveis
		    {
		      switch ( whatsBeingDeclared )
		      {
			case RECORDDECLARATION : $$ = buildRecordFields ( $1, $3, procno );
						 break;
			case VARIABLEDECLARATION : $$ = buildDeclaration ( $1, procno, $3 );
						   break;
			case PROCFUNCDECLARATION : $$ = buildFormalParameter ( $1, $3, byrefFlag );
						   break;
		      }
		    };

dec_funcoes : { $$ = makeNode ( FUNCPROC, NULL, 0, 0, NODES ); }
	    | dec_funcoes def_funcao
	      {
		addNode ( $1, $2 );
	      }
	    | dec_funcoes def_procedimento
	      {
		addNode ( $1, $2 );
	      };

def_funcao : cab_funcao _PVIRG bloco _PVIRG
	     {
	       addNode ( $1, $3 );
	       $$ = $1;
	       verifyIfFunctionReturnsValue ( $$ -> point.nodes [ 0 ] -> point.nameVar );
	     }
	   | cab_funcao _PVIRG _FORWARD _PVIRG
	     {
	       $$ = NULL;
	     };

cab_funcao :  _FUNCTION _IDENT par_formais _DOISP tipo_elementar
	      { $$ = buildProcedureFunction ( $2, procno, $5 ); };

def_procedimento : cab_procedimento _PVIRG bloco
		   {
		     addNode ( $1, $3 );
		   }
		   _PVIRG
		   {
		     $$ = $1;
		   }
		 | cab_procedimento _PVIRG _FORWARD _PVIRG
		 {
		   $$ = NULL;
		 };

cab_procedimento : _PROCEDURE _IDENT par_formais
		   {
		     $$ = buildProcedureFunction ( $2, procno, ( InfoType * ) VOID );
		   };

par_formais :
	    | _PARESQ conj_par_formais _PARDIR ;

conj_par_formais : {
		     byrefFlag = FALSE;
		     whatsBeingDeclared = PROCFUNCDECLARATION;
		   }
		   par_valores
		 | {
		     byrefFlag = TRUE;
		     whatsBeingDeclared = PROCFUNCDECLARATION;
		   }
		   par_variaveis
		 | par_funcionais
		 | par_procedimentais
		 | conj_par_formais _PVIRG
		   {
		     byrefFlag = FALSE;
		     whatsBeingDeclared = PROCFUNCDECLARATION;
		   }
		   par_valores
		 | conj_par_formais _PVIRG
		   {
		     byrefFlag = TRUE;
		     whatsBeingDeclared = PROCFUNCDECLARATION;
		   }
		   par_variaveis
		 | conj_par_formais _PVIRG par_funcionais
		 | conj_par_formais _PVIRG par_procedimentais;

par_valores : seq_def_variaveis;

par_variaveis : _VAR seq_def_variaveis;

par_funcionais : cab_funcao ;

par_procedimentais : cab_procedimento ;

tipo_base : _REAL
	    {
	      InfoType *auxInfo = ( InfoType * ) malloc ( sizeof ( InfoType ));
	      auxInfo -> type = REAL;
	      auxInfo -> more = NULL;
	      $$ = auxInfo;
	    }
	  | _CHAR
	    {
	      InfoType *auxInfo = ( InfoType * ) malloc ( sizeof ( InfoType ));
	      auxInfo -> type = CHAR;
	      auxInfo -> more = NULL;
	      $$ = auxInfo;
	    }
	  | _INTEGER
	    {
	      InfoType *auxInfo = ( InfoType * ) malloc ( sizeof ( InfoType ));
	      auxInfo -> type = INTEGER;
	      auxInfo -> more = NULL;
	      $$ = auxInfo;
	    }
	  | _BOOLEAN
	    {
	      InfoType *auxInfo = ( InfoType * ) malloc ( sizeof ( InfoType ));
	      auxInfo -> type = BOOLEAN;
	      auxInfo -> more = NULL;
	      $$ = auxInfo;
	    }
	  | _TEXT
	    {
	      $$ = NULL; 
	    };

tipo_def_user : _IDENT
		{ $$ = VerifyType ( $1 ); }
	      | tipo_enumerado
		{ $$ = NULL; }
	      | tipo_subintervalo
		{ $$ = NULL; };

tipo_escalar : tipo_base
	       { $$ = $1; }
	     | tipo_def_user
	       { $$ = $1; };

tipo_elementar : tipo_escalar
		 { $$ = $1; }
	       | tipo_ponteiro
		 { $$ = NULL; };

tipo_estruturado : tipo_array
		   { $$ = NULL; }
		 | _PACKED tipo_array
		   { $$ = NULL; }
		 | tipo_file
		   { $$ = NULL; }
		 | _PACKED tipo_file
		   { $$ = NULL; }
		 | tipo_conjunto
		   { $$ = NULL; }
		 | _PACKED tipo_conjunto
		   { $$ = NULL; }
		 | tipo_record
		   { $$ = $1; }
		 | _PACKED tipo_record
		   { $$ = NULL; }
		 ;

tipo : tipo_elementar
       { $$ = $1; }
     | tipo_estruturado
       { $$ = $1; };

tipo_enumerado : _PARESQ seq_identificadores _PARDIR ;

tipo_subintervalo : const_escalar _PONPON const_escalar ;

const_escalar : const_s_sinal
	      | _ADD const_s_sinal
	      | _SUB const_s_sinal ;

tipo_ponteiro : _CHAP tipo_escalar
	      | _CHAP tipo_estruturado;

tipo_array : _ARRAY _RECESQ seq_tipos _RECDIR _OF tipo ; /*verificar o tipo*/

tipo_conjunto : _SET _OF tipo_escalar ; /*verificar o tipo*/

tipo_file : _FILE _OF tipo ; /*verificar o tipo*/

seq_tipos : tipo_def_user
	| seq_tipos _VIRG tipo_def_user;

tipo_record : _RECORD _END
	      {
		InfoType * aux = ( InfoType * ) malloc ( sizeof ( InfoType ));
		aux -> type = RECORD;
		aux -> more = NULL;
		$$ = aux;
	      }
	    | _RECORD
	      {
		pushFieldsStack ();
		whatsBeingDeclared = RECORDDECLARATION;
	      }
	      lista_campos _END
	      {
		SymbolInfo *auxFields = popFieldsStack ();

		if ( !emptyStack ())
		  whatsBeingDeclared = RECORDDECLARATION;
                else
		  whatsBeingDeclared = VARIABLEDECLARATION;
		$$ = buildRecord ( auxFields );
	      };

lista_campos : seq_campos
	     | seq_campos _PVIRG
	     | seq_campos _PVIRG parte_variante
	     | parte_variante ;

seq_campos : campo
	   | seq_campos _PVIRG campo ;

campo : seq_def_variaveis;

parte_variante : _CASE secc_identificacao _OF conj_corpo_variante  ;

conj_corpo_variante : corpo_variante_aux
	| conj_corpo_variante corpo_variante_aux ;

corpo_variante_aux : corpo_variante %prec _PVIRG
	| corpo_variante _PVIRG ;

corpo_variante : seq_constantes _DOISP _PARESQ  _PARDIR
	|seq_constantes _DOISP _PARESQ lista_campos _PARDIR ;

secc_identificacao : _IDENT _DOISP tipo
	| _IDENT ;

variavel : _IDENT
	   { $$ = VariableVerify ( $1, NULL, TRUE ); }
	 | variavel_2
	   { $$ = $1; };

variavel_2 : _IDENT corpo_variavel
	     {
	       $$ = VariableVerify ( $1, IdsFieldsList, FALSE );
	       IdsFieldsList = NULL;
	     };

corpo_variavel : _RECESQ  seq_expressoes _RECDIR
	       | _POINT _IDENT
		 { IdsFieldsList = addId ( IdsFieldsList, $2 ); }
	       | _CHAP
	       | corpo_variavel _RECESQ  seq_expressoes _RECDIR
	       | corpo_variavel _POINT _IDENT
		 { IdsFieldsList = addId ( IdsFieldsList, $3 ); }
	       | corpo_variavel _CHAP ;

seq_expressoes : expressao
	| seq_expressoes _VIRG expressao ;

inst_composta : _BEGIN seq_instrucoes _END
		{
		  changeNodeName ( $2, COMPOUND );
		  $$ = $2;
		};

instrucao :
	    { $$ = makeNode ( EMPTY, NULL, 0, 0, NODES ); }
	  | _INT _DOISP conj_instrucoes
	    { $$ = NULL; }
	  | conj_instrucoes
	    { $$ = $1; };

conj_instrucoes : inst_atribuicao
		  { $$ = $1; }
		| inst_procedimental
		  { $$ = $1; }
		| inst_composta
		  { $$ = $1; }
		| inst_if
		  { $$ = $1; }
		| inst_case
		  { $$ = NULL; }
		| inst_while
		  { $$ = $1; }
		| inst_repeat
		  { $$ = NULL; }
		| inst_for
		  { $$ = NULL; }
		| inst_with
		  { $$ = NULL; }
		| inst_goto
		  { $$ = NULL; }
		| inst_write
		  { $$ = $1; }
		| inst_read
		  { $$ = $1; };

inst_atribuicao : variavel _ATR expressao
		  { $$ = AssignmentVerify ( $1, $3 ); };

inst_procedimental : _IDENT
		     { $$ = VerifyProcFuncCall ( $1, NULL, PROCEDURE ); }
		   | _IDENT _PARESQ seq_param_actuais _PARDIR
		     { $$ = VerifyProcFuncCall ( $1, $3, PROCEDURE ); };

seq_param_actuais : expressao
                    {
		      $$ = makeNode ( SEQVAR, NULL, 0, 0, NODES );
		      addNode ( $$, $1 );
                    }
		  | seq_param_actuais _VIRG expressao
		    {
		      addNode ( $1, $3 );
		      $$ = $1;
                    };

inst_if : _IF expressao _THEN conj_instrucoes 
          { $$ = buildIfInstruction ( $2, $4, NULL ); } 
	| _IF expressao _THEN conj_instrucoes _ELSE conj_instrucoes 
	  { $$ = buildIfInstruction ( $2, $4, $6 ); }
	;

inst_case : _CASE expressao _OF corpo_case _END;

inst_while : _WHILE expressao _DO instrucao 
             { $$ = buildWhileInstruction ( $2, $4 ); }
	   ; 

inst_repeat : _REPEAT seq_instrucoes _UNTIL expressao ;

inst_for : _FOR _IDENT _ATR expressao _TO expressao _DO instrucao
	 | _FOR _IDENT _ATR expressao _DOWNTO expressao _DO instrucao ;

inst_with : _WITH seq_variaveis _DO instrucao ;

inst_goto : _GOTO _INT ;

inst_write : _WRITE corpo_write
             {
	       changeNodeName ( $2, WRITENODE );
	       $$ = $2;
	       VerifyWriteParameters ( $$ );
	     }
	   | _WRITELN corpo_writeln
             {
	       changeNodeName ( $2, WRITENODE );
	       addNode ( $2, makeNode ( NEWLINE, NULL, 0, 0, NAME ));
	       $$ = $2;
	       VerifyWriteParameters ( $$ );
	     };

inst_read : _READ _PARESQ seq_variaveis _PARDIR
	    {
	      changeNodeName ( $3, READNODE );
	      $$ = $3;
	      VerifyReadParameters ( $$ );
	    }
	  | _READLN _PARESQ seq_variaveis _PARDIR
	    {
	      changeNodeName ( $3, READNODE );
	      addNode ( $3, makeNode ( NEWLINE, NULL, 0, 0, NAME ));
	      $$ = $3;
	      VerifyReadParameters ( $$ );
	    }
	  | _READLN
	    {
	      $$ = makeNode ( READNODE, NULL, 0, 0, NODES );
	      addNode ( $$, makeNode ( NEWLINE, NULL, 0, 0, NAME ));
	    };

corpo_write : _PARESQ seq_exp_write _PARDIR
	      { $$ = $2; };

corpo_writeln :
                { $$ = NULL; }
	      | corpo_write
		{ $$ = $1; };

seq_exp_write : exp_write
                {
		  $$ = makeNode ( SEQVAR, NULL, 0, 0, NODES );
		  addNode ( $$, $1 );
                }
	      | seq_exp_write _VIRG exp_write
		{
		  addNode ( $1, $3 );
		  $$ = $1;
                };

exp_write : exp_simples
            {
	      $$ = makeNode ( PRINTNODE, NULL, 0, 0, NODES );
	      addNode ( $$, $1 );
	    }
	  | exp_simples _DOISP _INT
            {
	      $$ = makeNode ( PRINTNODE, NULL, 0, 0, NODES );
	      addNode ( $$, $1 );
	      addNode ( $$, makeNode ( STRINGCTRLNODE, NULL, $3, 0, NAME ));
            }
	  | exp_simples _DOISP _INT _DOISP _INT;

corpo_case : seq_constantes _DOISP instrucao
	   | corpo_case _PVIRG seq_constantes _DOISP instrucao ;

seq_constantes : constante
	       | seq_constantes _VIRG constante ;

seq_variaveis : variavel
		{ $$ = makeNode ( SEQVAR, NULL, 0, 0, NODES );
		  addNode ( $$, $1 );
		}
	      | seq_variaveis _VIRG variavel
		{
		  addNode ( $1, $3 );
		  $$ = $1;
		};

seq_instrucoes : instrucao
		 {
		   $$ = makeNode ( SEQINST, NULL, 0, 0, NODES );
		   addNode ( $$, $1 );
		 }
	       | error _PVIRG
		 {
		   yyerrok;
		 }
		 instrucao
		 {
		   $$ = makeNode ( SEQINST, NULL, 0, 0, NODES );
		   addNode ( $$, $4 );
		 }
	       | seq_instrucoes _PVIRG instrucao
		 {
		   addNode ( $1, $3 );
		   $$ = $1;
		 }

expressao : exp_simples
	    { $$ = $1; }
	  | exp_simples _EQL exp_simples
	    { $$ = RelationVerify ( $1, $3, EQUAL ); }
	  | exp_simples _DIF exp_simples
	    { $$ = RelationVerify ( $1, $3, DIFERENT ); }
	  | exp_simples _SML exp_simples
	    { $$ = RelationVerify ( $1, $3, SMALLER ); }
	  | exp_simples _SEQL exp_simples
	    { $$ = RelationVerify ( $1, $3, SMALLEREQUAL ); }
	  | exp_simples _GEQL exp_simples
	    { $$ = RelationVerify ( $1, $3, GREATEREQUAL ); }
	  | exp_simples _GRT exp_simples
	    { $$ = RelationVerify ( $1, $3, GREATER ); }
	  | exp_simples _IN exp_simples
	    { $$ = NULL; }
	  ;

exp_simples : seq_termos 
              { $$  =$1; };

seq_termos : seq_factores
             { $$ = $1; }     
	   | seq_termos _ADD seq_factores 
	     { $$ = OperationVerify ( $1, $3, ADD ); }
	   | seq_termos _SUB seq_factores
	     { $$ = OperationVerify ( $1, $3, SUB ); }
	   | seq_termos _OR seq_factores
	     { $$ = RelationVerify ( $1, $3, OR ); };

seq_factores : factor
	       { $$ = $1; }
	     | seq_factores _MUL factor
	       { $$ = OperationVerify ( $1, $3, MUL ); }
	     | seq_factores _FRAC factor
	       { $$ = NULL; }
	     | seq_factores _DIV factor
	       { $$ = OperationVerify ( $1, $3, DIV ); }
	     | seq_factores _MOD factor
	       { $$ = OperationVerify ( $1, $3, MOD ); }
	     | seq_factores _AND factor
	       { $$ = RelationVerify ( $1, $3, AND ); };

factor : factor_s_sinal
         { $$ = $1; }
       | _ADD factor_s_sinal
	 { $$ = $2; }
       | _SUB factor_s_sinal
	 {
	   $$ = makeNode ( NEGATIVENODE, NULL, 0, 0, NODES );
   	   addNode ( $$, $2 ); 
         };

factor_s_sinal : _IDENT
	 { $$ = VariableVerify ( $1, NULL, FALSE ); }
       | const_s_sinal_2
	 { $$ = $1; }
       | _NIL
	 { $$ = NULL; }
       | _STRING
	  { $$ = CharVerify ( $1 ); }
       | variavel_2
	 { $$ = $1; }
       | _IDENT _PARESQ seq_param_actuais _PARDIR
	 { $$ = VerifyProcFuncCall ( $1, $3, FUNCTION ); }
       | _PARESQ expressao _PARDIR
	 { $$ = $2; }
       | _NOT factor
	 { $$ = RelationVerify ( $2, NULL, NOT ); }
       | conjunto
	 { $$ = NULL; }
       ;

conjunto : _RECESQ  _RECDIR
	| _RECESQ corpo_conjunto _RECDIR ;

corpo_conjunto :  seq_esp_expressoes
	| corpo_conjunto _VIRG seq_esp_expressoes ;

seq_esp_expressoes : expressao
	| expressao _PONPON expressao ;

constante : _STRING
	    { $$ = makeNode ( STRINGNODE, ( void * ) $1, 0, 0, NAME ); }
	  | const_s_sinal
	    { $$ = $1; }
	  | _ADD const_s_sinal
	    { $$ = $2; }
	  | _SUB const_s_sinal
	    {
	      $$ = makeNode ( NEGATIVENODE, NULL, 0, 0, NODES );
	      addNode ( $$, $2 );
            };

const_s_sinal : _IDENT
		{ $$ = makeNode ( VARNAME, ( void * ) $1, 0, procno, NAME ); }
	      | const_s_sinal_2 
		{ $$ = $1; };


const_s_sinal_2 : _NUM
		  { $$ = NULL; }
		| _CAR
		  { $$ = makeNode ( CHARNODE, NULL, $1, 0, NAME ); }
		| _INT
		  { $$ = makeNode ( INTEGERNODE, NULL, $1, 0, NAME ); }
		| _TRUE
		  { $$ = makeNode ( BOOLNODE, NULL, TRUE, 0, NAME ); }
		| _FALSE
		  { $$ = makeNode ( BOOLNODE, NULL, FALSE, 0, NAME ); };


%%

#include "lexyy.c"

extern Bucket *hashTable[]; /* Para tirar. */
char *outputFilename;
int optimize = TRUE;

yyerror ()
{
  printf ( "Erro de sintaxe, linha %i\n", lineno );
  programWithErrors = TRUE;
}

VerifyOutputSwitch ( char **argv, int argc, int *i )
{
  char *userSwitch = argv [ *i ], *aux;
  if (( strlen ( userSwitch ) > strlen ( "-output" )) ||
      strncmp ( userSwitch, "-output", strlen ( userSwitch  )) ||
      ( *i == ( argc - 1 )))
    return FALSE;
  outputFilename = ( char * ) malloc ( strlen ( argv [ *i + 1 ] ) + 1 );
  strcpy ( outputFilename, argv [ *i + 1 ] );
  (*i)++;
  return TRUE;
}

VerifyOptimizeSwitch ( char *userSwitch )
{
  if (( strlen ( userSwitch ) > strlen ( "-Optimize" )) ||
      strncmp ( userSwitch, "-Optimize", strlen ( userSwitch )))
    return FALSE;
  optimize = FALSE;
  return TRUE;
}

void main ( int argc, char **argv )
{
  int i = 1;
  int catchFile = FALSE;

  while ( i < argc )
  {
    if ( argv [ i ][ 0 ] == '-' )
    {
      if ( !( VerifyOutputSwitch ( argv, argc, &i ) ||
	      VerifyOptimizeSwitch ( argv [ i ] )))
      {
	fprintf ( stderr, "Opcao invalida na linha de comando\n" );
	exit ( 0 );
      }
	 }
    else
      if ( !catchFile )
      {
	yyin = fopen ( argv [ i ], "r" );
	if ( yyin == NULL )
	{
	  fprintf ( stderr, "Erro ao abrir o ficheiro %s\n", argv [ i ] );
	  exit ( 0 );
	}
	catchFile = TRUE;
      }
      else
      {
	fprintf ( stderr, "Erro na linha de comando\n" );
	exit ( 0 );
      }
    i++;
  }
  if ( yyin == NULL )
  {
	 fprintf ( stderr, "Nao foi especificado nenhum ficheiro para compilar\n" );
    exit ( 0 );
  }
  if ( outputFilename == NULL )
  {
    outputFilename = ( char * ) malloc ( sizeof ( "a.out" ) + 1 );
    strcpy ( outputFilename, "a.out" );
  } 
  yyparse ();
  if ( programWithErrors )
    exit ( 0 );
  if ( optimize )
    optimizeTree ( tree );
  printTree ( tree, 0 );
  dumpProcTable ();
  generateAssemblyCode ( tree, outputFilename );
}

yywrap ()
{
  return 1;
}

yyreject ()
{
}