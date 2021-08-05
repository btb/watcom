#include <stdlib.h>

void main()
  {
    char *buffer;

    buffer = malloc( 80 );
    buffer = realloc( buffer, 100 );
  }
