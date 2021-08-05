;**
;** bimo.asm:
;** Assembler code for real-mode and protected-mode
;** INT 0xC interrupt handlers to support the INT 0xC
;** interrupt in both modes
;**
.386
;**
;** The real-mode interrupt handler is in a 16-bit code
;** segment so that the assembler will generate the right
;** code.  We will copy this code down to a 16-bit segment
;** in low memory rather than executing it in place.
;**

_TEXT16 SEGMENT BYTE PUBLIC USE16 'CODE'
    ASSUME  cs:_TEXT16

    PUBLIC  rmhandler_
rmhandler_:
    push    es
    push    bx
    mov     bx,0B800h
    mov     es,bx		    ; ES = 0xB800
    sub     bx,bx		    ; BX = 0
    mov     WORD PTR es:[bx],0720h  ; Clear 2 char cells
    mov     WORD PTR es:[bx+2],0720h
    mov     BYTE PTR es:[bx],'R'    ; Write R to memory
    pop     bx
    pop     es
    push    ax
    push    dx
    mov     dx,03FAh
    in	    al,dx		    ; Read ports so
    mov     dx,03F8h		    ; interrupts can
    in	    al,dx		    ; continue to be
    mov     dx,020h		    ; generated
    mov     al,dl
    out     dx,al		    ; Send EOI
    pop     dx
    pop     ax
    iret
_TEXT16 ENDS
;**
;** The protected-mode interrupt handler is in a 32-bit code
;** segment.  Even so, we have to be sure to force an IRETD
;** at the end of the handler, because MASM doesn't generate
;** one.  This handler will be called on a 32-bit stack by
;** DOS/4GW.
;**
;** _DATA is the flat model data segment, which we load into
;** ES so we can write to absolute address 0xB8000.  (In the
;** flat model, DS is based at 0.)
;**
_DATA	SEGMENT BYTE PUBLIC USE32 'DATA'
_DATA	ENDS

DGROUP GROUP _DATA

_TEXT	SEGMENT BYTE PUBLIC USE32 'CODE'
    ASSUME  cs:_TEXT

    PUBLIC  com1_init_
com1_init_:
    mov     ax,0F3h		    ; 9600,n,8,1
    mov     dx,0		    ; com1
    int     14h 		    ; Initialize COM1
    mov     bx,03F8h		    ; COM1 port space
    lea     dx,[bx+5]		    ; line status reg
    in	    al,dx
    lea     dx,[bx+4]		    ; modem control reg
    in	    al,dx
    or	    al,8		    ; enable OUT2 int
    out     dx,al
    lea     dx,[bx+2]		    ; int id register
    in	    al,dx
    mov     dx,bx		    ; data receive reg
    in	    al,dx
    in	    al,21h		    ; interrupt mask reg
    and     al,0EFh		    ; force IRQ4 unmask
    out     21h,al
    lea     dx,[bx+1]		    ; int enable reg
    mov     al,1
    out     dx,al		    ; enable received int
    ret

    PUBLIC  pmhandler_
pmhandler_:
    push    es
    push    bx
    mov     bx,DGROUP
    mov     es,bx
    mov     ebx,0B8000h 	    ; ES:EBX=flat:0B8000h
    mov     DWORD PTR es:[ebx],07200720h  ; Clear cells
    mov     BYTE PTR es:[ebx+2],'P' ; Write P to memory
    pop     bx
    pop     es
    push    ax
    push    dx
    mov     dx,03FAh
    in	    al,dx		    ; Read ports so
    mov     dx,03F8h		    ; interrupts can
    in	    al,dx		    ; continue to be
    mov     dx,020h		    ; generated
    mov     al,dl
    out     dx,al		    ; Send EOI
    pop     dx
    pop     ax
    iretd
_TEXT	ENDS
    END
