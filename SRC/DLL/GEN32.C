/*
 *  GEN32.C
 *
 *  Compile:	wcc386 gen32 /zw
 *  Link:	wlink @gen32
 *  Bind:	wbind gen32 -n
 */
#include <windows.h>
#include <stdio.h>

/*
 * comment out this line if you do not want do the 16-bit
 * dll call test
 */
#define DO_16BIT_TEST

extern char end;
extern int _curbrk;

#pragma aux default modify[fs gs];
#define DLL_1 1
#define DLL_2 2
#define DLL_3 3

int PASCAL WinMain( HANDLE hInstance,
		    HANDLE hPrevInstance,
		    LPSTR lpCmdLine,
		    int nCmdShow )
{
  FARPROC fp;
  HANDLE hlib16, hlib32;
  HINDIR hIndira;
  HINDIR hIndir1, hIndir2, hIndir3;
  DWORD cb;
  char buf[128];

#ifdef DO_16BIT_TEST
  /*
   * 16-bit DLL test, calling with Microsoft C calling conventions
   */
  hlib16 = LoadLibrary( "dll16.dll" );
  fp = GetProcAddress( hlib16, PASS_WORD_AS_POINTER( 1 ) );

  hIndira = GetIndirectFunctionHandle( fp, INDIR_CDECL, INDIR_WORD,
	      INDIR_DWORD, INDIR_WORD, INDIR_WORD,
	      INDIR_DWORD, INDIR_ENDLIST );

  cb = InvokeIndirectFunction( hIndira,
			       0x1, 0x11110000, 0x1100, 0x10,
			       0x22222222 );
  sprintf( buf, "CDECL RC = %lx", cb );
  MessageBox( NULL, buf, "Gen32", MB_OK | MB_TASKMODAL );
  FreeLibrary( hlib16 );
#endif

  /*
   * 32-bit DLL test
   */
  hlib32 = LoadLibrary( "dll32.dll" );
  fp = GetProcAddress( hlib32, "Win386LibEntry" );

  hIndir1 = GetIndirectFunctionHandle( fp, INDIR_WORD, INDIR_DWORD,
	      INDIR_WORD, INDIR_WORD, INDIR_ENDLIST );
  hIndir2 = GetIndirectFunctionHandle( fp, INDIR_DWORD, INDIR_WORD,
	      INDIR_WORD, INDIR_ENDLIST );
  hIndir3 = GetIndirectFunctionHandle( fp, INDIR_PTR, INDIR_WORD, INDIR_WORD,
	  INDIR_DWORD, INDIR_WORD, INDIR_DWORD, INDIR_WORD, INDIR_ENDLIST );

  cb = InvokeIndirectFunction( hIndir1, 0x666, 0x77777111, 0x6969, DLL_1 );
  sprintf( buf, "RC1 = %lx", cb );
  MessageBox( NULL, buf, "Gen32", MB_OK | MB_TASKMODAL );

  cb = InvokeIndirectFunction( hIndir2, 0x12345678, 0x8888, DLL_2 );
  sprintf( buf, "RC2 = %lx", cb );
  MessageBox( NULL, buf, "Gen32", MB_OK | MB_TASKMODAL );

  cb = InvokeIndirectFunction( hIndir3, "A Test String", 1, 2,
			       0xabcddcba, 3, 0x12344321, DLL_3 );
  sprintf( buf, "RC3 = %lx", cb );
  MessageBox( NULL, buf, "Gen32", MB_OK | MB_TASKMODAL );
  FreeLibrary( hlib32 );

  return( 0 );
}
