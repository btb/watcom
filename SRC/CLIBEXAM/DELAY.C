#include <dos.h>

void main()
  {
    sound( 200 );
    delay( 500 );  /* delay for 1/2 second */
    nosound();
  }
