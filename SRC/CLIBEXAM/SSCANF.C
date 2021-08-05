
#include <stdio.h>

void main()
  {
    int day, year;
    char weekday[20], month[20];

    sscanf( "Friday August 0014 1987",
	    "%s %s %d  %d",
	     weekday, month, &day, &year );
    printf( "%s %s %d %d\n",
	     weekday, month, day, year );
  }

//************ Sample program output ************
//Friday August 14 1987
