/*
 *  sys/locking.h	Flags for locking() function
 *
 *  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
 */
#ifndef __LOCKING_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#define LK_UNLCK    0	/* unlock region of a file */
#define LK_LOCK     1	/* lock a region of a file */
#define LK_NBLCK    2	/* non-blocking lock */
#define LK_RLCK     3	/* lock for writing */
#define LK_NBRLCK   4	/* non-blocking lock for writing */

int locking(int __handle,int __mode,unsigned long __nbyte);

#define __LOCKING_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
