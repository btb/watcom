#include <stdio.h>
#include <malloc.h>

void main()
  {
    char *p;
    char *fmt = "Memory available = %u\n";

    printf( fmt, _memavl() );
    _nheapgrow();
    printf( fmt, _memavl() );
    p = (char *) malloc( 2000 );
    printf( fmt, _memavl() );
  }
//************ Sample program output ************
//Memory available = 0
//Memory available = 62732
//Memory available = 60730
