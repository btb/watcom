/*
 *  assert.h
 *
 *  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
 */
#undef	assert
#ifdef __cplusplus
extern "C" {
#endif

#ifdef NDEBUG
 #define assert(__ignore) ((void)0)
#else
 extern  void		__assert( int, char *, char *, int );
 #define assert(expr)	__assert(expr,#expr,__FILE__,__LINE__)
#endif
#ifdef __cplusplus
};
#endif
