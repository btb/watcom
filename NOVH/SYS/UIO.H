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
* This include file defines iovec structure.  This structure is used by
* the socket I/O interface in socket.h
*
*****************************************************************************/

#ifndef _UIO_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

struct iovec {
	char	*iov_base;
	int	iov_len;
};

#define _UIO_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _UIO_H_INCLUDED */

