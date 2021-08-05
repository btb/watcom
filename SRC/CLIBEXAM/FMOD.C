#include <stdio.h>
#include <math.h>

void main()
  {
    printf( "%f\n", fmod(  4.5,  2.0 ) );
    printf( "%f\n", fmod( -4.5,  2.0 ) );
    printf( "%f\n", fmod(  4.5, -2.0 ) );
    printf( "%f\n", fmod( -4.5, -2.0 ) );
  }
//************ Sample program output ************
//0.500000
//-0.500000
//0.500000
//-0.500000
