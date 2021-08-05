#include <stdio.h>
#include <ctype.h>

char chars[] = {
    'A',
    0x99,
    'Z'
};

#define SIZE sizeof( chars ) / sizeof( char )

void main()
  {
    int   i;

    for( i = 0; i < SIZE; i++ ) {
      printf( "Char %c is %san ASCII character\n",
	    chars[i],
	    ( isascii( chars[i] ) ) ? "" : "not " );
    }
  }
//************ Sample program output ************
//Char A is an ASCII character
//Char ™ is not an ASCII character
//Char Z is an ASCII character
