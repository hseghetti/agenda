
# line 4 "pascal.y"
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


# line 20 "pascal.y"
typedef union 
{
  int intval;
  char *strval;
  double realval;
  Node *nodeval;
  InfoType *typeval;
} YYSTYPE;
# define _AND 257
# define _ARRAY 258
# define _BEGIN 259
# define _CASE 260
# define _CONST 261
# define _DIV 262
# define _DO 263
# define _DOWNTO 264
# define _ELSE 265
# define _END 266
# define _FILE 267
# define _FOR 268
# define _FUNCTION 269
# define _GOTO 270
# define _IF 271
# define _IN 272
# define _LABEL 273
# define _MOD 274
# define _NIL 275
# define _NOT 276
# define _OF 277
# define _OR 278
# define _PACKED 279
# define _PROCEDURE 280
# define _PROGRAM 281
# define _RECORD 282
# define _REPEAT 283
# define _SET 284
# define _THEN 285
# define _TO 286
# define _TYPE 287
# define _UNTIL 288
# define _VAR 289
# define _WHILE 290
# define _WITH 291
# define _FORWARD 292
# define _PVIRG 293
# define _EQL 294
# define _DIF 295
# define _SML 296
# define _SEQL 297
# define _GEQL 298
# define _GRT 299
# define _ADD 300
# define _SUB 301
# define _MUL 302
# define _FRAC 303
# define _PARESQ 304
# define _PARDIR 305
# define _RECESQ 306
# define _RECDIR 307
# define _ATR 308
# define _POINT 309
# define _VIRG 310
# define _DOISP 311
# define _PONPON 312
# define _CHAP 313
# define _MAXINT 314
# define _FALSE 315
# define _TRUE 316
# define _INPUT 317
# define _OUTPUT 318
# define _BOOLEAN 319
# define _CHAR 320
# define _INTEGER 321
# define _REAL 322
# define _TEXT 323
# define _WRITE 324
# define _WRITELN 325
# define _READ 326
# define _READLN 327
# define _IDENT 328
# define _INT 329
# define _NUM 330
# define _STRING 331
# define _CAR 332
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern short yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
YYSTYPE yylval, yyval;
# define YYERRCODE 256

# line 718 "pascal.y"


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
}short yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 36,
	328, 15,
	-2, 14,
-1, 41,
	328, 22,
	-2, 21,
-1, 90,
	312, 221,
	-2, 68,
-1, 119,
	308, 116,
	-2, 144,
-1, 136,
	328, 31,
	-2, 29,
-1, 201,
	328, 47,
	-2, 49,
-1, 329,
	328, 53,
	-2, 55,
	};
# define YYNPROD 228
# define YYLAST 688
short yyact[]={

 177, 362, 174, 332, 210, 102, 381, 354,  95, 226,
 330, 214, 189, 275, 315, 274,  55,  54, 364,  38,
  20,  66, 215,  81,  33, 105,  25, 188, 287,  49,
  53,  51,  82,  52, 284, 229, 185,  10,  35, 135,
  50, 134,  27,  21,  74,  50,  46,  84,   5,  83,
  50,  50,  44, 262, 350, 378,  99, 100, 312, 214,
 131, 175, 179,  65, 162,  96,  97, 163, 152,  93,
 253, 164, 372,  68, 350, 377, 350, 349,  80,  66,
  55,  54, 339,  50,  88,  86,  87,  85,  89, 323,
 178, 270, 181,  90,  53,  51,  35,  52,  27,  50,
  50,  55,  54, 158, 386, 153, 154, 103, 138, 137,
  59, 121,  28,  16, 173,  53,  51, 176,  52, 124,
 344, 126, 120, 325, 131, 289, 131,  66, 260,  29,
 165, 182, 183, 340, 123, 310, 291, 258, 311, 159,
  50, 122, 125, 248,  81, 162, 146, 259, 163,  50,
  50,  50, 164,  82, 388,  50, 382, 131, 161, 131,
 162, 205, 218, 163, 309,  74, 324, 164,  84, 221,
  83, 260, 228, 201, 195, 127, 128, 129, 130, 119,
 104, 194, 222, 166, 220, 223,  96,  97, 249, 224,
  93, 254, 321, 288, 260, 131, 131, 322, 289, 216,
 290,  55,  54, 291,  15,  88,  86,  87,  85,  89,
 279, 204,  14, 280,  90,  53,  51,  15,  52, 191,
 131, 208, 329,  96,  97, 285, 278,  93,   7,  42,
 245, 131, 228,  37, 328, 243,  80, 376,  55,  54,
 326, 282,  88,  86,  87,  85,  89, 244, 269, 257,
 347,  90,  53,  51, 156,  52, 292, 131,  50, 240,
 131, 131, 316, 237,  46, 319, 155, 317, 318, 267,
 266, 175, 179,  50, 314, 241, 242, 348, 157, 175,
 179, 238, 239,  50, 333, 231, 232, 233, 234, 235,
 236, 136, 133, 156,  13, 331, 171, 172,  13, 341,
 178, 342, 181, 251, 171, 172, 132,  41, 178,  36,
 181,  55,  54, 199, 230,   8,  31, 197, 352,  55,
  54, 254, 346,  23, 173,  53,  51, 176,  52, 213,
 212,   4, 173,  53,  51, 176,  52,  50,  62,  79,
 351,  50,  50, 358, 131, 357,  69,  46, 338,  63,
 131,  50, 334,  50, 255, 368, 359,  46, 148,  46,
 374, 370, 371, 375,  50, 369, 373, 367, 147, 366,
  46,  13, 281,  96,  97, 263, 353,  93, 331, 131,
 131, 131, 345, 149, 383, 384, 385, 387,  55,  54,
 343, 118,  88,  86,  87,  85,  89, 380,  59, 121,
 379,  90,  53,  51,  59,  52, 256, 124, 360, 126,
 120,  47,  48, 365,  62, 293, 294, 295, 296, 297,
 298, 299, 123,  59, 121,  63,  55,  54,  18, 122,
 125, 169, 124, 225, 126, 120, 227, 186,  94,  49,
  53,  51,  45,  52,  96,  97, 168, 123,  93, 170,
  71,  11, 200,  81, 122, 125, 101,   9,  70,  55,
  54, 190,  82, 127, 128, 129, 130, 119, 104,  96,
  97,  76,  90,  53,  51,  75,  52,  84,  73,  83,
  77,  34,  26, 108,  55,  54, 207, 276, 127, 128,
 129, 130, 119, 277, 252, 180, 219,  49,  53,  51,
 313,  52, 115, 114, 113, 112, 263, 110, 160, 363,
 361, 283, 211, 150, 206,  72,  92, 187,  91, 356,
 355, 273, 272,  56, 271, 268,  98,  60, 203,  64,
  40, 144,  67,  61,  32,  43,  24,  19,  30, 145,
  22,  17,  12,   6,   3,  78, 142,   2,  39, 139,
 141, 151, 261, 140, 192, 143, 117, 111, 109, 116,
 107, 167, 106,  58,  57,   1,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
 184,   0,   0,   0, 196, 198, 187, 187, 202,   0,
 193, 217,   0,   0,   0,   0,   0,   0,   0, 209,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0, 250, 337, 336,   0,   0,   0, 327,   0,   0,
 335, 246, 247,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 264, 265,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 320,   0,   0,   0,   0,   0,   0, 286,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0, 303, 304, 305, 306, 307,   0,   0,
   0,   0, 308,   0,   0, 300, 301, 302 };
