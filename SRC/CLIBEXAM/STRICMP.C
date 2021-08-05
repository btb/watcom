#include <stdio.h>
#include <string.h>

void main()
  {
    printf( "%d\n", stricmp( "AbCDEF", "abcdef" ) );
    printf( "%d\n", stricmp( "abcdef", "ABC"	) );
    printf( "%d\n", stricmp( "abc",    "ABCdef" ) );
    printf( "%d\n", stricmp( "Abcdef", "mnopqr" ) );
    printf( "%d\n", stricmp( "Mnopqr", "abcdef" ) );
  }
//************ Sample program output ************
//0
//100
//-100
//-12
//12
