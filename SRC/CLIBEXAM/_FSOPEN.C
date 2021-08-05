#include <stdio.h>

void main()
  {
    FILE *fp;

    /*
      open a file and prevent others from writing to it
    */
    fp = _fsopen( "report.dat", "w", SH_DENYWR );
    if( fp != NULL ) {
      /* rest of code goes here */
      fclose( fp );
    }
  }
