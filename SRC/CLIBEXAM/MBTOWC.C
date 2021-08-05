#include <stdio.h>
#include <stdlib.h>

void main()
  {
    char    *wc = "string";
    wchar_t wbuffer[10];
    int     i, len;

    printf( "Character encodings do %shave "
	    "state-dependent encoding\n",
	    ( mbtowc( wbuffer, NULL, 0 ) )
	    ? "" : "not " );

    len = mbtowc( wbuffer, wc, 2 );
    wbuffer[len] = '\0';
    printf( "%s(%d)\n", wc, len );
    for( i = 0; i < len; i++ )
	printf( "/%4.4x", wbuffer[i] );
    printf( "\n" );
  }
//************ Sample program output ************
//Character encodings do not have state-dependent encoding
//string(1)
///0073
