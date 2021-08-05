/*
    MOUSE.C - The following program demonstrates how
    to use the mouse interrupt (0x33) with DOS/4GW.

    Compile and link: wcl386 /l=dos4g mouse
*/
#include <stdio.h>
#include <dos.h>
#include <i86.h>

int right_button = 0;
int mouse_event = 0;
int mouse_code = 0;
int mouse_cx = 0;
int mouse_dx = 0;

/* Set up data buffer for mouse cursor bitmap */
unsigned short cursor[] =
{
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000,
    0x0001, 0x0200, 0x0000, 0x0000
};

#pragma off (check_stack)
void _loadds far click_handler (int max, int mcx, int mdx)
{
#pragma aux click_handler parm [EAX] [ECX] [EDX]
	mouse_event = 1;
	mouse_code = max;
	mouse_cx = mcx;
	mouse_dx = mdx;
	if( mouse_code & 8 ) right_button = 1;
}
#pragma on (check_stack)

void main( void )
{
    struct SREGS sregs;
    union REGS inregs, outregs;
    int installed = 0;
    int orig_mode = 0;
    int far *ptr;
    int (far *function_ptr)();

    segread(&sregs);

    /* get original video mode */

    inregs.w.ax = 0x0f00;
    int386( 0x10, &inregs, &outregs );

    printf( "Current Mode = %u\n",
	    orig_mode=outregs.h.al );

    /* check for mouse driver */

    inregs.w.ax = 0;
    int386 (0x33, &inregs, &outregs);
    if( installed = (outregs.w.ax == -1) )
	printf( "Mouse installed...\n" );
    else
	printf( "Mouse NOT installed...\n" );

    if( installed ) {

	/* goto graphics mode */

	inregs.h.ah = 0x00;
	inregs.h.al = 0x4;
	int386( 0x10, &inregs, &outregs );

	/* show mouse cursor */

	inregs.w.ax = 0x1;
	int386( 0x33, &inregs, &outregs );

	/* set mouse cursor form */

	inregs.w.ax = 0x9;
	inregs.w.bx = 0x0;
	inregs.w.cx = 0x0;
	ptr = cursor;
	inregs.x.edx = FP_OFF( ptr );
	sregs.es     = FP_SEG( ptr );
	int386x( 0x33, &inregs, &outregs, &sregs );

	/* install click watcher */

	inregs.w.ax = 0xC;
	inregs.w.cx = 0x0002 + 0x0008;
	function_ptr = click_handler;
	inregs.x.edx = FP_OFF( function_ptr );
	sregs.es     = FP_SEG( function_ptr );
	int386x( 0x33, &inregs, &outregs, &sregs );

	while( !right_button ) {
	    if( mouse_event ) {
		printf( "Event = %x : CX = %u DX = %u\n",
			 mouse_code, mouse_cx, mouse_dx );
		mouse_event = 0;
	    }
	}
    }

    /* check installation again (to clear watcher) */

    inregs.w.ax = 0;
    int386( 0x33, &inregs, &outregs );
    if( outregs.w.ax == -1 )
	printf( "DONE : Mouse still installed...\n" );
    else
	printf( "DONE : Mouse NOT installed...\n" );

    inregs.h.ah = 0x00;
    inregs.h.al = orig_mode;
    int386( 0x10, &inregs, &outregs );
}
