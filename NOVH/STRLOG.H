/** Copyright (c) 1989  Mentat Inc.
 ** strlog.h 1.3, last change 7/18/90
 **/

#ifndef _STRLOG_
#ifdef __cplusplus
extern "C" {
#endif
#define	_STRLOG_

struct log_ctl {
	short	mid;
	short	sid;
	char	level;
	short	flags;
	long	ltime;
	long	ttime;
	int    seq_no;
};

#define	SL_FATAL	0x1	/* Fatal error */
#define	SL_NOTIFY	0x2	/* Notify the system administrator */
#define	SL_ERROR	0x4	/* Pass message to error logger */
#define	SL_TRACE	0x8	/* Pass message to tracer */

struct trace_ids {
	short	ti_mid;
	short	ti_sid;
	char	ti_level;
	short	ti_flags;
};

#define	I_TRCLOG	1
#define	I_ERRLOG	2

#define	LOGMSGSZ	128

#ifdef __cplusplus
};
#endif
#endif
