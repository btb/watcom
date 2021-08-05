#include <stdio.h>
#include <stdlib.h>
#include <process.h>

#define  STACK_SIZE   4096
#if defined(__386__)
  #define FAR
#else
  #define FAR __far
#endif

void FAR child( void FAR *parm )
  {
    char * FAR *argv = (char * FAR *) parm;
    int  i;

    for( i = 0; argv[i]; i++ ) {
      printf( "argv[%d] = %s\n", i, argv[i] );
    }
    _endthread();
  }

void main()
  {
    char *stack;
    char *args[3];
    int   tid;

    args[0] = "child";
    args[1] = "parm";
    args[2] = NULL;
    stack = (char *) malloc( STACK_SIZE );
    tid = _beginthread( child, stack, STACK_SIZE, args );
  }
