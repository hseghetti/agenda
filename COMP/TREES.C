#include "trees.h"

Node* makeNode ( int name, void *nodes, int nNodes, int procno, int type )
{
  Node *aux;

  aux = ( Node* ) malloc ( sizeof ( Node ));
  aux -> name = name;
  switch ( type )
  {
    case NODES : aux -> point.nodes = nodes;
	         break;
    case NAME : aux -> point.nameVar = nodes;
		break;
    case FIELD : aux -> point.fields = nodes;
		 break;
  }
  aux -> nNodes = nNodes;
  aux -> procno = procno;
  return aux;
}

void changeNodeName ( Node *node, int name )
{
  node -> name = name;
}

void addNode ( Node *Node1, void *Node2 )
{
  if ( Node1 -> point.nodes == NULL )
    Node1 -> point.nodes = ( Node ** ) malloc ( sizeof ( Node * ));
  else
    Node1 -> point.nodes = ( Node ** ) realloc ( Node1 -> point.nodes, sizeof ( Node * ) * ( Node1 -> nNodes + 1 ));
  ( Node1 -> point.nodes ) [ Node1 -> nNodes ] = Node2;
  Node1 -> nNodes++;
}

int variableNode ( Node *node )
{
  if (( node -> name == VARNAME ) || ( node -> name == FIELDS ))
    return TRUE;
  else
    return FALSE;
}

Node *getTopNode ( NodeList *list )
{
  if ( list != NULL )
    return list -> node;
  else
    return NULL;
}

NodeList *addNodeToStack ( NodeList *list, Node *node )
{
  if ( list == NULL )
  {
    list = ( NodeList * ) malloc ( sizeof ( NodeList ));

    list -> node = node;
    list -> next = NULL;
  }
  else
  {
    NodeList *aux = ( NodeList * ) malloc ( sizeof ( NodeList ));

    aux -> node = node;
    aux -> next = list;
    list = aux;
  };
  return list;
}

NodeList *addNodeToList ( NodeList *list, Node *node )
{
  NodeList *aux, *first = list;

  aux = ( NodeList * ) malloc ( sizeof ( NodeList ));
  aux -> node = node;
  aux -> next = NULL;
  if ( list == NULL )
    return aux;
  else
  {
    while ( list -> next != NULL )
      list = list -> next;
    list -> next = aux;
    return first;
  }
}


NodeList *removeNode ( NodeList *list )
{
  if ( list != NULL )
  {
    NodeList *aux;

    aux = list;
    list = list -> next;
    free ( aux );
  }
  return list;
}

