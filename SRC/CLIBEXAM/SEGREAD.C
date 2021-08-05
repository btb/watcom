#include <stdio.h>
#include <dos.h>

void main()
  {
    struct SREGS sregs;

    segread( &sregs );
    printf( "Current value of CS is %04X\n", sregs.cs );
  }
