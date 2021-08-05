#include <stdio.h>
#include <string.h>

void main()
  {
    char *p = "Find all vowels";

    while( p != NULL ) {
      printf( "%s\n", p );
      p = strpbrk( p+1, "aeiouAEIOU" );
    }
  }
//************ Sample program output ************
//Find all vowels
//ind all vowels
//all vowels
//owels
//els
