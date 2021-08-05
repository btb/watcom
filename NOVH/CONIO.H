/****************************************************************************
*
* (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
* NetWare C NLM Runtime Library source code
*
*****************************************************************************/

#ifndef _CONIO_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define DONT_AUTO_ACTIVATE    0x00000001 // prevents auto activation when
                                         // screens are created and no other
                                         // screens exist

#define DONT_CHECK_CTRL_CHARS 0x00000010 // turns off ^C and ^S processing
#define AUTO_DESTROY_SCREEN   0x00000020 // prevents "Press any key to close" msg
#define POP_UP_SCREEN         0x00000040 // for a pop up screen
#define UNCOUPLED_CURSORS     0x00000080 // for distinct input & output cursors



#define HAS_A_CLIB_HANDLE             0x00000100
#define _KEYBOARD_INPUT_ACTIVE        0x00010000 
#define _PROCESS_BLOCKED_ON_KEYBOARD  0x00020000
#define _PROCESS_BLOCKED_ON_SCREEN    0x00040000
#define _INPUT_CURSOR_DISABLED        0x00080000
#define _SCREEN_HAS_TITLE_BAR         0x00400000
#define _NON_SWITCHABLE_SCREEN        0x01000000


#ifdef   __INLINE_FUNCTIONS__

 #pragma intrinsic(inp,inpw,outp,outpw)

 #pragma aux _disable = 0xFA  /* CLI */;

 #pragma aux _enable  = 0xFB  /* STI */;

 #pragma aux inpd     = 0xED  /* in eax, dx  */\
             parm [dx] value [eax];

 #pragma aux outpd    = 0xEF  /* out dx, eax */\
             parm [dx] [eax] value [eax];

#endif

extern char *cgets(
         char *__buf );

extern int cputs(
         const char *__buf );

extern int cprintf(
         const char *__fmt, ... );

extern int    cscanf(
         const char *__fmt, ... );

extern void _disable(
         void );

extern void _enable(
         void );

extern int getch(
         void );

extern int getche(
         void );

extern unsigned int inp(
         int __port );

extern unsigned int inpw(
         int __port );

extern unsigned int inpd(
         int __port );

extern int kbhit(
         void );

extern unsigned int outp(
         int __port,
         int __value );

extern unsigned int outpw(
         int __port,
         int __value );

extern unsigned int outpd(
         int __port,
         int __value );

extern int putch(
         int __c );

extern int ungetch(
         int __c );

extern int CheckIfScreenDisplayed(
         int __screenHandle,
         long __waitFlag );  

extern void clrscr(
         void );

extern void ConsolePrintf(
         char *__format, ... );

extern void CopyToScreenMemory(
         WORD __height,
         WORD __width,
         BYTE *__Rect,
         WORD __beg_x,
         WORD __beg_y );

extern void CopyFromScreenMemory(
         WORD __height,
         WORD __width,
         BYTE *__Rect,
         WORD __beg_x,
         WORD __beg_y );

extern int CoupleInputOutputCursors(
         void );

extern int CreateScreen(
         char *__screenName,
         BYTE __attributes);

extern int DecoupleInputOutputCursors(
         void );

extern int DestroyScreen(
         int __screenHandle );

extern int DisplayInputCursor(
         void );

extern int DisplayScreen(
         int __screenHandle );

extern int DropPopUpScreen(
         int __screenHandle );

extern int GetCurrentScreen(
         void );

extern BYTE GetCursorCouplingMode(void);

extern WORD GetCursorShape(
         BYTE *startline,
         BYTE *endline );

extern WORD GetCursorSize(
         BYTE *firstline,
         BYTE *lastline);

extern int __GetScreenID(
         int __screenHandle );

extern int GetScreenInfo( 
         int   handle, 
         char *name, 
         LONG *attrib );

extern int GetPositionOfOutputCursor(
         WORD *__rowP,
         WORD *__columnP);

extern int GetSizeOfScreen(
         WORD *__heightP,
         WORD *__widthP);

extern void gotoxy(
         WORD __col,
         WORD __row );

extern int HideInputCursor(
         void );

extern int IsColorMonitor(void);

extern int PressAnyKeyToContinue(
         void );

extern int PressEscapeToQuit(
         void );

extern void RingTheBell(
         void );

extern int ScanScreens(
         int   __LastScreenID,
         char *__name,
         LONG *__attrib );

extern int ScrollScreenRegionDown(
         int __firstLine,
         int __numLines );

extern int ScrollScreenRegionUp(
         int __firstLine,
         int __numLines );

extern BYTE SetAutoScreenDestructionMode(
         BYTE __newMode );

extern BYTE SetCtrlCharCheckMode(
         BYTE __newMode );

extern BYTE SetCursorCouplingMode(
         BYTE __newMode );

extern WORD SetCursorShape(
         BYTE startline,
         BYTE endline );

extern int SetCurrentScreen(
         int __screenHandle);

extern int SetInputAtOutputCursorPosition(
         void );

extern int SetOutputAtInputCursorPosition(
         void );

extern int SetPositionOfInputCursor(
         WORD __row,
         WORD __column);

extern LONG SetScreenAreaAttribute(
         LONG   line,
         LONG   column,
         LONG   numLines,
         LONG   numColumns,
         LONG   attribute);

extern LONG SetScreenCharacterAttribute(
         LONG   line,
         LONG   column,
         LONG   attribute);

extern int SetScreenRegionAttribute(
         int  __firstLine,
         int  __numLines,
         BYTE __attribute);

extern WORD wherex(
         void );

extern WORD wherey(
         void );

#define _CONIO_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _CONIO_H_INCLUDED  */
