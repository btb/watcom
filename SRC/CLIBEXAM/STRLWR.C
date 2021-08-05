#include <stdio.h>
#include <string.h>

char source[] = { "A mixed-case STRING" };

void main()
  {
    printf( "%s\n", source );
    printf( "%s\n", strlwr( source ) );
    printf( "%s\n", source );
  }
//************ Sample program output ************
//A mixed-case STRING
//a mixed-case string
//a mixed-case string
