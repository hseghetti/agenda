# include "stdio.h"
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX 200
# define output(c) putc(c,yyout)
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng; extern char yytext[];
int yymorfg;
extern char *yysptr, yysbuf[];
int yytchar;
FILE *yyin ={stdin}, *yyout ={stdout};
extern int yylineno;
struct yysvf { 
	struct yywork *yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "scope.h"

int flag_pas = 0;
int lineno = 1;
int procno = 0;
# define YYNEWLINE 10
yylex(){
int nstr; extern int yyprevious;
while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:
	lineno++;
break;
case 2:
	;
break;
case 3:
{ flag_pas = 0; }
break;
case 4:
	{ 
		  yylval.intval = yytext[1];
		  flag_pas = 0;
		  return _CAR;
		}
break;
case 5:
	{
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
break;
case 6:
{
		  int c = input();

		  if (c!=')') {
		    unput(c);
		    unput('*');
		    unput('(');
		    yymore();
		  }
		  flag_pas = 0;
		}
break;
case 7:
	{ return _AND; }
break;
case 8:
	{ return _ARRAY; }
break;
case 9:
	{ return _BEGIN; }
break;
case 10:
	{ return _CASE; }
break;
case 11:
	{ return _CONST; }
break;
case 12:
	{ return _DIV; }
break;
case 13:
	{ return _DO; }
break;
case 14:
{ return _DOWNTO; }
break;
case 15:
	{ return _ELSE; }
break;
case 16:
	{ return _END; }
break;
case 17:
	{ return _FILE; }
break;
case 18:
	{ return _FOR; }
break;
case 19:
{ return _FORWARD; }
break;
case 20:
{ ++procno; return _FUNCTION; }
break;
case 21:
	{ return _GOTO; }
break;
case 22:
	{ return _IF; }
break;
case 23:
	{ return _IN; }
break;
case 24:
	{ return _LABEL; }
break;
case 25:
	{ return _MOD; }
break;
case 26:
	{ return _NIL; }
break;
case 27:
	{ return _NOT; }
break;
case 28:
	{ return _OF; }
break;
case 29:
	{ return _OR; }
break;
case 30:
{ return _PACKED; }
break;
case 31:
{ ++procno; return _PROCEDURE; }
break;
case 32:
{ return _PROGRAM; }
break;
case 33:
{ return _RECORD; }
break;
case 34:
{ return _REPEAT; }
break;
case 35:
	{ return _SET; }
break;
case 36:
	{ return _THEN; }
break;
case 37:
	{ return _TO; }
break;
case 38:
	{ return _TYPE; }
break;
case 39:
	{ return _UNTIL; }
break;
case 40:
	{ return _VAR; }
break;
case 41:
	{ return _WHILE; }
break;
case 42:
	{ return _WITH; }
break;
case 43:
	{ return _ADD; }
break;
case 44:
	{ return _SUB; }
break;
case 45:
	{ return _MUL; }
break;
case 46:
	{ return _FRAC; }
break;
case 47:
	{ return _EQL; }
break;
case 48:
	{ return _DIF; }
break;
case 49:
	{ return _SML; }
break;
case 50:
	{ return _SEQL; }
break;
case 51:
	{ return _GEQL; }
break;
case 52:
	{ return _GRT; }
break;
case 53:
	{ return _PARESQ; }
break;
case 54:
	{ return _PARDIR; }
break;
case 55:
	{ return _RECESQ; }
break;
case 56:
	{ return _RECDIR; }
break;
case 57:
	{ return _ATR; }
break;
case 58:
	{ return _POINT; }
break;
case 59:
	{ return _VIRG; }
break;
case 60:
	{ return _PVIRG; }
break;
case 61:
	{ return _DOISP; }
break;
case 62:
	{ return _PONPON; }
break;
case 63:
	{ return _CHAP; }
break;
case 64:
{ return _MAXINT; }
break;
case 65:
	{ return _FALSE; }
break;
case 66:
	{ return _TRUE; }
break;
case 67:
{ return _BOOLEAN; }
break;
case 68:
	{ return _CHAR; }
break;
case 69:
{ return _INTEGER; }
break;
case 70:
	{ return _REAL; }
break;
case 71:
	{ return _TEXT; }
break;
case 72:
         { return _READ; }
break;
case 73:
       { return _READLN; }
break;
case 74:
	{ return _WRITE; }
break;
case 75:
{ return _WRITELN; }
break;
case 76:
	{ 
			  yylval.strval = (char *)
				malloc(sizeof(char) * (yyleng + 1));
			  strcpy(yylval.strval, yytext);
			  return _IDENT;
			}
break;
case 77:
	{
		  yylval.intval = atoi(yytext);
		  return _INT;
		}
break;
case 78:
	{
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
break;
case 79:
{
					  yylval.realval = atof(yytext);
					  return _NUM;
					}
break;
case 80:
	{
		  printf ("Erro de Sintaxe.\n");
		  yyerrok;
		}
break;
case -1:
break;
default:
fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */
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
int yyvstop[] ={
0,

77,
0,

77,
0,

80,
0,

2,
80,
0,

1,
0,

80,
0,

53,
80,
0,

54,
80,
0,

45,
80,
0,

43,
80,
0,

59,
80,
0,

44,
80,
0,

58,
78,
80,
0,

46,
80,
0,

77,
80,
0,

61,
80,
0,

60,
80,
0,

49,
80,
0,

47,
80,
0,

52,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

76,
80,
0,

55,
80,
0,

56,
80,
0,

63,
80,
0,

80,
0,

5,
0,

62,
0,

78,
0,

77,
0,

57,
0,

50,
0,

48,
0,

51,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

13,
76,
0,

76,
79,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

22,
76,
0,

23,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

28,
76,
0,

29,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

37,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

3,
0,

4,
5,
0,

5,
0,

4,
0,

6,
0,

79,
0,

7,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

12,
76,
0,

76,
0,

76,
0,

16,
76,
0,

76,
0,

76,
0,

18,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

25,
76,
0,

26,
76,
0,

27,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

35,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

40,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

10,
76,
0,

68,
76,
0,

76,
0,

76,
0,

15,
76,
0,

76,
0,

17,
76,
0,

76,
0,

76,
0,

21,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

72,
76,
0,

70,
76,
0,

76,
0,

76,
0,

71,
76,
0,

36,
76,
0,

66,
76,
0,

38,
76,
0,

76,
0,

76,
0,

42,
76,
0,

76,
0,

8,
76,
0,

9,
76,
0,

76,
0,

11,
76,
0,

76,
0,

65,
76,
0,

76,
0,

76,
0,

76,
0,

24,
76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

76,
0,

39,
76,
0,

41,
76,
0,

74,
76,
0,

76,
0,

14,
76,
0,

76,
0,

76,
0,

76,
0,

64,
76,
0,

30,
76,
0,

76,
0,

76,
0,

73,
76,
0,

33,
76,
0,

34,
76,
0,

76,
0,

67,
76,
0,

19,
76,
0,

76,
0,

69,
76,
0,

76,
0,

32,
76,
0,

75,
76,
0,

20,
76,
0,

76,
0,

31,
76,
0,
0};
# define YYTYPE int
struct yywork { YYTYPE verify, advance; } yycrank[] ={
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,4,	1,5,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
1,6,	1,7,	1,8,	1,9,	
1,10,	1,11,	1,12,	1,13,	
1,14,	1,15,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	1,16,	
1,17,	1,18,	1,19,	1,20,	
0,0,	0,0,	1,21,	1,22,	
1,23,	1,24,	1,25,	1,26,	
1,27,	1,28,	1,29,	1,28,	
1,28,	1,30,	1,31,	1,32,	
1,33,	1,34,	1,28,	1,35,	
1,36,	1,37,	1,38,	1,39,	
1,40,	1,28,	1,28,	1,28,	
1,41,	7,48,	1,42,	1,43,	
1,3,	16,53,	18,54,	18,55,	
20,56,	2,7,	2,8,	22,60,	
47,103,	2,11,	2,12,	2,13,	
2,14,	24,65,	0,0,	0,0,	
22,57,	22,61,	24,57,	24,66,	
22,57,	0,0,	24,57,	2,16,	
2,17,	2,18,	2,19,	2,20,	
1,44,	0,0,	1,3,	2,22,	
2,23,	2,24,	2,25,	2,26,	
2,27,	2,28,	2,29,	2,28,	
2,28,	2,30,	2,31,	2,32,	
2,33,	2,34,	2,28,	2,35,	
2,36,	2,37,	2,38,	2,39,	
2,40,	2,28,	2,28,	2,28,	
2,41,	6,45,	2,42,	2,43,	
27,57,	27,75,	0,0,	0,0,	
27,57,	6,45,	6,46,	13,49,	
30,78,	13,50,	13,50,	13,50,	
13,50,	13,50,	13,50,	13,50,	
13,50,	13,50,	13,50,	23,62,	
28,57,	30,57,	0,0,	38,94,	
28,57,	30,57,	23,63,	38,57,	
2,44,	29,76,	13,51,	0,0,	
23,57,	23,64,	0,0,	6,47,	
23,57,	29,77,	6,45,	6,45,	
0,0,	29,57,	31,79,	15,50,	
6,45,	15,52,	15,52,	15,52,	
15,52,	15,52,	15,52,	15,52,	
15,52,	15,52,	15,52,	31,57,	
31,80,	32,81,	35,87,	31,57,	
33,83,	6,45,	32,57,	32,82,	
40,96,	40,97,	32,57,	35,57,	
33,57,	0,0,	40,57,	35,57,	
33,84,	34,85,	40,98,	21,57,	
21,57,	21,57,	21,57,	21,57,	
21,57,	21,57,	21,57,	21,57,	
21,57,	57,57,	34,57,	0,0,	
0,0,	57,57,	34,86,	6,45,	
21,57,	21,57,	21,57,	21,57,	
21,57,	21,57,	21,57,	21,57,	
21,57,	21,57,	21,57,	21,57,	
21,57,	21,58,	21,57,	21,57,	
21,57,	21,59,	21,57,	21,57,	
21,57,	21,57,	21,57,	21,57,	
21,57,	21,57,	25,67,	0,0,	
25,67,	6,45,	21,57,	25,68,	
25,68,	25,68,	25,68,	25,68,	
25,68,	25,68,	25,68,	25,68,	
25,68,	36,88,	59,57,	26,71,	
44,99,	39,95,	59,107,	0,0,	
0,0,	0,0,	36,57,	26,72,	
44,99,	44,99,	36,57,	0,0,	
26,57,	26,73,	39,57,	25,69,	
26,57,	25,70,	39,57,	26,74,	
37,89,	25,57,	62,57,	37,90,	
45,46,	0,0,	62,57,	62,110,	
0,0,	37,57,	37,91,	46,46,	
45,46,	37,92,	58,106,	0,0,	
0,0,	0,0,	44,99,	46,46,	
37,93,	44,99,	44,99,	48,48,	
58,57,	64,112,	60,108,	44,99,	
58,57,	64,57,	63,111,	48,48,	
48,48,	60,57,	61,57,	61,109,	
69,57,	60,57,	61,57,	0,0,	
69,57,	69,115,	45,101,	63,57,	
44,99,	45,46,	45,46,	63,57,	
71,117,	46,102,	71,57,	45,46,	
46,46,	46,46,	71,57,	65,57,	
73,57,	0,0,	46,46,	65,57,	
73,119,	48,48,	66,57,	65,113,	
48,104,	48,48,	66,57,	72,118,	
45,46,	72,57,	48,48,	66,114,	
0,0,	72,57,	44,99,	46,46,	
50,50,	50,50,	50,50,	50,50,	
50,50,	50,50,	50,50,	50,50,	
50,50,	50,50,	70,116,	48,48,	
74,120,	75,57,	76,57,	0,0,	
74,57,	75,57,	76,57,	75,121,	
70,57,	50,51,	45,46,	0,0,	
70,57,	51,67,	0,0,	51,67,	
44,100,	46,46,	51,105,	51,105,	
51,105,	51,105,	51,105,	51,105,	
51,105,	51,105,	51,105,	51,105,	
52,50,	48,48,	52,52,	52,52,	
52,52,	52,52,	52,52,	52,52,	
52,52,	52,52,	52,52,	52,52,	
45,46,	83,57,	84,57,	0,0,	
0,0,	83,57,	84,57,	46,46,	
67,105,	67,105,	67,105,	67,105,	
67,105,	67,105,	67,105,	67,105,	
67,105,	67,105,	0,0,	48,48,	
68,68,	68,68,	68,68,	68,68,	
68,68,	68,68,	68,68,	68,68,	
68,68,	68,68,	77,57,	78,123,	
80,125,	0,0,	77,57,	79,57,	
77,122,	85,128,	81,126,	79,57,	
81,57,	0,0,	80,57,	78,57,	
81,57,	79,124,	80,57,	78,57,	
85,57,	82,57,	68,57,	0,0,	
85,57,	82,57,	68,57,	82,127,	
86,57,	86,129,	88,57,	87,130,	
86,57,	87,131,	88,57,	89,57,	
88,133,	91,57,	90,135,	89,57,	
0,0,	91,57,	0,0,	0,0,	
87,57,	89,134,	87,132,	90,57,	
87,57,	92,57,	93,57,	90,57,	
93,137,	92,57,	93,57,	94,57,	
92,136,	0,0,	95,57,	94,57,	
96,140,	94,138,	95,139,	106,57,	
97,57,	96,57,	98,142,	106,57,	
97,57,	96,57,	97,141,	98,57,	
107,143,	108,144,	109,145,	98,57,	
109,57,	110,146,	108,57,	111,57,	
109,57,	0,0,	108,57,	111,147,	
113,57,	107,57,	110,57,	112,57,	
113,57,	107,57,	110,57,	112,57,	
112,148,	114,149,	115,150,	116,57,	
117,57,	114,57,	0,0,	116,57,	
117,57,	117,151,	118,152,	115,57,	
119,57,	120,154,	0,0,	115,57,	
119,57,	0,0,	122,156,	118,57,	
0,0,	119,153,	0,0,	118,57,	
120,57,	121,57,	121,155,	122,57,	
120,57,	121,57,	123,157,	122,57,	
124,158,	0,0,	125,57,	0,0,	
126,57,	124,57,	125,57,	123,57,	
126,57,	124,57,	127,57,	123,57,	
128,159,	129,160,	127,57,	128,57,	
133,57,	129,161,	0,0,	128,57,	
133,57,	130,162,	131,57,	131,164,	
129,57,	132,165,	131,57,	0,0,	
129,57,	130,163,	0,0,	130,57,	
135,167,	134,57,	132,57,	130,57,	
135,57,	134,57,	132,57,	134,166,	
136,168,	137,169,	138,170,	0,0,	
139,57,	0,0,	141,172,	138,57,	
139,57,	136,57,	137,57,	138,57,	
141,57,	136,57,	137,57,	140,171,	
141,57,	140,57,	142,57,	143,57,	
0,0,	140,57,	142,57,	143,57,	
142,173,	144,175,	145,176,	146,57,	
147,57,	144,57,	143,174,	146,57,	
147,57,	0,0,	148,57,	145,57,	
151,179,	149,57,	148,57,	145,57,	
148,177,	149,57,	150,57,	149,178,	
152,57,	151,57,	150,57,	153,180,	
152,57,	151,57,	154,57,	155,57,	
156,182,	158,184,	154,57,	155,57,	
154,181,	158,57,	161,57,	156,57,	
153,57,	159,185,	161,187,	156,57,	
153,57,	157,183,	160,186,	157,57,	
163,57,	164,57,	159,57,	157,57,	
163,57,	164,189,	159,57,	160,57,	
162,188,	165,190,	162,57,	160,57,	
166,57,	167,57,	162,57,	168,57,	
166,57,	167,57,	0,0,	168,57,	
169,57,	170,191,	165,57,	170,57,	
169,57,	171,192,	165,57,	170,57,	
172,57,	174,57,	173,193,	175,57,	
172,57,	174,57,	171,57,	175,57,	
176,194,	177,57,	171,57,	173,57,	
0,0,	177,57,	179,57,	173,57,	
178,57,	178,195,	179,57,	180,57,	
178,57,	176,57,	181,197,	180,196,	
182,198,	176,57,	183,57,	181,57,	
184,57,	185,200,	183,57,	181,57,	
184,57,	182,57,	184,199,	186,201,	
188,203,	182,57,	187,202,	185,57,	
188,57,	0,0,	189,204,	185,57,	
190,57,	186,57,	0,0,	0,0,	
190,57,	186,57,	190,205,	187,57,	
189,57,	191,57,	192,57,	187,57,	
189,57,	191,57,	192,57,	193,206,	
194,207,	193,57,	195,57,	196,208,	
194,57,	193,57,	195,57,	197,57,	
197,209,	0,0,	198,57,	197,57,	
199,57,	196,57,	198,210,	200,57,	
199,57,	196,57,	201,57,	200,57,	
0,0,	0,0,	201,57,	202,212,	
202,57,	201,211,	203,57,	204,57,	
202,57,	205,57,	203,57,	204,57,	
206,213,	205,57,	207,57,	208,57,	
206,57,	209,214,	207,57,	208,57,	
210,57,	209,57,	211,57,	212,57,	
210,57,	213,57,	211,215,	212,57,	
214,57,	213,57,	215,216,	216,57,	
214,57,	0,0,	0,0,	216,57,	
0,0,	0,0,	0,0,	215,57,	
0,0,	0,0,	0,0,	215,57,	
0,0};
struct yysvf yysvec[] ={
0,	0,	0,
yycrank+-1,	0,		yyvstop+1,
yycrank+-61,	yysvec+1,	yyvstop+3,
yycrank+0,	0,		yyvstop+5,
yycrank+0,	0,		yyvstop+7,
yycrank+0,	0,		yyvstop+10,
yycrank+-152,	0,		yyvstop+12,
yycrank+51,	0,		yyvstop+14,
yycrank+0,	0,		yyvstop+17,
yycrank+0,	0,		yyvstop+20,
yycrank+0,	0,		yyvstop+23,
yycrank+0,	0,		yyvstop+26,
yycrank+0,	0,		yyvstop+29,
yycrank+117,	0,		yyvstop+32,
yycrank+0,	0,		yyvstop+36,
yycrank+153,	yysvec+13,	yyvstop+39,
yycrank+36,	0,		yyvstop+42,
yycrank+0,	0,		yyvstop+45,
yycrank+37,	0,		yyvstop+48,
yycrank+0,	0,		yyvstop+51,
yycrank+39,	0,		yyvstop+54,
yycrank+183,	0,		yyvstop+57,
yycrank+34,	yysvec+21,	yyvstop+60,
yycrank+110,	yysvec+21,	yyvstop+63,
yycrank+36,	yysvec+21,	yyvstop+66,
yycrank+231,	yysvec+21,	yyvstop+69,
yycrank+226,	yysvec+21,	yyvstop+72,
yycrank+78,	yysvec+21,	yyvstop+75,
yycrank+98,	yysvec+21,	yyvstop+78,
yycrank+115,	yysvec+21,	yyvstop+81,
yycrank+99,	yysvec+21,	yyvstop+84,
yycrank+133,	yysvec+21,	yyvstop+87,
yycrank+140,	yysvec+21,	yyvstop+90,
yycrank+146,	yysvec+21,	yyvstop+93,
yycrank+164,	yysvec+21,	yyvstop+96,
yycrank+145,	yysvec+21,	yyvstop+99,
yycrank+220,	yysvec+21,	yyvstop+102,
yycrank+243,	yysvec+21,	yyvstop+105,
yycrank+101,	yysvec+21,	yyvstop+108,
yycrank+228,	yysvec+21,	yyvstop+111,
yycrank+148,	yysvec+21,	yyvstop+114,
yycrank+0,	0,		yyvstop+117,
yycrank+0,	0,		yyvstop+120,
yycrank+0,	0,		yyvstop+123,
yycrank+-291,	0,		yyvstop+126,
yycrank+-315,	yysvec+6,	0,	
yycrank+-322,	yysvec+6,	0,	
yycrank+65,	0,		yyvstop+128,
yycrank+-334,	0,		0,	
yycrank+0,	0,		yyvstop+130,
yycrank+340,	0,		yyvstop+132,
yycrank+370,	0,		0,	
yycrank+382,	yysvec+13,	yyvstop+134,
yycrank+0,	0,		yyvstop+136,
yycrank+0,	0,		yyvstop+138,
yycrank+0,	0,		yyvstop+140,
yycrank+0,	0,		yyvstop+142,
yycrank+163,	yysvec+21,	yyvstop+144,
yycrank+258,	yysvec+21,	yyvstop+146,
yycrank+212,	yysvec+21,	yyvstop+148,
yycrank+267,	yysvec+21,	yyvstop+150,
yycrank+268,	yysvec+21,	yyvstop+152,
yycrank+236,	yysvec+21,	yyvstop+154,
yycrank+277,	yysvec+21,	yyvstop+156,
yycrank+259,	yysvec+21,	yyvstop+158,
yycrank+289,	yysvec+21,	yyvstop+160,
yycrank+296,	yysvec+21,	yyvstop+162,
yycrank+400,	0,		0,	
yycrank+412,	yysvec+21,	yyvstop+165,
yycrank+270,	yysvec+21,	yyvstop+168,
yycrank+330,	yysvec+21,	yyvstop+170,
yycrank+284,	yysvec+21,	yyvstop+172,
yycrank+303,	yysvec+21,	yyvstop+174,
yycrank+290,	yysvec+21,	yyvstop+176,
yycrank+322,	yysvec+21,	yyvstop+178,
yycrank+323,	yysvec+21,	yyvstop+180,
yycrank+324,	yysvec+21,	yyvstop+182,
yycrank+392,	yysvec+21,	yyvstop+185,
yycrank+405,	yysvec+21,	yyvstop+188,
yycrank+397,	yysvec+21,	yyvstop+190,
yycrank+404,	yysvec+21,	yyvstop+192,
yycrank+402,	yysvec+21,	yyvstop+194,
yycrank+411,	yysvec+21,	yyvstop+196,
yycrank+363,	yysvec+21,	yyvstop+198,
yycrank+364,	yysvec+21,	yyvstop+201,
yycrank+410,	yysvec+21,	yyvstop+204,
yycrank+418,	yysvec+21,	yyvstop+206,
yycrank+434,	yysvec+21,	yyvstop+208,
yycrank+420,	yysvec+21,	yyvstop+210,
yycrank+425,	yysvec+21,	yyvstop+212,
yycrank+437,	yysvec+21,	yyvstop+214,
yycrank+427,	yysvec+21,	yyvstop+216,
yycrank+439,	yysvec+21,	yyvstop+219,
yycrank+440,	yysvec+21,	yyvstop+221,
yycrank+445,	yysvec+21,	yyvstop+223,
yycrank+448,	yysvec+21,	yyvstop+225,
yycrank+455,	yysvec+21,	yyvstop+227,
yycrank+454,	yysvec+21,	yyvstop+229,
yycrank+461,	yysvec+21,	yyvstop+231,
yycrank+0,	yysvec+44,	0,	
yycrank+0,	0,		yyvstop+233,
yycrank+0,	0,		yyvstop+235,
yycrank+0,	0,		yyvstop+238,
yycrank+0,	0,		yyvstop+240,
yycrank+0,	0,		yyvstop+242,
yycrank+0,	yysvec+67,	yyvstop+244,
yycrank+453,	yysvec+21,	yyvstop+246,
yycrank+475,	yysvec+21,	yyvstop+249,
yycrank+468,	yysvec+21,	yyvstop+251,
yycrank+466,	yysvec+21,	yyvstop+253,
yycrank+476,	yysvec+21,	yyvstop+255,
yycrank+469,	yysvec+21,	yyvstop+257,
yycrank+477,	yysvec+21,	yyvstop+259,
yycrank+474,	yysvec+21,	yyvstop+261,
yycrank+483,	yysvec+21,	yyvstop+264,
yycrank+493,	yysvec+21,	yyvstop+266,
yycrank+485,	yysvec+21,	yyvstop+268,
yycrank+486,	yysvec+21,	yyvstop+271,
yycrank+501,	yysvec+21,	yyvstop+273,
yycrank+494,	yysvec+21,	yyvstop+275,
yycrank+506,	yysvec+21,	yyvstop+278,
yycrank+507,	yysvec+21,	yyvstop+280,
yycrank+509,	yysvec+21,	yyvstop+282,
yycrank+521,	yysvec+21,	yyvstop+284,
yycrank+519,	yysvec+21,	yyvstop+286,
yycrank+516,	yysvec+21,	yyvstop+288,
yycrank+518,	yysvec+21,	yyvstop+291,
yycrank+524,	yysvec+21,	yyvstop+294,
yycrank+529,	yysvec+21,	yyvstop+297,
yycrank+538,	yysvec+21,	yyvstop+299,
yycrank+545,	yysvec+21,	yyvstop+301,
yycrank+536,	yysvec+21,	yyvstop+303,
yycrank+548,	yysvec+21,	yyvstop+305,
yycrank+530,	yysvec+21,	yyvstop+307,
yycrank+547,	yysvec+21,	yyvstop+310,
yycrank+546,	yysvec+21,	yyvstop+312,
yycrank+563,	yysvec+21,	yyvstop+314,
yycrank+564,	yysvec+21,	yyvstop+316,
yycrank+561,	yysvec+21,	yyvstop+318,
yycrank+558,	yysvec+21,	yyvstop+320,
yycrank+571,	yysvec+21,	yyvstop+323,
yycrank+566,	yysvec+21,	yyvstop+325,
yycrank+572,	yysvec+21,	yyvstop+327,
yycrank+573,	yysvec+21,	yyvstop+329,
yycrank+579,	yysvec+21,	yyvstop+331,
yycrank+589,	yysvec+21,	yyvstop+333,
yycrank+581,	yysvec+21,	yyvstop+335,
yycrank+582,	yysvec+21,	yyvstop+338,
yycrank+588,	yysvec+21,	yyvstop+341,
yycrank+591,	yysvec+21,	yyvstop+343,
yycrank+596,	yysvec+21,	yyvstop+345,
yycrank+599,	yysvec+21,	yyvstop+348,
yycrank+598,	yysvec+21,	yyvstop+350,
yycrank+614,	yysvec+21,	yyvstop+353,
yycrank+604,	yysvec+21,	yyvstop+355,
yycrank+605,	yysvec+21,	yyvstop+357,
yycrank+613,	yysvec+21,	yyvstop+360,
yycrank+621,	yysvec+21,	yyvstop+362,
yycrank+607,	yysvec+21,	yyvstop+364,
yycrank+624,	yysvec+21,	yyvstop+366,
yycrank+629,	yysvec+21,	yyvstop+368,
yycrank+612,	yysvec+21,	yyvstop+370,
yycrank+632,	yysvec+21,	yyvstop+372,
yycrank+622,	yysvec+21,	yyvstop+375,
yycrank+623,	yysvec+21,	yyvstop+378,
yycrank+644,	yysvec+21,	yyvstop+380,
yycrank+634,	yysvec+21,	yyvstop+382,
yycrank+635,	yysvec+21,	yyvstop+385,
yycrank+637,	yysvec+21,	yyvstop+388,
yycrank+642,	yysvec+21,	yyvstop+391,
yycrank+645,	yysvec+21,	yyvstop+394,
yycrank+656,	yysvec+21,	yyvstop+396,
yycrank+650,	yysvec+21,	yyvstop+398,
yycrank+661,	yysvec+21,	yyvstop+401,
yycrank+651,	yysvec+21,	yyvstop+403,
yycrank+653,	yysvec+21,	yyvstop+406,
yycrank+671,	yysvec+21,	yyvstop+409,
yycrank+659,	yysvec+21,	yyvstop+411,
yycrank+666,	yysvec+21,	yyvstop+414,
yycrank+664,	yysvec+21,	yyvstop+416,
yycrank+669,	yysvec+21,	yyvstop+419,
yycrank+677,	yysvec+21,	yyvstop+421,
yycrank+683,	yysvec+21,	yyvstop+423,
yycrank+676,	yysvec+21,	yyvstop+425,
yycrank+678,	yysvec+21,	yyvstop+428,
yycrank+689,	yysvec+21,	yyvstop+430,
yycrank+695,	yysvec+21,	yyvstop+432,
yycrank+701,	yysvec+21,	yyvstop+434,
yycrank+686,	yysvec+21,	yyvstop+436,
yycrank+702,	yysvec+21,	yyvstop+438,
yycrank+694,	yysvec+21,	yyvstop+440,
yycrank+703,	yysvec+21,	yyvstop+442,
yycrank+704,	yysvec+21,	yyvstop+445,
yycrank+711,	yysvec+21,	yyvstop+448,
yycrank+710,	yysvec+21,	yyvstop+451,
yycrank+712,	yysvec+21,	yyvstop+453,
yycrank+723,	yysvec+21,	yyvstop+456,
yycrank+717,	yysvec+21,	yyvstop+458,
yycrank+720,	yysvec+21,	yyvstop+460,
yycrank+722,	yysvec+21,	yyvstop+462,
yycrank+725,	yysvec+21,	yyvstop+465,
yycrank+728,	yysvec+21,	yyvstop+468,
yycrank+734,	yysvec+21,	yyvstop+470,
yycrank+736,	yysvec+21,	yyvstop+472,
yycrank+737,	yysvec+21,	yyvstop+475,
yycrank+739,	yysvec+21,	yyvstop+478,
yycrank+742,	yysvec+21,	yyvstop+481,
yycrank+744,	yysvec+21,	yyvstop+483,
yycrank+745,	yysvec+21,	yyvstop+486,
yycrank+747,	yysvec+21,	yyvstop+489,
yycrank+750,	yysvec+21,	yyvstop+491,
yycrank+752,	yysvec+21,	yyvstop+494,
yycrank+753,	yysvec+21,	yyvstop+496,
yycrank+755,	yysvec+21,	yyvstop+499,
yycrank+758,	yysvec+21,	yyvstop+502,
yycrank+769,	yysvec+21,	yyvstop+505,
yycrank+761,	yysvec+21,	yyvstop+507,
0,	0,	0};
struct yywork *yytop = yycrank+851;
struct yysvf *yybgin = yysvec+1;
char yymatch[] ={
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,011 ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
011 ,01  ,01  ,01  ,01  ,01  ,01  ,047 ,
01  ,01  ,'*' ,'+' ,01  ,'+' ,01  ,01  ,
'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,
'0' ,'0' ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,01  ,01  ,01  ,01  ,'_' ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,'}' ,01  ,01  ,
0};
char yyextra[] ={
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
/*	ncform	4.1	83/08/11	*/

int yylineno =1;
# define YYU(x) x
# define NLSTATE yyprevious=YYNEWLINE
char yytext[YYLMAX];
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
char yysbuf[YYLMAX];
char *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
yylook(){
	register struct yysvf *yystate, **lsp;
	register struct yywork *yyt;
	struct yysvf *yyz;
	int yych;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	char *yylastch;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	if (!yymorfg)
		yylastch = yytext;
	else {
		yymorfg=0;
		yylastch = yytext+yyleng;
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == yycrank){		/* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == yycrank)break;
				}
			*yylastch++ = yych = input();
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if ( (int)yyt > (int)yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if((int)yyt < (int)yycrank) {		/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = yylastch-yytext+1;
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch ");
					sprint(yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
		yyprevious = yytext[0] = input();
		if (yyprevious>0)
			output(yyprevious);
		yylastch=yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}
yyback(p, m)
	int *p;
{
if (p==0) return(0);
while (*p)
	{
	if (*p++ == m)
		return(1);
	}
return(0);
}
	/* the following are only used in the lex library */
yyinput(){
	return(input());
	}
yyoutput(c)
  int c; {
	output(c);
	}
yyunput(c)
   int c; {
	unput(c);
	}
