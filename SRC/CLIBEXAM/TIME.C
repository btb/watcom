#include <stdio.h>
#include <time.h>

void main()
  {
    time_t time_of_day;

    time_of_day = time( NULL );
    printf( "It is now: %s", ctime( &time_of_day ) );
  }
//************ Sample program output ************
//It is now: Fri Dec 25 15:58:42 1987
