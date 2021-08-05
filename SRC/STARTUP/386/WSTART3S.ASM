

     
     
     
     
     
     
     

   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
;%  Copyright (C) 1988-1993 by WATCOM International Corp. All	%
;%  rights reserved. No part of this software may be reproduced %
;%  in any form or by any means - graphic, electronic or	%
;%  mechanical, including photocopying, recording, taping	%
;%  or information storage and retrieval systems - except	%
;%  with the written permission of WATCOM International Corp.	%
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
;
; startup code for WATCOM C 386 (Windows Extender) Version 9.5
;
;	This must be assembled using the following command:
;		386asm wstart
;
.387
.386p

DGROUP group CONST,_DATA,DATA,XIB,XI,XIE,YIB,YI,YIE,_BSS,STACK

extrn __DOSseg__:byte

	extrn	WINMAIN : near

FarProc MACRO name
public name
name	label FWORD
	      dd 0
	      dw 0
ENDM

	assume	nothing

	extrn	_edata		: byte		; end of DATA (start of BSS)
	extrn	_end		: byte		; end of BSS (start of STACK)

	extrn	GETMODULEFILENAME : near
	extrn	__InitRtns	: near
	extrn	__FiniRtns	: near
	extrn	 exit		: near

; this guarantees that no function pointer will equal NULL
; (WLINK will keep segment 'BEGTEXT' in front)
; This segment must be at least 4 bytes in size to avoid confusing the
; signal function.

BEGTEXT segment use32 word public 'CODE'
        assume  cs:BEGTEXT
forever: jmp    short forever
___begtext label byte
        nop
        nop
        nop
        nop
	public ___begtext
        assume  cs:nothing
BEGTEXT ends

_TEXT	segment use32 word public 'CODE'

XIB	segment word public 'DATA'
XIB	ends
XI	segment word public 'DATA'
XI	ends
XIE	segment word public 'DATA'
XIE	ends

YIB	segment word public 'DATA'
YIB	ends
YI	segment word public 'DATA'
YI	ends
YIE	segment word public 'DATA'
YIE	ends

_DATA	segment use32 word public 'DATA'

MAX_FILE_NAME	equ	144
TMPSTACK	equ	100h	; location on stack to copy command line
DS16		equ	32	; location for 16-bit ds
;
; these variables must all be kept in order
;
_LocalPtr   dw	0
public _LocalPtr
hInstance  dw  0
hPrevInstance  dw  0
lpCmdLine  dd  0
cmdShow    dw  0
__no87	   dw 0 		; non-zero => "NO87" environment var present

; magical selectors for real memory
public ___A000,___B000,___B800,___C000,___D000,___E000,___F000
___A000 dw	0
___B000 dw	0
___B800 dw	0
___C000 dw	0
___D000 dw	0
___E000 dw	0
___F000 dw	0

; data ptrs
FarProc  _DataSelectorBaseAddr 
FarProc  _DataSelectorSizeAddr 

