/** Copyright (c) 1989  Mentat Inc.
 ** stropts.h 1.7, last change 7/9/90
 **/

#ifndef	_STROPTS_
#ifdef __cplusplus
extern "C" {
#endif
#define	_STROPTS_

/* ioctl command values */
#ifdef BSD
#include <ioctl.h>
#else
#ifdef VMS
#define	_IO(t,v)	(v)
#else
#define	_IO(t,v)	(('t' << 8)|v)
#endif
#endif

#define	I_NREAD		_IO(t,1)	/* return the number of bytes in 1st msg */
#define	I_PUSH		_IO(t,2)	/* push module just below stream head */
#define	I_POP		_IO(t,3)	/* pop module below stream head */
#define	I_LOOK		_IO(t,4)	/* retrieve name of first stream module */
#define	I_FLUSH		_IO(t,5)	/* flush all input and/or output queues */
#define	I_SRDOPT	_IO(t,6)	/* set the read mode */
#define	I_GRDOPT	_IO(t,7)	/* get the current read mode */
#define	I_STR		_IO(t,8)	/* create an internal ioctl message */
#define	I_SETSIG	_IO(t,9)	/* request SIGPOLL signal on events */
#define	I_GETSIG	_IO(t,10)	/* query the registered events */
#define	I_FIND		_IO(t,11)	/* check for module in stream */
#define	I_LINK		_IO(t,12)	/* connect stream under mux fd */
#define	I_UNLINK	_IO(t,13)	/* disconnect two streams */
#define	I_PEEK		_IO(t,15)	/* peek at data on read queue */
#define	I_FDINSERT	_IO(t,16)	/* create a message and send downstream */
#define	I_SENDFD	_IO(t,17)	/* send an fd to a connected pipe stream */
#define	I_RECVFD	_IO(t,18)	/* retrieve a file descriptor */

/* ioctl values needed on non-5.3 systems */
#define	I_GETMSG	_IO(t,40)	/* getmsg() system call */
#define	I_PUTMSG	_IO(t,41)	/* putmsg() system call */
#define	I_POLL		_IO(t,42)	/* poll() system call */
#define	I_SETDELAY	_IO(t,43)	/* set blocking status */
#define	I_GETDELAY	_IO(t,44)	/* get blocking status */
#define	I_RUN_QUEUES	_IO(t,45)	/* sacrifice for the greater good */

#ifdef	VMS
#define	I_MAPREGION	_IO(t,57)	/* permanently map a user region */
#define	I_UNMAP		_IO(t,58)	/* unmap previously set region */
#endif

/* priority message request on putmsg() or strpeek */
#define	RS_HIPRI	0x1

/* return values from getmsg(), 0 indicates all ok */
#define	MORECTL		0x1	/* more control info available */
#define	MOREDATA	0x2	/* more data available */

/* flush requests */
#define	FLUSHR		0x1		/* Flush the read queue */
#define	FLUSHW		0x2		/* Flush the write queue */
#define	FLUSHRW		(FLUSHW|FLUSHR)	/* Flush both */

/* signal event masks */
#define	S_INPUT		0x1	/* non-priority message has arrived */
#define	S_HIPRI		0x2	/* priority message on stream head read q */
#define	S_OUTPUT	0x4	/* write queue is no longer full */
#define	S_MSG		0x8	/* signal message at front of read queue */

/* read modes for I_S|GRDOPT */
#define	RNORM		0	/* byte-stream mode, default */
#define	RMSGD		1	/* message-discard mode */
#define	RMSGN		2	/* message-nondiscard mode */
#define	RFILL		3	/* fill read buffer mode (PSE private) */

struct	strbuf {
	int	maxlen;		/* max buffer length */
	int	len;		/* length of data */
	char	* buf;		/* pointer to buffer */
};

/* structure of ioctl data on I_FDINSERT */
struct	strfdinsert {
	struct strbuf	ctlbuf;
	struct strbuf	databuf;
	long		flags;	/* type of message, 0 or RS_HIPRI */
	int		fildes;	/* fd of other stream */
	int		offset;	/* where to put other stream read qp */
};

/* I_PEEK structure */
struct	strpeek {
	struct strbuf	ctlbuf;
	struct strbuf	databuf;
	long		flags;	/* if RS_HIPRI, get priority messages only */
};

/* structure of ioctl data on I_RECVFD */
struct	strrecvfd {
	int		fd;	/* new file descriptor */
	unsigned short	uid;	/* user id of sending stream */
	unsigned short	gid;
	char		fill[8];
};

/* structure of ioctl data on I_STR */
struct	strioctl {
	int	ic_cmd;		/* downstream command */
	int	ic_timout;	/* ACK/NAK timeout */
	int	ic_len;		/* length of data arg */
	char	* ic_dp;	/* ptr to data arg */
};

/* Prototypes */
int putmsg(int fd, struct strbuf *ctlptr, struct strbuf *dataptr, int flags);
int getmsg(int fd, struct strbuf *ctlptr, struct strbuf *dataptr, int *flags);
int ioctl(int fildes, int request, void *arg);

#ifdef __cplusplus
};
#endif
#endif	/*_STROPTS_*/
