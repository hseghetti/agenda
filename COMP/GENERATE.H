#ifndef _GENERATE
#define _GENERATE

#include <stdio.h>
#include "optimize.h"
#include "types.h"
#include "trees.h"
#include "register.h"
#include "symbTbl.h"
#include "semantic.h"

#define NOFLAG    0
#define IFFLAG    1
#define WHILEFLAG 2

void  generateAssemblyCode ( Node *, char * );
void  generateAssemblyForPrint ( Node * );
void  generateAssemblyDisplay ();
void  generateAssembly ( Node * );
int   getLocalDataSizeAndCalcOffsets ( int );
void  generateAssemblyForProcnodeFuncnode ( Node * );
void  generateAssemblyForProccallFunccall ( Node * );
void  generateRecordCopy ( SymbolInfo *, char * );
void  generateAssemblyForIf ( Node * );
void  generateAssemblyForWhile ( Node * );
void  generateAssemblyForAssignment ( Node * );
char  *generateAssemblyForVariable ( SymbolInfo * );
char  *generateAssemblyForVarByref ( SymbolInfo * );
char  *generateAssemblyForExpression ( Node *, int );
void  generateAssemblyForSubexpression ( Node *, int );
void  generateAssemblyStack ( void );

#endif