; proc lists
FarProc AddDLLEntryAddr
FarProc Invoke16BitFunctionAddr
FarProc WINFUNCTION0ADDR
FarProc WINFUNCTION1ADDR
FarProc WINFUNCTION2ADDR
FarProc WINFUNCTION3ADDR
FarProc WINFUNCTION4ADDR
FarProc WINFUNCTION5ADDR
FarProc WINFUNCTION6ADDR
FarProc WINFUNCTION7ADDR
FarProc WINFUNCTION8ADDR
FarProc WINFUNCTION9ADDR
FarProc WINFUNCTION10ADDR
FarProc WINFUNCTION11ADDR
FarProc WINFUNCTION12ADDR
FarProc WINFUNCTION13ADDR
FarProc WINFUNCTION14ADDR
FarProc WINFUNCTION15ADDR
FarProc WINFUNCTION16ADDR
FarProc WINFUNCTION17ADDR
FarProc WINFUNCTION18ADDR
FarProc WINFUNCTION19ADDR
FarProc WINFUNCTION20ADDR
FarProc WINFUNCTION21ADDR
FarProc WINFUNCTION22ADDR
FarProc WINFUNCTION23ADDR
FarProc WINFUNCTION24ADDR
FarProc WINFUNCTION25ADDR
FarProc WINFUNCTION26ADDR
FarProc WINFUNCTION27ADDR
FarProc WINFUNCTION28ADDR
FarProc WINFUNCTION29ADDR
FarProc WINFUNCTION30ADDR
FarProc WINFUNCTION31ADDR
FarProc WINFUNCTION32ADDR
FarProc WINFUNCTION33ADDR
FarProc WINFUNCTION34ADDR
FarProc WINFUNCTION35ADDR
FarProc WINFUNCTION36ADDR
FarProc WINFUNCTION37ADDR
FarProc WINFUNCTION38ADDR
FarProc WINFUNCTION39ADDR
FarProc WINFUNCTION40ADDR
FarProc WINFUNCTION41ADDR
FarProc WINFUNCTION42ADDR
FarProc WINFUNCTION43ADDR
FarProc WINFUNCTION44ADDR
FarProc WINFUNCTION45ADDR
FarProc WINFUNCTION46ADDR
FarProc WINFUNCTION47ADDR
FarProc WINFUNCTION48ADDR
FarProc WINFUNCTION49ADDR
FarProc WINFUNCTION50ADDR
FarProc WINFUNCTION51ADDR
FarProc WINFUNCTION52ADDR
FarProc WINFUNCTION53ADDR
FarProc WINFUNCTION54ADDR
FarProc WINFUNCTION55ADDR
FarProc WINFUNCTION56ADDR
FarProc WINFUNCTION57ADDR
FarProc WINFUNCTION58ADDR
FarProc WINFUNCTION59ADDR
FarProc WINFUNCTION60ADDR
FarProc WINFUNCTION61ADDR
FarProc WINFUNCTION62ADDR
FarProc WINFUNCTION63ADDR
FarProc WINFUNCTION64ADDR
FarProc WINFUNCTION65ADDR
FarProc WINFUNCTION66ADDR
FarProc WINFUNCTION67ADDR
FarProc WINFUNCTION68ADDR
FarProc WINFUNCTION69ADDR
FarProc WINFUNCTION70ADDR
FarProc WINFUNCTION71ADDR
FarProc WINFUNCTION72ADDR
FarProc WINFUNCTION73ADDR
FarProc WINFUNCTION74ADDR
FarProc WINFUNCTION75ADDR
FarProc WINFUNCTION76ADDR
FarProc WINFUNCTION77ADDR
FarProc WINFUNCTION78ADDR
FarProc WINFUNCTION79ADDR
FarProc WINFUNCTION80ADDR
FarProc WINFUNCTION81ADDR
FarProc WINFUNCTION82ADDR
FarProc WINFUNCTION83ADDR
FarProc WINFUNCTION84ADDR
FarProc WINFUNCTION85ADDR
FarProc WINFUNCTION86ADDR
FarProc WINFUNCTION87ADDR
FarProc WINFUNCTION88ADDR
FarProc WINFUNCTION89ADDR
FarProc WINFUNCTION90ADDR
FarProc WINFUNCTION91ADDR
FarProc WINFUNCTION92ADDR
FarProc WINFUNCTION93ADDR
FarProc WINFUNCTION94ADDR
FarProc WINFUNCTION95ADDR
FarProc WINFUNCTION96ADDR
FarProc WINFUNCTION97ADDR
FarProc WINFUNCTION98ADDR
FarProc WINFUNCTION99ADDR
FarProc WINFUNCTION100ADDR
FarProc WINFUNCTION101ADDR
FarProc WINFUNCTION102ADDR
FarProc WINFUNCTION103ADDR
FarProc WINFUNCTION104ADDR
FarProc WINFUNCTION105ADDR
FarProc WINFUNCTION106ADDR
FarProc WINFUNCTION107ADDR
FarProc WINFUNCTION108ADDR
FarProc WINFUNCTION109ADDR
FarProc WINFUNCTION110ADDR
FarProc WINFUNCTION111ADDR
FarProc WINFUNCTION112ADDR
FarProc WINFUNCTION113ADDR
FarProc WINFUNCTION114ADDR
FarProc WINFUNCTION115ADDR
FarProc WINFUNCTION116ADDR
FarProc WINFUNCTION117ADDR
FarProc WINFUNCTION118ADDR
FarProc WINFUNCTION119ADDR
FarProc WINFUNCTION120ADDR
FarProc WINFUNCTION121ADDR
FarProc WINFUNCTION122ADDR
FarProc WINFUNCTION123ADDR
FarProc WINFUNCTION124ADDR
FarProc WINFUNCTION125ADDR
FarProc WINFUNCTION126ADDR
FarProc WINFUNCTION127ADDR
FarProc WINFUNCTION128ADDR
FarProc WINFUNCTION129ADDR
FarProc WINFUNCTION130ADDR
FarProc WINFUNCTION131ADDR
FarProc WINFUNCTION132ADDR
FarProc WINFUNCTION133ADDR
FarProc WINFUNCTION134ADDR
FarProc WINFUNCTION135ADDR
FarProc WINFUNCTION136ADDR
FarProc WINFUNCTION137ADDR
FarProc WINFUNCTION138ADDR
FarProc WINFUNCTION139ADDR
FarProc WINFUNCTION140ADDR
FarProc WINFUNCTION141ADDR
FarProc WINFUNCTION142ADDR
FarProc WINFUNCTION143ADDR
FarProc WINFUNCTION144ADDR
FarProc WINFUNCTION145ADDR
FarProc WINFUNCTION146ADDR
FarProc WINFUNCTION147ADDR
FarProc WINFUNCTION148ADDR
FarProc WINFUNCTION149ADDR
FarProc WINFUNCTION150ADDR
FarProc WINFUNCTION151ADDR
FarProc WINFUNCTION152ADDR
FarProc WINFUNCTION153ADDR
FarProc WINFUNCTION154ADDR
FarProc WINFUNCTION155ADDR
FarProc WINFUNCTION156ADDR
FarProc WINFUNCTION157ADDR
FarProc WINFUNCTION158ADDR
FarProc WINFUNCTION159ADDR
FarProc WINFUNCTION160ADDR
FarProc WINFUNCTION161ADDR
FarProc WINFUNCTION162ADDR
FarProc WINFUNCTION163ADDR
FarProc WINFUNCTION164ADDR
FarProc WINFUNCTION165ADDR
FarProc WINFUNCTION166ADDR
FarProc WINFUNCTION167ADDR
FarProc WINFUNCTION168ADDR
FarProc WINFUNCTION169ADDR
FarProc WINFUNCTION170ADDR
FarProc WINFUNCTION171ADDR
FarProc WINFUNCTION172ADDR
FarProc WINFUNCTION173ADDR
FarProc WINFUNCTION174ADDR
FarProc WINFUNCTION175ADDR
FarProc WINFUNCTION176ADDR
FarProc WINFUNCTION177ADDR
FarProc WINFUNCTION178ADDR
FarProc WINFUNCTION179ADDR
FarProc WINFUNCTION180ADDR
FarProc WINFUNCTION181ADDR
FarProc WINFUNCTION182ADDR
FarProc WINFUNCTION183ADDR
FarProc WINFUNCTION184ADDR
FarProc WINFUNCTION185ADDR
FarProc WINFUNCTION186ADDR
FarProc WINFUNCTION187ADDR
FarProc WINFUNCTION188ADDR
FarProc WINFUNCTION189ADDR
FarProc WINFUNCTION190ADDR
FarProc WINFUNCTION191ADDR
FarProc WINFUNCTION192ADDR
FarProc WINFUNCTION193ADDR
FarProc WINFUNCTION194ADDR
FarProc WINFUNCTION195ADDR
FarProc WINFUNCTION196ADDR
FarProc WINFUNCTION197ADDR
FarProc WINFUNCTION198ADDR
FarProc WINFUNCTION199ADDR
FarProc WINFUNCTION200ADDR
FarProc WINFUNCTION201ADDR
FarProc WINFUNCTION202ADDR
FarProc WINFUNCTION203ADDR
FarProc WINFUNCTION204ADDR
FarProc WINFUNCTION205ADDR
FarProc WINFUNCTION206ADDR
FarProc WINFUNCTION207ADDR
FarProc WINFUNCTION208ADDR
FarProc WINFUNCTION209ADDR
FarProc WINFUNCTION210ADDR
FarProc WINFUNCTION211ADDR
FarProc WINFUNCTION212ADDR
FarProc WINFUNCTION213ADDR
FarProc WINFUNCTION214ADDR
FarProc WINFUNCTION215ADDR
FarProc WINFUNCTION216ADDR
FarProc WINFUNCTION217ADDR
FarProc WINFUNCTION218ADDR
FarProc WINFUNCTION219ADDR
FarProc WINFUNCTION220ADDR
FarProc WINFUNCTION221ADDR
FarProc WINFUNCTION222ADDR
FarProc WINFUNCTION223ADDR
FarProc WINFUNCTION224ADDR
FarProc WINFUNCTION225ADDR
FarProc WINFUNCTION226ADDR
FarProc WINFUNCTION227ADDR
FarProc WINFUNCTION228ADDR
FarProc WINFUNCTION229ADDR
FarProc WINFUNCTION230ADDR
FarProc WINFUNCTION231ADDR
FarProc WINFUNCTION232ADDR
FarProc WINFUNCTION233ADDR
FarProc WINFUNCTION234ADDR
FarProc WINFUNCTION235ADDR
FarProc WINFUNCTION236ADDR
FarProc WINFUNCTION237ADDR
FarProc WINFUNCTION238ADDR
FarProc WINFUNCTION239ADDR
FarProc WINFUNCTION240ADDR
FarProc WINFUNCTION241ADDR
FarProc WINFUNCTION242ADDR
FarProc WINFUNCTION243ADDR
FarProc WINFUNCTION244ADDR
FarProc WINFUNCTION245ADDR
FarProc WINFUNCTION246ADDR
FarProc WINFUNCTION247ADDR
FarProc WINFUNCTION248ADDR
FarProc WINFUNCTION249ADDR
FarProc WINFUNCTION250ADDR
FarProc WINFUNCTION251ADDR
FarProc WINFUNCTION252ADDR
FarProc WINFUNCTION253ADDR
FarProc WINFUNCTION254ADDR
FarProc WINFUNCTION255ADDR
FarProc WINFUNCTION256ADDR
FarProc WINFUNCTION257ADDR
FarProc WINFUNCTION258ADDR
FarProc WINFUNCTION259ADDR

 _LpCmdLine dd 0		; pointer to raw command line
 _LpPgmName dd 0		; pointer to program name (for argv[0])
 _STACKLOW dd 0 		; lowest address in stack
 _STACKTOP dd 0 		; lowest address in stack
