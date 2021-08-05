/*
 * This example clears the screen on DOS
 */
#include <dos.h>

void main()
  {
    union REGS	regs;

    regs.w.cx = 0;
    regs.w.dx = 0x1850;
    regs.h.bh = 7;
    regs.w.ax = 0x0600;
#ifdef __386__
    int386( 0x10, &regs, &regs );
#else
    int86( 0x10, &regs, &regs );
#endif
  }
