	ifndef	??version
?debug	macro
	endm
publicdll macro	name
	public	name
	endm
	endif
	?debug	V 300h
	?debug	S "GENERATE.C"
	?debug	C E9288284190A47454E45524154452E43
	?debug	C E9331084190A47454E45524154452E48
	?debug	C E94019CA181B433A5C424F524C414E44435C494E434C5544455C53+
	?debug	C 5444494F2E48
	?debug	C E94019CA181B433A5C424F524C414E44435C494E434C5544455C5F+
	?debug	C 444546532E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C5F+
	?debug	C 4E46494C452E48
	?debug	C E94019CA181B433A5C424F524C414E44435C494E434C5544455C5F+
	?debug	C 4E554C4C2E48
	?debug	C E9ADA882190A4F5054494D495A452E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C4D+
	?debug	C 414C4C4F432E48
	?debug	C E94019CA181B433A5C424F524C414E44435C494E434C5544455C41+
	?debug	C 4C4C4F432E48
	?debug	C E9DBA882190754595045532E48
	?debug	C E9E61A84190A53454D414E5449432E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C53+
	?debug	C 54444C49422E48
	?debug	C E94019CA181B433A5C424F524C414E44435C494E434C5544455C53+
	?debug	C 5444494F2E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C53+
	?debug	C 5452494E472E48
	?debug	C E9D9A882190754524545532E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C4D+
	?debug	C 414C4C4F432E48
	?debug	C E94019CA181B433A5C424F524C414E44435C494E434C5544455C41+
	?debug	C 4C4C4F432E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C53+
	?debug	C 5452494E472E48
	?debug	C E9DBA882190754595045532E48
	?debug	C E9DBA882190754595045532E48
	?debug	C E9D3A882190953594D4254424C2E48
	?debug	C E9A8A88219094841534854424C2E48
	?debug	C E9CEA882190853594D424F4C2E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C4D+
	?debug	C 414C4C4F432E48
	?debug	C E94019CA181B433A5C424F524C414E44435C494E434C5544455C41+
	?debug	C 4C4C4F432E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C53+
	?debug	C 5452494E472E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C4D+
	?debug	C 414C4C4F432E48
	?debug	C E94019CA181B433A5C424F524C414E44435C494E434C5544455C41+
	?debug	C 4C4C4F432E48
	?debug	C E9CEA882190853594D424F4C2E48
	?debug	C E9C1A882190753434F50452E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C53+
	?debug	C 54444C49422E48
	?debug	C E9CEA882190853594D424F4C2E48
	?debug	C E9D9A882190754524545532E48
	?debug	C E9DBA882190754595045532E48
	?debug	C E9D9A882190754524545532E48
	?debug	C E9BAA882190A52454749535445522E48
	?debug	C E9CEA882190853594D424F4C2E48
	?debug	C E94019CA181C433A5C424F524C414E44435C494E434C5544455C53+
	?debug	C 5452494E472E48
	?debug	C E9D3A882190953594D4254424C2E48
	?debug	C E9E61A84190A53454D414E5449432E48
_TEXT	segment byte public 'CODE'
_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
_DATA	segment word public 'DATA'
_label	label	word
	db	0
	db	0
_DATA	ends
_TEXT	segment byte public 'CODE'
   ;	
   ;	void generateAssemblyCode ( Node *tree, char *outputFilename )
   ;	
	assume	cs:_TEXT
_generateAssemblyCode	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
   ;	
   ;	{
   ;	  char reg [ 3 ];
   ;	
   ;	  output = fopen ( outputFilename, "w" );  
   ;	
	mov	ax,offset DGROUP:s@
	push	ax
	push	word ptr [bp+6]
	call	near ptr _fopen
	pop	cx
	pop	cx
	mov	word ptr DGROUP:output,ax
   ;	
   ;	
   ;	  generateAssemblyStack();
   ;	
	call	near ptr _generateAssemblyStack
   ;	
   ;	  generateAssemblyDisplay();
   ;	
	call	near ptr _generateAssemblyDisplay
   ;	
   ;	  fprintf ( output, "code\tSEGMENT word public 'code'\n" ); 
   ;	
	mov	ax,offset DGROUP:s@+2
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tASSUME\tCS:code,DS:data,SS:activations\n\n" );
   ;	
	mov	ax,offset DGROUP:s@+35
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "START:\tMOV\tAX,activations\n" );
   ;	
	mov	ax,offset DGROUP:s@+76
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\tSS,AX\n" );
   ;	
	mov	ax,offset DGROUP:s@+103
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\tAX,access\n" );
   ;	
	mov	ax,offset DGROUP:s@+115
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\tDS,AX\n" );
   ;	
	mov	ax,offset DGROUP:s@+131
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tLEA\tSP,TOP\n" );
   ;	
	mov	ax,offset DGROUP:s@+143
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tCALL\tmain\n\n" );
   ;	
	mov	ax,offset DGROUP:s@+156
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	
   ;	  /* Copia de zonas de memoria. */
   ;	  findRegister( NULL, AL, reg );
   ;	
	lea	ax,word ptr [bp-4]
	push	ax
	mov	ax,2
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	  fprintf ( output, "\nMOVE\tPROC\tNEAR\n" );
   ;	
	mov	ax,offset DGROUP:s@+169
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "MOVING:\n\tMOV\tAL,[SI]\n" );
   ;	
	mov	ax,offset DGROUP:s@+186
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\t[DI],AL\n" );
   ;	
	mov	ax,offset DGROUP:s@+208
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tINC\tSI\n" );
   ;	
	mov	ax,offset DGROUP:s@+222
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tINC\tDI\n" );
   ;	
	mov	ax,offset DGROUP:s@+231
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tLOOP\tMOVING\n" );
   ;	
	mov	ax,offset DGROUP:s@+240
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tENDP\tMOVE\n\n" );
   ;	
	mov	ax,offset DGROUP:s@+254
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	
   ;	  generateAssembly( tree );
   ;	
	push	word ptr [bp+4]
	call	near ptr _generateAssembly
	pop	cx
   ;	
   ;	  fprintf ( output, "code\tENDS\n\n" );
   ;	
	mov	ax,offset DGROUP:s@+267
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\textrn\twriteInteger:near\n" );
   ;	
	mov	ax,offset DGROUP:s@+279
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\textrn\twriteBoolean:near\n" );
   ;	
	mov	ax,offset DGROUP:s@+305
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\textrn\twriteChar:near\n" );
   ;	
	mov	ax,offset DGROUP:s@+331
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\textrn\twriteString:near\n" );
   ;	
	mov	ax,offset DGROUP:s@+354
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\textrn\twriteNewline:near\n" );
   ;	
	mov	ax,offset DGROUP:s@+379
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\textrn\treadChar:near\n" );
   ;	
	mov	ax,offset DGROUP:s@+405
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\textrn\treadBoolean:near\n" );
   ;	
	mov	ax,offset DGROUP:s@+427
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\textrn\treadInteger:near\n" );
   ;	
	mov	ax,offset DGROUP:s@+452
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tEND\tSTART\n\n" );
   ;	
	mov	ax,offset DGROUP:s@+477
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  close ( output );
   ;	
	push	word ptr DGROUP:output
	call	near ptr _close
	pop	cx
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyCode	endp
   ;	
   ;	void generateAssemblyStack ( void )
   ;	
	assume	cs:_TEXT
_generateAssemblyStack	proc	near
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	  fprintf ( output, "activations\tSEGMENT STACK 'STACK'\n" );
   ;	
	mov	ax,offset DGROUP:s@+490
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tDB\t1024\tDUP(?)\n" );
   ;	
	mov	ax,offset DGROUP:s@+525
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "TOP\tLABEL\tWORD\n" );
   ;	
	mov	ax,offset DGROUP:s@+542
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "activations\tENDS\n\n" );
   ;	
	mov	ax,offset DGROUP:s@+558
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_generateAssemblyStack	endp
   ;	
   ;	void generateAssemblyDisplay ( void )
   ;	
	assume	cs:_TEXT
_generateAssemblyDisplay	proc	near
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	  fprintf ( output, "data\tSEGMENT word public 'data'\n" ); 
   ;	
	mov	ax,offset DGROUP:s@+577
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "access\tDW\t%i\tDUP(?)\n", maxDepth + 1 );
   ;	
	mov	ax,word ptr DGROUP:_maxDepth
	inc	ax
	push	ax
	mov	ax,offset DGROUP:s@+610
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  fprintf ( output, "data\tENDS\n\n" );
   ;	
	mov	ax,offset DGROUP:s@+631
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_generateAssemblyDisplay	endp
   ;	
   ;	void generateAssembly( Node *node )
   ;	
	assume	cs:_TEXT
_generateAssembly	proc	near
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	si,word ptr [bp+4]
   ;	
   ;	{
   ;	  switch ( node->name )
   ;	
	mov	bx,word ptr [si]
	sub	bx,2
	cmp	bx,25
	ja	short @4@478
	shl	bx,1
	jmp	word ptr cs:@4@C594[bx]
@4@114:
   ;	
   ;	  {
   ;	    case PROCNODE:
   ;	    case FUNCNODE:
   ;	      generateAssemblyForProcnodeFuncnode( node );
   ;	
	push	si
	call	near ptr _generateAssemblyForProcnodeFuncn
@4@142:
	pop	cx
   ;	
   ;	      break;
   ;	
	jmp	short @4@478
@4@170:
   ;	
   ;	    case WRITENODE:
   ;	    case COMPOUND:
   ;	      {  
   ;		int counter;
   ;	
   ;		for ( counter = 0; counter < node->nNodes; counter++ )
   ;	
	xor	di,di
	jmp	short @4@254
@4@198:
   ;	
   ;		  generateAssembly( node->point.nodes[ counter ] );
   ;	
	mov	ax,di
	shl	ax,1
	mov	bx,word ptr [si+2]
	add	bx,ax
	push	word ptr [bx]
	call	near ptr _generateAssembly
	pop	cx
	inc	di
@4@254:
	cmp	word ptr [si+4],di
	jg	short @4@198
   ;	
   ;	      }
   ;	      break;
   ;	
	jmp	short @4@478
@4@310:
   ;	
   ;	    case PROCCALL:
   ;	      generateAssemblyForProccallFunccall( node );
   ;	
	push	si
	call	near ptr _generateAssemblyForProccallFuncc
	jmp	short @4@142
@4@338:
   ;	
   ;	      break;
   ;	    case ASSIGNMENT :
   ;	      generateAssemblyForAssignment ( node );
   ;	
	push	si
	call	near ptr _generateAssemblyForAssignment
	jmp	short @4@142
@4@366:
   ;	
   ;	      break;
   ;	    case IFNODE :
   ;	      generateAssemblyForIf ( node );
   ;	
	push	si
	call	near ptr _generateAssemblyForIf
	jmp	short @4@142
@4@394:
   ;	
   ;	      break;
   ;	    case WHILENODE :
   ;	      generateAssemblyForWhile ( node );
   ;	
	push	si
	call	near ptr _generateAssemblyForWhile
	jmp	short @4@142
@4@422:
   ;	
   ;	      break;
   ;	    case PRINTNODE :
   ;	      generateAssemblyForPrint ( node );
   ;	
	push	si
	call	near ptr _generateAssemblyForPrint
	jmp	short @4@142
@4@450:
   ;	
   ;	      break;
   ;	    case EMPTY:
   ;	      break;
   ;	
	jmp	short @4@478
@4@478:
   ;	
   ;	  }
   ;	}
   ;	
	pop	di
	pop	si
	pop	bp
	ret	