__ASTACKSIZ dd 0		; alternate stack size
__ASTACKPTR dd 0		; alternate stack pointer
 _curbrk   dd 0 		; top of usable memory
 _cbyte    dd 0 		; used by getch, getche
 _osmajor  db 4 		; major DOS version number
 _osminor  db 0 		; minor DOS version number
 _Extender db 0 		; 10 => 386 windows
__init_387_emulator db 0	; to prevent emulator from coming in with
				;	-fpi

public  _pid
 _pid	   dw 0
public  _wincmdptr
 _wincmdptr LABEL FWORD
cmd_offset dd 0
cmd_seg    dw 0
filename   db MAX_FILE_NAME dup(0)

 __FPE_handler label dword
___FPE_handler dd __null_FPE_rtn ; FPE handler

	public	 _LpCmdLine
	public	 _LpPgmName
	public	 _STACKLOW
	public	 _STACKTOP
        public  __ASTACKSIZ
        public  __ASTACKPTR
	public	 _curbrk
	public	 _cbyte
	public	 _osmajor
	public	 _osminor
	public	 _Extender
	public	__no87
	public	 __FPE_handler
	public	___FPE_handler
	public	__init_387_emulator

_DATA	ends

STACK	segment para stack 'STACK'
STACK	ends

_BSS	      segment word public 'BSS'
_BSS	      ends

