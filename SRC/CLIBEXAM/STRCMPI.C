#include <stdio.h>
#include <string.h>

void main()
  {
    printf( "%d\n", strcmpi( "AbCDEF", "abcdef" ) );
    printf( "%d\n", strcmpi( "abcdef", "ABC"	) );
    printf( "%d\n", strcmpi( "abc",    "ABCdef" ) );
    printf( "%d\n", strcmpi( "Abcdef", "mnopqr" ) );
    printf( "%d\n", strcmpi( "Mnopqr", "abcdef" ) );
  }
//************ Sample program output ************
//0
//100
//-100
//-12
//12
