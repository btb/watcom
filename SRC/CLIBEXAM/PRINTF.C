#include <stdio.h>

void main()
  {
    char *weekday, *month;

    weekday = "Saturday";
    month = "April";
    printf( "%s, %s %d, %d\n",
	  weekday, month, 18, 1987 );
    printf( "f1 = %8.4f f2 = %10.2E x = %#08x i = %d\n",
	    23.45,	3141.5926,   0x1db,	-1 );
  }
//************ Sample program output ************
//Saturday, April 18, 1987
//f1 =	23.4500 f2 =  3.14E+003 x = 0x0001db i = -1
