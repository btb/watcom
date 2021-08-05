/** Copyright (c) 1989  Mentat Inc.
 ** strstat.h 1.2, last change 7/18/90
 **/

#ifndef _STRSTAT_
#ifdef __cplusplus
extern "C" {
#endif
#define _STRSTAT_

/* module statistics structure */
struct	module_stat {
	long	ms_pcnt;	/* count of calls to put proc */
	long	ms_scnt;	/* count of calls to service proc */
	long	ms_ocnt;	/* count of calls to open proc */
	long	ms_ccnt;	/* count of calls to close proc */
	long	ms_acnt;	/* count of calls to admin proc */
	char	* ms_xptr;	/* pointer to private statistics */
	short	ms_xsize;	/* length of private statistics buffer */
};

#ifdef __cplusplus
};
#endif
#endif
