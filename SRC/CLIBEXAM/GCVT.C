#include <stdio.h>
#include <stdlib.h>

void main()
  {
    char buffer[80];

    printf( "%s\n", gcvt( -123.456789, 5, buffer ) );
    printf( "%s\n", gcvt( 123.456789E+12, 5, buffer ) );
  }
//************ Sample program output ************
//-123.46
//1.2346E+014
