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

#ifndef _PROCESS_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

/* values for __action_code used with ExitThread() */

#define TSR_THREAD     -1
#define EXIT_THREAD     0
#define EXIT_NLM        1

/* values for __mode used with spawnxx() */

#define P_WAIT                      0
#define P_NOWAIT                    1
#define P_OVERLAY                   2
#define P_NOWAITO                   4
#define P_SPAWN_IN_CURRENT_DOMAIN   8


#define NO_CONTEXT                  0
#define USE_CURRENT_CONTEXT         1

/* value to make a memory page present and writable */
#define MMU_PAGE_PRESENT_WRITE_USER (0x04 | 0x02 | 0x01)

/* stack defines */
#define MIN_STACKSIZE      (8192+16)
#define DEFAULT_STACKSIZE  8192

/* structure used to set up work to do process scheduling */
typedef struct WorkToDoStructure
{                                        
   struct   WorkToDoStructure *Link;
   void     (*workProcedure)();
   LONG     WorkResourceTag;
   LONG     PollCountAmount;              
   LONG     PollCountWhen;                 
} WorkToDo;


/*...custom data area variables...*/
extern void    *threadGroupCustomDataPtr;
extern LONG    threadGroupCustomDataSize;
extern void    *threadCustomDataPtr;
extern LONG    threadCustomDataSize;


void  abort(
         void );

int   AddLanguage(int   languageID,
         BYTE  *newLanguageName,
         int   showErrorsOnConsole);

int   atexit(
         void (*__func)( void ) );

int   AtUnload(
         void (*__func)( void ) );

int   BeginThread(
         void    (* __func) (void *),
         void     * __stackP,
         unsigned   __stackSize,
         void     * __arg );

#define beginthread BeginThread

int   BeginThreadGroup(
         void    (* __func) (void *),
         void     * __stackP,
         unsigned   __stackSize,
         void     * __arg );

int   Breakpoint(
         int   __arg);

int   ClearNLMDontUnloadFlag(
         int   NLMID);

void  delay(
         unsigned __milliseconds);

int   EnterCritSec(
         void );

int   ExitCritSec(
         void );

void  exit(
         int __status );

void  _exit(
         int __status );

void  ExitThread(
         int __action_code,
         int __termination_code );

unsigned int FindNLMHandle(
         char *__NLMFileName );

char *getcmd(
         char *__cmdLine );

int GetCurrentOSLanguageID(void);

char *getenv(
         const char *__name );

unsigned int GetNLMHandle(
         void );

int GetNLMID( 
         void );

int GetNLMIDFromThreadID( 
         int __threadID,
         char *fileName);

int GetNLMNameFromNLMID(
         int __NLMID,
         char *__fileName,
         char *__description );

LONG __GetPCBFromThreadID(
         int threadID);

LONG __GetThreadIDFromPCB(
         int PCB);

int   GetThreadContextSpecifier(
         int   threadID);

int   GetThreadID(
         void );

int   GetThreadGroupID( 
         void );

int   GetThreadName(
         int   __threadID,
         char *__tName );

LONG  GetThreadHandicap(
         int   threadID);

LONG  LoadLanguageMessageTable(char ***MessageTable,
         LONG  *messageCount,
         LONG  *languageID);

int   MapNLMIDToHandle(int NLMID);

int   RenameLanguage(int   languageID,
         BYTE  *newLanguageName,
         int showErrorsToConsole);

int   RenameThread(
         int   __threadID,
         char *__newName);

int   ResumeThread(
         int __threadID );

int   ReturnLanguageName(int  languageID,
         BYTE  *languageName);

int   ReturnNLMVersionInfoFromFile(
         BYTE  *__pathName,
         LONG  *majorVersion,
         LONG  *minorVersion,
         LONG  *revision,
         LONG  *year,
         LONG  *month,
         LONG  *day,
         BYTE  *copyrightString,
         BYTE  *description);

int   ReturnNLMVersionInformation(
         int   NLMHandle,
         LONG  *majorVersion,
         LONG  *minorVersion,
         LONG  *revision,
         LONG  *year,
         LONG  *month,
         LONG  *day,
         BYTE  *copyrightString,
         BYTE  *description);

int   ScheduleWorkToDo(
         void (*ProcedureToCall)(void * data, WorkToDo *workToDo),
         void *workData,
         WorkToDo *workToDo);

int   SetNLMDontUnloadFlag(
         int   NLMID);

int   SetThreadContextSpecifier(
         int threadID,
         int contextSpecifier);

int SetCurrentOSLanguageID(LONG newLanguageID);

int   SetNLMID( 
         int __newNLMID );

int SetThreadGroupID( 
         int __newThreadGroupID );

void SetThreadHandicap(
         int   threadID,
         int   handicap);

int   spawnlp(
         int __mode,
         const char *__path,
          char *__arg0,... );

int   spawnvp(
         int __mode,
         const char *__path,
         char **__argv );

int   SuspendThread(
         int __threadID );

int   system(
         const char *__cmd );

void  ThreadSwitch(
         void );

void  ThreadSwitchWithDelay(
         void );

void  ThreadSwitchLowPriority(
         void );

#define _PROCESS_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _PROCESS_H_INCLUDED  */
