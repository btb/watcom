#include <stdio.h>

void main()
  {
    FILE *stream;

    stream = fopen( "file", "r" );
    printf( "File number is %d\n", fileno( stream ) );
    fclose( stream );
  }
//************ Sample program output ************
//File number is 7
