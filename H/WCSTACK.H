//
//  wcstack.h    Defines for the WATCOM Stack Container Class
//
//  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
//

#ifndef _WCSTACK_H_INCLUDED

#ifndef __cplusplus
#error wcstack.h is for use with C++
#endif

#include <wcdefs.h>
#include <wclist.h>




//
//  The WCStack template class defines a stack.  The template supplies
//  the type of the data maintained in the stack, and the methods for
//  manipulating the stack.
//
//  The class 'Type' should be properly defined for copy and assignment
//  operations.
//

template<class Type, class FType>
class WCStack : private FType {
public:
    inline WCStack() {};
    inline ~WCStack() {};

    inline void push( const Type & data )  {
        FType::insert( data );
    };

    inline Type pop() {
        return( FType::get() );
    };

    inline Type top() const {
        return( FType::find( 0 ) );
    };

    inline WCbool isEmpty() const {
        return( FType::isEmpty() );
    };

    inline int entries() const {
        return( FType::entries() );
    };

    inline void clear() {
        FType::clear();
    };
};


#define _WCSTACK_H_INCLUDED
#endif
