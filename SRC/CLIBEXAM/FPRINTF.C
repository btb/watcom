#include <stdio.h>

char *weekday = { "Saturday" };
char *month = { "April" };

void main()
  {
    fprintf( stdout, "%s, %s %d, %d\n",
	  weekday, month, 18, 1987 );
  }
//************ Sample program output ************
//Saturday, April 18, 1987
