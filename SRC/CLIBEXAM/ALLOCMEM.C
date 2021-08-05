#include <stdio.h>
#include <dos.h>

void main()
  {
    unsigned short segment;

    /* Try to allocate 100 paragraphs, then free them */
    if( _dos_allocmem( 100, &segment ) != 0 ) {
      printf( "_dos_allocmem failed\n" );
      printf( "Only %u paragraphs available\n",
	       segment );
    } else {
      printf( "_dos_allocmem succeeded\n" );
      if( _dos_freemem( segment ) != 0 ) {
	printf( "_dos_freemem failed\n" );
      } else {
	printf( "_dos_freemem succeeded\n" );
      }
    }
  }
