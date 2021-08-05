#include <stdio.h>
#include <stdlib.h>

wchar_t wchar = { 0x0073 };
char	mbbuffer[MB_CUR_MAX];

void main()
  {
    int len;

    printf( "Character encodings do %shave "
	    "state-dependent encoding\n",
	    ( wctomb( NULL, 0 ) )
	    ? "" : "not " );

    len = wctomb( mbbuffer, wchar );
    mbbuffer[len] = '\0';
    printf( "%s(%d)\n", mbbuffer, len );
  }
//************ Sample program output ************
//Character encodings do not have state-dependent encoding
//s(1)
