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
      printf( "Char %c is %san uppercase character\n",
	    chars[i],
	    ( isupper( chars[i] ) ) ? "" : "not " );
    }
  }
//************ Sample program output ************
//Char A is an uppercase character
//Char a is not an uppercase character
//Char z is not an uppercase character
//Char Z is an uppercase character
