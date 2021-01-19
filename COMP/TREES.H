#ifndef TREES_H
#define TREES_H

#include <malloc.h>
#include <string.h>
#include "types.h"

typedef struct _Node
{
  int name;
  union
  {
    struct _Node **nodes;
    void *nameVar;
    IdList *fields;
  } point;
  int  nNodes;
  int  procno;
} Node;

typedef struct _NodeList {
        Node *node;
	struct _NodeList *next;
} NodeList;

Node     *makeNode ( int, void *, int, int, int );
void      changeNodeName ( Node *, int );
void      addNode ( Node *, void * );
int       variableNode ( Node * );
Node     *getTopNode ( NodeList *list );
NodeList *addNodeToList ( NodeList *list, Node *node );
NodeList *addNodeToStack ( NodeList *list, Node *node );
NodeList *removeNode ( NodeList *list );

#endif
