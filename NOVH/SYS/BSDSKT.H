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

#ifndef _SYS_BSDSKT_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*
 *                                                                            *
 *      NetWare 386 Developer's C Runtime library                             *
 *                                                                            *
 *      This include file defines the constants, types, structures,           *
 *      and prototypes for the Berkley Sockets functions.                     *        
 *                                                                            *
 *      (c) Copyright.  1989-1990 Novell, Inc.  All rights reserved.          *
 *      (c) Copyright 1982, 1985, 1986 Regents of the University of           *
 *      California.  All rights reserved.                                     *
 *                                                                            *
 *----------------------------------------------------------------------------*/

/* Generic BSD Socket Adapter Interface */

/*----------------------------------------------------------------------------*
 *   Select control block, used to wakeup sleeping select calls which         *
 *   refer to some socket.                                                    *
 *   IMPORTANT:  AESProcessStructure must be first element in structure.      *
 *----------------------------------------------------------------------------*/
typedef struct selcb
   {
   struct AESProcessStructure sel_aesps;  /* call-back control block */
   unsigned long     sel_done_time;       /* relative to CurrentTime */
   LONG              sel_pid;             /* sleeper's process ID */
   struct selcb      *sel_clsn_next;      /* collision queue */
   int               sel_flags;           /* see below */
   } selcb;

#define  sel_link          (selcb *)sel_aesps.ALink
#define  sel_delay_ticks   sel_aesps.AWakeUpDelayAmount
#define  sel_wakeup_time   sel_aesps.AWakeUpTime
#define  sel_anr           sel_aesps.AProcessToCall
#define  sel_tag           sel_aesps.ARTag
#define  sel_oldlink       sel_aesps.AOldLink

#define  SEL_CLSN    (1<<0)         /* on collision queue */
#define  SEL_WAKEUP  (1<<1)         /* woken up by protocol */
#define  SEL_TIMEOUT (1<<2)         /* timed out */
#define  SEL_AES     (1<<3)         /* AES wakeup pending */

/* Thread control block, used for bsd_sleep() and bsd_wakeup(). */
typedef struct skt_threadcb
   {
   struct skt_threadcb  *stc_next;  /* queue of sleepers */
   LONG        stc_pid;    /* sleeper's PID */
   int         stc_event;  /* mask of event flags */
   } skt_threadcb;

/*----------------------------------------------------------------------------*
 *   Client of GSA supplies this routine in PCB for upcalls,                  *
 *   especially for the case where an adapter unloads.                        *
 *----------------------------------------------------------------------------*/
typedef void gsa_anr(
         int handle,
         int opcode,
         char *argpt );

/* Op-codes for the ANR above. */
#define  BSDANR_DEREGISTER 1  /* stub out the adapter switch */

/*----------------------------------------------------------------------------*
 *   Each protocol adapter should include this structure at the beginning     *
 *   of its own control block.  The generic code modifies and examines        *
 *   these fields.  The specific protocol adapter may examine all fields,     *
 *   although most adapters will ignore most fields.  It may also modify      *
 *   some fields, as noted elsewhere.                                         *
 *----------------------------------------------------------------------------*/
struct sktswch;
typedef struct skthdr
   {
   struct skthdr  *gso_next;     /* generic adapter's queue */
   int            gso_structid;  /* always SKTSignature */
   struct sktswch *gso_switch;   /* protocol adapter switch */
   int            gso_clientid;  /* filled in by client */
   gsa_anr        *gso_clientanr;/* filled in by client */
   struct selcb   *gso_rselcb;   /* read select control block */
   struct selcb   *gso_wselcb;   /* write select control block */
   struct selcb   *gso_xselcb;   /* exception select control block */
   skt_threadcb   *gso_sleepq;   /* sleeping threads */
   int            gso_options;   /* SO_* flags, from socket.h */
   int            gso_state;     /* SS_* flags, below */
   int            gso_error;     /* last error on socket */
   int            gso_linger;
   int            gso_sndqta;
   int            gso_rcvqta;
   int            gso_sndlowat;
   int            gso_rcvlowat;
   int            gso_sndtimeo;
   int            gso_rcvtimeo;
   } skthdr;

#define  SKTSignature   0x20544B53  /* "SKT ", in memory dump */

