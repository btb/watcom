

     
     
     
     
     
     
     

   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
;%  Copyright (C) 1988-1993 by WATCOM International Corp. All	%
;%  rights reserved. No part of this software may be reproduced %
;%  in any form or by any means - graphic, electronic or	%
;%  mechanical, including photocopying, recording, taping	%
;%  or information storage and retrieval systems - except	%
;%  with the written permission of WATCOM International Corp.	%
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
;
; startup code for WATCOM C/C++32 Version 9.5
;
;	This must be assembled using the following command:
;		386asm cstart -twocase
;	To create startup code for Ergo's DPMI DOS extender
;		386asm cstart -twocase -define ERGO_DPMI
;
;   NOTE: All C library data should be defined in CRWDATA.ASM -- That way
;	  it's also available to ADS applications (who use ADSSTART.ASM).
;
	name	cstart

.387
.386p
	assume	nothing

	extrn	__CMain 	: near
	extrn	__InitRtns	: near
	extrn	__FiniRtns	: near
	extrn	__DOSseg__	: near
ifdef ERGO_DPMI
	extrn	_InitAPIExtensions : near
endif

	extrn	_edata		: byte		; end of DATA (start of BSS)
	extrn	_end		: byte		; end of BSS (start of STACK)

	extrn	 _dynend	: dword
	extrn	 _curbrk	: dword
	extrn	 _psp		: word
	extrn	 _osmajor	: byte
	extrn	 _osminor	: byte
	extrn	 _STACKLOW	: dword
	extrn	 _STACKTOP	: dword
	extrn	 _child 	: dword
	extrn	__no87		: word
	extrn	 _Extender	: byte
	extrn	 _Envptr	: dword
	extrn	 _Envseg	: word
	extrn	__FPE_handler	: dword
	extrn  ___FPE_handler	: dword
	extrn	 _LpCmdLine	: dword
	extrn	 _LpPgmName	: dword

DGROUP group _NULL,_AFTERNULL,CONST,_DATA,DATA,XIB,XI,XIE,YIB,YI,YIE,_BSS,STACK

; this guarantees that no function pointer will equal NULL
; (WLINK will keep segment 'BEGTEXT' in front)
; This segment must be at least 4 bytes in size to avoid confusing the
; signal function.

BEGTEXT  segment use32 para public 'CODE'
	assume	cs:BEGTEXT
forever	label	near
	int	3h
	jmp	short forever
___begtext label byte
	nop	;3
	nop	;4
	nop	;5
	nop	;6
	nop	;7
	nop	;8
	nop	;9
	nop	;A
	nop	;B
	nop	;C
	nop	;D
	nop	;E
	nop	;F
	public ___begtext
	assume	cs:nothing
BEGTEXT  ends

_TEXT	segment use32 dword public 'CODE'

	assume	ds:DGROUP

_NULL	segment para public 'BEGDATA'
__nullarea label word
	db	01h,01h,01h,00h
	public	__nullarea
_NULL	ends

_AFTERNULL segment word public 'BEGDATA'
_AFTERNULL ends

CONST	segment word public 'DATA'
CONST	ends

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


_DATA	 segment dword public 'DATA'
X_ERGO		equ	0
X_RATIONAL	equ	1
X_PHARLAP_V2	equ	2
X_PHARLAP_V3	equ	3
X_PHARLAP_V4	equ	4
X_PHARLAP_V5	equ	5
X_INTEL 	equ	9
__GDAptr   dd 0 		; IGC and Intel Code Builder GDA address
__D16Infoseg   dw	0020h	; DOS/4G kernel segment
__x386_zero_base_selector dw 0	; base 0 selector for X-32VM

	public	__GDAptr
	public	__D16Infoseg
	public	__x386_zero_base_selector
ifdef ERGO_DPMI
__MEMHandle	dd	0	; handle for linear base of image
	public	__MEMHandle
endif
_DATA	 ends


DATA	segment word public 'DATA'
DATA	ends

_BSS	      segment word public 'BSS'
_BSS	      ends

STACK_SIZE	equ	1000h

STACK	segment para stack 'STACK'
	db	(STACK_SIZE) dup(?)
STACK	ends


	assume	nothing
	public	_cstart_
	public	 __exit

	assume	cs:_TEXT

_cstart_ proc near
	jmp	short around

;
; copyright message
;
	db	"WATCOM C/C++32 Run-Time system. "
        db      "(c) Copyright by WATCOM International Corp. 1988-1993."
	db	" All rights reserved."
	align	4
	dd	___begtext	; make sure dead code elimination
				; doesn't kill BEGTEXT
__saved_DS  dw	0		; save area for DS for interrupt routines
;
; miscellaneous code-segment messages
;
ConsoleName	db	"con",00h

around: sti				; enable interrupts

	assume	ds:DGROUP

PSP_SEG equ	24h
ENV_SEG equ	2ch

	and	esp,0fffffffch		; make sure stack is on a 4 byte bdry
	mov	ebx,esp 		; get sp
	mov	 _STACKTOP,ebx		; set stack top
	mov	 _curbrk,ebx		; set first available memory location
