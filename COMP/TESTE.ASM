	ifndef	??version
?debug	macro
	endm
publicdll macro	name
	public	name
	endm
	endif
	?debug	V 300h
	?debug	S "TESTE.C"
	?debug	C E9377F84190754455354452E43
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
_TEXT	segment byte public 'CODE'
   ;	
   ;	 um ( int a, int b )
   ;	
	assume	cs:_TEXT
_um	proc	near
	push	bp
	mov	bp,sp
	mov	dx,word ptr [bp+4]
	mov	bx,word ptr [bp+6]
   ;	
   ;	{
   ;	  a=a+1;
   ;	
	mov	ax,dx
	inc	ax
	mov	dx,ax
   ;	
   ;	  b=b+2;
   ;	
	mov	ax,bx
	add	ax,2
	mov	bx,ax
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_um	endp
   ;	
   ;	main ()
   ;	
	assume	cs:_TEXT
_main	proc	near
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	  um;
   ;	
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_main	endp
	?debug	C E9
	?debug	C FA00000000
_TEXT	ends
_DATA	segment word public 'DATA'
s@	label	byte
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	public	_main
	public	_um
_s@	equ	s@
	end
