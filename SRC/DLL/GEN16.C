/*
 *  GEN16.C
 *
 *  Compile:	wcc gen16 /zw
 *  Link:	wlink @gen16
 */
#include <windows.h>
#include <stdio.h>

extern char end;
extern int _curbrk;
#define DLL_1 1
#define DLL_2 2
#define DLL_3 3

typedef long (FAR PASCAL *FARPROC2)();

int PASCAL WinMain( HANDLE hInstance,
		    HANDLE hPrevInstance,
		    LPSTR lpCmdLine,
		    int nCmdShow )
{
  HANDLE hlib;
  FARPROC2 fp;
  DWORD cb;
  char buf[128];

  hlib = LoadLibrary( "dll32.dll" );
  fp = (FARPROC2) GetProcAddress( hlib, "Win386LibEntry" );

  cb = fp( 0x666, 0x77777111, 0x6969, DLL_1 );
  sprintf( buf, "RC1 = %lx", cb );
  MessageBox( NULL, buf, "Gen16", MB_OK | MB_TASKMODAL );

  cb = fp( 0x12345678, 0x8888, DLL_2 );
  sprintf( buf, "RC2 = %lx", cb );
  MessageBox( NULL, buf, "Gen16", MB_OK | MB_TASKMODAL );

  cb = fp( (char far *) "A Test String", 1, 2 , 0xabcddcba, 3,
	      0x12344321, DLL_3 );
  sprintf( buf, "RC3 = %lx", cb );
  MessageBox( NULL, buf, "Gen16", MB_OK | MB_TASKMODAL );
  FreeLibrary( hlib );

  return( 0 );
}