/* gso_state bits: */
#define  SS_NOFDREF           (1<<0)   /* no file table ref any more */
#define  SS_ISCONNECTED       (1<<1)   /* socket connected to a peer */
#define  SS_ISCONNECTING      (1<<2)   /* in process of connecting to peer */
#define  SS_ISDISCONNECTING   (1<<3)   /* in process of disconnecting */
#define  SS_CANTSENDMORE      (1<<4)   /* can't send more data to peer */
#define  SS_CANTRCVMORE       (1<<5)   /* can't receive more data from peer */
#define  SS_RCVATMARK         (1<<6)   /* at mark on input */
#define  SS_PRIV              (1<<7)   /* privileged for broadcast, raw... */
#define  SS_NBIO              (1<<8)   /* non-blocking ops */
#define  SS_ASYNC             (1<<9)   /* async i/o notify */
#define  SS_RSELCLSN          (1<<10)  /* read select collision */
#define  SS_WSELCLSN          (1<<11)  /* write select collision */
#define  SS_XSELCLSN          (1<<12)  /* exception select collision */

/*----------------------------------------------------------------------------*
 *   Used to transfer appropriate parameters from mother to daughter during   *
 *   spawning.                                                                *
 *----------------------------------------------------------------------------*/
#define  GSO_SPAWN(m, d) \
   { \
   (d)->gso_structid = (m)->gso_structid; \
   (d)->gso_switch = (m)->gso_switch; \
   (d)->gso_clientanr = (m)->gso_clientanr; \
   (d)->gso_options = (m)->gso_options & ~SO_ACCEPTCONN; \
   (d)->gso_state = (m)->gso_state; \
   (d)->gso_linger = (m)->gso_linger; \
   (d)->gso_sndqta = (m)->gso_sndqta; \
   (d)->gso_rcvqta = (m)->gso_rcvqta; \
   (d)->gso_sndlowat = (m)->gso_sndlowat; \
   (d)->gso_rcvlowat = (m)->gso_rcvlowat; \
   (d)->gso_sndtimeo = (m)->gso_sndtimeo; \
   (d)->gso_rcvtimeo = (m)->gso_rcvtimeo; \
   }

/*----------------------------------------------------------------------------*
 *   BSD interface routines, called from above by Clib stubs.                 *
 *   These may also be called by non-Clib NW/386 NLMs.                        *
 *----------------------------------------------------------------------------*/
struct sockaddr;
struct msghdr;
struct timeval;

skthdr *bsd_accept(
         skthdr *sktpt,
         struct sockaddr *addr,
         int *addrlen,
         int *RCp );

int   bsd_bind(
         skthdr *sktpt,
         struct sockaddr *name,
         int namelen,
         int *RCp );

int   bsd_close(
         skthdr *sktpt,
         int *RCp );

int   bsd_connect(
         skthdr *sktpt,
         struct sockaddr *name,
         int namelen,
         int *RCp );

int   bsd_getpeername(
         skthdr *sktpt,
         struct sockaddr *name,
         int *namelen,
         int *RCp );

int   bsd_getsockname(
         skthdr *sktpt,
         struct sockaddr *name,
         int *namelen,
         int *RCp );

int   bsd_getsockopt(
         skthdr *sktpt,
         int level,
         int optname,
         char *optval,
         int *optlen,
         int *RCp );

int   bsd_setsockopt(
         skthdr *sktpt,
         int level,
         int optname,
         char *optval,
         int optlen,
         int *RCp );

int   bsd_ioctl(
         skthdr *sktpt,
         int request,
         char *arg,
         int *RCp );

int   bsd_listen(
         skthdr *sktpt,
         int backlog,
         int *RCp );

int   bsd_recvmsg(
         skthdr *sktpt,
         struct msghdr *msg,
         int flags,
         int *RCp );

int   bsd_select(
         int width,
         fd_set *readfds,
         fd_set *writefds,
         fd_set *exceptfds,
         struct timeval *timeout,
         int *RCp );

int   bsd_sendmsg(
         skthdr *sktpt,
         struct msghdr *msg,
         int flags,
         int *RCp );

int   bsd_shutdown(
         skthdr *sktpt,
         int how,
         int *RCp );

skthdr *bsd_socket(
         int domain,
         int type,
         int protocol,
         int *RCp );

void  bsd_fd_set(
         int n,
         fd_set *p );

void  bsd_fd_clr(
         int n,
         fd_set *p );

int   bsd_fd_isset(
         int n,
         fd_set *p );

int   bsd_forget_thread(
         skthdr *sktpt,
         int pid );


/*----------------------------------------------------------------------------*
 *   Specific Socket Adapter (SSA) routines.  The GSA enters these            *
 *   via a switch structure which the SSA registers with the GSA.             *
 *----------------------------------------------------------------------------*/
