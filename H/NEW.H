//
//  new.h -- C++ default storage allocators
//
//  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
//
#ifndef _NEW_H_INCLUDED

#ifndef __cplusplus
#error new.h is for use with C++
#else

#include <stddef.h>

#ifndef _PFV_DEFINED_
#define _PFV_DEFINED_
 typedef void (*PFV)( void );
#endif

void *operator new( size_t );
void *operator new( size_t, void * );
PFV set_new_handler( PFV );
void operator delete( void * );

#endif
#define _NEW_H_INCLUDED
#endif
