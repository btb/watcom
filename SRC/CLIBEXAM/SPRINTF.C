
#include <stdio.h>

char namebuf[13];
int  TempCount = 0;

char *make_temp_name()
  {
    sprintf( namebuf, "ZZ%.6o.TMP", TempCount++ );
    return( namebuf );
  }

void main()
  {
    FILE *tf1, *tf2;

    tf1 = fopen( make_temp_name(), "w" );
    tf2 = fopen( make_temp_name(), "w" );
    fputs( "temp file 1", tf1 );
    fputs( "temp file 2", tf2 );
    fclose( tf1 );
    fclose( tf2 );
  }

