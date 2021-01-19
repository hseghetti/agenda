#ifndef SEMANTICAN_H
#define SEMANTICAN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trees.h"
#include "types.h"
#include "symbTbl.h"

typedef struct
{
  int  type;
  void * more;
} InfoType;

typedef struct _Parameters
{
  char *name;
  InfoType *type;
  unsigned int byref;
  struct _Parameters *next;
} Parameters;

typedef struct _FieldsStack {
        SymbolInfo *fields;
	struct _FieldsStack *next;
} FieldsStack;

void       printTree ( Node *, int );
int        VerifyReadParameters ( Node * );
int        VerifyWriteParameters ( Node * );
void       BuildConst ( char *, Node *, int );
void       BuildType ( char *, InfoType *, int );
InfoType   *VerifyType ( char * );
int         SimpleType ( InfoType * );
Node       *VerifyProcFuncCall ( char *, Node *, int );
void        verifyIfFunctionReturnsValue ( SymbolInfo * );
Node       *buildProcedureFunction ( char *, int, InfoType * );
InfoType   *buildFormalParameter ( char *, InfoType *, unsigned int );
InfoType   *buildDeclaration ( char *name, char proc, InfoType *type );
Node       *VariableVerify ( char *, IdList *, int );
IdList     *transformList ( IdList * );
void       buildFieldsList ( IdList *, SymbolInfo * );
Node       *AssignmentVerify ( Node *, Node * );
Node       *IdentifierVerify ( char *name, int procno );
Node       *IntegerVerify ( int number );
Node       *CharVerify ( char *charValue );
Node       *RelationVerify ( Node *left, Node *right, int relation );
Node       *OperationVerify ( Node *left, Node *right, int operation );
Node       *buildIfInstruction ( Node *expression, Node *thenInst, Node *elseInst );
Node       *buildWhileInstruction ( Node *expression, Node *body );
int        emptyStack ();
void       pushFieldsStack ();
SymbolInfo *popFieldsStack ();
InfoType   *buildRecord ( SymbolInfo *fieldsList );
int        existsField ( char *id );
InfoType   *buildRecordFields ( char *field, InfoType *type, int proc ); 
InfoType   *getExpressionType ( Node *expression );
int        CompatibleTypes ( InfoType *, InfoType * );
IdList     *addId ( IdList *list, char *id );
void       freeIdList ( IdList **list );

#endif
