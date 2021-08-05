/** Copyright (c) 1989-1990  Mentat Inc.
 ** sysmacro.h 1.2, last change 7/18/90
 **/

#ifndef _SYSMACROS_
#ifdef __cplusplus
extern "C" {
#endif
#define _SYSMACROS_

#define	makedev(maj,min)	((maj << 16) | min)
#define	minor(dev)		(dev & 0xffff)
#define	major(dev)		((dev >> 16) & 0xffff)

#endif
#ifdef __cplusplus
};
#endif
   
