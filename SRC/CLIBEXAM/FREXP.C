#include <stdio.h>
#include <math.h>

void main()
  {
    int    expon;
    double value;

    value = frexp(  4.25, &expon );
    printf( "%f %d\n", value, expon );
    value = frexp( -4.25, &expon );
    printf( "%f %d\n", value, expon );
  }
//************ Sample program output ************
//0.531250 3
//-0.531250 3
