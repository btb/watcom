#include <stdio.h>
#include <ctype.h>

char chars[] = {
    'A',
    'a',
    'z',
    'Z'
};

#define SIZE sizeof( chars ) / sizeof( char )

void main()
  {
    int   i;

    for( i = 0; i < SIZE; i++ ) {
      printf( "Char %c is %sa lowercase character\n",
	    chars[i],
	    ( islower( chars[i] ) ) ? "" : "not " );
    }
  }
//************ Sample program output ************
//Char A is not a lowercase character
//Char a is a lowercase character
//Char z is a lowercase character
//Char Z is not a lowercase character