short yypact[]={

-1000,-1000,-1000,  50,-280, -76,  22,-291,  98, -93,
-1000,-196, 167,-309,-1000,-285,-1000,  36,-230,-181,
-1000,-1000,  27,-232,  16,-1000,-1000, -61,-1000,-310,
-1000,-1000,  14,-1000,-1000, -65,-1000, 111,-1000, 145,
-307,-1000,-235,-286,-1000,-1000,-1000,-299,-299,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-149,
  13,  -1,-287,-289,  -2,-1000,-202,-290,-1000,-1000,
-1000,-1000,-1000,-1000, 195,-1000,-1000,-1000,-1000,-1000,
-114,-160,  91,  81, 117,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-291,-244,-1000,-299,-299,-1000,-1000,
-1000,   0,-1000, -15,-208,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-169,-146,
   4,   4,   4,-149,-292,-301,-317, -85, -85,-123,
-130,-1000,  25,  21,-131,-131,-1000,-235,-307,-1000,
-1000,-1000,-1000,-1000,-1000,-1000, 144,-235,  73,-1000,
-249,-106, 169,-1000,-1000,-1000, 139,-1000, 164,   4,
-124,   4,   4,-293,-1000,  29,  -9, -19, -27,-1000,
-1000,-214,-214,-161,-1000,-1000,-1000,-1000,   4,   4,
-1000,  -4,  77, 143, -39,-171,-116,-1000,-242,-1000,
-1000,   4,-1000,-1000,-301,-301, -23, -24,-1000, -45,
-220,  69,-1000,-307,-1000,-1000, -97,-1000,-1000,-1000,
 106, -52,-1000,-1000,-294,-1000,-1000,-1000,-1000, 139,
-1000,-1000,   4,-300,-1000,-112,-1000,-107,-1000,-1000,
 164,   4,   4,   4,   4,   4,   4,   4,   4,   4,
   4,   4,   4,   4,   4,   4,-1000,-1000,   4,-141,
-1000,-1000,-172,-1000,-254, 111, 139,   4,   4, 139,
-301,-113,-1000,-222,-139,-182,-1000,-1000, -53,-1000,
 -77, -71,-307,  -5,-1000,-1000,-1000,-1000,-1000,  75,
 144,-1000,-249,  71,-229,-1000,-174,-1000,-1000,   4,
-1000,   4, 125,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
 -27, -27, -27,-1000,-1000,-1000,-1000,-1000,-185,-1000,
-1000,   4,   4, -16,-234,-1000,-1000,-1000,  54,-1000,
-1000,-1000,   4,-322,-1000,-1000,-1000,-1000,-1000,  69,
-1000,-1000,-1000,-307,-235,-1000,-1000,-1000, 111,-235,
-1000,-1000,-1000, 164,-1000,-1000,-1000,-1000, 111, 139,
 111,   4,   4,-1000,-239,-307,  -5,-1000,-1000,-1000,
-1000, 111,-1000, -56,-236,-1000,-1000,-256,-1000,-1000,
 137, 134,-323,-1000,-1000,-1000,-1000,-148, 139, 139,
 139,-1000,-201,-1000,-1000,-1000,-1000,-151,-1000 };
short yypgo[]={

   0, 565, 451, 564, 563, 493,   5,  25, 562,   9,
 183, 561, 446, 431,   2, 391,  14, 560, 559, 433,
 449, 558, 557,   8, 437, 556, 461, 554, 552,  53,
 487,   0, 548, 483, 456, 547, 545, 450, 346,  73,
 339, 458, 480,  22, 544, 543, 457, 542, 541, 540,
 538, 537, 536, 535, 482, 534, 532, 481, 530, 529,
 528, 452, 525, 524, 522,  10, 521,   3,  15,  13,
 520, 519, 518, 516, 515, 478, 475, 471, 438, 514,
 513,   4, 512, 330, 329, 511, 510,   1, 509,  18,
 508, 436, 507, 505, 504, 503, 502, 500, 496, 495,
 494,  70 };