_generateAssembly	endp
@4@C594	label	word
	dw	@4@338
	dw	@4@478
	dw	@4@478
	dw	@4@478
	dw	@4@478
	dw	@4@478
	dw	@4@450
	dw	@4@478
	dw	@4@114
	dw	@4@478
	dw	@4@310
	dw	@4@478
	dw	@4@366
	dw	@4@170
	dw	@4@478
	dw	@4@478
	dw	@4@394
	dw	@4@478
	dw	@4@114
	dw	@4@478
	dw	@4@478
	dw	@4@478
	dw	@4@478
	dw	@4@478
	dw	@4@422
	dw	@4@170
   ;	
   ;	void generateAssemblyForPrint ( Node *node )
   ;	
	assume	cs:_TEXT
_generateAssemblyForPrint	proc	near
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	si,word ptr [bp+4]
   ;	
   ;	{
   ;	  char *reg;
   ;	
   ;	  switch ( node -> point.nodes [ 0 ] -> name )
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	mov	ax,word ptr [bx]
	cmp	ax,1
	je	short @5@114
	jmp	@5@338
@5@114:
   ;	
   ;	  {
   ;	    case VARNAME : reg = generateAssemblyForVariable ( node -> point.nodes [ 0 ] );
   ;	
	mov	bx,word ptr [si+2]
	push	word ptr [bx]
	call	near ptr _generateAssemblyForVariable
	pop	cx
	mov	di,ax
   ;	
   ;			   if ( node -> nNodes > 1 )
   ;	
	cmp	word ptr [si+4],1
	jle	short @5@170
   ;	
   ;			     fprintf ( output, "\tPUSH\t%i\n", node -> point.nodes [ 1 ] -> nNodes );
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx+2]
	push	word ptr [bx+4]
	mov	ax,offset DGROUP:s@+643
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
	jmp	short @5@198
@5@170:
   ;	
   ;			   else
   ;			     fprintf ( output, "\tPUSH\t0\n" );
   ;	
	mov	ax,offset DGROUP:s@+653
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
@5@198:
   ;	
   ;			   switch ( getSymbolType ( node -> point.nodes [ 0 ] -> point.nameVar ))
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolType
	pop	cx
	cbw	
	cmp	ax,2
	je	short @5@282
	jmp	short @5@310
@5@282:
   ;	
   ;			   {
   ;			     case INTEGER : fprintf ( output, "\tPUSH\t%s\n", reg );
   ;	
	push	di
	mov	ax,offset DGROUP:s@+662
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					    fprintf ( output, "\tCALL\twriteInteger\n" );
   ;	
	mov	ax,offset DGROUP:s@+672
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;					    break;
   ;	
	jmp	short @5@310
@5@310:
   ;	
   ;			   }
   ;			   fprintf ( output, "\tPOP\t%s\n", reg );
   ;	
	push	di
	mov	ax,offset DGROUP:s@+692
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;			   fprintf ( output, "\tPOP\t%s\n", reg );
   ;	
	push	di
	mov	ax,offset DGROUP:s@+701
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;			   cleanRegister ( reg );
   ;	
	push	di
	call	near ptr _cleanRegister
	pop	cx
   ;	
   ;			   break;
   ;	
	jmp	short @5@338
@5@338:
   ;	
   ;	  }
   ;	}
   ;	
	pop	di
	pop	si
	pop	bp
	ret	
_generateAssemblyForPrint	endp
   ;	
   ;	int getLocalDataSizeAndCalcOffsets( int procNo )
   ;	
	assume	cs:_TEXT
_getLocalDataSizeAndCalcOffsets	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
	push	di
   ;	
   ;	{
   ;	  int paramOffset = 6; /* IP + control link + access link */
   ;	
	mov	di,6
   ;	
   ;	  int localOffset = 2;
   ;	
	mov	word ptr [bp-2],2
   ;	
   ;	  SymbolInfo *aux;
   ;	
   ;	  for ( aux = procTable[ procNo ]; aux != NULL; aux = getSymbolNext( aux ))
   ;	
	mov	ax,word ptr [bp+4]
	shl	ax,1
	mov	bx,word ptr DGROUP:_procTable
	add	bx,ax
	mov	si,word ptr [bx]
	jmp	short @6@254
@6@58:
   ;	
   ;	  {
   ;	    int typeSize = getTypeSize( aux );
   ;	
	push	si
	call	near ptr _getTypeSize
	pop	cx
	mov	word ptr [bp-4],ax
   ;	
   ;	
   ;	    if ( getSymbolParam( aux ))
   ;	
	push	si
	call	near ptr _getSymbolParam
	pop	cx
	or	al,al
	je	short @6@198
   ;	
   ;	    {
   ;	      paramOffset = updateOffset( paramOffset, INTEGERSIZE ); /* Forcar o alinhamento por words. */
   ;	
	mov	ax,2
	push	ax
	push	di
	call	near ptr _updateOffset
	pop	cx
	pop	cx
	mov	di,ax
   ;	
   ;	      setSymbolOffs( aux, paramOffset );
   ;	
	push	di
	push	si
	call	near ptr _setSymbolOffs
	pop	cx
	pop	cx
   ;	
   ;	      if ( getSymbolByref( aux ))
   ;	
	push	si
	call	near ptr _getSymbolByref
	pop	cx
	or	al,al
	je	short @6@142
   ;	
   ;		paramOffset += ADDRESSSIZE;
   ;	
	add	di,2
	jmp	short @6@170
@6@142:
   ;	
   ;	      else
   ;	        paramOffset += typeSize;
   ;	
	add	di,word ptr [bp-4]
@6@170:
   ;	
   ;	    }
   ;	
	jmp	short @6@226
@6@198:
   ;	
   ;	    else
   ;	    {
   ;	      localOffset = updateOffset( localOffset, typeSize );
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	call	near ptr _updateOffset
	pop	cx
	pop	cx
	mov	word ptr [bp-2],ax
   ;	
   ;	      setSymbolOffs( aux, -localOffset );
   ;	
	mov	ax,word ptr [bp-2]
	neg	ax
	push	ax
	push	si
	call	near ptr _setSymbolOffs
	pop	cx
	pop	cx
   ;	
   ;	      localOffset += typeSize;
   ;	
	mov	ax,word ptr [bp-4]
	add	word ptr [bp-2],ax
@6@226:
	push	si
	call	near ptr _getSymbolNext
	pop	cx
	mov	si,ax
@6@254:
	or	si,si
	jne	short @6@58
   ;	
   ;	    }
   ;	  }
   ;	  return ( localOffset - 2 );
   ;	
	mov	ax,word ptr [bp-2]
	add	ax,-2
	jmp	short @6@310
@6@310:
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_getLocalDataSizeAndCalcOffsets	endp
   ;	
   ;	void generateAssemblyForProcnodeFuncnode ( Node *node )
   ;	
	assume	cs:_TEXT
_generateAssemblyForProcnodeFuncn	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
	push	di
	mov	si,word ptr [bp+4]
   ;	
   ;	{  
   ;	  char *reg = (char *) malloc( sizeof( char ) * 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	di,ax
   ;	
   ;	  int nNodes, counter;
   ;	  
   ;	  depth = getSymbolDepth ( node->point.nodes[0]->point.nameVar );
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolDepth
	pop	cx
	mov	word ptr DGROUP:_depth,ax
   ;	
   ;	  fprintf ( output, "%s\tPROC\tNEAR\n", getSymbolName ( node->point.nodes[0]->point.nameVar )); 
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolName
	pop	cx
	push	ax
	mov	ax,offset DGROUP:s@+710
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tPUSH\tBP\n" );
   ;	
	mov	ax,offset DGROUP:s@+724
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  findRegister( NULL, ANYTHING, reg );
   ;	
	push	di
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tMOV\t%s,access[%i]\n\tPUSH\t%s\n", reg, depth * 2, reg );
   ;	
	push	di
	mov	ax,word ptr DGROUP:_depth
	shl	ax,1
	push	ax
	push	di
	mov	ax,offset DGROUP:s@+734
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,10
   ;	
   ;	  fprintf ( output, "\tMOV\tBP,SP\n" );
   ;	
	mov	ax,offset DGROUP:s@+763
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\taccess[%i],BP\n", depth *2 );
   ;	
	mov	ax,word ptr DGROUP:_depth
	shl	ax,1
	push	ax
	mov	ax,offset DGROUP:s@+775
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tSUB\tSP,%i\n", getLocalDataSizeAndCalcOffsets( getSymbolProc( node->point.nodes[0]->point.nameVar )));
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolProc
	pop	cx
	push	ax
	call	near ptr _getLocalDataSizeAndCalcOffsets
	pop	cx
	push	ax
	mov	ax,offset DGROUP:s@+795
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  generateAssembly( node->point.nodes[1]->point.nodes[1] );      
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx+2]
	mov	bx,word ptr [bx+2]
	push	word ptr [bx+2]
	call	near ptr _generateAssembly
	pop	cx
   ;	
   ;	  fprintf ( output, "\tPOP\tAX\n" );
   ;	
	mov	ax,offset DGROUP:s@+807
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  findRegister ( NULL, AX, reg );
   ;	
	push	di
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tMOV\tSP,BP\n" );
   ;	
	mov	ax,offset DGROUP:s@+816
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  findRegister( NULL, ANYTHING, reg );
   ;	
	push	di
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tPOP\t%s\n\tMOV\taccess[%i],%s\n", reg, depth * 2, reg );
   ;	
	push	di
	mov	ax,word ptr DGROUP:_depth
	shl	ax,1
	push	ax
	push	di
	mov	ax,offset DGROUP:s@+828
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,10
   ;	
   ;	  fprintf ( output, "\tPOP\tBP\n" );
   ;	
	mov	ax,offset DGROUP:s@+856
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  if ( !strcmp( "main", getSymbolName ( node->point.nodes[0]->point.nameVar )))
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolName
	pop	cx
	push	ax
	mov	ax,offset DGROUP:s@+865
	push	ax
	call	near ptr _strcmp
	pop	cx
	pop	cx
	or	ax,ax
	jne	short @7@86
   ;	
   ;	  {
   ;	    fprintf ( output, "\tMOV\tAH,4Ch\n" );
   ;	
	mov	ax,offset DGROUP:s@+870
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	    fprintf ( output, "\tINT\t21h\n" );
   ;	
	mov	ax,offset DGROUP:s@+883
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
@7@86:
   ;	
   ;	  }
   ;	  fprintf ( output, "\tRET\n" );
   ;	
	mov	ax,offset DGROUP:s@+893
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tENDP\t%s\n\n", getSymbolName ( node->point.nodes[0]->point.nameVar )); 
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolName
	pop	cx
	push	ax
	mov	ax,offset DGROUP:s@+899
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  if ( nNodes = node->point.nodes[1]->point.nodes[0]->nNodes )
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx+2]
	mov	bx,word ptr [bx+2]
	mov	bx,word ptr [bx]
	mov	ax,word ptr [bx+4]
	mov	word ptr [bp-2],ax
	or	ax,ax
	je	short @7@226
   ;	
   ;	    for ( counter = 0; counter < nNodes; counter++ )
   ;	
	mov	word ptr [bp-4],0
	jmp	short @7@198
@7@142:
   ;	
   ;	      generateAssembly( node->point.nodes[1]->point.nodes[0]->point.nodes[ counter ] );
   ;	
	mov	ax,word ptr [bp-4]
	shl	ax,1
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx+2]
	mov	bx,word ptr [bx+2]
	mov	bx,word ptr [bx]
	mov	bx,word ptr [bx+2]
	add	bx,ax
	push	word ptr [bx]
	call	near ptr _generateAssembly
	pop	cx
	inc	word ptr [bp-4]
@7@198:
	mov	ax,word ptr [bp-4]
	cmp	ax,word ptr [bp-2]
	jl	short @7@142
@7@226:
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyForProcnodeFuncn	endp
   ;	
   ;	void generateAssemblyForProccallFunccall ( Node *node )
   ;	
	assume	cs:_TEXT
