#include <stdio.h>
#include <time.h>

void main()
  {
    time_t time_of_day;
    auto char buf[26];
    auto struct tm tmbuf;

    time_of_day = time( NULL );
    _gmtime( &time_of_day, &tmbuf );
    printf( "It is now: %.24s GMT\n",
	    _asctime( &tmbuf, buf ) );
  }
//************ Sample program output ************
//It is now: Fri Dec 25 15:58:27 1987 GMT