ifdef ERGO_DPMI
	mov	ax,es			; get segment address of PSP
	mov	 _psp,ax		; save segment address of PSP
	mov	__MEMHandle,esi		;
	call	_InitAPIExtensions	;
	mov	al,X_ERGO		; indicate Ergo DOS Extender
	mov	bx,ds			; force bx = DGROUP
	sub	esi,esi 		; offset 0 for environment strings
	mov	cx,es:[02Ch]		; get segment for environment strings
	mov	edi,81H 		; DOS command buffer _psp:edi
else
	mov	ax,PSP_SEG		; get segment address of PSP
	mov	 _psp,ax		; save segment address of PSP
;
;	get DOS & Extender version number
;
	mov	ebx,'PHAR'		; set ebx to "PHAR"
	sub	eax,eax 		; set eax to 0
	mov	ah,30h
	int	21h			; modifies eax,ebx,ecx,edx
	mov	 _osmajor,al
	mov	 _osminor,ah
	mov	ecx,eax 		; remember DOS version number
	sub	esi,esi 		; offset 0 for environment strings
	mov	edi,81H 		; DOS command buffer es:edi
	shr	eax,16			; get top 16 bits of eax
	cmp	ax,'DX' 		; if top 16 bits = "DX"
	jne	not_pharlap		; then its pharlap
	sub	bl,'0'			; - save major version number
	mov	al,bl			; - (was in ascii)
;+
;	following code added to support TNT Dos extender v6.0
;
	push	eax			; - save version number
	mov	es, _psp		; - point to PSP
	mov	ebx,es:[5Ch]		; - get highest addr used
	add	ebx,000000FFFh		; - round up to 4K boundary
	and	ebx,0FFFFF000h		; - ...
	mov	 _curbrk,ebx		; - set first available memory locn
	shr	ebx,12			; - calc. # of 4k pages
	mov	ax,ds			; - set ES=data segment
	mov	es,ax			; - ...
	mov	ah,4Ah			; - shrink block to minimum amount
	int	21h			; - ...
	pop	eax			; - restore version number
;-
	mov	bx,ds			; - get value of Phar Lap data segment
	mov	cx,ENV_SEG		; - PharLap environment segment
	jmp	short know_ext1 	; else
not_pharlap:				; - see if Intel Code Builder
	cmp	ax,'BC' 		; - if Intel Code Builder
	jne	not_Intel		; - ... then
GDA_PSPA equ	16			; - offset into GDA to PSP address
GDA_LDPT equ	28			; - offset into GDA to load address
	mov	__GDAptr,edx		; - save address of GDA
	mov	esi,edx 		; - get address of GDA
	mov	edx,GDA_LDPT[esi]	; - get application load point address
	mov	ebx,esp 		; - calc amount of memory to keep
	sub	ebx,edx 		; - ...
	mov	ah,4Ah			; - resize to minimum memory
	int	21h			; - ...
	mov	bx,ds			; - just use ds (FLAT model)
	mov	 _psp,ds		; - save segment address of PSP
	mov	eax,GDA_PSPA[esi]	; - get address of PSP
	add	edi,eax 		; - add address of PSP
	sub	esi,esi 		; - zero esi
	mov	si,02ch[eax]		; - get environment segment into si
	shl	esi,4			; - convert to flat address
	mov	cx,ds			; - segment to access environment area
	mov	al,X_INTEL		; - indicate Intel Code Builder
know_ext1:jmp	short know_extender	; else
not_Intel:				; -
	mov	dx,78h			; - see if Rational DOS/4G
	mov	ax,0FF00h		; - ...
	int	21h			; - ...
	cmp	al,0			; - ...
	je	short not_DOS4G 	; - quit if not Rational DOS/4G
	mov	ax,gs			; - get segment address of kernel
	cmp	ax,0			; - if not zero
	je	short rat9		; - then
	mov	__D16Infoseg,ax 	; - - remember it
rat9:					; - endif
	mov	al,X_RATIONAL		; - indicate Rational 32-bit Extender
	mov	bx,ds			; - just use ds (FLAT model)
	mov	 _psp,es		; - save segment address of PSP
	mov	cx,es:[02ch]		; - get environment segment into cx
	jmp	short know_extender	; else
not_DOS4G:				; -
	mov	dx,ds			; - save ds
	mov	cx,PSP_SEG		; - get PSP segment descriptor
	mov	ds,cx			; - ... into ds
	mov	cx,ds:[02ch]		; - get environment segment into cx
	mov	ds,dx			; - restore ds
	mov	bx,17h			; - get writeable code segment for Ergo
	mov	al,X_ERGO		; - indicate Ergo OS/386
know_extender:				; endif
endif
	mov	 _Extender,al		; record extender type
	mov	es,bx			; get access to code segment
	mov	es:__saved_DS,ds	; save DS value
	mov	 _Envptr,esi		; save address of environment strings
	mov	 _Envseg,cx		; save segment of environment area
	push	esi			; save address of environment strings
