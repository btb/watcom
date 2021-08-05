/*
 *  DLL32.C
 *
 *  Compile:	wcc386 dll32 /zw /d2
 *  Link:	wlink @dll32
 *  Bind:	wbind dll32 -d -n
 */
#include <windows.h>	/* required for all Windows applications */
#include <dos.h>

int FAR PASCAL Lib1( WORD w1, DWORD w2, WORD w3 )
{
  char buf[128];

  sprintf( buf, "Lib1: w1=%hx, w2=%lx, w3=%hx", w1, w2, w3 );
  MessageBox( NULL, buf, "DLL32", MB_OK | MB_TASKMODAL );
  return( w1 + w2);
}

int FAR PASCAL Lib2( DWORD w1, WORD w2 )
{
  char buf[128];

  sprintf( buf, "Lib2: w1=%lx, w2=%hx", w1, w2 );
  MessageBox( NULL, buf, "DLL32", MB_OK | MB_TASKMODAL );
  return( w1 + 1 );
}

int FAR PASCAL Lib3( LPSTR data, WORD a, WORD b,
		     DWORD d1, WORD c, DWORD d2 )
{
  char far *str;
  char buf[128];

  str = MK_FP32( data );
  sprintf( buf, "Lib3: string ==>%Fs<==", str );
  MessageBox( NULL, buf, "DLL32", MB_OK | MB_TASKMODAL );
  sprintf( buf, "Lib3: a=%hd, b=%hd, c=%hd", a, b, c );
  MessageBox( NULL, buf, "DLL32", MB_OK | MB_TASKMODAL );
  sprintf( buf, "Lib3: d1=%lx, d2=%lx", d1, d2 );
  MessageBox( NULL, buf, "DLL32", MB_OK | MB_TASKMODAL );
  return( d1 + d2 );
}

extern void BreakPoint( void );
#pragma aux BreakPoint = 0xcc;

extern short GetSS( void );
#pragma aux GetSS = 0x8C 0xD0 value[ax];

int PASCAL WinMain( HANDLE hInstance, HANDLE x1, LPSTR lpCmdLine, int x2 )
{
  short i;
  char buf[128];

  BreakPoint();
  DefineDLLEntry( 1, (void *) Lib1, DLL_WORD, DLL_DWORD, DLL_WORD,
		      DLL_ENDLIST );
  DefineDLLEntry( 2, (void *) Lib2, DLL_DWORD, DLL_WORD, DLL_ENDLIST );
  DefineDLLEntry( 3, (void *) Lib3, DLL_PTR, DLL_WORD, DLL_WORD,
		      DLL_DWORD, DLL_WORD, DLL_DWORD, DLL_ENDLIST );
  i = GetSS();
  sprintf( buf, "DLL32 Started, SS=%hx", i );
  MessageBox( NULL, buf, "DLL32", MB_OK | MB_TASKMODAL );
  return( 1 );
}
