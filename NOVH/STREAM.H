/** Copyright (c) 1989  Mentat Inc.
 ** stream.h 1.10, last change 8/6/90
 **/

#ifndef _STREAM_
#ifdef __cplusplus
extern "C" {
#endif
#define _STREAM_

struct qinit;
/* defines module or driver */
struct streamtab {
	struct qinit	* st_rdinit;	/* defines read QUEUE */
	struct qinit	* st_wrinit;	/* defines write QUEUE */
	struct qinit	* st_muxrinit;	/* for multiplexing drivers only */
	struct qinit	* st_muxwinit;	/* ditto */
};

struct q_xtra;
struct msgb;
struct queue {
	struct qinit	* q_qinfo;	/* procedures and limits for queue */
	struct msgb	* q_first;	/* head of message queue */
	struct msgb	* q_last;	/* tail of message queue */
	struct queue	* q_next;	/* next QUEUE in Stream */
	struct queue	* q_link;	/* link to scheduling queue */
	char		* q_ptr;	/* to private data structure */
	ushort		q_count;	/* weighted count of characters on q */
	ushort		q_flag;		/* QUEUE state */
	short		q_minpsz;	/* min packet size accepted */
	short		q_maxpsz;	/* max packet size accepted */
	ushort		q_hiwat;	/* high water mark, for flow control */
	ushort		q_lowat;	/* low water mark */
	struct q_xtra	* q_osx;	/* Pointer to OS-dependent extra stuff */
	struct queue	* q_ffcp;	/* Forward flow control pointer */
	struct queue	* q_bfcp;	/* Backward flow control pointer */
};
typedef	struct	queue	queue_t;

/* Q state defines */
#define	F_Q_IS_WRITE_Q		0x1
#define	F_Q_DISABLED		0x2
#define	F_Q_FULL		0x4
#define	F_Q_TO_SCHEDULE		0x8
#define	F_Q_PUT_STOPPED		0x10
#define	F_Q_WELDED		0x20
#define	F_Q_SEQUENT_SYNCH	0x40
/* Q state defines for 5.4 compatibility */
#define QREADR		0x80
#define QFULL	F_Q_FULL
#define QENAB	F_Q_TO_SCHEDULE

struct module_stat;
struct module_info;
struct	qinit {
	int	(*qi_putp)();		/* put procedure */
	int	(*qi_srvp)();		/* service procedure */
	int	(*qi_qopen)();		/* called on each open or a push */
	int	(*qi_qclose)();		/* called on last close or a pop */
	int	(*qi_qadmin)();		/* reserved for future use */
	struct module_info * qi_minfo;	/* information structure */
	struct module_stat * qi_mstat;	/* statistics structure - optional */
};

struct	module_info {
	unsigned short	mi_idnum;	/* module ID number */
	char	* mi_idname;	/* module name */
	short	mi_minpsz;	/* min packet size, for developer use */
	short	mi_maxpsz;	/* max packet size, for developer use */
	short	mi_hiwat;	/* hi-water mark, for flow control */
	short	mi_lowat;	/* lo-water mark, for flow control */
};

struct datab;
/* message block */
struct	msgb {
	struct msgb	* b_next;	/* next message on queue */
	struct msgb	* b_prev;	/* previous message on queue */
	struct msgb	* b_cont;	/* next message block of message */
	unsigned char	* b_rptr;	/* first unread data byte in buffer */
	unsigned char	* b_wptr;	/* first unwritten data byte */
	struct datab	* b_datap;	/* data block */
#ifdef	MSGB_XTRA
	MSGB_XTRA
#endif
};
typedef	struct msgb	mblk_t;

/* data descriptor */
struct	datab {
	struct datab	* db_freep;	/* used internally */
	unsigned char	* db_base;	/* first byte of buffer */
	unsigned char	* db_lim;	/* last byte+1 of buffer */
	unsigned char	db_ref;		/* count of messages pointing to block*/
	unsigned char	db_type;	/* message type */
	unsigned char	db_class;	/* used internally */
	unsigned char	db_pad[1];	/* Take to a quad word boundary */
};
typedef	struct datab	dblk_t;

/* Used in M_IOCTL mblks to muxes (ioc_cmd I_LINK) */
struct	linkblk {
	queue_t	* l_qtop;	/* lowest level write queue of upper stream */
	queue_t	* l_qbot;	/* highest level write queue of lower stream */
	int	l_index;	/* system-unique index for lower stream */
};

/* Message types */
#define	QNORM		0
#define	M_DATA		0		/* Ordinary data */
#define	M_PROTO		1		/* Internal control info and data */
#define	M_BREAK		010		/* Request a driver to send a break */
#define	M_PASSFP	011		/* Used to pass a file pointer */
#define	M_SIG		013		/* Requests a signal to be sent */
#define	M_DELAY		014		/* Request a real-time delay */
#define	M_CTL		015		/* For inter-module communication */
#define	M_IOCTL		016		/* Used internally for I_STR requests */
#define	M_SETOPTS	020		/* Alters characteristics of stream head */
/* Priority messages types */
#define	QPCTL		0200
#define	M_IOCACK	0201		/* Positive ack of previous M_IOCTL */
#define	M_IOCNAK	0202		/* Previous M_IOCTL failed */
#define	M_PCPROTO	0203		/* Same as M_PROTO except for priority*/
#define	M_PCSIG		0204		/* Priority signal */
#define	M_FLUSH		0206		/* Requests modules to flush queues */
#define	M_STOP		0207		/* Request drivers to stop output */
#define	M_START		0210		/* Request drivers to start output */
#define	M_HANGUP	0211		/* Driver can no longer produce data */
#define	M_ERROR		0212		/* Reports downstream error condition */
#define	M_READ		0213		/* Reports client read at stream head */
#define	M_HPDATA	0214		/* PSE-private type; high priority data */

#define	FLUSHALL	1
#define	FLUSHDATA	0

/* structure contained in an M_IOCTL message block */
struct	iocblk {
	int	ioc_cmd;		/* ioctl command type */
	unsigned short	ioc_uid;	/* effective uid of user */
	unsigned short	ioc_gid;	/* effective gid of user */
	unsigned int	ioc_id;		/* ioctl id */
	unsigned int	ioc_count;	/* count of bytes in data field */
	int	ioc_error;		/* error code */
	int	ioc_rval;		/* return value */
};

/* structure contained in an M_PASSFP message block */
struct sth_s;
struct	strpfp {
	unsigned long	pass_file_cookie;	/* file 'pointer' */
	unsigned short	pass_uid;		/* user id of sending stream */
	unsigned short	pass_gid;
	struct sth_s	* pass_sth;		/* Stream head pointer of passed stream */
};

/* structure contained in an M_SETOPTS message block */
struct	stroptions {
	short	so_flags;		/* options to set */
	short	so_readopt;		/* read option */
	unsigned short	so_wroff;	/* write offset */
	short	so_minpsz;		/* minimum read packet size */
	short	so_maxpsz;		/* maximum read packet size */
	unsigned short	so_hiwat;	/* read queue high-water mark */
	unsigned short	so_lowat;	/* read queue low-water mark */
};
/* definitions for so_flags field */
#define	SO_ALL		0377	/* Update all options */
#define	SO_READOPT	01	/* Set the read mode */
#define	SO_WROFF	02	/* Insert an offset in write M_DATA mblks */
#define	SO_MINPSZ	04	/* Change the min packet size on sth rq */
#define	SO_MAXPSZ	010	/* Change the max packet size on sth rq */
#define	SO_HIWAT	020	/* Change the high water mark on sth rq */
#define	SO_LOWAT	040	/* Change the low water mark */
#define	SO_MREADON	0100	/* Request M_READ messages */
#define	SO_MREADOFF	0200	/* Don't gen M_READ messages */

/* Buffer Allocation Priority */
#define	BPRI_LO		1
#define	BPRI_MED	2
#define	BPRI_HI		3

#ifndef	INFPSZ
#define	INFPSZ		-1
#endif

#ifndef MAXMSGSIZE
#define	MAXMSGSIZE	4096
#endif

/** Test whether message is a data message */
#define	datamsg(type)	((type) == M_DATA || (type) == M_PROTO || (type) == M_PCPROTO)

/** Re-allow a queue to be scheduled for service */
#define	enableok(q)	((q)->q_flag &= ~F_Q_DISABLED)

/** Prevent a queue from being scheduled */
#define	noenable(q)	((q)->q_flag |= F_Q_DISABLED)

/** Get pointer to the mate queue */
#define	OTHERQ(q)	(((q)->q_flag & F_Q_IS_WRITE_Q) ? RD(q) : WR(q))

#ifndef	MULTI_CPU
#ifdef DEBUG
#define putnext(q, mp)	__putnext(q, mp)
extern	int __putnext (queue_t *q, mblk_t *mp);
#else
#define	putnext(q, mp)	((*(q)->q_next->q_qinfo->qi_putp)(q->q_next, mp))
#endif
#define	puthere(q, mp)	((*(q)->q_qinfo->qi_putp)(q, mp))
#endif

/** Get pointer to the read queue, assumes 'q' is a write queue ptr */
#define	RD(q)	(&(q)[-1])

/** Get pointer to the write queue, assumes 'q' is a read queue ptr */
#define	WR(q)	(&(q)[1])

#define	OPENFAIL	(-1)
#define	CLONEOPEN	0x2
#define	MODOPEN		0x1

#define	NSTREVENT	40
#define	STRMSGSZ	MAXMSGSIZE
#define	STRCTLSZ	1024
#define STRLOFRAC	80
#define	STRMEDFRAC	90
#define	MAXBSIZE	MAXMSGSIZE

#define max(x1,x2)	((x1) >= (x2) ? (x1) : (x2))
#define min(x1,x2)	((x1) <= (x2) ? (x1) : (x2))

extern	mblk_t	* allocb(   int size, int pri   );
extern	queue_t	* allocq(   void   );
extern	int	adjmsg(   mblk_t * mp, int len_param   );
extern	queue_t	* backq(   queue_t * q   );
extern	int	bufcall(   int size, int pri, int (* func)(), long arg   );
#ifndef bcopy
extern	void	bcopy(   char * src, char * dst, int len   );
#endif
#ifndef bzero
extern	void	bzero(   char * buffer, int nbytes   );
#endif
extern	int	canput(   queue_t * q   );
extern	mblk_t	* copyb(   mblk_t * mp   );
extern	mblk_t	* copymsg(   mblk_t * mp   );
extern	mblk_t	* dupb(   mblk_t * bp   );
extern	mblk_t	* dupmsg(   mblk_t * mp   );
extern	int	flushq(   queue_t * q, int flag   );
extern	int	freeb(   mblk_t * bp   );
extern	int	freemsg(   mblk_t * mp   );
extern	int	freeq(   queue_t * q   );
extern	mblk_t	* getq(   queue_t * q   );
extern	int	insq(   queue_t * q, mblk_t * emp, mblk_t * nmp   );
extern	int	linkb(   mblk_t * mp1, mblk_t * mp2   );
extern	int	msgdsize(   mblk_t * mp   );
extern	int	pullupmsg(   mblk_t * mp, int len   );
extern	int	putbq(   queue_t * q, mblk_t * mp   );
extern	int	putctl(   queue_t * q, int type   );
extern	int	putctl1(   queue_t * q, int type, int c   );
extern	int	putq(   queue_t * q, mblk_t * mp   );
extern	int	qenable(   queue_t * q   );
extern	int	qreply(   queue_t * q, mblk_t * mp   );
extern	int	qsize(   queue_t * q   );
extern	mblk_t	* rmvb(   mblk_t * mp, mblk_t * bp   );
extern	int	rmvq(   queue_t * q, mblk_t * mp   );
extern	int	strlog(   short sid, short mid, char level, short aflags, ...   );
extern	int	testb(   int size, int pri   );
extern	int	timeout(   int (* func)(), void * arg, int ticks   );
extern	mblk_t	* unlinkb(   mblk_t * mp   );
extern	int unbufcall(   int id   );

#ifndef	sleep
#define	sleep		StreamSleep
#endif

#ifdef __cplusplus
};
#endif
#endif