_generateAssemblyForProccallFuncc	proc	near
	push	bp
	mov	bp,sp
	sub	sp,18
	push	si
	push	di
   ;	
   ;	{
   ;	  SymbolInfo     *info1 = node->point.nodes[0]->point.nameVar; /* O subprograma a chamar. */
   ;	
	mov	bx,word ptr [bp+4]
	mov	bx,word ptr [bx+2]
	mov	bx,word ptr [bx]
	mov	ax,word ptr [bx+2]
	mov	word ptr [bp-2],ax
   ;	
   ;	  SubprogramInfo *info2 = ( SubprogramInfo * ) getSymbolMore( info1 );
   ;	
	push	word ptr [bp-2]
	call	near ptr _getSymbolMore
	pop	cx
	mov	word ptr [bp-4],ax
   ;	
   ;	  ParameterInfo  *info3 = getSubprogramArgs( info2 );
   ;	
	push	word ptr [bp-4]
	call	near ptr _getSubprogramArgs
	pop	cx
	mov	word ptr [bp-6],ax
   ;	
   ;	  int narg = getSubprogramNarg( info2 );
   ;	
	push	word ptr [bp-4]
	call	near ptr _getSubprogramNarg
	pop	cx
	cbw	
	mov	word ptr [bp-8],ax
   ;	
   ;	  int counter = 0;
   ;	
	mov	word ptr [bp-10],0
   ;	
   ;	  int argSize = 0;
   ;	
	mov	word ptr [bp-12],0
	jmp	@8@786
@8@58:
   ;	
   ;	
   ;	  for ( ; counter < narg; counter++ )
   ;	  {
   ;	    char *reg;
   ;	
   ;	    if ( getParameterByref( &info3[counter] ))
   ;	
	mov	ax,word ptr [bp-10]
	mov	dx,3
	imul	dx
	mov	dx,word ptr [bp-6]
	add	dx,ax
	push	dx
	call	near ptr _getParameterByref
	pop	cx
	or	ax,ax
	jne	@@42
	jmp	@8@366
@@42:
   ;	
   ;	    {
   ;	      SymbolInfo *info = node->point.nodes[counter + 1]->point.nameVar;
   ;	
	mov	ax,word ptr [bp-10]
	inc	ax
	shl	ax,1
	mov	bx,word ptr [bp+4]
	mov	bx,word ptr [bx+2]
	add	bx,ax
	mov	bx,word ptr [bx]
	mov	si,word ptr [bx+2]
   ;	
   ;	
   ;	      if ( getSymbolParam( info ) & getSymbolByref( info ))
   ;	
	push	si
	call	near ptr _getSymbolParam
	pop	cx
	push	ax
	push	si
	call	near ptr _getSymbolByref
	pop	cx
	pop	dx
	test	dl,al
	je	short @8@142
   ;	
   ;	      {
   ;		findRegister( NULL, ANYTHING, reg = (char *) malloc( sizeof( char ) * 3 ));
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	word ptr [bp-14],ax
	push	ax
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;		fprintf( output, "\tMOV\t%s,WORD PTR [BP + %i]\n", reg, getSymbolOffs( info ));
   ;	
	push	si
	call	near ptr _getSymbolOffs
	pop	cx
	push	ax
	push	word ptr [bp-14]
	mov	ax,offset DGROUP:s@+910
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;		fprintf( output, "\tPUSH\t%s\n", reg );
   ;	
	push	word ptr [bp-14]
	mov	ax,offset DGROUP:s@+938
	jmp	short @8@282
@8@142:
   ;	
   ;	      }
   ;	      else
   ;	      {
   ;		int auxDepth = getSymbolDepth( info );
   ;	
	push	si
	call	near ptr _getSymbolDepth
	pop	cx
	mov	di,ax
   ;	
   ;	
   ;		findRegister( NULL, ANYTHING, reg = (char *) malloc( sizeof( char ) * 3 ));
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	word ptr [bp-14],ax
	push	ax
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;		if ( auxDepth == depth ) 
   ;	
	cmp	di,word ptr DGROUP:_depth
	jne	short @8@198
   ;	
   ;		  fprintf( output, "\tLEA\t%s,WORD PTR [BP + %i]\n", reg, getSymbolOffs( info ));
   ;	
	push	si
	call	near ptr _getSymbolOffs
	pop	cx
	push	ax
	push	word ptr [bp-14]
	mov	ax,offset DGROUP:s@+948
	jmp	short @8@226
@8@198:
   ;	
   ;	        else {
   ;		  fprintf( output, "\tMOV\tDI,access[%i]\n", auxDepth * 2 ); 
   ;	
	mov	ax,di
	shl	ax,1
	push	ax
	mov	ax,offset DGROUP:s@+976
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;		  fprintf( output, "\tLEA\t%s,SS:[DI + %i]\n", reg, getSymbolOffs( info ));
   ;	
	push	si
	call	near ptr _getSymbolOffs
	pop	cx
	push	ax
	push	word ptr [bp-14]
	mov	ax,offset DGROUP:s@+996
@8@226:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;		}
   ;		fprintf( output, "\tPUSH\t%s\n", reg );
   ;	
	push	word ptr [bp-14]
	mov	ax,offset DGROUP:s@+1018
@8@282:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	      }
   ;	      argSize += 2;
   ;	
	add	word ptr [bp-12],2
   ;	
   ;	    }
   ;	
	jmp	@8@758
@8@366:
   ;	
   ;	    else {
   ;	      int size = getTypeSize ( getParameterParam( &info3[counter] ));
   ;	
	mov	ax,word ptr [bp-10]
	mov	dx,3
	imul	dx
	mov	dx,word ptr [bp-6]
	add	dx,ax
	push	dx
	call	near ptr _getParameterParam
	pop	cx
	push	ax
	call	near ptr _getTypeSize
	pop	cx
	mov	word ptr [bp-16],ax
   ;	
   ;	
   ;	      switch ( size ) 
   ;	
	mov	ax,word ptr [bp-16]
	cmp	ax,1
	je	short @8@506
	cmp	ax,2
	je	short @8@506
	jmp	@8@702
@8@506:
   ;	
   ;	      {
   ;		case INTEGERSIZE:
   ;		case BOOLEANSIZE: /* Tambem serve para caracteres. */
   ;		  {
   ;		     char *aux = ( char * ) malloc ( 3 ),
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;			  *tmp, *reg = generateAssemblyForExpression( node->point.nodes[counter + 1], NOFLAG );
   ;	
	xor	ax,ax
	push	ax
	mov	ax,word ptr [bp-10]
	inc	ax
	shl	ax,1
	mov	bx,word ptr [bp+4]
	mov	bx,word ptr [bx+2]
	add	bx,ax
	push	word ptr [bx]
	call	near ptr _generateAssemblyForExpression
	pop	cx
	pop	cx
	mov	di,ax
   ;	
   ;	
   ;		     aux [ 0 ] = reg[ 0 ];
   ;	
	mov	al,byte ptr [di]
	mov	byte ptr [si],al
   ;	
   ;		     aux [ 1 ] = (( reg[ 1 ] == 'H' ) ? 'L' : 'H' );
   ;	
	cmp	byte ptr [di+1],72
	jne	short @8@562
	mov	al,76
	jmp	short @8@590
@8@562:
	mov	al,72
@8@590:
	mov	byte ptr [si+1],al
   ;	
   ;		     aux [ 2 ] = '\0';
   ;	
	mov	byte ptr [si+2],0
   ;	
   ;		     if ( reg[ 1 ] == 'H' )
   ;	
	cmp	byte ptr [di+1],72
	jne	short @8@646
   ;	
   ;		     {
   ;		       fprintf ( output, "\tMOV\t%s, %s\n", reg, aux );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1028
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;		       tmp = aux;
   ;	
	mov	word ptr [bp-18],si
   ;	
   ;		       strcpy ( aux, reg );
   ;	
	push	di
	push	si
	call	near ptr _strcpy
	pop	cx
	pop	cx
   ;	
   ;		       reg = tmp;
   ;	
	mov	di,word ptr [bp-18]
@8@646:
   ;	
   ;	             }
   ;		     fprintf ( output, "\tXOR\t%s, %s\n", aux, aux );
   ;	
	push	si
	push	si
	mov	ax,offset DGROUP:s@+1041
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;	             aux [ 1 ] = 'X';
   ;	
	mov	byte ptr [si+1],88
   ;	
   ;		     findRegister ( NULL, giveRegisterCode ( aux ), aux );
   ;	
	push	si
	push	si
	call	near ptr _giveRegisterCode
	pop	cx
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	             reg = aux;
   ;	
	mov	di,si
   ;	
   ;	             fprintf( output, "\tPUSH\t%s\n", reg );
   ;	
	push	di
	mov	ax,offset DGROUP:s@+1054
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;		  }
   ;		  break;
   ;	
	jmp	@8@730
@8@702:
   ;	
   ;	        default:
   ;		  cleanRegisters ();
   ;	
	call	near ptr _cleanRegisters
   ;	
   ;		  findRegister( NULL, BX, reg = ( char * ) malloc( sizeof( char ) * 3 ));
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	word ptr [bp-14],ax
	push	ax
	mov	ax,3
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;		  fprintf ( output, "\tMOV\tBX,DS\n" );
   ;	
	mov	ax,offset DGROUP:s@+1064
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;		  fprintf ( output, "\tMOV\tDS,SS\n" );
   ;	
	mov	ax,offset DGROUP:s@+1076
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;		  fprintf ( output, "\tMOV\tES,SS\n" );
   ;	
	mov	ax,offset DGROUP:s@+1088
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;		  fprintf ( output, "\tMOV\tSI,%s\n", generateAssemblyForExpression( node->point.nodes[counter + 1], NOFLAG ));
   ;	
	xor	ax,ax
	push	ax
	mov	ax,word ptr [bp-10]
	inc	ax
	shl	ax,1
	mov	bx,word ptr [bp+4]
	mov	bx,word ptr [bx+2]
	add	bx,ax
	push	word ptr [bx]
	call	near ptr _generateAssemblyForExpression
	pop	cx
	pop	cx
	push	ax
	mov	ax,offset DGROUP:s@+1100
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;		  fprintf ( output, "\tMOV\tDI,SP\n" );
   ;	
	mov	ax,offset DGROUP:s@+1112
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;		  fprintf ( output, "\tSUB\tSP,%i\n", size );
   ;	
	push	word ptr [bp-16]
	mov	ax,offset DGROUP:s@+1124
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;		  findRegister( NULL, CX, reg );
   ;	
	push	word ptr [bp-14]
	mov	ax,6
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;		  fprintf ( output, "\tMOV\tCX,%i\n", size );
   ;	
	push	word ptr [bp-16]
	mov	ax,offset DGROUP:s@+1136
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;		  fprintf ( output, "\tCALL\tMOVE\n" );
   ;	
	mov	ax,offset DGROUP:s@+1148
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;		  fprintf ( output, "\tMOV\tDS,BX\n" );
   ;	
	mov	ax,offset DGROUP:s@+1160
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;		  cleanRegisters ();
   ;	
	call	near ptr _cleanRegisters
   ;	
   ;		  free( reg );
   ;	
	push	word ptr [bp-14]
	call	near ptr _free
	pop	cx
   ;	
   ;		  break;
   ;	
	jmp	short @8@730
@8@730:
   ;	
   ;	      } 
   ;	      argSize += size; 
   ;	
	mov	ax,word ptr [bp-16]
	add	word ptr [bp-12],ax
@8@758:
	inc	word ptr [bp-10]
@8@786:
	mov	ax,word ptr [bp-10]
	cmp	ax,word ptr [bp-8]
	jge	@@43
	jmp	@8@58
@@43:
   ;	
   ;	    }	  
   ;	  }
   ;	  fprintf ( output, "\tCALL\t%s\n", getSymbolName( info1 ));
   ;	
	push	word ptr [bp-2]
	call	near ptr _getSymbolName
	pop	cx
	push	ax
	mov	ax,offset DGROUP:s@+1172
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tADD\tSP,%i\n", argSize );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+1182
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyForProccallFuncc	endp
   ;	
   ;	void generateRecordCopy( SymbolInfo *info, char *address )
   ;	
	assume	cs:_TEXT
_generateRecordCopy	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
	push	si
	push	di
	mov	si,word ptr [bp+4]
   ;	
   ;	{
   ;	  char *reg;
   ;	  int size = getTypeSize( info );
   ;	
	push	si
	call	near ptr _getTypeSize
	pop	cx
	mov	word ptr [bp-2],ax
   ;	
   ;	
   ;	  cleanRegisters ();
   ;	
	call	near ptr _cleanRegisters
   ;	
   ;	  findRegister( NULL, BX, reg = ( char * ) malloc( sizeof( char ) * 3 ));
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	di,ax
	push	ax
	mov	ax,3
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tMOV\tBX,DS\n" );
   ;	
	mov	ax,offset DGROUP:s@+1194
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\tDS,SS\n" );
   ;	
	mov	ax,offset DGROUP:s@+1206
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\tES,SS\n" );
   ;	
	mov	ax,offset DGROUP:s@+1218
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\tSI,[%s]\n", address );
   ;	
	push	word ptr [bp+6]
	mov	ax,offset DGROUP:s@+1230
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tMOV\tDI,access[%i]\n", getSymbolDepth( info ) * 2 );
   ;	
	push	si
	call	near ptr _getSymbolDepth
	pop	cx
	shl	ax,1
	push	ax
	mov	ax,offset DGROUP:s@+1244
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tMOV\tDI,SS:[DI+%i]\n", getSymbolOffs( info ));
   ;	
	push	si
	call	near ptr _getSymbolOffs
	pop	cx
	push	ax
	mov	ax,offset DGROUP:s@+1264
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  findRegister( NULL, CX, reg );
   ;	
	push	di
	mov	ax,6
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tMOV\tCX,%i\n", size );
   ;	
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+1284
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tCALL\tMOVE\n" );
   ;	
	mov	ax,offset DGROUP:s@+1296
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  fprintf ( output, "\tMOV\tDS,BX\n" );
   ;	
	mov	ax,offset DGROUP:s@+1308
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;	  cleanRegisters ();
   ;	
	call	near ptr _cleanRegisters
   ;	
   ;	  free( reg );
   ;	
	push	di
	call	near ptr _free
	pop	cx
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateRecordCopy	endp
   ;	
   ;	void generateAssemblyForIf ( Node *node )
   ;	
	assume	cs:_TEXT
_generateAssemblyForIf	proc	near
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
	push	di
	mov	si,word ptr [bp+4]
   ;	
   ;	{
   ;	  char *reg;
   ;	  int label1 = ++label; 
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	di,ax
   ;	
   ;	  int auxlabel = label1;
   ;	
	mov	word ptr [bp-4],di
   ;	
   ;	
   ;	  reg = generateAssemblyForExpression ( node -> point.nodes [ 0 ], IFFLAG );
   ;	
	mov	ax,1
	push	ax
	mov	bx,word ptr [si+2]
	push	word ptr [bx]
	call	near ptr _generateAssemblyForExpression
	pop	cx
	pop	cx
	mov	word ptr [bp-2],ax
   ;	
   ;	  generateAssembly ( node -> point.nodes [ 1 ] -> point.nodes [ 0 ]);
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx+2]
	mov	bx,word ptr [bx+2]
	push	word ptr [bx]
	call	near ptr _generateAssembly
	pop	cx
   ;	
   ;	  if ( node -> nNodes == 3 ) 
   ;	
	cmp	word ptr [si+4],3
	jne	short @10@86
   ;	
   ;	  {
   ;	    int label2 = ++label; 
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-6],ax
   ;	
   ;	
   ;	    fprintf ( output, "\tJMP\t_%i\n", label2 ); 
   ;	
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+1320
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	    fprintf ( output, "_%i :\n", label1 ); 
   ;	
	push	di
	mov	ax,offset DGROUP:s@+1330
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	    generateAssembly ( node -> point.nodes [ 2 ] -> point.nodes [ 0 ] );
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx+4]
	mov	bx,word ptr [bx+2]
	push	word ptr [bx]
	call	near ptr _generateAssembly
	pop	cx
   ;	
   ;	    auxlabel = label2;
   ;	
	mov	ax,word ptr [bp-6]
	mov	word ptr [bp-4],ax
@10@86:
   ;	
   ;	  }
   ;	  fprintf ( output, "_%i :\n", auxlabel );
   ;	
	push	word ptr [bp-4]
	mov	ax,offset DGROUP:s@+1337
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyForIf	endp
   ;	
   ;	void generateAssemblyForWhile ( Node *node )
   ;	
	assume	cs:_TEXT
