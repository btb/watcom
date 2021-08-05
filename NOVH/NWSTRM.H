/** Copyright (c) 1990  Novell Inc.
 ** nwstrm.h 1.1, last change 3/31/90
 **/

#ifndef _NWSTRM_
#ifdef __cplusplus
extern "C" {
#endif
#define _NWSTRM_


/**** Common NetWare macros ****/
#ifndef BYTE
#define BYTE	unsigned char
#define WORD	unsigned short int
#define LONG	unsigned long
#endif
/****************************************************************************/


/**** NetWare specific STREAMS structures ****/
typedef struct {
	short int
			major_ver,
			minor_ver,
			revision;
	char	reserved[64 - (sizeof(short int) * 3)];
} nws_version_t;
#define VS	nws_version_t

typedef struct tc {
	struct tc
			*tc_link;		/* Link to next tc struct in timer list */
	LONG	tc_signature;	/* Signature, set and validated by nws_timeout */
	int		(*tc_func)(caddr_t, struct tc *);
	caddr_t	tc_arg;			/* Passed into nws_timeout and back to func */
	int		tc_state;		/* Internal state of timer */
	char	tc_other[48];	/* Internal structures */
} nws_timer_t;
/****************************************************************************/


/**** NetWare specific STREAMS constants and support variables ****/
#define MUX_LINKAGE	1

#undef delay
#define	delay(ticks)	StreamDelay(ticks)

#define StreamNodeSize	56
#define ReceiveBufferStructureExtraSize		((3 * 4) + StreamNodeSize)

#ifndef MAXMSGSIZE
#define MAXMSGSIZE		MaxMessageSize
extern int	MaxMessageSize;
#endif
/****************************************************************************/


/**** NetWare and Watcom specific interrupt controls ****/
#ifndef	spl0
/* spl (Set Priority Level) Macros instead of system calls */
#define spl0	splen
#define spl1	spln
#define spl2	spln
#define spl3	spln
#define spl4	spln
#define spl5	spln
#define spl6	spln
#define spl7	spln
#define splx	splnx

unsigned int splen(void);
#pragma aux splen =				\
		/* PUSHFD  */	0x9c	\
		/* POP EAX */	0x58	\
		/* STI	   */	0xfb	\
		value [EAX];

unsigned int spln(void);
#pragma aux spln = 				\
		/* PUSHFD  */	0x9c	\
		/* POP EAX */	0x58	\
		/* CLI	   */	0xfa	\
		value [EAX];

void splnx(unsigned int pri);
#pragma aux splnx = 			\
		/* PUSH EAX */	0x50	\
		/* POPFD    */	0x9d	\
		parm [EAX];

#endif
/****************************************************************************/


#ifndef _STREAM_
#include	<stream.h>
#endif

extern	mblk_t	*initb(void * header, void * dataPtr, int size, 
					int (*freeRoutine)(), void *freeArg);
extern	mblk_t	*allocbi(int size, int priority, int (*freeRoutine)(), 
					char *arg, char *ptr);
extern	int 	dev_load (char *name, struct streamtab *str);
extern	int 	dev_unload (char *name, int cmajor);

extern	int 	dev_register (LONG nlmHandle, char *name, 
					struct streamtab *str, int baseCount);
extern	int 	dev_unregister (LONG nlmHandle, char *name, int cmajor);
extern	nws_timer_t
				*nws_timeout (int (* func)(), void * arg, int ticks, 
					nws_timer_t *tc);
extern	int 	nws_untimeout (nws_timer_t *tc);

extern	int 	mod_load (char *name, struct streamtab *str);
extern	int 	mod_unload (char *name);
extern	int 	mod_register (LONG nlmHandle, char *name, 
					struct streamtab *str, int baseCount);
extern	int		mod_unregister (LONG nlmHandle, char *name);
#ifndef DEBUG
extern	void 	*StreamAlloc(unsigned size, int pri);
extern	int		StreamFree(void *cp);
#endif
extern	void 	StreamVersion (nws_version_t *version_struct);
extern	void 	*StreamRealloc(void *ptr, uint old_size, uint new_size);
#ifdef __cplusplus
};
#endif
#endif
       
