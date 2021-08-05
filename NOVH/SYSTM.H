/** Copyright (c) 1989-1990  Mentat Inc.
 ** systm.h 1.3, last change 7/18/90
 **/

#ifndef _SYSTM_
#ifdef __cplusplus
extern "C" {
#endif
#define _SYSTM_

#define	lbolt	(GetCurrentTime())
#define	time	(StreamTime())
extern	u32		GetCurrentTime();
extern	u32		StreamTime();

#ifdef __cplusplus
};
#endif
#endif
   
