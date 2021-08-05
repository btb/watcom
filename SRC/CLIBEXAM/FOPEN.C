#include <stdio.h>

void main()
  {
    FILE *fp;

    fp = fopen( "report.dat", "r" );
    if( fp != NULL ) {
      /* rest of code goes here */
      fclose( fp );
    }
  }