short yyr1[]={

   0,   1,  44,  35,  45,  45,  46,  46,   2,  47,
  47,  51,  51,  48,  48,  53,  52,  52,  52,  54,
  49,  49,  56,  55,  55,  55,  57,  50,  58,  50,
  59,  60,  59,  43,  43,  32,  32,  32,   3,   3,
  30,  62,   4,   4,   5,  61,  61,  64,  63,  66,
  63,  63,  63,  70,  63,  71,  63,  63,  63,  65,
  67,  68,  69,  36,  36,  36,  36,  36,  40,  40,
  40,  37,  37,  38,  38,  41,  41,  41,  41,  41,
  41,  41,  41,  39,  39,  72,  73,  78,  78,  78,
  74,  74,  75,  77,  76,  79,  79,  42,  80,  42,
  81,  81,  81,  81,  82,  82,  84,  83,  86,  86,
  87,  87,  88,  88,  85,  85,  15,  15,  31,  90,
  90,  90,  90,  90,  90,  91,  91,  33,   6,   6,
   6,   7,   7,   7,   7,   7,   7,   7,   7,   7,
   7,   7,   7,   8,  17,  17,  19,  19,  21,  21,
  92,  22,  93,  94,  94,  95,  96,  18,  18,  25,
  25,  25,  26,  27,  27,  28,  28,  29,  29,  29,
  97,  97,  89,  89,  24,  24,  34,  98,  34,  34,
   9,   9,   9,   9,   9,   9,   9,   9,  10,  11,
  11,  11,  11,  12,  12,  12,  12,  12,  12,  13,
  13,  13,  20,  20,  20,  20,  20,  20,  20,  20,
  20,  99,  99, 100, 100, 101, 101,  16,  16,  16,
  16,  23,  23,  14,  14,  14,  14,  14 };
short yyr2[]={

   0,   1,   0,   7,   0,   3,   1,   3,   6,   0,
   3,   1,   3,   0,   3,   0,   4,   1,   1,   3,
   0,   3,   0,   4,   1,   1,   3,   0,   0,   4,
   1,   0,   4,   3,   3,   0,   2,   2,   4,   4,
   5,   0,   5,   4,   3,   0,   3,   0,   2,   0,
   2,   1,   1,   0,   4,   0,   4,   3,   3,   1,
   2,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   2,   1,   2,   1,
   2,   1,   2,   1,   1,   3,   3,   1,   2,   2,
   2,   2,   6,   3,   3,   1,   3,   2,   0,   4,
   1,   2,   3,   1,   1,   3,   1,   4,   1,   2,
   1,   2,   4,   5,   3,   1,   1,   1,   2,   3,
   2,   1,   4,   3,   2,   1,   3,   3,   0,   3,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   3,   1,   4,   1,   3,   4,   6,
   5,   4,   4,   8,   8,   4,   2,   2,   2,   4,
   4,   1,   3,   0,   1,   1,   3,   1,   3,   5,
   3,   5,   1,   3,   1,   3,   1,   0,   4,   3,
   1,   3,   3,   3,   3,   3,   3,   3,   1,   1,
   3,   3,   3,   1,   3,   3,   3,   3,   3,   1,
   2,   2,   1,   1,   1,   1,   1,   4,   3,   2,
   1,   2,   3,   1,   3,   1,   3,   1,   1,   2,
   2,   1,   1,   1,   1,   1,   1,   1 };
short yychk[]={

-1000,  -1, -35, -44, 281, 328, -45, 304, 293, -46,
 328,  -2, -47, 273, 305, 310, 309, -48, 261, -51,
 329, 328, -49, 287, -52, 256, -54, 328, 293, 310,
 -50, 289, -55, 256, -57, 328, 293, 294, 329, -32,
 -58, 293, 294, -53, -16, 331, -23, 300, 301, 328,
 -14, 330, 332, 329, 316, 315, -33,  -3,  -4, 259,
 -30,  -5, 269, 280, -59, -43, 328, -56, -39, -38,
 -41, -37, -74, -75, 279, -76, -77, -42, -36, -40,
 313, 258, 267, 284, 282, 322, 320, 321, 319, 323,
 328, -72, -73, 304, -78, -23, 300, 301, -54, -23,
 -23, -34,  -6, 256, 329,  -7,  -8, -17, -33, -21,
 -92, -22, -93, -94, -95, -96, -18, -25, -15, 328,
 271, 260, 290, 283, 268, 291, 270, 324, 325, 326,
 327, -31, 293, 293, 328, 328, 293, 311, 310, -57,
 -75, -76, -77, -42, -37, -41, 306, 277, 277, 266,
 -80, -46, 312, -23, -23, 266, 293, 293, 311, 308,
 -90, 304, 306, 309, 313,  -9, -10, -11, -12, -13,
 -20, 300, 301, 328, -14, 275, 331, -31, 304, 276,
 -99, 306,  -9,  -9, -34, 328, -24, -15, 328, 329,
 -26, 304, -27, -26, 304, 304,  -2, 292,  -2, 292,
 -61, 304, -61, -60, -39, -43, -79, -40, -39, -37,
 -81, -82, -83, -84, 260, -43, 305, -78,  -6, -98,
  -7,  -9, 306, 309, 313, -19,  -9, -91,  -9, 328,
 285, 294, 295, 296, 297, 298, 299, 272, 300, 301,
 278, 302, 303, 262, 274, 257, -20, -20, 304,  -9,
 -13, 307,-100,-101,  -9, 277, 263, 288, 308, 263,
 310, -28, -29, -10, -24, -24, 293, 293, -62, 293,
 311, -63, -64, -66, -68, -69, -30,  -5, -43, 307,
 310, 266, 293, -85, 328,  -6, -91, 328, 305, 310,
 307, 310,  -7, -10, -10, -10, -10, -10, -10, -10,
 -12, -12, -12, -13, -13, -13, -13, -13, -19, 305,
 307, 310, 312, -97, -89, -16,  -6,  -9,  -9,  -6,
 -15, 305, 310, 311, 305, 305, 293, -38, 305, 293,
 -65, -43, -67, 289, 277, -40, -83, -84, 277, 311,
 307,  -9,  -9, 265, 305,-101,  -9, 266, 293, 311,
 310, 286, 264, -29, 329, -70, -71, -68, -69, -43,
 -39, -86, -87, -88, -89, -39,  -7, -89,  -6, -16,
  -9,  -9, 311, -65, -67, -87, 293, 311, 311, 263,
 263, 329, 304,  -6,  -6,  -6, 305, -81, 305 };
