//
//  wclibase.h    Defines for the WATCOM Container List Iterator Base Classes
//
//  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
//

#ifndef _WCLIBASE_H_INCLUDED

#ifndef __cplusplus
#error wclibase.h is for use with C++
#endif

#include <wcdefs.h>



//
//  The WCIterExcept class defines the exception handling for the list
//  iterator classes.  The current errors now supported are:
//
//      undef_iter  -- if an iterator is outside the bounds of the list,   
//                     trying to use it is not defined.
//      undef_item  -- if an iterator does not have a current value, trying
//                     to obtain a value list item is not well defined.
//      iter_range  -- the iterator advance value cannot be non-positive
//

class WCIterExcept {
private:
    int             exception_flags;

public:
    inline WCIterExcept() : exception_flags(0) {};
    inline virtual ~WCIterExcept() {};

    enum wciterstate {                  // Error state
        all_fine    = 0x0000,           // - no errors
        undef_iter  = 0x0001,           // - iterator position is undefined
        undef_item  = 0x0002,           // - current iterator item is undefined
        iter_range  = 0x0004,           // - iterator advance value is bad

        // value to use to check for all errors
        check_all   = (undef_iter|undef_item|iter_range)
    };
    typedef int wciter_state;

    class failure : public __WATCOM_exception {
    private:
        wciter_state    _cause;
    public:
        failure( wciter_state state ) : _cause( state ) {};
        wciter_state cause() const {
            return( _cause );
        };
    };

    inline wciter_state exceptions() const {
        return( exception_flags );
    }

    inline wciter_state exceptions( wciter_state flag_set ) {
        wciter_state old_flags = exception_flags;
        exception_flags = flag_set;
        return( old_flags );
    }
};




//
//  The WCListIterBase class is used as a basis for the iterator
//  classes for the various list containers. 
//
//  It is an abstract base class to prevent objects of this class
//  from being created.
//

class WCListIterBase : public WCIterExcept {
protected:
    WCIsvListBase *     curr_list;
    WCSLink *           curr_item;
    int                 at_end;

    static WCSLink * base_advance( WCListIterBase * const, int );
    static WCDLink * base_retreat( WCListIterBase * const, int );
    static WCSLink * base_tail_hit( WCListIterBase * const, WCSLink * );
    static void base_tail_unhit( WCListIterBase * const, WCSLink * );
    static void item_undefined( WCListIterBase * const );
    static void iter_undefined( WCListIterBase * const );
    static void range_bad( WCListIterBase * const );

    inline void base_reset();
    inline void base_reset_list( WCIsvListBase * list );

public:
    inline WCListIterBase() : curr_item(0), curr_list(0), at_end(FALSE) {};
    inline WCListIterBase( WCIsvListBase * list )
                         : curr_item(0), curr_list(list), at_end(FALSE) {};
    inline virtual ~WCListIterBase() = 0;

    inline WCSLink * operator()();
    inline WCSLink * operator++();
    inline WCSLink * operator+=( int );
    inline WCDLink * operator--();
    inline WCDLink * operator-=( int );
};

inline WCListIterBase::~WCListIterBase() {};

inline void WCListIterBase::base_reset() {
    at_end = FALSE;
    curr_item = 0;
}

inline void WCListIterBase::base_reset_list( WCIsvListBase * list ) {
    curr_list = list;
    base_reset();
}

inline WCSLink * WCListIterBase::operator()() {
    return( base_advance( this, 1 ) );
}

inline WCSLink * WCListIterBase::operator++() {
    return( base_advance( this, 1 ) );
}

inline WCDLink * WCListIterBase::operator--() {
    return( base_retreat( this, 1 ) );
}

inline WCSLink * WCListIterBase::operator+=( int incr_amount ) {
    return( base_advance( this, incr_amount ) );
}

inline WCDLink * WCListIterBase::operator-=( int incr_amount ) {
    return( base_retreat( this, incr_amount ) );
}




//
//  The WCIsvListIterBase defines the base iterator class for intrusive
//  value type containers.
//

template<class Type, class FType>
class WCIsvListIterBase : private WCListIterBase {
public:
    inline WCIsvListIterBase() {};
    inline virtual ~WCIsvListIterBase() = 0;
    inline WCIsvListIterBase( FType * slist ) : WCListIterBase( slist ) {};

