#include <stdio.h>
#include <math.h>

void main()
  {
    printf( "%f %f %f %f %f\n", ceil( -2.1 ), ceil( -2. ),
	ceil( 0.0 ), ceil( 2. ), ceil( 2.1 ) );
  }
//************ Sample program output ************
//-2.000000 -2.000000 0.000000 2.000000 3.000000
