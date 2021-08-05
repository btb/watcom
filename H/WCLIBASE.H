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
//      undef_iter  -- if an iterator is outside the bounds of the list, or
//		       if the iterator was never initialized with a list,
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
    enum {			// bit flags for outside_list
	before_first	= 0x0001,
	after_last	= 0x0002
    };
    WCIsvListBase *     curr_list;
    WCSLink *           curr_item;
    // if outside_list is non-zero, curr_item must be 0.
    int			outside_list;

    WCSLink *           base_advance( int );
    WCDLink *           base_retreat( int );
    inline WCSLink *    base_get_tail() {
	return( curr_list->tail );
    };
    WCSLink *           base_tail_hit( WCSLink * );
    void                base_tail_unhit( WCSLink * );
    void                item_undefined( void );
    void                iter_undefined( void );
    void                range_bad( void );

    inline void base_reset();
    inline void base_reset_list( WCIsvListBase * list );

public:
    inline WCListIterBase() : curr_item( 0 ), curr_list( 0 )
    				, outside_list( 0 ) {};
    inline WCListIterBase( WCIsvListBase * list )
                         : curr_item( 0 ), curr_list( list )
			 , outside_list( before_first ) {};
    inline virtual ~WCListIterBase() = 0;

    inline WCSLink * operator()();
    inline WCSLink * operator++();
    inline WCSLink * operator+=( int );
    inline WCDLink * operator--();
    inline WCDLink * operator-=( int );
};

inline WCListIterBase::~WCListIterBase() {};

inline void WCListIterBase::base_reset() {
    curr_item = 0;
    outside_list = before_first;
}

inline void WCListIterBase::base_reset_list( WCIsvListBase * list ) {
    curr_list = list;
    base_reset();
}

inline WCSLink * WCListIterBase::operator()() {
    return( base_advance( 1 ) );
}

inline WCSLink * WCListIterBase::operator++() {
    return( base_advance( 1 ) );
}

inline WCDLink * WCListIterBase::operator--() {
    return( base_retreat( 1 ) );
}

inline WCSLink * WCListIterBase::operator+=( int incr_amount ) {
    return( base_advance( incr_amount ) );
}

inline WCDLink * WCListIterBase::operator-=( int incr_amount ) {
    return( base_retreat( incr_amount ) );
}




//
//  The WCIsvListIterBase defines the base iterator class for intrusive
//  value type containers.
//

template<class Type, class FType>
class WCIsvListIterBase : public WCListIterBase {
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
	if( ( curr_list == 0 )||( curr_item == 0 ) ) {
	    item_undefined();
	    return( 0 );
	}
        return( (Type *)curr_item );
    };
    
    inline FType * container() {
	if( curr_list == 0 ) {
	    iter_undefined();
	}
        return( (FType *)curr_list );
    };

    WCbool insert( Type * );

    WCbool append( Type * );
};

template<class Type, class FType>
inline WCIsvListIterBase<Type,FType>::~WCIsvListIterBase() {};

template<class Type, class FType>
WCbool WCIsvListIterBase<Type,FType>::insert( Type * datum ) {
    if( ( curr_list == 0 )||( curr_item == 0 ) ) {
	iter_undefined();
	return( FALSE );
    }
    WCSLink * prev_item = curr_item;
    WCbool ret_val;
    if( prev_item != 0 ) {
        prev_item = ((WCDLink *)prev_item)->prev.link;
    }
    WCSLink * curr_tail = base_tail_hit( prev_item );
    ret_val = ((FType *)curr_list)->insert( datum );
    base_tail_unhit( curr_tail );
    return( ret_val );
};

template<class Type, class FType>
WCbool WCIsvListIterBase<Type,FType>::append( Type * datum ) {
    if( ( curr_list == 0 )||( curr_item == 0 ) ) {
	iter_undefined();
	return( FALSE );
    }
    WCbool ret_val;
    if( curr_item == base_get_tail() ) {
	ret_val = ((FType *)curr_list)->append( datum );
    } else {
	WCSLink * curr_tail = base_tail_hit( curr_item );
	ret_val = ((FType *)curr_list)->insert( datum );
	base_tail_unhit( curr_tail );
    }
    return( ret_val );
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
	if( curr_list == 0 ) {
	    iter_undefined();
	}
        return( (FType *)curr_list );
    };

    Type current();

    WCbool insert( Type& );
    
    WCbool append( Type& );
};

template<class Type, class FType, class LType>
inline WCValListIterBase<Type,FType,LType>::~WCValListIterBase() {};

template<class Type, class FType, class LType>
Type WCValListIterBase<Type,FType,LType>::current() {
    Type ret_val;
    if( ( curr_list == 0 )||( curr_item == 0 ) ) {
        item_undefined();
    } else {
        LType * tmp_nisv = (LType *)(FType *)curr_item;
        ret_val = tmp_nisv->data;
    }
    return( ret_val );
};

template<class Type, class FType, class LType>
WCbool WCValListIterBase<Type,FType,LType>::insert( Type& datum ) {
    if( ( curr_list == 0 )||( curr_item == 0 ) ) {
	iter_undefined();
	return( FALSE );
    }
    WCSLink * prev_item = curr_item;
    WCbool ret_val;
    if( prev_item != 0 ) {
        prev_item = ((WCDLink *)prev_item)->prev.link;
    }
    WCSLink * curr_tail = base_tail_hit( prev_item );
    ret_val = ((FType *)curr_list)->insert( datum );
    base_tail_unhit( curr_tail );
    return( ret_val );
};

template<class Type, class FType, class LType>
WCbool WCValListIterBase<Type,FType,LType>::append( Type& datum ) {
    if( ( curr_list == 0 )||( curr_item == 0 ) ) {
	iter_undefined();
	return( FALSE );
    }
    WCbool ret_val;
    if( curr_item == base_get_tail() ) {
	ret_val = ((FType *)curr_list)->append( datum );
    } else {
	WCSLink * curr_tail = base_tail_hit( curr_item );
	ret_val = ((FType *)curr_list)->insert( datum );
	base_tail_unhit( curr_tail );
    }
    return( ret_val );
};




#define _WCLIBASE_H_INCLUDED
#endif
