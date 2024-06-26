/****************************************************************************
*
* (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
* (c) Copyright 1982, 1985, 1986 Regents of the University of
*     California.  All rights reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
* NetWare C NLM Runtime Library source code
*
*****************************************************************************/

#ifndef _SYS_SOCKET_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Definitions related to sockets: types, address families, options.
 */

/*
 * Types
 */
#define	SOCK_NULL	   0		/* just NW OFSD, no socket */
#define	SOCK_STREAM	   1		/* stream socket */
#define	SOCK_DGRAM	   2		/* datagram socket */
#define	SOCK_RAW	      3		/* raw-protocol interface */
#define	SOCK_RDM	      4		/* reliably-delivered message */
#define	SOCK_SEQPACKET	5		/* sequenced packet stream */

/*
 * Option flags per-socket.
 */
#define	SO_DEBUG	      0x0001		/* turn on debugging info recording */
#define	SO_ACCEPTCONN	0x0002		/* socket has had listen() */
#define	SO_REUSEADDR	0x0004		/* allow local address reuse */
#define	SO_KEEPALIVE	0x0008		/* keep connections alive */
#define	SO_DONTROUTE	0x0010		/* just use interface addresses */
#define	SO_BROADCAST	0x0020		/* permit sending of broadcast msgs */
#define	SO_USELOOPBACK	0x0040		/* bypass hardware when possible */
#define	SO_LINGER	   0x0080		/* linger on close if data present */
#define	SO_OOBINLINE	0x0100		/* leave received OOB data in line */
/*
 * N.B.: The following definition is present only for compatibility
 * with release 3.0.  It will disappear in later releases.
 */
#define	SO_DONTLINGER	(~SO_LINGER)	/* ~SO_LINGER */

/*
 * Additional options, not kept in so_options.
 */
#define	SO_SNDBUF	0x1001		/* send buffer size */
#define	SO_RCVBUF	0x1002		/* receive buffer size */
#define	SO_SNDLOWAT	0x1003		/* send low-water mark */
#define	SO_RCVLOWAT	0x1004		/* receive low-water mark */
#define	SO_SNDTIMEO	0x1005		/* send timeout */
#define	SO_RCVTIMEO	0x1006		/* receive timeout */
#define	SO_ERROR	   0x1007		/* get error status and clear */
#define	SO_TYPE		0x1008		/* get socket type */

/*
 * Structure used for manipulating linger option.
 */
struct	linger
   {
	int	l_onoff;		   /* option on/off */
	int	l_linger;		/* linger time */
   };

/*
 * Level number for (get/set)sockopt() to apply to socket itself.
 */
#define	SOL_SOCKET	0xffff		/* options for socket level */

/*
 * Address families.
 */
#define	AF_UNSPEC	   0		/* unspecified */
#define	AF_UNIX		   1		/* local to host (pipes, portals) */
#define	AF_INET		   2		/* internetwork: UDP, TCP, etc. */
#define	AF_NS		      6		/* XEROX NS protocols */
#define	AF_APPLETALK	16		/* Apple Talk */
#define	AF_OSI		   19		/* umbrella for all families used
               					 * by OSI (e.g. protosw lookup) */
#define	AF_GOSIP	      22		/* U.S. Government OSI */

#define	AF_MAX		   21

/*
 * Structure used by kernel to store most
 * addresses.
 */
struct sockaddr
   {
	unsigned short	sa_family;	/* address family */
	char		sa_data[14];	   /* up to 14 bytes of direct address */
   };

/*
 * Structure used by kernel to pass protocol
 * information in raw sockets.
 */
struct sockproto
   {
	unsigned short	sp_family;	   /* address family */
	unsigned short	sp_protocol;	/* protocol */
   };

/*
 * Protocol families, same as address families for now.
 */
#define	PF_UNSPEC	   AF_UNSPEC
#define	PF_UNIX		   AF_UNIX
#define	PF_INET		   AF_INET
#define	PF_NS		      AF_NS
#define	PF_APPLETALK	AF_APPLETALK
#define	PF_OSI		   AF_OSI
#define	PF_GOSIP	      AF_GOSIP

#define	PF_MAX		   AF_MAX

#define	TSTPROTO_NPIPE	0		/* test protocol "numbered pipe" */

/*
 * Maximum queue length specifiable by listen.
 */
#define	SOMAXCONN	5

/*
 * Message header for recvmsg and sendmsg calls.
 */
struct iovec;
struct msghdr 
   {
	char	   *msg_name;		   /* optional address */
	int	   msg_namelen;		/* size of address */
	struct	iovec *msg_iov;	/* scatter/gather array */
	int	   msg_iovlen;		   /* # elements in msg_iov */
	char	   *msg_accrights;	/* access rights sent/received */
	int	   msg_accrightslen;
   };

#define	MSG_OOB		   0x1		/* process out-of-band data */
#define	MSG_PEEK	      0x2		/* peek at incoming message */
#define	MSG_DONTROUTE	0x4		/* send without using routing tables */

#define	MSG_MAXIOVLEN	16

#define	SKT	int			         /* for clib clients */

int   accept(
         SKT s,
         struct sockaddr *addr,
         int *addrlen );

int   bind(
         SKT s,
         struct sockaddr *name,
         int namelen );

int   connect(
         SKT s,
         struct sockaddr *name,
         int namelen );

#ifndef fcntl
int   fcntl(
         SKT s,
         int option,
         int arg );
#endif

int   getpeername(
         SKT s,
         struct sockaddr *name,
         int *namelen );

int   getsockname(
         SKT s,
         struct sockaddr *name,
         int *namelen );

int   getsockopt(
         SKT s,
         int level,
         int optname,
         char *optval,
         int *optlen );

int   setsockopt(
         SKT s,
         int level,
         int optname,
         char *optval,
         int optlen );

int   listen(
         SKT s,
         int backlog );

int   readv(
         SKT s,
         struct iovec *iov,
         int iovcnt );

int   recv(
         SKT s,
         char *msg,
         int len,
         int flags );

int   recvfrom(
         SKT s,
         char *msg,
         int len,
         int flags,
         struct sockaddr *from,
         int *fromlen );

int   recvmsg(
         SKT s,
         struct msghdr *msg,
         int flags );

struct timeval;
int   select(
         int width,
         fd_set *readfds,
         fd_set *writefds,
         fd_set *exceptfds,
         struct timeval *timeout );

int   send(
         SKT s,
         char *msg,
         int len,
         int flags );

int   sendto(
         SKT s,
         char *msg,
         int len,
         int flags,
         struct sockaddr *to,
         int tolen );

int   sendmsg(
         SKT s,
         struct msghdr *msg,
         int flags );

int   shutdown(
         SKT s,
         int how );

int   socket(
         int domain,
         int type,
         int protocol );

int   writev(
         SKT s,
         struct iovec *iov,
         int iovcnt );

int   sel_cvt_to_skts(
         int width,
         fd_set *fdpt );
void  sel_cvt_from_skts(
         int width,
         fd_set *fdpt );

#define _SYS_SOCKET_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _SYS_SOCKET_H_INCLUDED */
