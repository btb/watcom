#include <stdio.h>
#include <time.h>
#include <sys\timeb.h>

void main()
  {
    struct timeb timebuf;
    char   *tod;

    ftime( &timebuf );
    tod = ctime( &timebuf.time );
    printf( "The time is %.19s.%hu %s",
	tod, timebuf.millitm, &tod[20] );
  }
//************ Sample program output ************
//The time is Tue Dec 25 15:58:42.870 1990