short yydef[]={

   2,  -2,   1,   0,   0,   4,   0,   0,   9,   0,
   6,   0,  13,   0,   5,   0,   3,  20,   0,   0,
  11,   7,  27,   0,   0,  17,  18,   0,  10,   0,
  35,  28,   0,  24,  25,   0,  -2,   0,  12,   0,
   0,  -2,   0,   0,  19, 217, 218,   0,   0, 221,
 222, 223, 224, 225, 226, 227,   8,  36,  37, 128,
   0,   0,   0,   0,   0,  30,   0,   0,  26,  83,
  84,  73,  74,  75,   0,  77,  79,  81,  71,  72,
   0,   0,   0,   0,  98,  63,  64,  65,  66,  67,
  -2,  69,  70,   0,   0,  87,   0,   0,  16, 219,
 220,   0, 176,   0,   0, 130, 131, 132, 133, 134,
 135, 136, 137, 138, 139, 140, 141, 142,   0,  -2,
   0,   0,   0, 128,   0,   0,   0,   0, 163,   0,
 161, 117,   9,   9,  45,  45,  -2,   0,   0,  23,
  76,  78,  80,  82,  90,  91,   0,   0,   0,  97,
   0,   0,   0,  88,  89, 127, 128, 177,   0,   0,
 118,   0,   0,   0, 121,   0, 180, 188, 189, 193,
 199,   0,   0, 202, 203, 204, 205, 206,   0,   0,
 210,   0,   0,   0,   0,   0,   0, 174, 116, 156,
 157,   0, 158, 164,   0,   0,   0,   0,  41,   0,
   0,  -2,  44,   0,  33,  34,   0,  95,  94,  93,
   0, 100, 103, 104,   0, 106,  85,  86, 179, 128,
 129, 143,   0,   0, 124,   0, 146,   0, 125, 120,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0, 200, 201,   0,   0,
 209, 211,   0, 213, 215,   0, 128,   0,   0, 128,
   0,   0, 165, 167,   0,   0,  38,  39,   0,  43,
   0,   0,   0,   0,  51,  52,  61,  62,  32,   0,
   0,  99, 101,   0, 115, 178,   0, 123, 145,   0,
 119,   0, 148, 181, 182, 183, 184, 185, 186, 187,
 190, 191, 192, 194, 195, 196, 197, 198,   0, 208,
 212,   0,   0,   0,   0, 172, 151, 152,   0, 155,
 175, 162,   0,   0, 159, 160,  42,  40,  46,  -2,
  48,  59,  50,   0,   0,  96, 102, 105,   0,   0,
 122, 147, 126,   0, 207, 214, 216, 150,   0, 128,
   0,   0,   0, 166, 168,   0,   0,  57,  58,  60,
  92, 107, 108, 110,   0, 114, 149,   0, 170, 173,
   0,   0,   0,  54,  56, 109, 111,   0, 128, 128,
 128, 169,   0, 171, 153, 154, 112,   0, 113 };
#ifndef lint
static char yaccpar_sccsid[] = "@(#)yaccpar	4.1	(Berkeley)	2/11/83";
#endif not lint

#
# define YYFLAG -1000
# define YYERROR goto yyerrlab
# define YYACCEPT return(0)
# define YYABORT return(1)

/*	parser for yacc output	*/

#ifdef YYDEBUG
int yydebug = 0; /* 1 for debugging */
#endif
YYSTYPE yyv[YYMAXDEPTH]; /* where the values are stored */
int yychar = -1; /* current input token number */
int yynerrs = 0;  /* number of errors */
short yyerrflag = 0;  /* error recovery flag */

