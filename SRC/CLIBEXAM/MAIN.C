
#include <stdio.h>

int main( int argc, char *argv[] )
  {
    int i;
    for( i = 0; i < argc; ++i ) {
      printf( "argv[%d] = %s\n", i, argv[i] );
    }
    return( 0 );
  }
//************ Sample program output ************
//argv[0] = C:\WATCOM\DEMO\MYPGM.EXE
//argv[1] = hhhhh
//argv[2] = another arg
//
//
//mypgm hhhhh  "another arg"
//
