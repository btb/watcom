#include <stdio.h>
#include <ctype.h>

char chars[] = {
    'A',
    0x09,
    'Z'
};

#define SIZE sizeof( chars ) / sizeof( char )

void main()
  {
    int   i;

    for( i = 0; i < SIZE; i++ ) {
      printf( "Char %c is %sa Control character\n",
	    chars[i],
	    ( iscntrl( chars[i] ) ) ? "" : "not " );
    }
  }
//************ Sample program output ************
//Char A is not a Control character
//Char	   is a Control character
//Char Z is not a Control character
