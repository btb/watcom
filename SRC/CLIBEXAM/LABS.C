#include <stdio.h>
#include <stdlib.h>

void main()
  {
    long x, y;

    x = -50000L;
    y = labs( x );
    printf( "labs(%ld) = %ld\n", x, y );
  }
//************ Sample program output ************
//labs(-50000) = 50000
