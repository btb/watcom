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

#ifndef _DEBUGAPI_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif
#define _DEBUGAPI_H_INCLUDED

#include <nwtypes.h>
#include <errno.h>

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Info flags                                                               *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define PROCESSOR_EXCEPTION_BIT      0x0001
#define HAS_EXCEPTION_ERROR_CODE_BIT 0x0002
#define DO_AES_DEBUG_BIT             0x0004
#define HAS_OTHER_ERROR_CODE_BIT     0x0008
#define ABEND_CALLED_BIT             0x0010
#define HARD_ABEND_BIT               0x0020
#define MSENGINE_BIT                 0x0040

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Codes returnable by debug exception handlers (the                        *
 *   routine defined by debuggerEntry in debuggerStructure)                    *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define RETURN_TO_INTERNAL_DEBUGGER  1
#define RETURN_TO_PROGRAM            0
#define RETURN_TO_NEXT_ALT_DEBUGGER -1
#define RETURN_TO_NEXT_DEBUGGER     -2

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Exception number definitions                                             *
 *                                                                            *
 *   Note: Numbers 0    - 31   are hardware processor exception numbers       *
 *         Numbers 32   - 999  are reserved for the OS                        *
 *         Numbers 1000 - 4999 are available to SignalDebugEvent              *
 *         Numbers 5000 and greater are reserved                              *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define ENTER_DEBUGGER_EVENT        256
#define KEYBOARD_BREAK_EVENT        257
#define INVALID_INTERRUPT_ABEND     258
#define ASSEMBLY_ABEND              260
#define OTHER_PROCESSOR_BREAK       261

#define START_NLM_EVENT             1000
#define TERMINATE_NLM_EVENT         1001
#define NLM_FAILED_INIT_EVENT       1002

#define START_THREAD_EVENT          1100
#define TERMINATE_THREAD_EVENT      1101
#define THREAD_BOOBY_TRAP_EVENT     1102
#define BREAKPOINT_FUNCTION_EVENT   1110

#define PROTECT_NLM_INIT            2000
#define PROTECT_NLM_CHECK           2001
#define PROTECT_NLM_EXIT            2002

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Defines for SetABreakpoint type and size parameters                      *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define EXECUTION_BREAKPOINT  0
#define WRITE_BREAKPOINT      1
#define READ_WRITE_BREAKPOINT 3

#define ONE_BYTE_BREAKPOINT   0
#define TWO_BYTE_BREAKPOINT   1
#define FOUR_BYTE_BREAKPOINT  3

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Defines for RegisterDebugger DDSFlags parameter                          *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define OBSOLETE_FRAME_BIT  0x00   /* T_StackFrame*/
#define EXTENDED_FRAME_BIT  0x10   /* T_Ext_StackFrame*/
#define TSS_FRAME_BIT       0x20   /* T_TSS_StackFrame*/



/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Defines for RegisterDebugger position parameter                          *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define ALWAYS_AT_FIRST -1
#define AT_FIRST         0
#define AT_END           1
#define ALWAYS_AT_END    2

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   LoadModule load options                                                  *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define LO_NORMAL    0x0000
#define LO_STARTUP   0x0001
#define LO_PROTECT   0x0002
#define LO_DEBUG     0x0004

#define DEBUG_SIGNATURE 0x47554244

struct ScreenStruct;

typedef struct T_StackFrame
   {
   WORD  GS[2];
   WORD  FS[2];
   WORD  ES[2];
   WORD  DS[2];
   LONG  EDI;
   LONG  ESI;
   LONG  EBP;
   LONG  ESP;
   LONG  EBX;
   LONG  EDX;
   LONG  ECX;
   LONG  EAX;
   int   exceptionNumber;
   char *exceptionDescription;
   int   infoFlags;
   int   errorCode;
   LONG  EIP;
   WORD  CS[2];
   LONG  EFLAGS;
   } T_StackFrame;

