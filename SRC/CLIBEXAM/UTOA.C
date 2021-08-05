#include <stdio.h>
#include <stdlib.h>

void main()
  {
    int base;
    char buffer[18];

    for( base = 2; base <= 16; base = base + 2 )
      printf( "%2d %s\n", base,
	      utoa( (unsigned) 12765, buffer, base ) );
  }
//************ Sample program output ************
// 2 11000111011101
// 4 3013131
// 6 135033
// 8 30735
//10 12765
//12 7479
//14 491b
//16 31dd
