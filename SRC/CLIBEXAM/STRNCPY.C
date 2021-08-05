#include <stdio.h>
#include <string.h>

void main()
  {
    char buffer[15];

    printf( "%s\n", strncpy( buffer, "abcdefg", 10 ) );
    printf( "%s\n", strncpy( buffer, "1234567",  6 ) );
    printf( "%s\n", strncpy( buffer, "abcdefg",  3 ) );
    printf( "%s\n", strncpy( buffer, "*******",  0 ) );
  }
//************ Sample program output ************
//abcdefg
//123456g
//abc456g
//abc456g
