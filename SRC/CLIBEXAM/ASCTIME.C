#include <stdio.h>
#include <time.h>

void main()
  {
    struct tm  time_of_day;
    time_t     ltime;
    auto char  buf[26];

    time( &ltime );
    _localtime( &ltime, &time_of_day );
    printf( "Date and time is: %s\n",
	    _asctime( &time_of_day, buf ) );
  }
//************ Sample program output ************
//Date and time is: Sat Mar 21 15:58:27 1987
