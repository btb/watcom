#include <stdio.h>
#include <stdlib.h>

void main()
  {
     char *str;
     int  dec, sign;

     str = fcvt( -123.456789, 5, &dec, &sign );
     printf( "str=%s, dec=%d, sign=%d\n", str,dec,sign );
  }
//************ Sample program output ************
//str=12345679, dec=3, sign=-1