_generateAssemblyForWhile	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
	push	di
	mov	si,word ptr [bp+4]
   ;	
   ;	{
   ;	  char *reg;
   ;	  int label1 = ++label, 
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-4],ax
   ;	
   ;	      label2 = ++label;
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	di,ax
   ;	
   ;	
   ;	  fprintf ( output, "\tJMP\t_%i\n", label2 );
   ;	
	push	di
	mov	ax,offset DGROUP:s@+1344
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  fprintf ( output, "_%i :\n", label1 ); 
   ;	
	push	word ptr [bp-4]
	mov	ax,offset DGROUP:s@+1354
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  generateAssembly ( node -> point.nodes [ 1 ] );
   ;	
	mov	bx,word ptr [si+2]
	push	word ptr [bx+2]
	call	near ptr _generateAssembly
	pop	cx
   ;	
   ;	  fprintf ( output, "_%i :\n", label2 );
   ;	
	push	di
	mov	ax,offset DGROUP:s@+1361
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  reg = generateAssemblyForExpression ( node -> point.nodes [ 0 ], WHILEFLAG );
   ;	
	mov	ax,2
	push	ax
	mov	bx,word ptr [si+2]
	push	word ptr [bx]
	call	near ptr _generateAssemblyForExpression
	pop	cx
	pop	cx
	mov	word ptr [bp-2],ax
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyForWhile	endp
   ;	
   ;	void generateAssemblyForAssignment ( Node *node )
   ;	
	assume	cs:_TEXT
