#include <stdio.h>
#include <string.h>

void main()
  {
    char *p;
    char *buffer;
    char *delims = { " .," };

    buffer = strdup( "Find words, all of them." );
    printf( "%s\n", buffer );
    p = strtok( buffer, delims );
    while( p != NULL ) {
      printf( "word: %s\n", p );
      p = strtok( NULL, delims );
    }
    printf( "%s\n", buffer );
  }
//************ Sample program output ************
//Find words, all of them.
//word: Find
//word: words
//word: all
//word: of
//word: them
//Find