;
;	copy command line into bottom of stack
;
	mov	es, _psp		; point to PSP
	mov	edx,offset DGROUP:_end
	add	edx,0FH
	and	dl,0F0H
	sub	ecx,ecx
	mov	cl,es:[edi-1]		; get length of command
	cld				; set direction forward
	mov	al,' '
	rep	scasb
	lea	esi,-1[edi]
	mov	edi,edx
	mov	bx,es
	mov	dx,ds
	mov	ds,bx
	mov	es,dx			; es:edi is destination
	je	noparm
	inc	ecx
	rep	movsb
noparm: sub	al,al
	stosb				; store NULLCHAR
	stosb				; assume no pgm name
	pop	esi			; restore address of environment strings
	dec	edi			; back up pointer 1
	push	edi			; save pointer to pgm name
	push	edx			; save ds(stored in dx)
	mov	ds,es: _Envseg		; get segment addr of environment area
	sub	ebp,ebp 		; assume "no87" env. var. not present
L1:	mov	eax,[esi]		; get first 4 characters
	or	eax,20202020h		; map to lower case
	cmp	eax,'78on'		; check for "no87"
	jne	short L2		; skip if not "no87"
	cmp	byte ptr 4[esi],'='	; make sure next char is "="
	jne	short L2		; no
	inc	ebp			; - indicate "no87" was present
L2:	cmp	byte ptr [esi],0	; end of string ?
	lodsb
	jne	L2			; until end of string
	cmp	byte ptr [esi],0	; end of all strings ?
	jne	L1			; if not, then skip next string
	lodsb
	inc	esi			; point to program name
	inc	esi			; . . .
;
;	copy the program name into bottom of stack
;
L3:	cmp	byte ptr [esi],0	; end of pgm name ?
	movsb				; copy a byte
	jne	L3			; until end of pgm name
	pop	ds			; restore ds
	pop	esi			; restore address of pgm name
	mov	ebx,esp 		; end of stack in data segment

	assume	ds:DGROUP
	mov	__no87,bp		; set state of "no87" enironment var
	mov	 _STACKLOW,edi		; save low address of stack
	mov	 _dynend,ebx		; set top of dynamic memory area

	mov	ecx,offset DGROUP:_end	; end of _BSS segment (start of STACK)
	mov	edi,offset DGROUP:_edata; start of _BSS segment
	sub	ecx,edi 		; calc # of bytes in _BSS segment
	cmp	byte ptr  _Extender,X_RATIONAL	; if not Rational DOS extender
	jne	short zerobss		; then zero whole BSS
	cmp	ecx,1000h		; if size of BSS <= 4K
	jbe	short zerobss		; then just zero it
	mov	ecx,1000h		; only zero first 4K under Rational
					; DOS extender will zero rest of pages
zerobss:mov	dl,cl			; save bottom 2 bits of count in edx
	shr	ecx,2			; calc # of dwords
	sub	eax,eax 		; zero the _BSS segment
	rep	stosd			; ...
	mov	cl,dl			; get bottom 2 bits of count
	and	cl,3			; ...
	rep	stosb			; ...

	mov	eax,offset DGROUP:_end	; cmd buffer pointed at by EAX
	add	eax,0FH
	and	al,0F0H
	mov	 _LpCmdLine,eax		; save command line address
	mov	 _LpPgmName,esi		; save program name address
	call	__InitRtns		; call initializer routines
	sub	ebp,ebp			; ebp=0 indicate end of ebp chain
	call	__CMain
_cstart_ endp

;	don't touch AL in __exit_, it has the return code

 __exit  proc near
ifdef __3S__
	pop	eax			; parm 1 (rc)
endif
	jmp	short	ok

	public	 __exit_with_msg

; must be #pragma aborts
 __exit_with_msg:
ifdef __3S__
	pop	eax			; parm 1 (msg)
	pop	edx			; parm 2 (rc)
endif
; input: EAX - pointer to message to print
;	 EDX - exit code

	push	edx			; save return code
	push	eax			; save address of msg
	mov	edx,offset ConsoleName
	mov	ax,03d01h		; write-only access to screen
	int	021h
	mov	bx,ax			; get file handle
	pop	edx			; restore address of msg
	mov	esi,edx 		; get address of msg
	cld				; make sure direction forward
L4:	lodsb				; get char
	cmp	al,0			; end of string?
	jne	L4			; no
	mov	ecx,esi 		; calc length of string
	sub	ecx,edx 		; . . .
	dec	ecx			; . . .
	mov	ah,040h 		; write out the string
	int	021h			; . . .
	pop	eax			; restore return code
ok:
	push	eax			; save return code
	call	__FiniRtns		; call finializer routines
	pop	eax			; restore return code
	mov	ah,04cH 		; DOS call to exit with return code
	int	021h			; back to DOS
 __exit  endp

	public	__GETDS
	align	4
__GETDS proc	near
	mov	ds,cs:__saved_DS	; load saved DS value
	ret				; return
__GETDS endp

_TEXT	ends

	end	_cstart_
