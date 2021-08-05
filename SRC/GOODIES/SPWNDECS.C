/*
    SPWNDECS.C - Will be spawned by the SPWNRECS program.

    Compile & Link: wcl386 /l=ergo spwndecs
 */
#include <stdio.h>
#include <stdlib.h>

void main()
{
    puts( "\nApplication #2 spawned\n" );
    /* Exit with error code 59 */
    exit( 59 );
}
