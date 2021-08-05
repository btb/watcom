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
      printf( "Char %c is %sa digit character\n",
	    chars[i],
	    ( isdigit( chars[i] ) ) ? "" : "not " );
    }
  }
//************ Sample program output ************
//Char A is not a digit character
//Char 5 is a digit character
//Char $ is not a digit character
