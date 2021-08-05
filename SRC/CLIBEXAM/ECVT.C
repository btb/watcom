#include <stdio.h>
#include <stdlib.h>

void main()
  {
     char *str;
     int  dec, sign;

     str = ecvt( 123.456789, 6, &dec, &sign );
     printf( "str=%s, dec=%d, sign=%d\n", str,dec,sign );
  }
//************ Sample program output ************
//str=123457, dec=3, sign=0
