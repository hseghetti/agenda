#include "hashTbl.h"


static Bucket *unusedBucketList = NULL;
/* static */ Bucket *hashTable[ TBLSIZE ];


/*
 * hash
 *
 *  Action : Calcula o indice ( do vector que suporta a tabela de hashing )
 *           correspondente a chave fornecida pela string.
 *  In: s = string contendo a chave.
 *  Returns: Inteiro contendo o valor do indice do vector.
 */
static int hash( char *s )
{
  char *p;
  unsigned h = 0,
           g;

  for ( p = s; *p != EOS; p++ ) {
    h = ( h << 4 ) + ( *p );
    if ( g = h & 0xf0000000 ) {
      h = h ^ ( g >> 24 );
      h = h ^ g;
    }
  }
  return h % TBLSIZE;
}


/*
 * insert
 *
 *  Action : Insere um novo contentor na tabela de hashing.
 *           O contentor e inserido mesmo que ja exista outro com a mesma chave.
 *  In: name = string contendo a chave do novo contentor.
 *      info = Ponteiro para uma estrutura contendo a informacao a inserir.
 *             Esta estrutura pode ser de qualquer tipo.
 *  Returns: Ponteiro para a estrutura contendo a informacao caso esta tenha
 *           sido inserida com sucesso na tabela. NULL caso contrario.
 */
void *insert( char *name, void *info )
{
  int     idx = hash( name );
  Bucket *aux = hashTable[ idx ];
  Bucket *new;

  if ( unusedBucketList ) {
    new = unusedBucketList;
    unusedBucketList = new->next;
  }
  else
    if (( new = ( Bucket * ) malloc( sizeof( Bucket ))) == NULL )
      return NULL;
  new->prev = NULL;
  new->next = NULL;
  new->name = ( char * ) malloc( strlen( name ) + 1 );
  strcpy( new->name, name );
  new->info = info;
  if ( aux != NULL ) {
    aux->prev = new;
    new->next = aux;
  }
  hashTable[ idx ] = new;
  return info;
}


/*
 * lookup
 *
 *  Action : Procura um contentor na tabela de hashing 
 *           cuja chave corresponde a string fornecida.
 *  In: name = string contendo a chave do contentor a procurar.
 *  Returns: Ponteiro para a estrutura ( a primeira cuja chave corresponde ao
 *           parametro ) contendo a informacao caso esta tenha sido encontrada
 *	     na tabela. NULL se nao conseguiu encontrar o contentor.
 */
void *lookup( char *name )
{
  Bucket *aux;

  for ( aux = hashTable[ hash( name ) ]; aux != NULL; aux = aux->next )
    if ( strcmp( name, aux->name ) == 0 )
      return aux->info;
  return NULL;
}


/*
 * delete
 *
 *  Action : Retira um contentor da tabela de hashing.
 *           O contentor a retirar tem que existir.
 *	     O contentor retirado e colocado na lista de contentores nao 
 *	     utilizados de modo a que da proxima vez que seja necessario um 
 *	     contentor para guardar informacao nao seja preciso alocar nova
 *           memoria.
 *  In: name = string contendo a chave do contentor a retirar.
 *  Returns: Ponteiro para a estrutura ( a primeira cujo contentor tem a
 *	     chave correspondente ao parametro ) contendo a informacao.
 */
void *delete( char *name )
{
  int     idx;
  void   *ret;
  Bucket *aux;

  for ( aux = hashTable[ idx = hash( name ) ];
        strcmp( name, aux->name ) != 0;
        aux = aux->next )
    ;
  ret = aux->info;
  if ( aux->next != NULL )
    aux->next->prev = aux->prev;
  if ( aux->prev == NULL )
    hashTable[ idx ] = aux->next;
  else
    aux->prev->next = aux->next;
  aux->prev = NULL;
  free( aux->name );
  aux->name = NULL;
  aux->info = NULL;
  aux->next = unusedBucketList;
  unusedBucketList = aux;
  return ret;
}


/*
 * freeUnusedBucketList
 *
 *  Action : Liberta a lista de contentores que foi criada ao longo da
 *           manipulacao da tabela de hashing. Devera ser usada quando
 *	     nao for mais necessaria a utilizacao da tabela de hashing.
 *  In: 
 *  Returns: 
 */
void freeUnusedBucketList( void )
{
  Bucket *aux;

  for ( aux = unusedBucketList; aux != NULL; aux = unusedBucketList ) {
    unusedBucketList = aux->next;
    free( aux );
  }
}