typedef skthdr *ssa_accept(
         skthdr *pcbpt,
         struct sockaddr *addr,
         int *addrlen,
         int *rcpt );

typedef void ssa_bind(
         skthdr *pcbpt,
         struct sockaddr *name,
         int namelen,
         int *rcpt );

typedef void ssa_close(
         skthdr *pcbpt,
         int *rcpt );

typedef void ssa_connect(
         skthdr *pcbpt,
         struct sockaddr *name,
         int namelen,
         int *rcpt );

typedef void ssa_getpeername(
         skthdr *pcbpt,
         struct sockaddr *name,
         int *namelen,
         int *rcpt );

typedef void ssa_getsockname(
         skthdr *pcbpt,
         struct sockaddr *name,
         int *namelen,
         int *rcpt );

typedef void ssa_getsockopt(
         skthdr *pcbpt,
         int level,
         int optname,
         char *optval,
         int *optlen,
         int *rcpt );

typedef void ssa_setsockopt(
         skthdr *pcbpt,
         int level,
         int optname,
         char *optval,
         int optlen,
         int *rcpt );

typedef void ssa_ioctl(
         skthdr *pcbpt,
         int request,
         char *arg,
         int *rcpt );

typedef void ssa_listen(
         skthdr *pcbpt,
         int backlog,
         int *rcpt );

typedef int ssa_recvmsg(
         skthdr *pcbpt,
         struct msghdr *msg,
         int flags,
         int *rcpt );

typedef int ssa_rselect(
         skthdr *pcbpt );

typedef int ssa_wselect(
         skthdr *pcbpt );

typedef int ssa_xselect(
         skthdr *pcbpt );

typedef int ssa_sendmsg(
         skthdr *pcbpt,
         struct msghdr *msg,
         int flags,
         int *rcpt );

typedef void ssa_shutdown(
         skthdr *pcbpt,
         int how,
         int *rcpt );

typedef struct skthdr *ssa_socket(
         int *rcpt );

/* Specific Socket Adapter switch, registered with GSA. */
typedef struct sktswch
   {
   struct sktswch *sas_next;        /* forms a list of switches */
   int               sas_version;   /* contains SKT_VERSION */
   int               sas_type;      /* SOCK_*, from socket.h */
   int               sas_family;    /* PF_*, from socket.h */
   int               sas_protocol;  /* *PROTO_*, per-family ID */
   ssa_accept        *sas_accept;
   ssa_bind          *sas_bind;
   ssa_close         *sas_close;
   ssa_connect       *sas_connect;
   ssa_getpeername   *sas_getpeername;
   ssa_getsockname   *sas_getsockname;
   ssa_getsockopt    *sas_getsockopt;
   ssa_setsockopt    *sas_setsockopt;
   ssa_ioctl         *sas_ioctl;
   ssa_listen        *sas_listen;
   ssa_recvmsg       *sas_recvmsg;
   ssa_rselect       *sas_rselect;
   ssa_wselect       *sas_wselect;
   ssa_wselect       *sas_xselect;
   ssa_sendmsg       *sas_sendmsg;
   ssa_shutdown      *sas_shutdown;
   ssa_socket        *sas_socket;
   } sktswch;

#define  SKT_VERSION 0x0001      /* GSA interface version */

#define  SKTE_OK           0  /* function worked right */
#define  SKTE_BADVERSION   1  /* bsd_register() failed */
#define  SKTE_NOTFOUND     2  /* bsd_deregister() didn't find the */
                              /* indicated switch on the list */

/*----------------------------------------------------------------------------*
 *   bsd_sleep, bsd_wakeup events:                                            *
 *   Read and write are given distinct flags to promote efficiency.           *
 *   All other events are lumped together to assure robustness.               *
 *----------------------------------------------------------------------------*/
#define  BSL_READ    (1<<0)
#define  BSL_WRITE   (1<<1)
#define  BSL_GENERAL (BSL_READ | BSL_WRITE)

/* These are called from below, by the specific protocol adapter. */
unsigned int bsd_deregister(
         sktswch *swpt );

unsigned int bsd_register(
         sktswch *swpt );

void  bsd_select_wakeup(
         selcb *selcbpt );

void  bsd_sleep(
         skthdr *sktpt,
         int event );

void  bsd_wakeup(
         skthdr *sktpt,
         int event );

int   bsd_wakeup_all(
         skthdr *sktpt );

#define _SYS_BSDSKT_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _SYS_BSDSKT_H_INCLUDED */
