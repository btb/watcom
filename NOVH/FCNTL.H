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

#ifndef _FCNTL_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#define O_RDONLY           0x0000  /* open for read only */
#define O_WRONLY           0x0001  /* open for write only */
#define O_RDWR             0x0002  /* open for read and write */
#define O_APPEND           0x0010  /* writes done at end of file */
#define O_CREAT            0x0020  /* create new file */
#define O_TRUNC            0x0040  /* truncate existing file */
#define O_EXCL             0x0080  /* exclusive open */

#define O_TEXT             0x0100  /* text file */
#define O_BINARY           0x0200  /* binary file */
#define O_NDELAY           0x0400  /* nonblocking flag */

#define F_GETFL            0x0001
#define F_SETFL            0x0002
#define FNDELAY            0x0004  /* fcntl() non-blocking I/O */


int fcntl(
         int         handle,
         int         cmd,
         int         arg);

int   open(
         const char *__path,
         int         __oflag,
         ... );
int   sopen(
         const char *__path,
         int         __oflag,
         int         __shflag, 
         ... );

#define _FCNTL_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _FCNTL_H_INCLUDED  */
