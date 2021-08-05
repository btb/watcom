/* MIX1C.C - This C program calls a FORTRAN function to
 *	     compute the max of three numbers.
 *
 * Compile: wcc -ml mix1c
 *	    wcc386 mix1c
 * Link:    wlink file mix1c, mix1f name mix1
 */

#include <stdio.h>

#pragma aux tmax3 "^";
long int tmax3( long int *, long int *, long int * );

void main()
{
    long int  result;
    long int  i, j, k;

    i = -1;
    j = 12;
    k = 5;
    result = tmax3( &i, &j, &k );
    printf( "Maximum is %ld\n", result );
}
