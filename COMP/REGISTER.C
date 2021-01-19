#include "register.h"

RegisterInfo registers [ 4 ] = {{{ NULL, NULL, NULL }, { 0, 0, 0 }},
				{{ NULL, NULL, NULL }, { 0, 0, 0 }},
				{{ NULL, NULL, NULL }, { 0, 0, 0 }},
				{{ NULL, NULL, NULL }, { 0, 0, 0 }}};

static int clock = 0;

char *inRegister ( SymbolInfo *variable )
{
  int i, registerIdType;

  switch ( getTypeSize ( variable ))
  {
    case BOOLEANSIZE : registerIdType = BITS8; /* Tambem serve para os chars por que tem o mesmo tamanho do boolean */
		       break;
    case INTEGERSIZE : registerIdType = BITS16;
		       break;
  }
  for ( i = 0; i < NUMREGISTERS; i++ )
  { 
    if ( registerIdType = BITS16 )
    {
      if ( variable == registers [ i ].parts [ FULL ] )
	return giveRegisterName ( i * NUMPARTS + FULL );
    }
    else
    {
      if ( variable == registers [ i ].parts [ LOW ] )
	return giveRegisterName ( i * NUMPARTS + LOW );
      else
        if ( variable == registers [ i ].parts [ HIGH ] )
  	  return giveRegisterName ( i * NUMPARTS + HIGH );
    }
  }
  return NULL; 
}

int giveRegisterCode ( char *reg )
{
  if ( !strcmp ( reg, "AX" ))
    return AX;
  else if ( !strcmp ( reg, "AH" ))
    return AH;
  else if ( !strcmp ( reg, "AL" ))
    return AL;
  else if ( !strcmp ( reg, "BX" ))
    return BX;
  else if ( !strcmp ( reg, "BH" ))
    return BH;
  else if ( !strcmp ( reg, "BL" ))
    return BL;
  else if ( !strcmp ( reg, "CX" ))
    return CX;
  else if ( !strcmp ( reg, "CH" ))
    return CH;
  else if ( !strcmp ( reg, "CL" ))
    return CL;
  else if ( !strcmp ( reg, "DX" ))
    return DX;
  else if ( !strcmp ( reg, "DH" ))
    return DH;
  else if ( !strcmp ( reg, "DL" ))
    return DL;
}

void cleanRegister ( char *reg )
{
  int registerId = giveRegisterCode ( reg );
  int seg = registerId / NUMPARTS;
  int off = registerId % NUMPARTS;

  registers [ seg ].parts [ off ] = NULL;
  registers [ seg ].lastUsed [ off ] = 0;
}

void cleanRegisters ( void )
{
  int i;

  for ( i = 0; i < NUMREGISTERS * NUMPARTS; i++ )
    cleanRegister ( giveRegisterName ( i ));
}

int findRegister ( SymbolInfo *variable, int registerId, char *reg )
{
  int registerIdType, i, lastUsed, seg, off, aux;

  ++clock;
  if ( variable == NULL )
  {
    if ( registerId % NUMPARTS == 0 )
      registerIdType = BITS16;
    else
      registerIdType = BITS8;
  }
  else
  {
    switch ( getTypeSize ( variable ))
    {
      case BOOLEANSIZE : registerIdType = BITS8; /* Tambem serve para os chars por que tem o mesmo tamanho do boolean */
			 break;
      case INTEGERSIZE : registerIdType = BITS16;
			 break;
    }
  }
  if ( registerId != ANYTHING )
  {
    seg = registerId / NUMPARTS;
    off = registerId % NUMPARTS;

    registers [ seg ].parts [ off ] = variable;
    registers [ seg ].lastUsed [ off ] = clock;
    strcpy ( reg, giveRegisterName ( registerId ));
    return TRUE;
  }
  seg = 0;
  off = 0;
  lastUsed = clock;
  for ( i = 0; i < NUMREGISTERS; i++ )
  {
    if ( registerIdType == BITS16 )
    {
      if (( registers [ i ].parts [ FULL ] == variable ) &&
	  ( registers [ i ].parts [ FULL ] != NULL ))
      {
	registers [ i ].lastUsed [ FULL ] = clock;
	strcpy ( reg, giveRegisterName ( i * ( NUMREGISTERS - 1 ) + FULL ));
	return FALSE;
      }
      if (( registers [ i ].lastUsed [ FULL ] == 0 ) &&
	  ( registers [ i ].lastUsed [ LOW ] == 0 ) &&
	  ( registers [ i ].lastUsed [ HIGH ] == 0 ))
      {
	seg = i;
	break;
      }
    }
    else
    {
      if ( registers [ i ].parts [ LOW ] == variable )
      {
	registers [ i ].lastUsed [ LOW ] = clock;
	strcpy ( reg, giveRegisterName ( i * ( NUMREGISTERS - 1 ) + LOW ));
	return FALSE;
      }
      if ( registers [ i ].parts [ HIGH ] == variable )
      {
	registers [ i ].lastUsed [ HIGH ] = clock;
	strcpy ( reg, giveRegisterName ( i * ( NUMREGISTERS - 1 ) + HIGH ));
	return FALSE;
      }
      if ((( registers [ i ].lastUsed [ LOW ] == 0 ) ||
	   ( registers [ i ].lastUsed [ HIGH ] == 0 )) &&
	  ( registers [ i ].lastUsed [ FULL ] == 0 ))
      {
	seg = i;
	break;
      }
    }
    if ( lastUsed >= ( aux = giveAgeOfYounger ( registers [ i ].lastUsed )))
    {
      seg = i;
      lastUsed = aux;
    }
  }
  if ( registerIdType == BITS16 )
  {
    off = FULL;
    registers [ seg ].lastUsed [ LOW ] = 0;
    registers [ seg ].parts [ LOW ] = NULL;
    registers [ seg ].lastUsed [ HIGH ] = 0;
    registers [ seg ].parts [ HIGH ] = NULL;
  }
  else
  {
    if ( registers [ seg ].lastUsed [ LOW ] > registers [ seg ].lastUsed [ HIGH ] )
      off = HIGH;
    else
      off = LOW;
    registers [ seg ].lastUsed [ FULL ] = 0;
    registers [ seg ].parts [ FULL ] = NULL;
  }
  registers [ seg ].lastUsed [ off ] = clock;
  registers [ seg ].parts [ off ] = variable;
  strcpy ( reg, giveRegisterName ( seg * ( NUMREGISTERS - 1 ) + off ));
  return TRUE;
}

int giveAgeOfYounger ( int *ages )
{
  int younger = ages [ 0 ];

  if ( ages [ 1 ] >= younger )
    younger = ages [ 1 ];
  if ( ages [ 2 ] >= younger )
    younger = ages [ 2 ];
  return younger;
}

char *giveRegisterName ( int registerId )
{
  switch ( registerId )
  {
    case AX : return "AX";
	      break;
    case AH : return "AH";
	      break;
    case AL : return "AL";
	      break;
    case BX : return "BX";
	      break;
    case BH : return "BH";
	      break;
    case BL : return "BL";
	      break;
    case CX : return "CX";
	      break;
    case CH : return "CH";
	      break;
    case CL : return "CL";
	      break;
    case DX : return "DX";
	      break;
    case DH : return "DH";
	      break;
    case DL : return "DL";
	      break;
  }
}
