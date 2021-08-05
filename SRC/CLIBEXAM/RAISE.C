/*
 * This program loops until a SIGINT signal
 * is received or a count is exceeded.
 */
#include <stdio.h>
#include <signal.h>

sig_atomic_t signal_count;
sig_atomic_t signal_number;

static void alarm_handler( int signum )
  {
    ++signal_count;
    signal_number = signum;
  }

void main()
  {
    unsigned long i;

    signal_count = 0;
    signal_number = 0;
    signal( SIGINT, alarm_handler );

    printf( "Program looping. Press Ctrl/C.\n" );
    for( i = 0; i < 3000000; i++ ) {
      if( i > 2000000 ) raise( SIGINT );
      if( signal_count > 0 ) {
	printf( "Signal %d received\n", signal_number );
	break;
      }
    }
  }