CONST	segment word public 'DATA'
CONST	ends

DATA	segment word public 'DATA'
DATA	ends

	assume	cs:_TEXT
	assume	ds:_DATA
	assume	fs:_DATA
	assume	gs:_DATA
	assume	ss:_DATA

__saved_DS dw 0
public _cstart_
public _wstart_
_cstart_ proc  far
_wstart_:
	dd	offset	hInstance ; loader starts execution 8 bytes past here
	dd	_end
	mov	_LocalPtr,gs
	mov	WORD PTR ds:DS16,gs	; save the data segment at stack bot

	mov	 _STACKTOP,esp
	mov	 _STACKLOW,100h		; 

	; initialize bss
	lea	ecx,DGROUP:_end 	; end of _BSS segment (start of free)
	lea	edi,DGROUP:_edata	; start of _BSS segment
	sub	ecx,edi 		; calc # of bytes in _BSS segment
	xor	eax,eax 		; zero the _BSS segment
	mov	dl,cl			; copy the lower bits of size
	shr	ecx,2			; get number of dwords
	rep	stosd			; copy them
	mov	cl,dl			; get lower bits
	and	cl,3			; get number of bytes left (modulo 4)
	rep	stosb

	; save ds
	lea	ecx,__saved_DS
	mov	ds:[ecx],ds

	; set up heap
	lea	edx,DGROUP:_end 	; start of free
	add	edx,3
	and	edx,not 3
	mov	 _curbrk,edx

	; put command string on the stack
	push	es
	mov	ebx,TMPSTACK
	mov	 _LpCmdLine,ebx		; for use by initargv
	mov	esi,lpCmdLine		; offset + selector
	mov	edx,esi 		; get the
	shr	edx,10h 		;   selector
	cmp	edx,0			; is it zero?
	jne	okcpy			; no, do the copy
	mov	byte ptr ds:[ebx],0	; put a trailing zero
	jmp	short donecpy
