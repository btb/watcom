#include <stdio.h>
#include <ctype.h>

char chars[] = {
    'A',
    '!',
    '.',
    ',',
    ':',
    ';'
};

#define SIZE sizeof( chars ) / sizeof( char )

void main()
  {
    int   i;

    for( i = 0; i < SIZE; i++ ) {
      printf( "Char %c is %sa punctuation character\n",
	    chars[i],
	    ( ispunct( chars[i] ) ) ? "" : "not " );
    }
  }
//************ Sample program output ************
//Char A is not a punctuation character
//Char ! is a punctuation character
//Char . is a punctuation character
//Char , is a punctuation character
//Char : is a punctuation character
//Char ; is a punctuation character
