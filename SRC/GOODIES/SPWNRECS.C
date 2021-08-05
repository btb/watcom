/*
    SPWNRECS.C - The following program demonstrates how to
    spawn another OS/386 application.

    Compile & Link: wcl386 /l=ergo spwnrecs
 */
#include <process.h>
#include <stdio.h>

void main()
{
    int app2_exit_code;

    puts( "Spawning a protect-mode application..."
	  "using spawnlp() with P_WAIT" );
    puts( "Spawning application #2..." );
    app2_exit_code = spawnlp( P_WAIT, "up",
			    "up", "spwndecs.c", NULL );

    printf( "Application #2 returned with exit code %d",
		app2_exit_code );
}
