%{
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "scope.h"

int flag_pas = 0;
int lineno = 1;
int procno = 0;
%}


%%
"\n"		lineno++;
[ \t]		; 
\{[^\}]*\}	{ flag_pas = 0; }
'.'		{ 
		  yylval.intval = yytext[1];
		  flag_pas = 0;
		  return _CAR;
		}
'[^']*'		{
		  char c = input();
		  
		  yytext[--yyleng]=0;
		  unput(c);
		  if (c == '\'')
		    yymore();
		  else {
		    flag_pas = 0;
		    yylval.strval = ( char * ) malloc ( strlen ( yytext ));
		    strcpy ( yylval.strval, yytext + 1 );
		    return _STRING;
		  }
		}
"(*"[^*]*"*"	{
		  int c = input();

		  if (c!=')') {
		    unput(c);
		    unput('*');
		    unput('(');
		    yymore();
		  }
		  flag_pas = 0;
		}
"AND"		{ return _AND; }
"ARRAY"		{ return _ARRAY; }
"BEGIN"		{ return _BEGIN; }
"CASE"		{ return _CASE; }
"CONST"		{ return _CONST; }
"DIV"		{ return _DIV; }
"DO"		{ return _DO; }
"DOWNTO"	{ return _DOWNTO; }
"ELSE"		{ return _ELSE; }
"END"		{ return _END; }
"FILE"		{ return _FILE; }
"FOR"		{ return _FOR; }
"FORWARD"	{ return _FORWARD; }
"FUNCTION"	{ ++procno; return _FUNCTION; }
"GOTO"		{ return _GOTO; }
"IF"		{ return _IF; }
"IN"		{ return _IN; }
"LABEL"		{ return _LABEL; }
"MOD"		{ return _MOD; }
"NIL"		{ return _NIL; }
"NOT"		{ return _NOT; }
"OF"		{ return _OF; }
"OR"		{ return _OR; }
"PACKED"	{ return _PACKED; }
"PROCEDURE"	{ ++procno; return _PROCEDURE; }
"PROGRAM"	{ return _PROGRAM; }
"RECORD"	{ return _RECORD; }
"REPEAT"	{ return _REPEAT; }
"SET"		{ return _SET; }
"THEN"		{ return _THEN; }
"TO"		{ return _TO; }
"TYPE"		{ return _TYPE; }
"UNTIL"		{ return _UNTIL; }
"VAR"		{ return _VAR; }
"WHILE"		{ return _WHILE; }
"WITH"		{ return _WITH; }

"+"		{ return _ADD; }
"-"		{ return _SUB; }
"*"		{ return _MUL; }
"/"		{ return _FRAC; }
"="		{ return _EQL; }
"<>"		{ return _DIF; }
"<"		{ return _SML; }
"<="		{ return _SEQL; }
">="		{ return _GEQL; }
">"		{ return _GRT; }
"("		{ return _PARESQ; }
")"		{ return _PARDIR; }
"["		{ return _RECESQ; }
"]"		{ return _RECDIR; }
":="		{ return _ATR; }
"."		{ return _POINT; }
","		{ return _VIRG; }
";"		{ return _PVIRG; }
":"		{ return _DOISP; }
".."		{ return _PONPON; }
"^"		{ return _CHAP; }

"MAXINT"	{ return _MAXINT; }
"FALSE"		{ return _FALSE; }
"TRUE"		{ return _TRUE; }

"BOOLEAN"	{ return _BOOLEAN; }
"CHAR"		{ return _CHAR; }
"INTEGER"	{ return _INTEGER; }
"REAL"		{ return _REAL; }
"TEXT"		{ return _TEXT; }

"READ"          { return _READ; }
"READLN"        { return _READLN; }
"WRITE"		{ return _WRITE; }
"WRITELN"	{ return _WRITELN; }

[A-Z][A-Z0-9_]*		{ 
			  yylval.strval = (char *)
				malloc(sizeof(char) * (yyleng + 1));
			  strcpy(yylval.strval, yytext);
			  return _IDENT;
			}
[0-9]*		{
		  yylval.intval = atoi(yytext);
		  return _INT;
		}
[0-9]*"."[0-9]*		{
			  int c;
			  yylval.realval = atof(yytext);
			  if (yytext[yyleng-1] == '.') {
			    c = input();
			    unput(c);
			    if ('.' == c)
			    REJECT;
			  }
			  else
			    return _NUM;
			}
[0-9]*("."[0-9]*)?"E"[-+]?[0-9]+	{
					  yylval.realval = atof(yytext);
					  return _NUM;
					}

.		{
		  printf ("Erro de Sintaxe.\n");
		  yyerrok;
		}


%%
#undef getc

int getc(FILE *stream_pas) {

  char car_pas;

  car_pas = fgetc(stream_pas);
  if (car_pas == '\'')
    flag_pas = 1;
  if (!flag_pas)
    if ((car_pas >= 'a') && (car_pas <= 'z'))
      car_pas = toupper(car_pas);
  return car_pas;
}
