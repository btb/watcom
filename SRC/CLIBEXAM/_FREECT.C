#include <stdio.h>
#include <malloc.h>

void main()
  {
    int  i;

    printf( "Can allocate %u longs before _nheapgrow\n",
	    _freect( sizeof(long) ) );
    _nheapgrow();
    printf( "Can allocate %u longs after _nheapgrow\n",
	    _freect( sizeof(long) ) );
    for( i = 1; i < 1000; i++ ) {
      _nmalloc( sizeof(long) );
    }
    printf( "After allocating 1000 longs:\n" );
    printf( "Can still allocate %u longs\n",
	    _freect( sizeof(long) ) );
  }
//************ Sample program output ************
//Can allocate 0 longs before _nheapgrow
//Can allocate 10447 longs after _nheapgrow
//After allocating 1000 longs:
//Can still allocate 9447 longs
