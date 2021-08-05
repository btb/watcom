#include <stdio.h>

void main()
  {
    FILE *fp;
    int c;

    fp = fopen( "file", "r" );
    if( fp != NULL ) {
      c = fgetc( fp );
      while( c != EOF ) {
	fputchar( c );
	c = fgetc( fp );
      }
      fclose( fp );
    }
  }
