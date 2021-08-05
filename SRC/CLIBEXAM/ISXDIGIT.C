#include <stdio.h>
#include <ctype.h>

char chars[] = {
    'A',
    '5',
    '$'
};

#define SIZE sizeof( chars ) / sizeof( char )

void main()
  {
    int   i;

    for( i = 0; i < SIZE; i++ ) {
      printf( "Char %c is %sa hexadecimal digit"
	    " character\n", chars[i],
	    ( isxdigit( chars[i] ) ) ? "" : "not " );
    }
  }
//************ Sample program output ************
//Char A is a hexadecimal digit character
//Char 5 is a hexadecimal digit character
//Char $ is not a hexadecimal digit character