_generateAssemblyForAssignment	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
	push	di
	mov	si,word ptr [bp+4]
   ;	
   ;	{
   ;	  char *regExpression, regVariable [ 3 ];
   ;	
   ;	  regExpression = generateAssemblyForExpression ( node -> point.nodes [ 1 ], NOFLAG );
   ;	
	xor	ax,ax
	push	ax
	mov	bx,word ptr [si+2]
	push	word ptr [bx+2]
	call	near ptr _generateAssemblyForExpression
	pop	cx
	pop	cx
	mov	di,ax
   ;	
   ;	  if ( node -> point.nodes [ 0 ] -> name == VARNAME )
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	cmp	word ptr [bx],1
	je	@@44
	jmp	@12@478
@@44:
   ;	
   ;	  {
   ;	    if ( getSymbolType ( node -> point.nodes [ 0 ] -> point.nameVar ) == RECORD )
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolType
	pop	cx
	cmp	al,5
	jne	short @12@114
   ;	
   ;	      generateRecordCopy ( node -> point.nodes [ 0 ] -> point.nameVar, regExpression ); 
   ;	
	push	di
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _generateRecordCopy
	pop	cx
	pop	cx
	jmp	@12@450
@12@114:
   ;	
   ;	    else
   ;	    {
   ;	      int depthSym = getSymbolDepth ( node -> point.nodes [ 0 ] -> point.nameVar ),
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolDepth
	pop	cx
	mov	word ptr [bp-2],ax
   ;	
   ;		  off = getSymbolOffs ( node -> point.nodes [ 0 ] -> point.nameVar );
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _getSymbolOffs
	pop	cx
	mov	word ptr [bp-4],ax
   ;	
   ;	
   ;	      if ( depth == depthSym )
   ;	
	mov	ax,word ptr DGROUP:_depth
	cmp	ax,word ptr [bp-2]
	jne	short @12@282
   ;	
   ;	      {
   ;	        if ( off >= 0 )
   ;	
	cmp	word ptr [bp-4],0
	jl	short @12@198
   ;	
   ;	          fprintf ( output, "\tMOV\t[BP+%i], %s\n", off, regExpression );
   ;	
	push	di
	push	word ptr [bp-4]
	mov	ax,offset DGROUP:s@+1368
	jmp	short @12@226
@12@198:
   ;	
   ;	        else
   ;	          fprintf ( output, "\tMOV\t[BP%i], %s\n", off, regExpression );
   ;	
	push	di
	push	word ptr [bp-4]
	mov	ax,offset DGROUP:s@+1386
@12@226:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;	      }
   ;	
	jmp	short @12@394
@12@282:
   ;	
   ;	      else
   ;	      {
   ;	        fprintf ( output, "\tMOV\tDI, access[%i]\n", depthSym * 2 );
   ;	
	mov	ax,word ptr [bp-2]
	shl	ax,1
	push	ax
	mov	ax,offset DGROUP:s@+1403
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	        if ( off >= 0 )
   ;	
	cmp	word ptr [bp-4],0
	jl	short @12@338
   ;	
   ;	          fprintf ( output, "\tMOV\tSS:[DI+%i], %s\n", off, regExpression );
   ;	
	push	di
	push	word ptr [bp-4]
	mov	ax,offset DGROUP:s@+1424
	jmp	short @12@366
@12@338:
   ;	
   ;	        else
   ;	          fprintf ( output, "\tMOV\tSS:[DI%i], %s\n", off, regExpression );
   ;	
	push	di
	push	word ptr [bp-4]
	mov	ax,offset DGROUP:s@+1445
@12@366:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
@12@394:
   ;	
   ;	      }
   ;	      if ( regExpression = inRegister ( node -> point.nodes [ 0 ] -> point.nameVar ))
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	push	word ptr [bx+2]
	call	near ptr _inRegister
	pop	cx
	mov	di,ax
	or	ax,ax
	je	short @12@450
   ;	
   ;	        cleanRegister ( regExpression );
   ;	
	push	di
	call	near ptr _cleanRegister
	pop	cx
@12@450:
   ;	
   ;	    }
   ;	  }
   ;	
	jmp	short @12@534
@12@478:
   ;	
   ;	  else
   ;	    if ( node -> point.nodes [ 0 ] -> name == RETURNVALUE )
   ;	
	mov	bx,word ptr [si+2]
	mov	bx,word ptr [bx]
	cmp	word ptr [bx],29
	jne	short @12@534
   ;	
   ;	    {
   ;	      fprintf ( output, "\tPUSH\t%s\n", regExpression );
   ;	
	push	di
	mov	ax,offset DGROUP:s@+1465
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	      cleanRegister ( regExpression );
   ;	
	push	di
	call	near ptr _cleanRegister
	pop	cx
@12@534:
   ;	
   ;	    }
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyForAssignment	endp
   ;	
   ;	char *generateAssemblyForVariable ( SymbolInfo *variable )
   ;	
	assume	cs:_TEXT
_generateAssemblyForVariable	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
	push	di
   ;	
   ;	{
   ;	  int depthSym = getSymbolDepth ( variable ),
   ;	
	push	word ptr [bp+4]
	call	near ptr _getSymbolDepth
	pop	cx
	mov	word ptr [bp-2],ax
   ;	
   ;	      off = getSymbolOffs ( variable ),
   ;	
	push	word ptr [bp+4]
	call	near ptr _getSymbolOffs
	pop	cx
	mov	si,ax
   ;	
   ;	      aux;
   ;	  char *regResult = ( char * ) malloc ( 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	di,ax
   ;	
   ;	
   ;	  if ( getSymbolType ( variable ) == RECORD )
   ;	
	push	word ptr [bp+4]
	call	near ptr _getSymbolType
	pop	cx
	cmp	al,5
	jne	short @13@86
   ;	
   ;	    aux = findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	di
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	jmp	short @13@114
@13@86:
   ;	
   ;	  else
   ;	    aux = findRegister ( variable, ANYTHING, regResult );
   ;	
	push	di
	mov	ax,255
	push	ax
	push	word ptr [bp+4]
@13@114:
	call	near ptr _findRegister
	add	sp,6
	mov	word ptr [bp-4],ax
   ;	
   ;	  if ( aux ) 
   ;	
	cmp	word ptr [bp-4],0
	jne	@@45
	jmp	@13@786
@@45:
   ;	
   ;	  {
   ;	    if ( getSymbolType ( variable ) == RECORD )
   ;	
	push	word ptr [bp+4]
	call	near ptr _getSymbolType
	pop	cx
	cmp	al,5
	jne	short @13@506
   ;	
   ;	    {
   ;	      if ( depth == depthSym )
   ;	
	mov	ax,word ptr DGROUP:_depth
	cmp	ax,word ptr [bp-2]
	jne	short @13@366
   ;	
   ;	      {
   ;	        if ( off >= 0 )
   ;	
	or	si,si
	jl	short @13@282
   ;	
   ;	          fprintf ( output, "\tMOV\t%s, BP+%i\n", regResult, off );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1475
	jmp	short @13@310
@13@282:
   ;	
   ;	        else
   ;	          fprintf ( output, "\tMOV\t%s, BP%i\n", regResult, off );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1491
@13@310:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;	      }
   ;	
	jmp	short @13@478
@13@366:
   ;	
   ;	      else
   ;	      {
   ;	        fprintf ( output, "\tMOV\tDI, access[%i]\n", depthSym * 2 );
   ;	
	mov	ax,word ptr [bp-2]
	shl	ax,1
	push	ax
	mov	ax,offset DGROUP:s@+1506
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	        if ( off >= 0 )
   ;	
	or	si,si
	jl	short @13@422
   ;	
   ;	          fprintf ( output, "\tMOV\t%s, DI+%i\n", regResult, off );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1527
	jmp	short @13@450
@13@422:
   ;	
   ;	        else
   ;	          fprintf ( output, "\tMOV\t%s, DI%i\n", regResult, off );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1543
@13@450:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
@13@478:
   ;	
   ;	      }
   ;	    }
   ;	
	jmp	short @13@786
@13@506:
   ;	
   ;	    else
   ;	      if ( depth == depthSym )
   ;	
	mov	ax,word ptr DGROUP:_depth
	cmp	ax,word ptr [bp-2]
	jne	short @13@674
   ;	
   ;	      {
   ;	        if ( off >= 0 )
   ;	
	or	si,si
	jl	short @13@590
   ;	
   ;	          fprintf ( output, "\tMOV\t%s, [BP+%i]\n", regResult, off );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1558
	jmp	short @13@618
@13@590:
   ;	
   ;	        else
   ;	          fprintf ( output, "\tMOV\t%s, [BP%i]\n", regResult, off );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1576
@13@618:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;	      }
   ;	
	jmp	short @13@786
@13@674:
   ;	
   ;	      else
   ;	      {
   ;	        fprintf ( output, "\tMOV\tDI, access[%i]\n", depthSym * 2 );
   ;	
	mov	ax,word ptr [bp-2]
	shl	ax,1
	push	ax
	mov	ax,offset DGROUP:s@+1593
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	        if ( off >= 0 )
   ;	
	or	si,si
	jl	short @13@730
   ;	
   ;	          fprintf ( output, "\tMOV\t%s, SS:[DI+%i]\n", regResult, off );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1614
	jmp	short @13@758
@13@730:
   ;	
   ;	        else
   ;	          fprintf ( output, "\tMOV\t%s, SS:[DI%i]\n", regResult, off );
   ;	
	push	si
	push	di
	mov	ax,offset DGROUP:s@+1635
@13@758:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
@13@786:
   ;	
   ;	      }
   ;	  }
   ;	  return regResult;
   ;	
	mov	ax,di
	jmp	short @13@814
@13@814:
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyForVariable	endp
   ;	
   ;	char *generateAssemblyForVarByref ( SymbolInfo * variable )
   ;	
	assume	cs:_TEXT
_generateAssemblyForVarByref	proc	near
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
	push	di
	mov	di,word ptr [bp+4]
   ;	
   ;	{
   ;	  int depthSym = getSymbolDepth ( variable ),
   ;	
	push	di
	call	near ptr _getSymbolDepth
	pop	cx
	mov	word ptr [bp-2],ax
   ;	
   ;	      off = getSymbolOffs ( variable ),
   ;	
	push	di
	call	near ptr _getSymbolOffs
	pop	cx
	mov	si,ax
   ;	
   ;	      aux;
   ;	  char *regResult = ( char * ) malloc ( 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	word ptr [bp-6],ax
   ;	
   ;	
   ;	  if ( getSymbolType ( variable ) == RECORD )
   ;	
	push	di
	call	near ptr _getSymbolType
	pop	cx
	cmp	al,5
	jne	short @14@86
   ;	
   ;	    aux = findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	word ptr [bp-6]
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	jmp	short @14@114
@14@86:
   ;	
   ;	  else
   ;	    aux = findRegister ( variable, ANYTHING, regResult );
   ;	
	push	word ptr [bp-6]
	mov	ax,255
	push	ax
	push	di
@14@114:
	call	near ptr _findRegister
	add	sp,6
	mov	word ptr [bp-4],ax
   ;	
   ;	  if ( aux ) 
   ;	
	cmp	word ptr [bp-4],0
	je	short @14@562
   ;	
   ;	  {
   ;	    if ( depth == depthSym )
   ;	
	mov	ax,word ptr DGROUP:_depth
	cmp	ax,word ptr [bp-2]
	jne	short @14@338
   ;	
   ;	    {
   ;	      if ( off >= 0 )
   ;	
	or	si,si
	jl	short @14@254
   ;	
   ;	        fprintf ( output, "\tMOV\tDI, [BP+%i]\n", off );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+1655
	jmp	short @14@282
@14@254:
   ;	
   ;	      else
   ;	        fprintf ( output, "\tMOV\tDI, [BP%i]\n", off );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+1673
@14@282:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	    }
   ;	
	jmp	short @14@450
@14@338:
   ;	
   ;	    else
   ;	    {
   ;	      fprintf ( output, "\tMOV\tDI, access[%i]\n", depthSym * 2 );
   ;	
	mov	ax,word ptr [bp-2]
	shl	ax,1
	push	ax
	mov	ax,offset DGROUP:s@+1690
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	      if ( off >= 0 )
   ;	
	or	si,si
	jl	short @14@394
   ;	
   ;	        fprintf ( output, "\tMOV\tDI, SS:[DI+%i]\n", off );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+1711
	jmp	short @14@422
@14@394:
   ;	
   ;	      else
   ;	        fprintf ( output, "\tMOV\tDI, SS:[DI%i]\n", off );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+1732
@14@422:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
@14@450:
   ;	
   ;	    }
   ;	    if ( getSymbolType ( variable ) == RECORD )
   ;	
	push	di
	call	near ptr _getSymbolType
	pop	cx
	cmp	al,5
	jne	short @14@506
   ;	
   ;	      fprintf ( output, "\tMOV\t%s, DI\n", regResult );
   ;	
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+1752
	jmp	short @14@534
@14@506:
   ;	
   ;	    else
   ;	      fprintf ( output, "\tMOV\t%s, SS:[DI]\n", regResult );
   ;	
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+1765
@14@534:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
@14@562:
   ;	
   ;	  }
   ;	  return regResult;
   ;	
	mov	ax,word ptr [bp-6]
	jmp	short @14@590
@14@590:
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyForVarByref	endp
   ;	
   ;	char *generateAssemblyForExpression ( Node *node, int flag )
   ;	
	assume	cs:_TEXT
_generateAssemblyForExpression	proc	near
	push	bp
	mov	bp,sp
	push	si
   ;	
   ;	{
   ;	  char *regResult = ( char * ) malloc ( 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;	
   ;	  generateAssemblyForSubexpression ( node, flag );
   ;	
	push	word ptr [bp+6]
	push	word ptr [bp+4]
	call	near ptr _generateAssemblyForSubexpression
	pop	cx
	pop	cx
   ;	
   ;	  findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	si
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	  fprintf ( output, "\tPOP\t%s\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+1783
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	  return regResult;
   ;	
	mov	ax,si
	jmp	short @15@58
@15@58:
   ;	
   ;	}
   ;	
	pop	si
	pop	bp
	ret	
_generateAssemblyForExpression	endp
   ;	
   ;	void generateAssemblyForSubexpression ( Node *node, int flag )
   ;	
	assume	cs:_TEXT
_generateAssemblyForSubexpression	proc	near
	push	bp
	mov	bp,sp
	sub	sp,12
	push	si
	push	di
	mov	di,word ptr [bp+4]
   ;	
   ;	{
   ;	  char *regResult;
   ;	  int  depth, auxFlag = 0;
   ;	
	mov	word ptr [bp-2],0
   ;	
   ;	
   ;	  switch ( node -> name )
   ;	
	mov	ax,word ptr [di]
	mov	word ptr [bp-4],ax
	mov	cx,8
	mov	bx,offset @16@C2786
@16@114:
	mov	ax,word ptr cs:[bx]
	cmp	ax,word ptr [bp-4]
	je	short @16@198
	add	bx,2
	loop	short @16@114
	jmp	@16@2830
@16@198:
	jmp	word ptr cs:[bx+16]
@16@226:
   ;	
   ;	  {
   ;	    case VARNAME : if ( getSymbolParam ( node -> point.nameVar ) && getSymbolByref ( node -> point.nameVar ))
   ;	
	push	word ptr [di+2]
	call	near ptr _getSymbolParam
	pop	cx
	or	al,al
	je	short @16@310
	push	word ptr [di+2]
	call	near ptr _getSymbolByref
	pop	cx
	or	al,al
	je	short @16@310
   ;	
   ;			     regResult = generateAssemblyForVarByref ( node -> point.nameVar );
   ;	
	push	word ptr [di+2]
	call	near ptr _generateAssemblyForVarByref
	jmp	short @16@338
@16@310:
   ;	
   ;			   else
   ;			     regResult = generateAssemblyForVariable ( node -> point.nameVar );
   ;	
	push	word ptr [di+2]
	call	near ptr _generateAssemblyForVariable
@16@338:
	pop	cx
	mov	si,ax
   ;	
   ;			   break;
   ;	
	jmp	@16@2830
@16@394:
   ;	
   ;	    case FIELDS  : { 
   ;			     SymbolInfo *aux = node -> point.nameVar;
   ;	
	mov	ax,word ptr [di+2]
	jmp	short @16@450
@16@422:
   ;	
   ;	
   ;			     while ( aux -> next != NULL )
   ;		               aux = aux -> next;	       
   ;	
	mov	bx,word ptr [bp-6]
	mov	ax,word ptr [bx+16]
@16@450:
	mov	word ptr [bp-6],ax
	mov	bx,word ptr [bp-6]
	cmp	word ptr [bx+16],0
	jne	short @16@422
   ;	
   ;			     if ( getSymbolParam ( aux ) && getSymbolByref ( aux ))
   ;	
	push	word ptr [bp-6]
	call	near ptr _getSymbolParam
	pop	cx
	or	al,al
	je	short @16@590
	push	word ptr [bp-6]
	call	near ptr _getSymbolByref
	pop	cx
	or	al,al
	je	short @16@590
   ;	
   ;			       regResult = generateAssemblyForVarByref ( aux );
   ;	
	push	word ptr [bp-6]
	call	near ptr _generateAssemblyForVarByref
	jmp	short @16@618
@16@590:
   ;	
   ;			     else
   ;			       regResult = generateAssemblyForVariable ( aux );
   ;	
	push	word ptr [bp-6]
	call	near ptr _generateAssemblyForVariable
@16@618:
	pop	cx
	mov	si,ax
   ;	
   ;			     break;
   ;	
	jmp	@16@2830
@16@674:
   ;	
   ;			   }
   ;	    case FUNCCALL : generateAssemblyForProccallFunccall ( node );
   ;	
	push	di
	call	near ptr _generateAssemblyForProccallFuncc
	pop	cx
   ;	
   ;			    regResult = ( char * ) malloc ( 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;			    strcpy ( regResult, "AX" );
   ;	
	mov	ax,offset DGROUP:s@+1792
	push	ax
	push	si
	call	near ptr _strcpy
	pop	cx
	pop	cx
   ;	
   ;			    break;
   ;	
	jmp	@16@2830
@16@702:
   ;	
   ;	    case INTEGERNODE : regResult = ( char * ) malloc ( 7 );
   ;	
	mov	ax,7
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;			       sprintf ( regResult, "%i", node -> nNodes );
   ;	
	push	word ptr [di+4]
	mov	ax,offset DGROUP:s@+1795
	jmp	short @16@758
@16@730:
   ;	
   ;			       break;
   ;	    case CHARNODE : regResult = ( char * ) malloc ( 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;			    sprintf ( regResult, "%i", node -> nNodes );
   ;	
	push	word ptr [di+4]
	mov	ax,offset DGROUP:s@+1798
@16@758:
	push	ax
	push	si
	call	near ptr _sprintf
	add	sp,6
   ;	
   ;			    break;
   ;	
	jmp	@16@2830
@16@786:
   ;	
   ;	    case BOOLNODE : regResult = ( char * ) malloc ( 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;			    if ( node -> nNodes == TRUE )
   ;	
	cmp	word ptr [di+4],255
	jne	short @16@842
   ;	
   ;			      sprintf ( regResult, "255" );
   ;	
	mov	ax,offset DGROUP:s@+1801
	jmp	short @16@870
@16@842:
   ;	
   ;	                    else 
   ;			      sprintf ( regResult, "0" );
   ;	
	mov	ax,offset DGROUP:s@+1805
@16@870:
	push	ax
	push	si
	call	near ptr _sprintf
	pop	cx
	pop	cx
   ;	
   ;	                    break;
   ;	
	jmp	@16@2830
@16@926:
   ;	
   ;	    case OPERATION : {
   ;		   	       char *reg1 = ( char * ) malloc ( 3 ),
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	word ptr [bp-6],ax
   ;	
   ;				    *reg2 = ( char * ) malloc ( 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	word ptr [bp-8],ax
   ;	
   ;	
   ;	                       generateAssemblyForSubexpression ( node -> point.nodes [ 0 ], flag );
   ;	
	push	word ptr [bp+6]
	mov	bx,word ptr [di+2]
	push	word ptr [bx]
	call	near ptr _generateAssemblyForSubexpression
	pop	cx
	pop	cx
   ;	
   ;	                       generateAssemblyForSubexpression ( node -> point.nodes [ 1 ], flag );
   ;	
	push	word ptr [bp+6]
	mov	bx,word ptr [di+2]
	push	word ptr [bx+2]
	call	near ptr _generateAssemblyForSubexpression
	pop	cx
	pop	cx
   ;	
   ;			       switch ( node -> procno )
   ;	
	mov	ax,word ptr [di+6]
	cmp	ax,3
	je	short @16@1122
	cmp	ax,4
	je	short @16@1094
	cmp	ax,5
	je	short @16@1094
	jmp	short @16@1178
@16@1094:
   ;	
   ;			       {
   ;				 case MOD :
   ;				 case DIV : findRegister ( NULL, DX, ( char * ) malloc ( 3 ));
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	push	ax
	mov	ax,9
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
@16@1122:
   ;	
   ;				 case MUL : findRegister ( NULL, AX, reg1 );
   ;	
	push	word ptr [bp-6]
	xor	ax,ax
@16@1150:
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;					    break;
   ;	
	jmp	short @16@1206
@16@1178:
   ;	
   ;	                         default : findRegister ( NULL, ANYTHING, reg1 );
   ;	
	push	word ptr [bp-6]
	mov	ax,255
	jmp	short @16@1150
@16@1206:
   ;	
   ;					   break;
   ;			       }
   ;	                       findRegister ( NULL, ANYTHING, reg2 );
   ;	
	push	word ptr [bp-8]
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	                       fprintf ( output, "\tPOP\t%s\n", reg2 );
   ;	
	push	word ptr [bp-8]
	mov	ax,offset DGROUP:s@+1807
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                       fprintf ( output, "\tPOP\t%s\n", reg1 );
   ;	
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+1816
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;			       switch ( node -> procno )
   ;	
	mov	bx,word ptr [di+6]
	dec	bx
	cmp	bx,4
	jbe	@@46
	jmp	@16@1542
@@46:
	shl	bx,1
	jmp	word ptr cs:@16@C2994[bx]
@16@1318:
   ;	
   ;			       {
   ;			         case ADD : fprintf ( output, "\tADD\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+1825
@16@1346:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;				    	    regResult = reg1;
   ;	
	mov	si,word ptr [bp-6]
   ;	
   ;				    	    cleanRegister ( regResult );
   ;	
	push	si
@16@1374:
	call	near ptr _cleanRegister
	pop	cx
   ;	
   ;					    break;
   ;	
	jmp	@16@1542
@16@1402:
   ;	
   ;			         case SUB : fprintf ( output, "\tSUB\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+1838
	jmp	short @16@1346
@16@1430:
   ;	
   ;				    	    regResult = reg1;
   ;					    cleanRegister ( regResult );
   ;					    break;
   ;	                         case MUL : fprintf ( output, "\tIMUL\t%s\n", reg2 );
   ;	
	push	word ptr [bp-8]
	mov	ax,offset DGROUP:s@+1851
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					    regResult = ( char * ) malloc ( sizeof ( char ) * 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;					    strcpy ( regResult, "AX" );
   ;	
	mov	ax,offset DGROUP:s@+1861
	push	ax
	push	si
	call	near ptr _strcpy
	pop	cx
	pop	cx
   ;	
   ;					    cleanRegister ( "AX" );
   ;	
	mov	ax,offset DGROUP:s@+1864
	push	ax
	call	near ptr _cleanRegister
	pop	cx
   ;	
   ;					    cleanRegister ( "DX" );
   ;	
	mov	ax,offset DGROUP:s@+1867
	jmp	short @16@1514
@16@1458:
   ;	
   ;					    break;
   ;	                         case DIV : fprintf ( output, "\tCWD\n" );
   ;	
	mov	ax,offset DGROUP:s@+1870
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;					    fprintf ( output, "\tIDIV\t%s\n", reg2 );
   ;	
	push	word ptr [bp-8]
	mov	ax,offset DGROUP:s@+1876
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					    regResult = ( char * ) malloc ( sizeof ( char ) * 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;					    strcpy ( regResult, "AX" );
   ;	
	mov	ax,offset DGROUP:s@+1886
	push	ax
	push	si
	call	near ptr _strcpy
	pop	cx
	pop	cx
   ;	
   ;					    cleanRegister ( "AX" );
   ;	
	mov	ax,offset DGROUP:s@+1889
	jmp	short @16@1514
@16@1486:
   ;	
   ;					    break;
   ;	                         case MOD : fprintf ( output, "\tCWD\n" );
   ;	
	mov	ax,offset DGROUP:s@+1892
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	pop	cx
	pop	cx
   ;	
   ;					    fprintf ( output, "\tIDIV\t%s\n", reg2 );
   ;	
	push	word ptr [bp-8]
	mov	ax,offset DGROUP:s@+1898
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					    regResult = ( char * ) malloc ( sizeof ( char ) * 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	si,ax
   ;	
   ;					    strcpy ( regResult, "DX" );
   ;	
	mov	ax,offset DGROUP:s@+1908
	push	ax
	push	si
	call	near ptr _strcpy
	pop	cx
	pop	cx
   ;	
   ;					    cleanRegister ( "AX" );
   ;	
	mov	ax,offset DGROUP:s@+1911
@16@1514:
	push	ax
	jmp	@16@1374
@16@1542:
   ;	
   ;					    break;
   ;			      }
   ;			    }
   ;	                    break;
   ;	
	jmp	@16@2830
@16@1570:
   ;	
   ;	    case RELATION : {
   ;		   	      char *reg1 = ( char * ) malloc ( 3 ),
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	word ptr [bp-6],ax
   ;	
   ;				   *reg2 = ( char * ) malloc ( 3 );
   ;	
	mov	ax,3
	push	ax
	call	near ptr _malloc
	pop	cx
	mov	word ptr [bp-8],ax
   ;	
   ;	
   ;	                      generateAssemblyForSubexpression ( node -> point.nodes [ 0 ], flag );
   ;	
	push	word ptr [bp+6]
	mov	bx,word ptr [di+2]
	push	word ptr [bx]
	call	near ptr _generateAssemblyForSubexpression
	pop	cx
	pop	cx
   ;	
   ;	                      generateAssemblyForSubexpression ( node -> point.nodes [ 1 ], flag );
   ;	
	push	word ptr [bp+6]
	mov	bx,word ptr [di+2]
	push	word ptr [bx+2]
	call	near ptr _generateAssemblyForSubexpression
	pop	cx
	pop	cx
   ;	
   ;	                      findRegister ( NULL, ANYTHING, reg1 );
   ;	
	push	word ptr [bp-6]
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	                      findRegister ( NULL, ANYTHING, reg2 );
   ;	
	push	word ptr [bp-8]
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;	                      fprintf ( output, "\tPOP\t%s\n", reg2 );
   ;	
	push	word ptr [bp-8]
	mov	ax,offset DGROUP:s@+1914
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                      fprintf ( output, "\tPOP\t%s\n", reg1 );
   ;	
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+1923
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;			      switch ( node -> procno )
   ;	
	mov	bx,word ptr [di+6]
	dec	bx
	cmp	bx,8
	jbe	@@47
	jmp	@16@2830
@@47:
	shl	bx,1
	jmp	word ptr cs:@16@C3042[bx]
@16@1682:
   ;	
   ;			      {
   ;			        case EQUAL : fprintf ( output, "\tCMP\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+1932
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;					     if ( flag == IFFLAG ) 
   ;	
	cmp	word ptr [bp+6],1
	jne	short @16@1738
   ;	
   ;					     {
   ;					       auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					       fprintf ( output, "\tJNE\t_%i\n", label );
   ;	
	push	word ptr DGROUP:_label
	mov	ax,offset DGROUP:s@+1945
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                     }
   ;	
	jmp	@16@1822
@16@1738:
   ;	
   ;	                                     else if ( flag == WHILEFLAG )
   ;	
	cmp	word ptr [bp+6],2
	jne	short @16@1794
   ;	
   ;					     {
   ;					       auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					       fprintf ( output, "\tJNE\t_%i\n", label - 1 );
   ;	
	mov	ax,word ptr DGROUP:_label
	dec	ax
	push	ax
	mov	ax,offset DGROUP:s@+1955
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                     }
   ;	
	jmp	@16@1822
@16@1794:
   ;	
   ;	                                     else
   ;					     {
   ;		                               int label1 = ++label,
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-10],ax
   ;	
   ;					           label2 = ++label;
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-12],ax
   ;	
   ;	                                   
   ;					       fprintf ( output, "\tJNE\t_%i\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+1965
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					       findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	si
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;					       fprintf ( output, "\tMOV\t%s, 255\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+1975
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					       fprintf ( output, "\tJMP\t_%i\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+1989
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					       fprintf ( output, "_%i :\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+1999
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					       fprintf ( output, "\tMOV\t%s, 0\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2006
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					       fprintf ( output, "_%i :\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2018
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					       cleanRegister ( regResult );
   ;	
	push	si
	call	near ptr _cleanRegister
	pop	cx
@16@1822:
   ;	
   ;	                                     }
   ;					     break;
   ;	
	jmp	@16@2830
@16@1850:
   ;	
   ;			        case DIFERENT : fprintf ( output, "\tCMP\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+2025
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;					        if ( flag == IFFLAG ) 
   ;	
	cmp	word ptr [bp+6],1
	jne	short @16@1906
   ;	
   ;						{
   ;					          auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					          fprintf ( output, "\tJE\t_%i\n", label );
   ;	
	push	word ptr DGROUP:_label
	mov	ax,offset DGROUP:s@+2038
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                        }
   ;	
	jmp	@16@1990
@16@1906:
   ;	
   ;	                                        else if ( flag == WHILEFLAG )
   ;	
	cmp	word ptr [bp+6],2
	jne	short @16@1962
   ;	
   ;						{
   ;					          auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					          fprintf ( output, "\tJE\t_%i\n", label - 1 );
   ;	
	mov	ax,word ptr DGROUP:_label
	dec	ax
	push	ax
	mov	ax,offset DGROUP:s@+2047
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                        }
   ;	
	jmp	@16@1990
@16@1962:
   ;	
   ;	                                        else
   ;					        {
   ;		                                  int label1 = ++label,
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-10],ax
   ;	
   ;					              label2 = ++label;
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-12],ax
   ;	
   ;	
   ;					          fprintf ( output, "\tJE\t_%i\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2056
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					          findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	si
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;					          fprintf ( output, "\tMOV\t%s, 255\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2065
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					          fprintf ( output, "\tJMP\t_%i\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2079
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					          fprintf ( output, "_%i :\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2089
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					          fprintf ( output, "\tMOV\t%s, 0\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2096
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					          fprintf ( output, "_%i :\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2108
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;						  cleanRegister ( regResult );
   ;	
	push	si
	call	near ptr _cleanRegister
	pop	cx
@16@1990:
   ;	
   ;	                                        }
   ;					        break;
   ;	
	jmp	@16@2830
@16@2018:
   ;	
   ;			        case SMALLER : fprintf ( output, "\tCMP\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+2115
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;					       if ( flag == IFFLAG ) 
   ;	
	cmp	word ptr [bp+6],1
	jne	short @16@2074
   ;	
   ;					       {
   ;						 auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					         fprintf ( output, "\tJNL\t_%i\n", label );
   ;	
	push	word ptr DGROUP:_label
	mov	ax,offset DGROUP:s@+2128
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                       }
   ;	
	jmp	@16@2158
@16@2074:
   ;	
   ;	                                       else if ( flag == WHILEFLAG )
   ;	
	cmp	word ptr [bp+6],2
	jne	short @16@2130
   ;	
   ;					       {
   ;						 auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					         fprintf ( output, "\tJNL\t_%i\n", label - 1 );
   ;	
	mov	ax,word ptr DGROUP:_label
	dec	ax
	push	ax
	mov	ax,offset DGROUP:s@+2138
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                       }
   ;	
	jmp	@16@2158
@16@2130:
   ;	
   ;	                                       else
   ;					       {
   ;		                                 int label1 = ++label,
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-10],ax
   ;	
   ;					             label2 = ++label;
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-12],ax
   ;	
   ;	
   ;		  			         fprintf ( output, "\tJNL\t_%i\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2148
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	si
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;					         fprintf ( output, "\tMOV\t%s, 255\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2158
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         fprintf ( output, "\tJMP\t_%i\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2172
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         fprintf ( output, "_%i :\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2182
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         fprintf ( output, "\tMOV\t%s, 0\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2189
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         fprintf ( output, "_%i :\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2201
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;						 cleanRegister ( regResult );
   ;	
	push	si
	call	near ptr _cleanRegister
	pop	cx
@16@2158:
   ;	
   ;	                                       }
   ;					       break;
   ;	
	jmp	@16@2830
@16@2186:
   ;	
   ;			        case GREATER : fprintf ( output, "\tCMP\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+2208
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;					       if ( flag == IFFLAG )
   ;	
	cmp	word ptr [bp+6],1
	jne	short @16@2242
   ;	
   ;					       {
   ;						 auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					         fprintf ( output, "\tJNG\t_%i\n", label );
   ;	
	push	word ptr DGROUP:_label
	mov	ax,offset DGROUP:s@+2221
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                       }
   ;	
	jmp	@16@2326
@16@2242:
   ;	
   ;	                                       else if ( flag == WHILEFLAG )
   ;	
	cmp	word ptr [bp+6],2
	jne	short @16@2298
   ;	
   ;					       {
   ;						 auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					         fprintf ( output, "\tJNG\t_%i\n", label - 1 );
   ;	
	mov	ax,word ptr DGROUP:_label
	dec	ax
	push	ax
	mov	ax,offset DGROUP:s@+2231
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                       }
   ;	
	jmp	@16@2326
@16@2298:
   ;	
   ;	                                       else
   ;					       {
   ;		                                 int label1 = ++label,
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-10],ax
   ;	
   ;					             label2 = ++label;
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-12],ax
   ;	
   ;	
   ;		  			         fprintf ( output, "\tJNG\t_%i\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2241
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	si
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;					         fprintf ( output, "\tMOV\t%s, 255\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2251
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         fprintf ( output, "\tJMP\t_%i\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2265
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         fprintf ( output, "_%i :\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2275
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         fprintf ( output, "\tMOV\t%s, 0\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2282
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					         fprintf ( output, "_%i :\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2294
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;						 cleanRegister ( regResult );
   ;	
	push	si
	call	near ptr _cleanRegister
	pop	cx
@16@2326:
   ;	
   ;	                                       }
   ;					       break;
   ;	
	jmp	@16@2830
@16@2354:
   ;	
   ;			        case SMALLEREQUAL : fprintf ( output, "\tCMP\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+2301
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;					            if ( flag == IFFLAG ) 
   ;	
	cmp	word ptr [bp+6],1
	jne	short @16@2410
   ;	
   ;						    {
   ;						      auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					              fprintf ( output, "\tJNLE\t_%i\n", label );
   ;	
	push	word ptr DGROUP:_label
	mov	ax,offset DGROUP:s@+2314
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                            }
   ;	
	jmp	@16@2494
@16@2410:
   ;	
   ;	                                            else if ( flag == WHILEFLAG )
   ;	
	cmp	word ptr [bp+6],2
	jne	short @16@2466
   ;	
   ;						    {
   ;						      auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					              fprintf ( output, "\tJNLE\t_%i\n", label - 1 );
   ;	
	mov	ax,word ptr DGROUP:_label
	dec	ax
	push	ax
	mov	ax,offset DGROUP:s@+2325
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                            }
   ;	
	jmp	@16@2494
@16@2466:
   ;	
   ;	                                            else
   ;					            {
   ;		                                      int label1 = ++label,
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-10],ax
   ;	
   ;					                  label2 = ++label;
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-12],ax
   ;	
   ;	
   ;					              fprintf ( output, "\tJNLE\t_%i\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2336
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	si
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;					              fprintf ( output, "\tMOV\t%s, 255\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2347
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              fprintf ( output, "\tJMP\t_%i\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2361
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              fprintf ( output, "_%i :\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2371
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              fprintf ( output, "\tMOV\t%s, 0\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2378
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              fprintf ( output, "_%i :\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2390
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;						      cleanRegister ( regResult );
   ;	
	push	si
	call	near ptr _cleanRegister
	pop	cx
@16@2494:
   ;	
   ;	                                            }
   ;						    break;
   ;	
	jmp	@16@2830
@16@2522:
   ;	
   ;			        case GREATEREQUAL : fprintf ( output, "\tCMP\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+2397
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
   ;	
   ;					            if ( flag == IFFLAG ) 
   ;	
	cmp	word ptr [bp+6],1
	jne	short @16@2578
   ;	
   ;						    {
   ;						      auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					              fprintf ( output, "\tJNGE\t_%i\n", label );
   ;	
	push	word ptr DGROUP:_label
	mov	ax,offset DGROUP:s@+2410
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                            }
   ;	
	jmp	@16@2662
@16@2578:
   ;	
   ;	                                            else if ( flag == WHILEFLAG )
   ;	
	cmp	word ptr [bp+6],2
	jne	short @16@2634
   ;	
   ;						    {
   ;						      auxFlag = 1;
   ;	
	mov	word ptr [bp-2],1
   ;	
   ;					              fprintf ( output, "\tJNGE\t_%i\n", label - 1 );
   ;	
	mov	ax,word ptr DGROUP:_label
	dec	ax
	push	ax
	mov	ax,offset DGROUP:s@+2421
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;	                                            }
   ;	
	jmp	@16@2662
@16@2634:
   ;	
   ;	                                            else
   ;				    	            {
   ;		                                      int label1 = ++label,
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-10],ax
   ;	
   ;					                  label2 = ++label;
   ;	
	inc	word ptr DGROUP:_label
	mov	ax,word ptr DGROUP:_label
	mov	word ptr [bp-12],ax
   ;	
   ;	
   ;					              fprintf ( output, "\tJNGE\t_%i\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2432
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              findRegister ( NULL, ANYTHING, regResult );
   ;	
	push	si
	mov	ax,255
	push	ax
	xor	ax,ax
	push	ax
	call	near ptr _findRegister
	add	sp,6
   ;	
   ;					              fprintf ( output, "\tMOV\t%s, 255\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2443
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              fprintf ( output, "\tJMP\t_%i\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2457
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              fprintf ( output, "_%i :\n", label1 );
   ;	
	push	word ptr [bp-10]
	mov	ax,offset DGROUP:s@+2467
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              fprintf ( output, "\tMOV\t%s, 0\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2474
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;					              fprintf ( output, "_%i :\n", label2 );
   ;	
	push	word ptr [bp-12]
	mov	ax,offset DGROUP:s@+2486
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
   ;	
   ;						      cleanRegister ( regResult );
   ;	
	push	si
	call	near ptr _cleanRegister
	pop	cx
@16@2662:
   ;	
   ;	                                            }
   ;						    break;
   ;	
	jmp	short @16@2830
@16@2690:
   ;	
   ;	                        case AND : fprintf ( output, "\tAND\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+2493
@16@2718:
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,8
	jmp	short @16@2802
@16@2746:
   ;	
   ;				           regResult = reg1;
   ;				           break;
   ;			        case OR : fprintf ( output, "\tOR\t%s, %s\n", reg1, reg2 );
   ;	
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+2506
	jmp	short @16@2718
@16@2774:
   ;	
   ;				          regResult = reg1;
   ;				          break;
   ;			        case NOT : fprintf ( output, "\tNOT\t%s\n", reg1 );
   ;	
	push	word ptr [bp-6]
	mov	ax,offset DGROUP:s@+2518
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
@16@2802:
   ;	
   ;				           regResult = reg1;
   ;	
	mov	si,word ptr [bp-6]
   ;	
   ;				           break;
   ;	
	jmp	short @16@2830
@16@2830:
   ;	
   ;			      }
   ;	
   ;		            }
   ;	  }
   ;	  if ( !auxFlag ) 
   ;	
	cmp	word ptr [bp-2],0
	jne	short @16@2886
   ;	
   ;	    fprintf ( output, "\tPUSH\t%s\n", regResult );
   ;	
	push	si
	mov	ax,offset DGROUP:s@+2527
	push	ax
	push	word ptr DGROUP:output
	call	near ptr _fprintf
	add	sp,6
@16@2886:
   ;	
   ;	  if (( node -> name != VARNAME ) && ( node -> name != FIELDS ) && ( !auxFlag ) && ( node -> name != INTEGERNODE ) && ( node -> 
   ;	
	cmp	word ptr [di],1
	je	short @16@3082
	cmp	word ptr [di],32
	je	short @16@3082
	cmp	word ptr [bp-2],0
	jne	short @16@3082
	cmp	word ptr [di],3
	je	short @16@3082
	cmp	word ptr [di],4
	je	short @16@3082
	cmp	word ptr [di],5
	je	short @16@3082
   ;	
   ;	    cleanRegister ( regResult );
   ;	
	push	si
	call	near ptr _cleanRegister
	pop	cx
@16@3082:
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_generateAssemblyForSubexpression	endp
@16@C3042	label	word
	dw	@16@1682
	dw	@16@1850
	dw	@16@2018
	dw	@16@2186
	dw	@16@2354
	dw	@16@2522
	dw	@16@2690
	dw	@16@2746
	dw	@16@2774
@16@C2994	label	word
	dw	@16@1318
	dw	@16@1402
	dw	@16@1430
	dw	@16@1458
	dw	@16@1486
@16@C2786	label	word
	db	1
	db	0
	db	3
	db	0
	db	4
	db	0
	db	5
	db	0
	db	6
	db	0
	db	7
	db	0
	db	28
	db	0
	db	32
	db	0
	dw	@16@226
	dw	@16@702
	dw	@16@730
	dw	@16@786
	dw	@16@1570
	dw	@16@926
	dw	@16@674
	dw	@16@394
_TEXT	ends
_BSS	segment word public 'BSS'
output	label	word
	db	2 dup (?)
	?debug	C E9
	?debug	C FA00000000
_BSS	ends
_DATA	segment word public 'DATA'
s@	label	byte
	db	'w'
	db	0
	db	'code'
	db	9
	db	'SEGMENT word public '
	db	39
	db	'code'
	db	39
	db	10
	db	0
	db	9
	db	'ASSUME'
	db	9
	db	'CS:code,DS:data,SS:activations'
	db	10
	db	10
	db	0
	db	'START:'
	db	9
	db	'MOV'
	db	9
	db	'AX,activations'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'SS,AX'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'AX,access'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DS,AX'
	db	10
	db	0
	db	9
	db	'LEA'
	db	9
	db	'SP,TOP'
	db	10
	db	0
	db	9
	db	'CALL'
	db	9
	db	'main'
	db	10
	db	10
	db	0
	db	10
	db	'MOVE'
	db	9
	db	'PROC'
	db	9
	db	'NEAR'
	db	10
	db	0
	db	'MOVING:'
	db	10
	db	9
	db	'MOV'
	db	9
	db	'AL,[SI]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'[DI],AL'
	db	10
	db	0
	db	9
	db	'INC'
	db	9
	db	'SI'
	db	10
	db	0
	db	9
	db	'INC'
	db	9
	db	'DI'
	db	10
	db	0
	db	9
	db	'LOOP'
	db	9
	db	'MOVING'
	db	10
	db	0
	db	9
	db	'ENDP'
	db	9
	db	'MOVE'
	db	10
	db	10
	db	0
	db	'code'
	db	9
	db	'ENDS'
	db	10
	db	10
	db	0
	db	9
	db	'extrn'
	db	9
	db	'writeInteger:near'
	db	10
	db	0
	db	9
	db	'extrn'
	db	9
	db	'writeBoolean:near'
	db	10
	db	0
	db	9
	db	'extrn'
	db	9
	db	'writeChar:near'
	db	10
	db	0
	db	9
	db	'extrn'
	db	9
	db	'writeString:near'
	db	10
	db	0
	db	9
	db	'extrn'
	db	9
	db	'writeNewline:near'
	db	10
	db	0
	db	9
	db	'extrn'
	db	9
	db	'readChar:near'
	db	10
	db	0
	db	9
	db	'extrn'
	db	9
	db	'readBoolean:near'
	db	10
	db	0
	db	9
	db	'extrn'
	db	9
	db	'readInteger:near'
	db	10
	db	0
	db	9
	db	'END'
	db	9
	db	'START'
	db	10
	db	10
	db	0
	db	'activations'
	db	9
	db	'SEGMENT STACK '
	db	39
	db	'STACK'
	db	39
	db	10
	db	0
	db	9
	db	'DB'
	db	9
	db	'1024'
	db	9
	db	'DUP(?)'
	db	10
	db	0
	db	'TOP'
	db	9
	db	'LABEL'
	db	9
	db	'WORD'
	db	10
	db	0
	db	'activations'
	db	9
	db	'ENDS'
	db	10
	db	10
	db	0
	db	'data'
	db	9
	db	'SEGMENT word public '
	db	39
	db	'data'
	db	39
	db	10
	db	0
	db	'access'
	db	9
	db	'DW'
	db	9
	db	'%i'
	db	9
	db	'DUP(?)'
	db	10
	db	0
	db	'data'
	db	9
	db	'ENDS'
	db	10
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'%i'
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'0'
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'CALL'
	db	9
	db	'writeInteger'
	db	10
	db	0
	db	9
	db	'POP'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'POP'
	db	9
	db	'%s'
	db	10
	db	0
	db	'%s'
	db	9
	db	'PROC'
	db	9
	db	'NEAR'
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'BP'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s,access[%i]'
	db	10
	db	9
	db	'PUSH'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'BP,SP'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'access[%i],BP'
	db	10
	db	0
	db	9
	db	'SUB'
	db	9
	db	'SP,%i'
	db	10
	db	0
	db	9
	db	'POP'
	db	9
	db	'AX'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'SP,BP'
	db	10
	db	0
	db	9
	db	'POP'
	db	9
	db	'%s'
	db	10
	db	9
	db	'MOV'
	db	9
	db	'access[%i],%s'
	db	10
	db	0
	db	9
	db	'POP'
	db	9
	db	'BP'
	db	10
	db	0
	db	'main'
	db	0
	db	9
	db	'MOV'
	db	9
	db	'AH,4Ch'
	db	10
	db	0
	db	9
	db	'INT'
	db	9
	db	'21h'
	db	10
	db	0
	db	9
	db	'RET'
	db	10
	db	0
	db	9
	db	'ENDP'
	db	9
	db	'%s'
	db	10
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s,WORD PTR [BP + %i]'
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'LEA'
	db	9
	db	'%s,WORD PTR [BP + %i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI,access[%i]'
	db	10
	db	0
	db	9
	db	'LEA'
	db	9
	db	'%s,SS:[DI + %i]'
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'XOR'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'BX,DS'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DS,SS'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'ES,SS'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'SI,%s'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI,SP'
	db	10
	db	0
	db	9
	db	'SUB'
	db	9
	db	'SP,%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'CX,%i'
	db	10
	db	0
	db	9
	db	'CALL'
	db	9
	db	'MOVE'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DS,BX'
	db	10
	db	0
	db	9
	db	'CALL'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'ADD'
	db	9
	db	'SP,%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'BX,DS'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DS,SS'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'ES,SS'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'SI,[%s]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI,access[%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI,SS:[DI+%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'CX,%i'
	db	10
	db	0
	db	9
	db	'CALL'
	db	9
	db	'MOVE'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DS,BX'
	db	10
	db	0
	db	9
	db	'JMP'
	db	9
	db	'_%i'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'JMP'
	db	9
	db	'_%i'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'[BP+%i], %s'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'[BP%i], %s'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI, access[%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'SS:[DI+%i], %s'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'SS:[DI%i], %s'
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, BP+%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, BP%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI, access[%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, DI+%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, DI%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, [BP+%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, [BP%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI, access[%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, SS:[DI+%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, SS:[DI%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI, [BP+%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI, [BP%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI, access[%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI, SS:[DI+%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'DI, SS:[DI%i]'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, DI'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, SS:[DI]'
	db	10
	db	0
	db	9
	db	'POP'
	db	9
	db	'%s'
	db	10
	db	0
	db	'AX'
	db	0
	db	'%i'
	db	0
	db	'%i'
	db	0
	db	'255'
	db	0
	db	'0'
	db	0
	db	9
	db	'POP'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'POP'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'ADD'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'SUB'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'IMUL'
	db	9
	db	'%s'
	db	10
	db	0
	db	'AX'
	db	0
	db	'AX'
	db	0
	db	'DX'
	db	0
	db	9
	db	'CWD'
	db	10
	db	0
	db	9
	db	'IDIV'
	db	9
	db	'%s'
	db	10
	db	0
	db	'AX'
	db	0
	db	'AX'
	db	0
	db	9
	db	'CWD'
	db	10
	db	0
	db	9
	db	'IDIV'
	db	9
	db	'%s'
	db	10
	db	0
	db	'DX'
	db	0
	db	'AX'
	db	0
	db	9
	db	'POP'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'POP'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'CMP'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'JNE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 255'
	db	10
	db	0
	db	9
	db	'JMP'
	db	9
	db	'_%i'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 0'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'CMP'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'JE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 255'
	db	10
	db	0
	db	9
	db	'JMP'
	db	9
	db	'_%i'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 0'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'CMP'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'JNL'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNL'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNL'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 255'
	db	10
	db	0
	db	9
	db	'JMP'
	db	9
	db	'_%i'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 0'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'CMP'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'JNG'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNG'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNG'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 255'
	db	10
	db	0
	db	9
	db	'JMP'
	db	9
	db	'_%i'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 0'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'CMP'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'JNLE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNLE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNLE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 255'
	db	10
	db	0
	db	9
	db	'JMP'
	db	9
	db	'_%i'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 0'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'CMP'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'JNGE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNGE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'JNGE'
	db	9
	db	'_%i'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 255'
	db	10
	db	0
	db	9
	db	'JMP'
	db	9
	db	'_%i'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'MOV'
	db	9
	db	'%s, 0'
	db	10
	db	0
	db	'_%i :'
	db	10
	db	0
	db	9
	db	'AND'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'OR'
	db	9
	db	'%s, %s'
	db	10
	db	0
	db	9
	db	'NOT'
	db	9
	db	'%s'
	db	10
	db	0
	db	9
	db	'PUSH'
	db	9
	db	'%s'
	db	10
	db	0
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	extrn	_inRegister:near
	extrn	_giveRegisterCode:near
	extrn	_close:near
	public	_label
	extrn	_depth:word
	extrn	_maxDepth:word
_output	equ	output
	public	_generateAssemblyStack
	public	_generateAssemblyForSubexpression
	public	_generateAssemblyForExpression
	public	_generateAssemblyForVarByref
	public	_generateAssemblyForVariable
	public	_generateAssemblyForAssignment
	public	_generateAssemblyForWhile
	public	_generateAssemblyForIf
	public	_generateRecordCopy
	public	_generateAssemblyForProccallFuncc
	public	_generateAssemblyForProcnodeFuncn
	public	_getLocalDataSizeAndCalcOffsets
	public	_generateAssembly
	public	_generateAssemblyDisplay
	public	_generateAssemblyForPrint
	public	_generateAssemblyCode
	extrn	_cleanRegisters:near
	extrn	_cleanRegister:near
	extrn	_findRegister:near
	extrn	_procTable:word
	extrn	_getSubprogramNarg:near
	extrn	_getSubprogramArgs:near
	extrn	_getParameterByref:near
	extrn	_getParameterParam:near
	extrn	_getTypeSize:near
	extrn	_getSymbolNext:near
	extrn	_getSymbolMore:near
	extrn	_setSymbolOffs:near
	extrn	_getSymbolOffs:near
	extrn	_getSymbolByref:near
	extrn	_getSymbolParam:near
	extrn	_getSymbolDepth:near
	extrn	_getSymbolType:near
	extrn	_getSymbolProc:near
	extrn	_getSymbolName:near
	extrn	_updateOffset:near
	extrn	_strcpy:near
	extrn	_strcmp:near
	extrn	_malloc:near
	extrn	_free:near
	extrn	_sprintf:near
	extrn	_fprintf:near
	extrn	_fopen:near
_s@	equ	s@
	end
