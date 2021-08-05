#include <stdio.h>
#include <stdlib.h>

void main()
  {
    int     len;
    char    *mbs = "string";

    printf( "Character encodings do %shave "
	    "state-dependent encoding\n",
	    ( mblen( NULL, 0 ) )
	    ? "" : "not " );

    len = mblen( "string", 6 );
    if( len != -1 ) {
      mbs[len] = '\0';
      printf( "Multibyte char '%s'(%d)\n", mbs, len );
    }
  }
//************ Sample program output ************
//Character encodings do not have state-dependent encoding
//Multibyte char 's'(1)
