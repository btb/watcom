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

#ifndef _ERRNO_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*
*                                                                            *
*      Errno macro                                                           *
*                                                                            *
*---------------------------------------------------------------------------*/
#define errno        *__get_errno_ptr()
/*---------------------------------------------------------------------------*
*                                                                            *
*      Non-ANSI error codes                                                  *
*                                                                            *
*---------------------------------------------------------------------------*/
#define ESUCCESS 0
#define EFAILURE (-1)
/*---------------------------------------------------------------------------*
*                                                                            *
*      ANSI error codes                                                      *
*                                                                            *
*---------------------------------------------------------------------------*/
#define ENOENT  1    /* No such file or directory */
#define E2BIG   2    /* Arg list too big          */
#define ENOEXEC 3    /* Exec format error         */
#define EBADF   4    /* Bad file number           */
#define ENOMEM  5    /* Not enough memory         */
#define EACCES  6    /* Permission denied         */
#define EEXIST  7    /* File exists               */
#define EXDEV   8    /* Cross-device link         */
#define EINVAL  9    /* Invalid argument          */
#define ENFILE  10   /* File table overflow       */
#define EMFILE  11   /* Too many open files       */
#define ENOSPC  12   /* No space left on device   */
/*---------------------------------------------------------------------------*
*                                                                            *
*      Math errors                                                           *
*                                                                            *
*---------------------------------------------------------------------------*/
#define EDOM    13   /* Argument too large        */
#define ERANGE  14   /* Result too large          */
/*---------------------------------------------------------------------------*
*                                                                            *
*      File locking error                                                    *
*                                                                            *
*---------------------------------------------------------------------------*/
#define EDEADLK 15   /* Resource deadlock would occur */
/*---------------------------------------------------------------------------*
*                                                                            *
*   Additional (implementation defined) errno values                         *
*                                                                            *
*---------------------------------------------------------------------------*/
#define EINUSE     16   /* resource(s) in use                                */
#define ESERVER    17   /* server error (out of memory, I/O error, etc.)     */
#define ENOSERVR   18   /* no server (no queue server, no file server...     */
#define EWRNGKND   19   /* wrong kind - an operation is being attempted      */
                        /*  on the wrong kind of object                      */
#define ETRNREST   20   /* transaction restarted (NetWareErrno == 163)       */
#define ERESOURCE  21   /* Resources are (maybe permanently) not available   */
#define EBADHNDL   22   /* A bad non-file handle (screen, semaphore, etc)    */
#define ENO_SCRNS  23   /* Screen I/O attempted when no screens              */
/*---------------------------------------------------------------------------*
*                                                                            *
*   Streams error codes                                                      *
*                                                                            *
*---------------------------------------------------------------------------*/
#define  EAGAIN    24   /* Resource temporarily unavailable                  */
#define  ENXIO     25   /* No such device or address                         */
#define  EBADMSG   26   /* Not a data message                                */
#define  EFAULT    27   /* Bad address                                       */
#define  EIO       28   /* Physical I/O error                                */
#define  ENODATA   29   /* No data                                           */
#define  ENOSTRMS  30   /* Streams not loaded                                */
/*---------------------------------------------------------------------------*
*                                                                            *
*   BSD sockets error codes                                                  *
*                                                                            *
*---------------------------------------------------------------------------*/
#define  EPROTO   31    /* Fatal protocol error                             */
#define  EPIPE    32    /* Broken pipe                                      */
#define  ESPIPE   33    /* Illegal seek (should be 29)                      */

/* non-blocking and interrupt i/o */
#define  ETIME       34 /* Ioctl acknowledge timeout                        */
#define  EWOULDBLOCK 35 /* Operation would block                            */
#define  EINPROGRESS 36 /* Operation now in progress                        */
#define  EALREADY    37 /* Operation already in progress                    */

/* ipc/network software                                                     */

/* argument errors */
#define  ENOTSOCK        38   /* Socket operation on non-socket             */
#define  EDESTADDRREQ    39   /* Destination address required               */
#define  EMSGSIZE        40   /* Message too long                           */
#define  EPROTOTYPE      41   /* Protocol wrong type for socket             */
#define  ENOPROTOOPT     42   /* Protocol not available                     */
#define  EPROTONOSUPPORT 43   /* Protocol not supported                     */
#define  ESOCKTNOSUPPORT 44   /* Socket type not supported                  */
#define  EOPNOTSUPP      45   /* Operation not supported on socket          */
#define  EPFNOSUPPORT    46   /* Protocol family not supported              */
#define  EAFNOSUPPORT    47   /* Address family not supported by protocol family */
#define  EADDRINUSE      48   /* Address already in use                     */
#define  EADDRNOTAVAIL   49   /* Can't assign requested address             */

/* operational errors */
#define  ENETDOWN        50   /* Network is down                            */
#define  ENETUNREACH     51   /* Network is unreachable                     */
#define  ENETRESET       52   /* Network dropped connection on reset        */
#define  ECONNABORTED    53   /* Software caused connection abort           */
#define  ECONNRESET      54   /* Connection reset by peer                   */
#define  ENOBUFS         55   /* No buffer space available                  */
#define  EISCONN         56   /* Socket is already connected                */
#define  ENOTCONN        57   /* Socket is not connected                    */
#define  ESHUTDOWN       58   /* Can't send after socket shutdown           */
#define  ETOOMANYREFS    59   /* Too many references: can't splice          */
#define  ETIMEDOUT       60   /* Connection timed out                       */
#define  ECONNREFUSED    61   /* Connection refused                         */

/*---------------------------------------------------------------------------*
*                                                                            *
*   NetWareErrno values (in addition to the ones niterror.h)                 *
*                                                                            *
*---------------------------------------------------------------------------*/
#define ERR_BAD_THREAD_ID        102
#define ERR_BAD_PRTY_CLASS       103
#define ERR_BAD_PRTY_SCOPE       104
#define ERR_NOT_A_POPUP_SCREEN   105
#define ERR_OPEN_SCREEN          106 
#define ERR_BAD_SHFLAG           107
#define ERR_BAD_ACCESS           108
#define ERR_BAD_ORIGIN           109
#define ERR_BAD_ACTION_CODE      110
#define ERR_OUT_OF_TASKS         111
#define ERR_BAD_QUERY_TYPE       112
#define ERR_BAD_LIBRARY_HANDLE   113
#define ERR_STREAMS              114
#define ERR_BAD_FILE_SERVER_ID   115
#define ERR_BAD_FLAGS            116

#define ERR_STRUCT_NOT_FOUND     200

#define ERR_INVALID_NAME_LENGTH 0xFE  

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   _msize error return values                                               *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define ERR_HEAP_BAD_PTR               0xFFFFFFFF
#define ERR_HEAP_BLOCK_ALREADY_FREE    0xFFFFFFFE

/*----------------------------------------------------------------------------*
 *                                                                            *
 *   Obsolete NetWareErrno values                                             *
 *                                                                            *
 *----------------------------------------------------------------------------*/
#define ERR_BAD_CONNECTION_ID    ERR_BAD_FILE_SERVER_ID

/*---------------------------------------------------------------------------*
*                                                                            *
*   Prototypes for errno helper functions (Do NOT call these directly)       *
*                                                                            *
*---------------------------------------------------------------------------*/
extern int *__get_errno_ptr( void );

#define _ERRNO_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _ERRNO_H_INCLUDED */