yyparse() {

	short yys[YYMAXDEPTH];
	short yyj, yym;
	register YYSTYPE *yypvt;
	register short yystate, *yyps, yyn;
	register YYSTYPE *yypv;
	register short *yyxi;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyps= &yys[-1];
	yypv= &yyv[-1];

 yystack:    /* put a state and value onto the stack */

#ifdef YYDEBUG
	if( yydebug  ) printf( "state %d, char 0%o\n", yystate, yychar );
#endif
		if( ++yyps> &yys[YYMAXDEPTH] ) { yyerror( "yacc stack overflow" ); return(1); }
		*yyps = yystate;
		++yypv;
		*yypv = yyval;

 yynewstate:

	yyn = yypact[yystate];

	if( yyn<= YYFLAG ) goto yydefault; /* simple state */

	if( yychar<0 ) if( (yychar=yylex())<0 ) yychar=0;
	if( (yyn += yychar)<0 || yyn >= YYLAST ) goto yydefault;

	if( yychk[ yyn=yyact[ yyn ] ] == yychar ){ /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if( yyerrflag > 0 ) --yyerrflag;
		goto yystack;
		}

 yydefault:
	/* default state action */

	if( (yyn=yydef[yystate]) == -2 ) {
		if( yychar<0 ) if( (yychar=yylex())<0 ) yychar = 0;
		/* look through exception table */

		for( yyxi=yyexca; (*yyxi!= (-1)) || (yyxi[1]!=yystate) ; yyxi += 2 ) ; /* VOID */

		while( *(yyxi+=2) >= 0 ){
			if( *yyxi == yychar ) break;
			}
		if( (yyn = yyxi[1]) < 0 ) return(0);   /* accept */
		}

	if( yyn == 0 ){ /* error */
		/* error ... attempt to resume parsing */

		switch( yyerrflag ){

		case 0:   /* brand new error */

			yyerror( "syntax error" );
		yyerrlab:
			++yynerrs;

		case 1:
		case 2: /* incompletely recovered error ... try again */

			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */

			while ( yyps >= yys ) {
			   yyn = yypact[*yyps] + YYERRCODE;
			   if( yyn>= 0 && yyn < YYLAST && yychk[yyact[yyn]] == YYERRCODE ){
			      yystate = yyact[yyn];  /* simulate a shift of "error" */
			      goto yystack;
			      }
			   yyn = yypact[*yyps];

			   /* the current yyps has no shift onn "error", pop stack */

#ifdef YYDEBUG
			   if( yydebug ) printf( "error recovery pops state %d, uncovers %d\n", *yyps, yyps[-1] );
#endif
			   --yyps;
			   --yypv;
			   }

			/* there is no state on the stack with an error shift ... abort */

	yyabort:
			return(1);


		case 3:  /* no shift yet; clobber input char */

#ifdef YYDEBUG
			if( yydebug ) printf( "error recovery discards char %d\n", yychar );
#endif

			if( yychar == 0 ) goto yyabort; /* don't discard EOF, quit */
			yychar = -1;
			goto yynewstate;   /* try again in the same state */

			}

		}

	/* reduction by production yyn */

#ifdef YYDEBUG
		if( yydebug ) printf("reduce %d\n",yyn);
#endif
		yyps -= yyr2[yyn];
		yypvt = yypv;
		yypv -= yyr2[yyn];
		yyval = yypv[1];
		yym=yyn;
			/* consult goto table to find next state */
		yyn = yyr1[yyn];
		yyj = yypgo[yyn] + *yyps + 1;
		if( yyj>=YYLAST || yychk[ yystate = yyact[yyj] ] != -yyn ) yystate = yyact[yypgo[yyn]];
		switch(yym){
			 
case 1:
# line 68 "pascal.y"
{
	  yyval.nodeval = yypvt[-0].nodeval;
	} break;
case 2:
# line 72 "pascal.y"
{ push ( makeScope ( 0 )); } break;
case 3:
# line 74 "pascal.y"
{
	     SymbolInfo *info; 

             info = makeSymbolInfo ( "main", 0, PROCEDURE, NULL );
	     tree = makeNode ( PROCNODE, NULL, 0, 0, NODES );
	     addNode ( tree, makeNode ( NAMENODE, info, 0, 0, NAME ));
	     addNode ( tree, yypvt[-1].nodeval );
	   } break;
case 8:
# line 93 "pascal.y"
{
	  yyval.nodeval = makeNode ( BLOCK, NULL, 0, procno, NODES );
	  addNode ( yyval.nodeval, yypvt[-1].nodeval );
	  addNode ( yyval.nodeval, yypvt[-0].nodeval );
	  deleteSymbols ();
	} break;
case 15:
# line 110 "pascal.y"
{
		   yyerrok;
                 } break;
case 19:
# line 118 "pascal.y"
{ 
	       BuildConst ( yypvt[-2].strval, yypvt[-0].nodeval, procno ); 
	     } break;
case 21:
# line 124 "pascal.y"
{
	      yyerrok;
	    } break;
case 22:
# line 129 "pascal.y"
{
	      yyerrok; 
            } break;
case 26:
# line 137 "pascal.y"
{
	  BuildType ( yypvt[-2].strval, yypvt[-0].typeval, procno );
        } break;
case 28:
# line 143 "pascal.y"
{
		  whatsBeingDeclared = VARIABLEDECLARATION;
		} break;
case 29:
# line 147 "pascal.y"
{
		  yyerrok;
                } break;
case 31:
# line 153 "pascal.y"
{
		  yyerrok;
                } break;
case 33:
# line 159 "pascal.y"
{
		      switch ( whatsBeingDeclared )
		      {

			case RECORDDECLARATION : yyval.typeval = buildRecordFields ( yypvt[-2].strval, yypvt[-0].typeval, procno );
						 break;
			case VARIABLEDECLARATION : yyval.typeval = buildDeclaration ( yypvt[-2].strval, procno, yypvt[-0].typeval );
						   break;
			case PROCFUNCDECLARATION : yyval.typeval = buildFormalParameter ( yypvt[-2].strval, yypvt[-0].typeval, byrefFlag );
						   break;
		      }
		    } break;
case 34:
# line 172 "pascal.y"
{
		      switch ( whatsBeingDeclared )
		      {
			case RECORDDECLARATION : yyval.typeval = buildRecordFields ( yypvt[-2].strval, yypvt[-0].typeval, procno );
						 break;
			case VARIABLEDECLARATION : yyval.typeval = buildDeclaration ( yypvt[-2].strval, procno, yypvt[-0].typeval );
						   break;
			case PROCFUNCDECLARATION : yyval.typeval = buildFormalParameter ( yypvt[-2].strval, yypvt[-0].typeval, byrefFlag );
						   break;
		      }
		    } break;
case 35:
# line 184 "pascal.y"
{ yyval.nodeval = makeNode ( FUNCPROC, NULL, 0, 0, NODES ); } break;
case 36:
# line 186 "pascal.y"
{
		addNode ( yypvt[-1].nodeval, yypvt[-0].nodeval );
	      } break;
case 37:
# line 190 "pascal.y"
{
		addNode ( yypvt[-1].nodeval, yypvt[-0].nodeval );
	      } break;
case 38:
# line 195 "pascal.y"
{
	       addNode ( yypvt[-3].nodeval, yypvt[-1].nodeval );
	       yyval.nodeval = yypvt[-3].nodeval;
	       verifyIfFunctionReturnsValue ( yyval.nodeval -> point.nodes [ 0 ] -> point.nameVar );
	     } break;
case 39:
# line 201 "pascal.y"
{
	       yyval.nodeval = NULL;
	     } break;
case 40:
# line 206 "pascal.y"
{ yyval.nodeval = buildProcedureFunction ( yypvt[-3].strval, procno, yypvt[-0].typeval ); } break;
case 41:
# line 209 "pascal.y"
{
		     addNode ( yypvt[-2].nodeval, yypvt[-0].nodeval );
		   } break;
case 42:
# line 213 "pascal.y"
{
		     yyval.nodeval = yypvt[-4].nodeval;
		   } break;
case 43:
# line 217 "pascal.y"
{
		   yyval.nodeval = NULL;
		 } break;
case 44:
# line 222 "pascal.y"
{
		     yyval.nodeval = buildProcedureFunction ( yypvt[-1].strval, procno, ( InfoType * ) VOID );
		   } break;
case 47:
# line 229 "pascal.y"
{
		     byrefFlag = FALSE;
		     whatsBeingDeclared = PROCFUNCDECLARATION;
		   } break;
case 49:
# line 234 "pascal.y"
{
		     byrefFlag = TRUE;
		     whatsBeingDeclared = PROCFUNCDECLARATION;
		   } break;
case 53:
# line 242 "pascal.y"
{
		     byrefFlag = FALSE;
		     whatsBeingDeclared = PROCFUNCDECLARATION;
		   } break;
case 55:
# line 248 "pascal.y"
{
		     byrefFlag = TRUE;
		     whatsBeingDeclared = PROCFUNCDECLARATION;
		   } break;
case 63:
# line 265 "pascal.y"
{
	      InfoType *auxInfo = ( InfoType * ) malloc ( sizeof ( InfoType ));
	      auxInfo -> type = REAL;
	      auxInfo -> more = NULL;
	      yyval.typeval = auxInfo;
	    } break;
case 64:
# line 272 "pascal.y"
{
	      InfoType *auxInfo = ( InfoType * ) malloc ( sizeof ( InfoType ));
	      auxInfo -> type = CHAR;
	      auxInfo -> more = NULL;
	      yyval.typeval = auxInfo;
	    } break;
case 65:
# line 279 "pascal.y"
{
	      InfoType *auxInfo = ( InfoType * ) malloc ( sizeof ( InfoType ));
	      auxInfo -> type = INTEGER;
	      auxInfo -> more = NULL;
	      yyval.typeval = auxInfo;
	    } break;
case 66:
# line 286 "pascal.y"
{
	      InfoType *auxInfo = ( InfoType * ) malloc ( sizeof ( InfoType ));
	      auxInfo -> type = BOOLEAN;
	      auxInfo -> more = NULL;
	      yyval.typeval = auxInfo;
	    } break;
case 67:
# line 293 "pascal.y"
{
	      yyval.typeval = NULL; 
	    } break;
case 68:
# line 298 "pascal.y"
{ yyval.typeval = VerifyType ( yypvt[-0].strval ); } break;
case 69:
# line 300 "pascal.y"
{ yyval.typeval = NULL; } break;
case 70:
# line 302 "pascal.y"
{ yyval.typeval = NULL; } break;
case 71:
# line 305 "pascal.y"
{ yyval.typeval = yypvt[-0].typeval; } break;
case 72:
# line 307 "pascal.y"
{ yyval.typeval = yypvt[-0].typeval; } break;
case 73:
# line 310 "pascal.y"
{ yyval.typeval = yypvt[-0].typeval; } break;
case 74:
# line 312 "pascal.y"
{ yyval.typeval = NULL; } break;
case 75:
# line 315 "pascal.y"
{ yyval.typeval = NULL; } break;
case 76:
# line 317 "pascal.y"
{ yyval.typeval = NULL; } break;
case 77:
# line 319 "pascal.y"
{ yyval.typeval = NULL; } break;
case 78:
# line 321 "pascal.y"
{ yyval.typeval = NULL; } break;
case 79:
# line 323 "pascal.y"
{ yyval.typeval = NULL; } break;
case 80:
# line 325 "pascal.y"
{ yyval.typeval = NULL; } break;
case 81:
# line 327 "pascal.y"
{ yyval.typeval = yypvt[-0].typeval; } break;
case 82:
# line 329 "pascal.y"
{ yyval.typeval = NULL; } break;
case 83:
# line 333 "pascal.y"
{ yyval.typeval = yypvt[-0].typeval; } break;
case 84:
# line 335 "pascal.y"
{ yyval.typeval = yypvt[-0].typeval; } break;
case 97:
# line 358 "pascal.y"
{
		InfoType * aux = ( InfoType * ) malloc ( sizeof ( InfoType ));
		aux -> type = RECORD;
		aux -> more = NULL;
		yyval.typeval = aux;
	      } break;
case 98:
# line 365 "pascal.y"
{
		pushFieldsStack ();
		whatsBeingDeclared = RECORDDECLARATION;
	      } break;
case 99:
# line 370 "pascal.y"
{
		SymbolInfo *auxFields = popFieldsStack ();

		if ( !emptyStack ())
		  whatsBeingDeclared = RECORDDECLARATION;
                else
		  whatsBeingDeclared = VARIABLEDECLARATION;
		yyval.typeval = buildRecord ( auxFields );
	      } break;
case 116:
# line 405 "pascal.y"
{ yyval.nodeval = VariableVerify ( yypvt[-0].strval, NULL, TRUE ); } break;
case 117:
# line 407 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 118:
# line 410 "pascal.y"
{
	       yyval.nodeval = VariableVerify ( yypvt[-1].strval, IdsFieldsList, FALSE );
	       IdsFieldsList = NULL;
	     } break;
case 120:
# line 417 "pascal.y"
{ IdsFieldsList = addId ( IdsFieldsList, yypvt[-0].strval ); } break;
case 123:
# line 421 "pascal.y"
{ IdsFieldsList = addId ( IdsFieldsList, yypvt[-0].strval ); } break;
case 127:
# line 428 "pascal.y"
{
		  changeNodeName ( yypvt[-1].nodeval, COMPOUND );
		  yyval.nodeval = yypvt[-1].nodeval;
		} break;
case 128:
# line 434 "pascal.y"
{ yyval.nodeval = makeNode ( EMPTY, NULL, 0, 0, NODES ); } break;
case 129:
# line 436 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 130:
# line 438 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 131:
# line 441 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 132:
# line 443 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 133:
# line 445 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 134:
# line 447 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 135:
# line 449 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 136:
# line 451 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 137:
# line 453 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 138:
# line 455 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 139:
# line 457 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 140:
# line 459 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 141:
# line 461 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 142:
# line 463 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 143:
# line 466 "pascal.y"
{ yyval.nodeval = AssignmentVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval ); } break;
case 144:
# line 469 "pascal.y"
{ yyval.nodeval = VerifyProcFuncCall ( yypvt[-0].strval, NULL, PROCEDURE ); } break;
case 145:
# line 471 "pascal.y"
{ yyval.nodeval = VerifyProcFuncCall ( yypvt[-3].strval, yypvt[-1].nodeval, PROCEDURE ); } break;
case 146:
# line 474 "pascal.y"
{
		      yyval.nodeval = makeNode ( SEQVAR, NULL, 0, 0, NODES );
		      addNode ( yyval.nodeval, yypvt[-0].nodeval );
                    } break;
case 147:
# line 479 "pascal.y"
{
		      addNode ( yypvt[-2].nodeval, yypvt[-0].nodeval );
		      yyval.nodeval = yypvt[-2].nodeval;
                    } break;
case 148:
# line 485 "pascal.y"
{ yyval.nodeval = buildIfInstruction ( yypvt[-2].nodeval, yypvt[-0].nodeval, NULL ); } break;
case 149:
# line 487 "pascal.y"
{ yyval.nodeval = buildIfInstruction ( yypvt[-4].nodeval, yypvt[-2].nodeval, yypvt[-0].nodeval ); } break;
case 151:
# line 493 "pascal.y"
{ yyval.nodeval = buildWhileInstruction ( yypvt[-2].nodeval, yypvt[-0].nodeval ); } break;
case 157:
# line 506 "pascal.y"
{
	       changeNodeName ( yypvt[-0].nodeval, WRITENODE );
	       yyval.nodeval = yypvt[-0].nodeval;
	       VerifyWriteParameters ( yyval.nodeval );
	     } break;
case 158:
# line 512 "pascal.y"
{
	       changeNodeName ( yypvt[-0].nodeval, WRITENODE );
	       addNode ( yypvt[-0].nodeval, makeNode ( NEWLINE, NULL, 0, 0, NAME ));
	       yyval.nodeval = yypvt[-0].nodeval;
	       VerifyWriteParameters ( yyval.nodeval );
	     } break;
case 159:
# line 520 "pascal.y"
{
	      changeNodeName ( yypvt[-1].nodeval, READNODE );
	      yyval.nodeval = yypvt[-1].nodeval;
	      VerifyReadParameters ( yyval.nodeval );
	    } break;
case 160:
# line 526 "pascal.y"
{
	      changeNodeName ( yypvt[-1].nodeval, READNODE );
	      addNode ( yypvt[-1].nodeval, makeNode ( NEWLINE, NULL, 0, 0, NAME ));
	      yyval.nodeval = yypvt[-1].nodeval;
	      VerifyReadParameters ( yyval.nodeval );
	    } break;
case 161:
# line 533 "pascal.y"
{
	      yyval.nodeval = makeNode ( READNODE, NULL, 0, 0, NODES );
	      addNode ( yyval.nodeval, makeNode ( NEWLINE, NULL, 0, 0, NAME ));
	    } break;
case 162:
# line 539 "pascal.y"
{ yyval.nodeval = yypvt[-1].nodeval; } break;
case 163:
# line 542 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 164:
# line 544 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 165:
# line 547 "pascal.y"
{
		  yyval.nodeval = makeNode ( SEQVAR, NULL, 0, 0, NODES );
		  addNode ( yyval.nodeval, yypvt[-0].nodeval );
                } break;
case 166:
# line 552 "pascal.y"
{
		  addNode ( yypvt[-2].nodeval, yypvt[-0].nodeval );
		  yyval.nodeval = yypvt[-2].nodeval;
                } break;
case 167:
# line 558 "pascal.y"
{
	      yyval.nodeval = makeNode ( PRINTNODE, NULL, 0, 0, NODES );
	      addNode ( yyval.nodeval, yypvt[-0].nodeval );
	    } break;
case 168:
# line 563 "pascal.y"
{
	      yyval.nodeval = makeNode ( PRINTNODE, NULL, 0, 0, NODES );
	      addNode ( yyval.nodeval, yypvt[-2].nodeval );
	      addNode ( yyval.nodeval, makeNode ( STRINGCTRLNODE, NULL, yypvt[-0].intval, 0, NAME ));
            } break;
case 174:
# line 577 "pascal.y"
{ yyval.nodeval = makeNode ( SEQVAR, NULL, 0, 0, NODES );
		  addNode ( yyval.nodeval, yypvt[-0].nodeval );
		} break;
case 175:
# line 581 "pascal.y"
{
		  addNode ( yypvt[-2].nodeval, yypvt[-0].nodeval );
		  yyval.nodeval = yypvt[-2].nodeval;
		} break;
case 176:
# line 587 "pascal.y"
{
		   yyval.nodeval = makeNode ( SEQINST, NULL, 0, 0, NODES );
		   addNode ( yyval.nodeval, yypvt[-0].nodeval );
		 } break;
case 177:
# line 592 "pascal.y"
{
		   yyerrok;
		 } break;
case 178:
# line 596 "pascal.y"
{
		   yyval.nodeval = makeNode ( SEQINST, NULL, 0, 0, NODES );
		   addNode ( yyval.nodeval, yypvt[-0].nodeval );
		 } break;
case 179:
# line 601 "pascal.y"
{
		   addNode ( yypvt[-2].nodeval, yypvt[-0].nodeval );
		   yyval.nodeval = yypvt[-2].nodeval;
		 } break;
case 180:
# line 607 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 181:
# line 609 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, EQUAL ); } break;
case 182:
# line 611 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, DIFERENT ); } break;
case 183:
# line 613 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, SMALLER ); } break;
case 184:
# line 615 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, SMALLEREQUAL ); } break;
case 185:
# line 617 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, GREATEREQUAL ); } break;
case 186:
# line 619 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, GREATER ); } break;
case 187:
# line 621 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 188:
# line 625 "pascal.y"
{ yyval.nodeval  =yypvt[-0].nodeval; } break;
case 189:
# line 628 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 190:
# line 630 "pascal.y"
{ yyval.nodeval = OperationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, ADD ); } break;
case 191:
# line 632 "pascal.y"
{ yyval.nodeval = OperationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, SUB ); } break;
case 192:
# line 634 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, OR ); } break;
case 193:
# line 637 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 194:
# line 639 "pascal.y"
{ yyval.nodeval = OperationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, MUL ); } break;
case 195:
# line 641 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 196:
# line 643 "pascal.y"
{ yyval.nodeval = OperationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, DIV ); } break;
case 197:
# line 645 "pascal.y"
{ yyval.nodeval = OperationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, MOD ); } break;
case 198:
# line 647 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-2].nodeval, yypvt[-0].nodeval, AND ); } break;
case 199:
# line 650 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 200:
# line 652 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 201:
# line 654 "pascal.y"
{
	   yyval.nodeval = makeNode ( NEGATIVENODE, NULL, 0, 0, NODES );
   	   addNode ( yyval.nodeval, yypvt[-0].nodeval ); 
         } break;
