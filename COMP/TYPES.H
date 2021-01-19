#ifndef TYPES_H
#define TYPES_H

#define BLOCK           0
#define	VARNAME         1
#define	ASSIGNMENT      2
#define	INTEGERNODE     3
#define CHARNODE        4
#define BOOLNODE        5
#define RELATION        6
#define OPERATION       7
#define EMPTY           8
#define FUNCPROC        9
#define PROCNODE       10
#define STRINGNODE     11
#define PROCCALL       12
#define NEGATIVENODE   13
#define IFNODE         14
#define COMPOUND       15
#define THENNODE       16
#define ELSENODE       17
#define WHILENODE      18
#define CONSTNODE      19
#define FUNCNODE       20
#define TYPEDEFNODE    21
#define SEQVAR         22
#define READNODE       23
#define NEWLINE        24
#define STRINGCTRLNODE 25
#define PRINTNODE      26
#define WRITENODE      27
#define FUNCCALL       28
#define RETURNVALUE    29
#define NAMENODE       30
#define SEQINST        31
#define FIELDS         32

#define EQUAL        1
#define DIFERENT     2
#define SMALLER      3
#define GREATER      4
#define SMALLEREQUAL 5
#define GREATEREQUAL 6
#define AND          7
#define OR           8
#define NOT          9

#define NODES 0
#define NAME 1
#define FIELD 2

#define TRUE 255 
#define FALSE 0

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define MOD 5

#define VARIABLEDECLARATION 0
#define RECORDDECLARATION   1
#define PROCFUNCDECLARATION 2

extern int procno;
extern int programWithErrors;
extern int lineno;

typedef struct _IdList {
        char *identifier;
	struct _IdList *next;
} IdList;

#endif
