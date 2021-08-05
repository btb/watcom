#include <stdio.h>
#include <malloc.h>

void main()
  {
     char *p, *fmt_string;
     fmt_string = "Amount of memory available is %u\n";
     printf( fmt_string, _memavl() );
     _nheapgrow();
     printf( fmt_string, _memavl() );
     p = (char *) malloc( 2000 );
     printf( fmt_string, _memavl() );
  }
//************ Sample program output ************
//Amount of memory available is 0
//Amount of memory available is 62732
//Amount of memory available is 60730