case 202:
# line 660 "pascal.y"
{ yyval.nodeval = VariableVerify ( yypvt[-0].strval, NULL, FALSE ); } break;
case 203:
# line 662 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 204:
# line 664 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 205:
# line 666 "pascal.y"
{ yyval.nodeval = CharVerify ( yypvt[-0].strval ); } break;
case 206:
# line 668 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 207:
# line 670 "pascal.y"
{ yyval.nodeval = VerifyProcFuncCall ( yypvt[-3].strval, yypvt[-1].nodeval, FUNCTION ); } break;
case 208:
# line 672 "pascal.y"
{ yyval.nodeval = yypvt[-1].nodeval; } break;
case 209:
# line 674 "pascal.y"
{ yyval.nodeval = RelationVerify ( yypvt[-0].nodeval, NULL, NOT ); } break;
case 210:
# line 676 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 217:
# line 689 "pascal.y"
{ yyval.nodeval = makeNode ( STRINGNODE, ( void * ) yypvt[-0].strval, 0, 0, NAME ); } break;
case 218:
# line 691 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 219:
# line 693 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 220:
# line 695 "pascal.y"
{
	      yyval.nodeval = makeNode ( NEGATIVENODE, NULL, 0, 0, NODES );
	      addNode ( yyval.nodeval, yypvt[-0].nodeval );
            } break;
case 221:
# line 701 "pascal.y"
{ yyval.nodeval = makeNode ( VARNAME, ( void * ) yypvt[-0].strval, 0, procno, NAME ); } break;
case 222:
# line 703 "pascal.y"
{ yyval.nodeval = yypvt[-0].nodeval; } break;
case 223:
# line 707 "pascal.y"
{ yyval.nodeval = NULL; } break;
case 224:
# line 709 "pascal.y"
{ yyval.nodeval = makeNode ( CHARNODE, NULL, yypvt[-0].intval, 0, NAME ); } break;
case 225:
# line 711 "pascal.y"
{ yyval.nodeval = makeNode ( INTEGERNODE, NULL, yypvt[-0].intval, 0, NAME ); } break;
case 226:
# line 713 "pascal.y"
{ yyval.nodeval = makeNode ( BOOLNODE, NULL, TRUE, 0, NAME ); } break;
case 227:
# line 715 "pascal.y"
{ yyval.nodeval = makeNode ( BOOLNODE, NULL, FALSE, 0, NAME ); } break;
		}
		goto yystack;  /* stack new state and value */

	}