typedef  struct T_TSS_StackFrame
{
/* 00 */LONG ExceptionReserved[7];
/* 1C */LONG *ExceptionCR3;
/* 20 */LONG ExceptionEIP;
/* 24 */LONG ExceptionSystemFlags;
/* 28 */LONG ExceptionEAX;
/* 2C */LONG ExceptionECX;
/* 30 */LONG ExceptionEDX;
/* 34 */LONG ExceptionEBX;
/* 38 */LONG ExceptionESP;
/* 3C */LONG ExceptionEBP;
/* 40 */LONG ExceptionESI;
/* 44 */LONG ExceptionEDI;
/* 48 */WORD ExceptionES[2];
/* 4C */WORD ExceptionCS[2];
/* 50 */WORD ExceptionSS[2];
/* 54 */WORD ExceptionDS[2];
/* 58 */WORD ExceptionFS[2];
/* 5C */WORD ExceptionGS[2];
/* 60 */WORD ExceptionLDT[2];
/* 64 */WORD ExceptionSpecial[2];
/* 68 */LONG ExceptionNumber;
/* 6C */BYTE *ExceptionDescription;
/* 70 */LONG ExceptionFlags;
/* 74 */LONG ExceptionErrorCode;
/* 78 */LONG ExceptionChainIO;
/* 7C */LONG ExceptionChainMS;
/* 80 */LONG ExceptionHistogram;
/* 84 */struct ProcessorStructure *ExceptionProcessorID;
}T_TSS_StackFrame;


typedef  struct T_Ext_StackFrame
{
   LONG *xExceptionCR3;
   LONG xExceptionReserved[4];
   struct ProcessorStructure *xExceptionProcessorID;
   WORD xExceptionSS[2];

   WORD xExceptionGS[2];
   WORD xExceptionFS[2];
   WORD xExceptionES[2];
   WORD xExceptionDS[2];
   LONG xExceptionEDI;
   LONG xExceptionESI;
   LONG xExceptionEBP;
   LONG xExceptionESP;
   LONG xExceptionEBX;
   LONG xExceptionEDX;
   LONG xExceptionECX;
   LONG xExceptionEAX;
   LONG xExceptionNumber;
   BYTE *xExceptionDescription;
   LONG xExceptionFlags;
   LONG xExceptionErrorCode;
   LONG xExceptionEIP;
   WORD xExceptionCS[2];
   LONG xExceptionSystemFlags;
}T_Ext_StackFrame;


/* Note the actual stack frame structure passed to the DDSdebuggerEntry   */
/* depends on the setting of DDSFlags when RegisterDebuggerRTag is called.*/
/* The defines for ???_FRAME_BIT determine which structure is returned.   */
/* The preferred frame for 4.0 is the TSS frame, the others are provided  */
/* for backwards compatibility.*/

struct debuggerStructure
{
   struct debuggerStructure *DDSlink;
   struct ResourceTagStructure *DDSResourceTag;
   LONG (*DDSdebuggerEntry)(struct T_StackFrame *stackFrame);
   signed char DDSPosition;
   BYTE DDSFlags;
   BYTE DDSReserved[2];
};

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Function prototypes                                                      *
 *                                                                            *
 *----------------------------------------------------------------------------*/

int   ReserveABreakpointRTag( 
         LONG __resourceTag );

int   UnReserveABreakpoint( 
         int   breakpointNumber );

int   CSetABreakpoint( 
         int breakpointNumber, 
         LONG breakLinearAddress,
         BYTE type, 
         BYTE size );

int   RegisterDebuggerRTag(
         struct debuggerStructure *debuggerStruct, 
         int position );

int   UnRegisterDebugger( 
         struct debuggerStructure *debuggerStruct );

LONG LoadModule( 
         struct ScreenStruct *screenID, 
         BYTE *commandLine,
         LONG loadOptions );

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Special functions                                                        *
 *                                                                            *
 *----------------------------------------------------------------------------*/
int SignalDebuggerEvent( int eventCode, void *eventInfo );

/* 
 * ExceptionEvent is a function callable only from assembly language
 */

#ifdef __cplusplus
};
#endif
#endif
