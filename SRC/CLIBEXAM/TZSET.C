#include <stdio.h>
#include <env.h>
#include <time.h>

void print_zone()
  {
    char *tz;

    printf( "TZ: %s\n", (tz = getenv( "TZ" ))
		    ? tz : "default EST5EDT" );
    printf( "  daylight: %d\n", daylight );
    printf( "  timezone: %ld\n", timezone );
    printf( "  time zone names: %s %s\n",
	    tzname[0], tzname[1] );
  }

void main()
  {
    print_zone();
    setenv( "TZ", "PST8PDT", 1 );
    tzset();
    print_zone();
  }
//************ Sample program output ************
//TZ: default EST5EDT
//  daylight: 1
//  timezone: 18000
//  time zone names: EST EDT
//TZ: PST8PDT
//  daylight: 1
//  timezone: 28800
//  time zone names: PST PDT