okcpy:	mov	es,dx
	mov	ds:cmd_seg,es		; save for later
	movzx	esi,si			;    use by getcmd
	mov	ds:cmd_offset,esi
again:	mov	al,byte ptr es:[esi]
	mov	byte ptr ds:[ebx],al
	cmp	al,0
	je	donecpy
	inc	esi
	inc	ebx
	jmp	short again
donecpy:pop	es

	movzx	eax,hInstance
	push	eax
	mov	edi, offset filename
	mov	 _LpPgmName,edi
	push	edi
	push	MAX_FILE_NAME
	call	GETMODULEFILENAME

	call	__InitRtns		; call initializer routines

;;	 
;;	_ASTACKPTR = (char *)alloca( _ASTACKSIZ ) + _ASTACKSIZ;
	mov	__ASTACKPTR,esp		; save address of alternate stack
	sub	esp,__ASTACKSIZ		; allocate alternate stack for F77

	; push parms for WINMAIN
	mov	ax,hInstance
	mov	 _pid,ax		; save for use by getpid()
	movzx	eax,ax
	push	eax
	mov	ax,hPrevInstance
	movzx	eax,ax
	push	eax
	mov	eax,TMPSTACK
	push	eax
	mov	ax,cmdShow
	movzx	eax,ax
	push	eax

	call	WINMAIN
	jmp	 exit			; exit
ife _MODEL and _BIG_CODE
if _MODEL NE _TINY
	dw	___begtext		; make sure dead code elimination
endif					; doesn't kill BEGTEXT segment
endif
_cstart_ endp


 __exit  proc far
public  __exit
	push	eax			; save return value
	call	__FiniRtns		; call finalizer routines
	pop	eax			; restore return value
	mov	esp, _STACKTOP		; reset stack pointer
	mov	ds,_LocalPtr		; restore ds
	ret
 __exit endp

__null_FPE_rtn proc near
	ret				; return
__null_FPE_rtn endp

public __GETDS
__GETDS proc near
	mov	ds,cs:__saved_DS
	ret
__GETDS endp

_TEXT	ends

	end _cstart_
