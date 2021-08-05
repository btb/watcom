/** Copyright (c) 1989  Mentat Inc.
 ** poll.h 1.2, last change 5/12/90
 **/

#ifndef	__POLL__
#ifdef __cplusplus
extern "C" {
#endif
#define __POLL__

#define	NPOLLFILE	65535

/* Poll masks */
#define	POLLIN		01	/* message available on read queue */
#define	POLLPRI		02	/* priority message available */
#define	POLLOUT		04	/* stream is writable */
#define	POLLERR		010	/* error message has arrived */
#define	POLLHUP		020	/* hangup has occurred */
#define	POLLNVAL	040	/* invalid fd */

/* array of streams to poll */
struct pollfd {
	int	fd;
	short	events;
	short	revents;
	int	_ifd;		/* Internal "fd" for the benefit of the kernel */
};

/* I_POLL structure for ioctl on non-5.3 systems */
struct strpoll {
	unsigned long	nfds;
	struct pollfd	* pollfdp;
	int		timeout;
};

/* Prototype */
int poll(  struct pollfd fds[], unsigned long nfds, int timeout  );
#ifdef __cplusplus
};
#endif
#endif
