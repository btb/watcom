#include <stdio.h>
#include <malloc.h>

void main()
  {
    char *p;
    size_t size;

    size = _memmax();
    printf( "Maximum memory available is %u\n", size );
    _nheapgrow();
    size = _memmax();
    printf( "Maximum memory available is %u\n", size );
    p = (char *) _nmalloc( size );
    size = _memmax();
    printf( "Maximum memory available is %u\n", size );
  }
//************ Sample program output ************
//Maximum memory available is 0
//Maximum memory available is 62700
//Maximum memory available is 0
