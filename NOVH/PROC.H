/** Copyright (c) 1989-1990  Mentat Inc.
 ** proc.h 1.3, last change 7/18/90
 **/

#ifndef _PROC_
#ifdef __cplusplus
extern "C" {
#endif
#define	_PROC_

struct proc {
	short	p_pid;
	short	p_pgrp;
};

#ifdef __cplusplus
};
#endif
#endif
   
