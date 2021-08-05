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

#ifndef _OSITLI_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Disconnect reason codes
 */

#define TPDR_NORMAL	(128 + 0)	/* Normal disconnect initiated by */
					/* the session entity. */
#define TPDR_CRCONG	(128 + 1)	/* Remote transport entity congestion */
					/* at connect request time */
#define TPDR_CONNEG	(128 + 2)	/* Connection negotiation failed */
#define TPDR_DUPSR	(128 + 3)	/* Duplicate source reference */
					/* detected for same pair of NSAPs */
#define TPDR_MMREF	(128 + 4)	/* Mismatched references */
#define TPDR_PE		(128 + 5)	/* Protocol error */
#define TPDR_REOVFL	(128 + 7)	/* Reference overflow */
#define TPDR_NWREF	(128 + 8)	/* Connection request refused on */
					/* this network connection */
#define TPDR_INVHD	(128 + 10)	/* Header or parameter length */
					/* invalid */
#define TPDR_RNS	0		/* Reason not specified */
#define TPDR_CONG	1		/* Congestion at the TSAP */
#define TPDR_NOSESS	2		/* Session entity not attached to */
					/* TSAP */
#define TPDR_UNKADDR	3		/* Address unknown */



/*
 * Options management pre-defined values.
 */
#define T_YES		 1
#define T_NO		 0
#define T_UNUSED 	-1
#define T_NULL		0
#define T_ABSREQ		0x8000

#define T_PRIDFLT	4
#define T_PRILOW	3
#define T_PRIMID	2
#define T_PRIHIGH	1
#define T_PRITOP	0

#define T_NOPROTECT		1
#define T_PASSIVEPROTECT	2
#define T_ACTIVEPROTECT		4

#define T_LTPDUDFLT	2048

#define T_CLASS0	0
#define T_CLASS1	1
#define T_CLASS2	2
#define T_CLASS3	3
#define T_CLASS4	4

/*
 * Options Management structures.
 */

struct rate {
	long targetvalue;	/* target value */
	long minacceptvalue;	/* minimum acceptable value */
};

struct reqvalue {
	struct rate called; 	/* called rate */
	struct rate calling;	/* calling rate */
};

struct thrpt {
	struct reqvalue maxthrpt;	/* maximum throughput */
	struct reqvalue avgthrpt;	/* average throughput */
};

struct management {
	short 	dflt;		/* T_YES: the following parameters are */
				/*   ignored, default values are used */
				/* T_NO: the following parameters are used */
	int 	ltpdu;		/* maximum length of TPDU (in octets) */
	short 	reastime;	/* reassignment time (in seconds) */
	char 	class;		/* preferred class; value T_CLASS0 - TCLASS4 */
	char 	altclass;	/* alternative class */
	char 	extform;	/* extended format T_YES or T_NO */
	char 	flowctrl;	/* flow control: T_YES or T_NO */
	char 	checksum;	/* checksum (cl. 4) T_YES or T_NO */
	char 	netexp;		/* network expedited data: T_YES or T_NO */
	char 	netrecptcf;	/* receipt confirmation: T_YES or T_NO */
};

/*
 * Connection oriented options.
 */
struct isoco_options {
	struct 	thrpt	 throughput;	 /* throughput */
	struct 	reqvalue transdel;	 /* transit delay */
	struct 	rate	 reserrorrate;	 /* residual error rate */
	struct 	rate	 transffailprob; /* transfer failure prob. */
	struct 	rate	 estfailprob;	 /* connection establ. failure prob. */
	struct	rate	 relfailprob;	 /* connection release failure prob. */
	struct	rate	 estdelay;	 /* connection establishment delay */
	struct	rate	 reldelay;	 /* connection release delay */
	struct	netbuf	 connresil;	 /* connection resilience */
	unsigned short	 protection;	 /* protection */
	short		 priority;	 /* priority */
	struct management mngmt;	 /* management parameters */
	char		 expd;		 /* expedited data: T_YES or T_NO */
};

/*
 * Connectionless options.
 */

struct isocl_options {
	struct	rate	transdel;	/* transit delay */
	struct	rate	reserrorrate;	/* residual error rate */
	unsigned short	protection;	/* protection */
	short		priority;	/* priority */
};

/*
 * Novell connectionless options.
 */

struct novell_isocl_options {
	struct	rate	transdel;	/* transit delay */
	struct	rate	reserrorrate;	/* residual error rate */
	unsigned short	protection;	/* protection */
	short		priority;	/* priority */
	int		checksum;	/* checksums */
};


#define _OSITLI_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _OSITLI_H_INCLUDED  */
