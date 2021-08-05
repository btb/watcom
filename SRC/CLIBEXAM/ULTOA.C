#include <stdio.h>
#include <stdlib.h>

void print_value( unsigned long int value )
  {
    int base;
    char buffer[18];

    for( base = 2; base <= 16; base = base + 2 )
      printf( "%2d %s\n", base,
	      ultoa( value, buffer, base ) );
  }

void main()
  {
    print_value( (unsigned) 12765L );
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
