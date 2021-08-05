/*
    BIMODAL.C - The following program demonstrates how
    to set up a bi-modal interrupt handler for DOS/4GW

    Compile and link: wcl386 /l=dos4g bimodal bimo.obj
*/

#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define D32RealSeg(P)	((((DWORD) (P)) >> 4) & 0xFFFF)
#define D32RealOff(P)	(((DWORD) (P)) & 0xF)

typedef unsigned int WORD;
typedef unsigned long DWORD;

extern void com1_init (void);
extern void __interrupt pmhandler (void);
extern void __interrupt __far rmhandler (void);

void *D32DosMemAlloc (DWORD size)
{
    union REGS r;

    r.x.eax = 0x0100;		/* DPMI allocate DOS memory */
    r.x.ebx = (size + 15) >> 4; /* Number of paragraphs requested */
    int386 (0x31, &r, &r);

    if (r.x.cflag)  /* Failed */
	    return ((DWORD) 0);
    return (void *) ((r.x.eax & 0xFFFF) << 4);
}

void main (void)
{
    union REGS r;
    struct SREGS sr;
    void *lowp;
    void far *fh;
    WORD orig_pm_sel;
    DWORD orig_pm_off;
    WORD orig_rm_seg;
    WORD orig_rm_off;
    int c;

    /* Save the starting protected-mode handler address */
    r.x.eax = 0x350C;	/* DOS get vector (INT 0Ch) */
    sr.ds = sr.es = 0;
    int386x (0x21, &r, &r, &sr);
    orig_pm_sel = (WORD) sr.es;
    orig_pm_off = r.x.ebx;

/*
    Save the starting real-mode handler address using DPMI
    (INT 31h).
*/
    r.x.eax = 0x0200;	/* DPMI get real mode vector */
    r.h.bl = 0x0C;
    int386 (0x31, &r, &r);
    orig_rm_seg = (WORD) r.x.ecx;
    orig_rm_off = (WORD) r.x.edx;

/*
    Allocate 128 bytes of DOS memory for the real-mode
    handler, which must of course be less than 128 bytes
    long.  Then copy the real-mode handler into that
    segment.
*/
    if(! ( lowp = D32DosMemAlloc(128) ) ) {
	printf ("Couldn't get low memory!\n");
	exit (1);
    }
    memcpy (lowp, (void *) rmhandler, 128);

/*
    Install the new protected-mode vector.  Because INT 0Ch
    is in the auto-passup range, its normal "passdown"
    behavior will change as soon as we install a
    protected-mode handler.  After this next call, when a
    real mode INT 0Ch is generated, it will be resignalled
    in protected mode and handled by pmhandler.
*/
    r.x.eax = 0x250C;	/* DOS set vector (INT 0Ch) */
    fh = (void far *) pmhandler;
    r.x.edx = FP_OFF (fh);
    /* DS:EDX == &handler */
    sr.ds = FP_SEG (fh);
    sr.es = 0;
    int386x (0x21, &r, &r, &sr);

/*
    Install the new real-mode vector.  We do this after
    installing the protected-mode vector in order to
    override the "passup" behavior.  After the next call,
    interrupts will be directed to the appropriate handler,
    regardless of which mode we are in when they are
    generated.
*/
    r.x.eax = 0x0201;
    r.h.bl = 0x0C;
    /* CX:DX == real mode &handler */
    r.x.ecx = D32RealSeg(lowp);
    r.x.edx = D32RealOff(lowp);
    int386 (0x31, &r, &r);

/*
    Initialize COM1.
*/
    com1_init ();

    puts( "Move mouse, transmit data; ESC to quit\n" );

    while( 1 ) {
	if( kbhit() ) {
	    if( ( (c = getch ()) & 0xff ) == 27 )
		    break;
	    putch (c);
	}
    delay( 1 );
    }

/*
    Clean up.
*/
    r.x.eax = 0x250C;	/* DOS set vector (INT 0Ch) */
    r.x.edx = orig_pm_off;
    sr.ds = orig_pm_sel;    /* DS:EDX == &handler */
    sr.es = 0;
    int386x (0x21, &r, &r, &sr);

    r.x.eax = 0x0201;	/* DPMI set real mode vector */
    r.h.bl = 0x0C;
    /* CX:DX == real mode &handler */
    r.x.ecx = (DWORD) orig_rm_seg;
    r.x.edx = (DWORD) orig_rm_off;
    int386 (0x31, &r, &r);
}
