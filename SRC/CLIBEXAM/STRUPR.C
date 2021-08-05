#include <stdio.h>
#include <string.h>

char source[] = { "A mixed-case STRING" };

void main()
  {
    printf( "%s\n", source );
    printf( "%s\n", strupr( source ) );
    printf( "%s\n", source );
  }
//************ Sample program output ************
//A mixed-case STRING
//A MIXED-CASE STRING
//A MIXED-CASE STRING
