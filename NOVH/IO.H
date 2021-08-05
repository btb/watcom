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


#ifndef _IO_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif
#include <nwtypes.h>
#include <sys\stat.h>

#define STDIN_HANDLE            0
#define STDOUT_HANDLE           1
#define STDERR_HANDLE           2
#define MAX_STDIO_HANDLE        STDERR_HANDLE

#define ACCESS_RD               0x0004
#define ACCESS_WR               0x0002
#define ACCESS_XQ               0x0001


/*
DOS styles attributes for use in creat and FEcreat
It is passed into creat and FECreat as the MSW of the parameter permission
*/

#define FA_NORMAL    0x00000000 /* Normal file - read/write permitted       */
#define FA_RDONLY    0x00010000 /* Read-only file                           */
#define FA_HIDDEN    0x00020000 /* Hidden file                              */
#define FA_SYSTEM    0x00040000 /* System file                              */
#define FA_EXECUTE   0x00080000 /* Execute only file                        */

#define FA_SUBDIR    0x00100000 /* Subdirectory                             */
#define FA_ARCHIVE   0x00200000 /* Archive file                             */
#define FA_SHARE     0x00800000 /* Used for compatibility with DOS software */
                                /* that is not network aware                */

/* Extended attributes:                                                     */

#define FA_TRANSAC   0x01000000 /* Transactional - file will use TTS        */
#define FA_READAUD   0x04000000 /* Read audit                               */
#define FA_WRITEAUD  0x08000000 /* Write audit                              */

#define FA_IMMPURG   0x10000000 /* Immediate purge                          */
#define FA_NORENAM   0x20000000 /* Rename inhibit                           */
#define FA_NODELET   0x40000000 /* Delete inhibit                           */
#define FA_NOCOPY    0x80000000 /* Copy inhibit                             */



int   access(
         const char *__path,
         int __mode );

int   chmod(
         const char *__path,
         int __pmode );

int   chsize(int __handle,
         LONG __size );

int   close(
         int __handle );

int   creat(
         const char *__path,
         int __pmode );

int   dup(
         int handle );

int   dup2(
         int handle,
         int handle2 );

int   eof(
         int __handle );

LONG  filelength(
         int __handle );

int   isatty(
         int __handle );

int   lock(
         int __handle,
         LONG __offset,
         LONG __nbytes );

LONG  lseek(
         int __handle,
         LONG __offset,
         int __origin );

int   open(
         const char *__path,
         int __oflag,
         ... );

LONG  read(
         int __handle,
         void *__buf,
         LONG __len );

int   setmode(
         int __handle,
         int __mode );

int   sopen(
         const char *__path,
         int __oflag,
         int __shflag,
         ... );

LONG  tell(
         int __handle );

int   umask(
         int __pmode );

int   unlink(
         const char *__path );

int   unlock(
         int __handle,
         LONG __offset,
         LONG __nbytes );

LONG  write(
         int __handle,
         void *__buf,
         LONG len );

#define _IO_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _IO_H_INCLUDED  */
