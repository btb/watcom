/*
 *  search.h	Function prototypes for searching functions
 *
 *  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
 */
#ifndef _SEARCH_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

void *lfind(const void *__key, const void *__base, unsigned *__num,
	    unsigned __width, int (* __compare)(const void *, const void *));
void *lsearch(const void *__key, const void *__base, unsigned *__num,
	    unsigned __width, int (* __compare)(const void *, const void *));
#define _SEARCH_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
