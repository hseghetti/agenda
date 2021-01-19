#ifndef SYMBOL_H
#define SYMBOL_H
#include <malloc.h>


#define CHAR            1
#define INTEGER         2
#define REAL            3
#define BOOLEAN         4
#define RECORD          5
#define TYPEDEF         6
#define TYPE            7
#define PROCEDURE       8
#define FUNCTION        9
#define VOID            10
#define ARRAY           11
#define CONST           12

#define CHARSIZE	1
#define INTEGERSIZE	2
#define BOOLEANSIZE	1
#define ADDRESSSIZE	2

#define NULL 0

#define FALSE 0
#define TRUE  255

int updateOffset( int, int );


typedef struct _Line {
	int   line;
	struct _Line *next;
} Line;


typedef struct _SymbolInfo {
        char *name;
        int   proc;
	int   type;
	int   depth;
	char  param;
	char  byref;
        int   offs;
	Line *used;
        void *more;
        struct _SymbolInfo *next;
} SymbolInfo;


SymbolInfo *makeSymbolInfo( char *, int, char, void * );
void freeSymbolInfo( SymbolInfo * );
char *getSymbolName( SymbolInfo * );
int   getSymbolProc( SymbolInfo * );
char  getSymbolType( SymbolInfo * );
int   getSymbolDepth( SymbolInfo * );
void  setSymbolDepth( SymbolInfo *, int );
char  getSymbolParam( SymbolInfo * );
void  setSymbolParam( SymbolInfo *, char );
char  getSymbolByref( SymbolInfo * );
void  setSymbolByref( SymbolInfo *, char );
int   getSymbolOffs( SymbolInfo * );
void  setSymbolOffs( SymbolInfo *, int );
void  setSymbolUsed( SymbolInfo *, int );
void *getSymbolMore( SymbolInfo * );
SymbolInfo *setSymbolNext( SymbolInfo *, SymbolInfo * );
SymbolInfo *getSymbolNext( SymbolInfo * );


typedef struct _ConstInfo {
	int type;
        int value;
} ConstInfo;


ConstInfo *makeConstInfo( char, int );
void freeConstInfo( ConstInfo * );
char getConstType( ConstInfo * );
int  getConstValue( ConstInfo * );


typedef struct _RecordInfo {
        SymbolInfo  *fields;
        unsigned int size;
} RecordInfo;


RecordInfo *makeRecordInfo( SymbolInfo * );
void freeRecordInfo( RecordInfo * );
SymbolInfo *getRecordFields( RecordInfo * );
unsigned int getRecordSize( RecordInfo * );


unsigned int getTypeSize( SymbolInfo * );


typedef struct _ParameterInfo {
        SymbolInfo  *param;     /* Ponteiro para a entrada correspondente
                                   ao parametro na tabela de simbolos.     */
        unsigned int byref : 1; /* Flag indicando passagem por referencia. */
} ParameterInfo;


ParameterInfo *makeParameterInfo( SymbolInfo *, unsigned int );
void freeParameterInfo( ParameterInfo * );
SymbolInfo *getParameterParam( ParameterInfo * );
unsigned int getParameterByref( ParameterInfo * );


typedef struct _SubprogramInfo {
        ParameterInfo *args; /* Array contendo a informacao sobre
                                os varios argumentos do subprograma. */
        char narg; /* Numero de argumentos. */
        char type; /* Tipo do valor retornado (VOID se procedimento). */
	char rets;
} SubprogramInfo;


SubprogramInfo *makeSubprogramInfo( ParameterInfo *, char, char );
void freeSubprogramInfo( SubprogramInfo * );
ParameterInfo *getSubprogramArgs( SubprogramInfo * );
char getSubprogramNarg( SubprogramInfo * );
char getSubprogramType( SubprogramInfo * );
char getSubprogramRets( SubprogramInfo * );
void setSubprogramRets( SubprogramInfo *, char );


#endif
