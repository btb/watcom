#include <stdio.h>
#include <string.h>

void main()
  {
    printf( "%s\n", strrchr( "abcdeabcde", 'a' ) );
    if( strrchr( "abcdeabcde", 'x' ) == NULL )
	printf( "NULL\n" );
  }
//************ Sample program output ************
//abcde
//NULL
