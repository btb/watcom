/*
 *  DLL16.C
 *
 *  Compile:	wcc dll16 /mc /zw /zu /zc /d2
 *  Link:	wlink @dll16
 *  DLL16.LNK:	debug all
 *		system windows dll initinstance memory
 *		file dll16
 *		option oneautodata
 *		option map
 *		option heapsize=32K
 *		export _Lib1.1
 *		libfile libentry
 */
#include <stddef.h>
#include <windows.h>

extern void BreakPoint( void );
#pragma aux BreakPoint = 0xcc;

extern short GetSS( void );
#pragma aux GetSS = 0x8C 0xD0 value[ax];

int PASCAL LibMain( HANDLE hmod, WORD dataseg, WORD heap, LPSTR cmdline )
{
  short i;
  char buf[128];

//BreakPoint();
  i = GetSS();
  sprintf( buf, "DLL16 Started, SS=%hx", i );
  MessageBox( NULL, buf, "DLL16", MB_OK | MB_TASKMODAL );
  return( 1 );
}

long cdecl FAR Lib1( WORD a, LONG b, WORD c, WORD d, LONG e )
{
  char buf[128];

  sprintf( buf, "Lib1: a=%hx, b=%lx, c=%hx, d=%hx, e=%lx",
		a, b, c, d, e );
  MessageBox( NULL, buf, "DLL16", MB_OK | MB_TASKMODAL );
  return( a + b + c + d + e );
}
