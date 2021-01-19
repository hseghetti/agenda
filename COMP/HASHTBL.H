#ifndef HASHTBL_H
#define HASHTBL_H
#define NULL    0
#define EOS     '\0'
#define TBLSIZE 211

#include "symbol.h"
#include <string.h>
#include <malloc.h>


typedef struct _Bucket {
        struct _Bucket *prev;
        struct _Bucket *next;
        char           *name;
        void           *info;
} Bucket;


void *insert( char *, void * );
void *lookup( char * );
void *delete( char * );
void  freeUnusedBucketList( void );


#endif
