#include <stdio.h>
#include <stdlib.h>

void main()
 {
    void *brk;

    brk = sbrk( 0x0000 );
    printf( "Old break value %p\n", brk );
    brk = sbrk( -0x0100 );
    printf( "Old break value %p\n", brk );
    brk = sbrk( 0x0000 );
    printf( "New break value %p\n", brk );
 }
