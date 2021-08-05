#include <stdio.h>
#include <math.h>

void main()
  {
    double integral_value, fractional_part;

    fractional_part = modf( 4.5, &integral_value );
    printf( "%f %f\n", fractional_part, integral_value );
    fractional_part = modf( -4.5, &integral_value );
    printf( "%f %f\n", fractional_part, integral_value );
  }
//************ Sample program output ************
//0.500000 4.000000
//-0.500000 -4.000000