    inline void reset( FType & slist ) {
        WCListIterBase::base_reset_list( &slist );
    };

    inline void reset() {
        WCListIterBase::base_reset();
    };

    inline Type * operator()() {
        return( (Type *)WCListIterBase::operator()() );
    };
    
    inline Type * operator++() {
        return( (Type *)WCListIterBase::operator++() );
    };
    
    inline Type * operator--() {
        return( (Type *)WCListIterBase::operator--() );
    };
    
    inline Type * operator+=( int adv_amount ) {
        return( (Type *)WCListIterBase::operator+=( adv_amount ) );
    };
    
    inline Type * operator-=( int adv_amount ) {
        return( (Type *)WCListIterBase::operator-=( adv_amount ) );
    };
    
    inline Type * current() {
        return( (Type *)curr_item );
    };
    
    inline FType * container() {
        return( (FType *)curr_list );
    };

    void insert( Type * );

    void append( Type * );
};

template<class Type, class FType>
inline WCIsvListIterBase<Type,FType>::~WCIsvListIterBase() {};

template<class Type, class FType>
void WCIsvListIterBase<Type,FType>::insert( Type * datum ) {
    WCSLink * prev_item = curr_item;
    if( prev_item != 0 ) {
        curr_item = ((WCDLink *)prev_item)->prev.link;
    }
    WCSLink * curr_tail = base_tail_hit( this, prev_item );
    ((FType *)curr_list)->insert( datum );
    base_tail_unhit( this, curr_tail );
};

template<class Type, class FType>
void WCIsvListIterBase<Type,FType>::append( Type * datum ) {
    WCSLink * curr_tail = base_tail_hit( this, curr_item );
    ((FType *)curr_list)->insert( datum );
    base_tail_unhit( this, curr_tail );
};




//
//  The WCValListIterBase defines the base iterator class for value type
//  containers.
//

template<class Type, class FType, class LType>
class WCValListIterBase : public WCListIterBase {
public:
    inline WCValListIterBase() {};
    inline virtual ~WCValListIterBase() = 0;
    inline WCValListIterBase( FType * slist ) : WCListIterBase( slist ) {};

    inline void reset( FType & dlist ) {
        WCListIterBase::base_reset_list( &dlist );
    };

    inline void reset() {
        WCListIterBase::base_reset();
    };

    inline int operator()() {
        return( WCListIterBase::operator()() != 0 );
    };
    
    inline int operator++() {
        return( WCListIterBase::operator++() != 0 );
    };
    
    inline int operator--() {
        return( WCListIterBase::operator--() != 0 );
    };
    
    inline int operator+=( int adv_amount ) {
        return( WCListIterBase::operator+=( adv_amount ) != 0 );
    };
    
    inline int operator-=( int adv_amount ) {
        return( WCListIterBase::operator-=( adv_amount ) != 0 );
    };

    inline FType * container() {
        return( (FType *)curr_list );
    };

    Type current();

    void insert( Type& );
    
    void append( Type& );
};

template<class Type, class FType, class LType>
inline WCValListIterBase<Type,FType,LType>::~WCValListIterBase() {};

template<class Type, class FType, class LType>
Type WCValListIterBase<Type,FType,LType>::current() {
    Type ret_val;
    if( curr_item == 0 ) {
        item_undefined( this );
    } else {
        LType * tmp_nisv = (LType *)(FType *)curr_item;
        ret_val = tmp_nisv->data;
    }
    return( ret_val );
};

template<class Type, class FType, class LType>
void WCValListIterBase<Type,FType,LType>::insert( Type& datum ) {
    WCSLink * prev_item = curr_item;
    if( prev_item != 0 ) {
        curr_item = ((WCDLink *)prev_item)->prev.link;
    }
    WCSLink * curr_tail = base_tail_hit( this, prev_item );
    ((FType *)curr_list)->insert( datum );
    base_tail_unhit( this, curr_tail );
};

template<class Type, class FType, class LType>
void WCValListIterBase<Type,FType,LType>::append( Type& datum ) {
    WCSLink * curr_tail = base_tail_hit( this, curr_item );
    ((FType *)curr_list)->insert( datum );
    base_tail_unhit( this, curr_tail );
};




#define _WCLIBASE_H_INCLUDED
#endif
