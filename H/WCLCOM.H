//
//  wclcom.h    Definitions for some common base classes used by
//              the WATCOM Container Classes
//
//  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
//

#ifndef _WCLCOM_H_INCLUDED

#ifndef __cplusplus
#error wclcom.h is for use with C++
#endif



//
//  The techniques for specifying the list classes are from
//  'The C++ Programming Language', 2nd Edition, Bjarne Stroustrup.
//




//
//  The WCSLink class is used as a basis for manipulating a number of
//  different containers.  In an intrusive container, this class provides
//  the base for the user defined class of single linked lists.
//
//  constructor: set the 'next' link field to 0 (will be reset when inserted
//		 into the list)
//  destructor: nothing needs to be explicitly destroyed in WCSLink.
//              It is not a pure virtual so that WCDLink can use it
//              to create the needed back link.
//

class WCSLink {
public:
    WCSLink *       link;

    inline WCSLink() : link( 0 ) {};
    inline virtual ~WCSLink() {};
};




//
//  The WCDLink class is used as a basis for manipulating a number of
//  different containers.  In an intrusive container, this class provides
//  the base for the user defined class of double linked lists.  The
//  WCSLink class is used as a base for this class.
//
//  constructor: the 'prev' link field is set up by the WCSLink constructor.
//  destructor: nothing needs to be explicitly destroyed in WCDLink.
//              Make it a pure virtual so that WCDLink will be an
//              abstract class.   We do not want anyone to instantiate
//              an object of this class.
//

class WCDLink : public WCSLink {
public:
    WCSLink         prev;


    inline WCDLink() {};
    inline virtual ~WCDLink() = 0;
};

inline WCDLink::~WCDLink() {};



//
//  The WCNIsvSLink class is used as a basis for non-intrusive singly
//  linked lists.
//

template<class Type>
class WCNIsvSLink : public WCSLink {
public:
    Type            data;

    inline WCNIsvSLink( const Type & datum ) : data( datum ) {};
    inline virtual ~WCNIsvSLink() {};
};




//
//  The WCNIsvDLink class is used as a basis for non-intrusive doubly
//  linked lists.
//

template<class Type>
class WCNIsvDLink : public WCDLink {
public:
    Type            data;

    inline WCNIsvDLink( const Type & datum ) : data( datum ) {};
    inline virtual ~WCNIsvDLink() {};
};



//
//  The WCListExcept class defines the exception handling for the list
//  classes.  The current errors now supported are:
//
//      not_empty   -- if a list which should be clear is being destroyed
//                     by the class destructor, this error can be thrown.
//      index_range -- if an index value is not valid, this error can
//                     be thrown.
//	empty_list  -- thrown on an attempt to find, findLast or get in an
//		       empty list
//      out_of_memory -- thrown by insert or append when an attempt to allocate
//		       memory failed
//

class WCListExcept {
private:
    int             exception_flags;

protected:
    inline void base_construct( const WCListExcept * orig ) {
	exception_flags = orig->exception_flags;
    }

public:
    inline WCListExcept() : exception_flags(0) {};
    inline virtual ~WCListExcept() {};

    enum wcliststate {                  // Error state
        all_fine      = 0x0000,		// - no errors
        not_empty     = 0x0001,		// - list is not empty on destruction
        index_range   = 0x0002,		// - index on find is out of range
        empty_list    = 0x0004,		// - list is empty on find or get
	out_of_memory = 0x0008,		// - allocation failed

        // value to use to check for all errors
        check_all   = (not_empty|index_range|empty_list|out_of_memory)
    };
    typedef int wclist_state;

    class failure : public __WATCOM_exception {
    private:
        wclist_state    _cause;
    public:
        failure( wclist_state state ) : _cause( state ) {};
        wclist_state cause() const {
            return( _cause );
        };
    };

    inline wclist_state exceptions() const {
        return( exception_flags );
    }

    inline wclist_state exceptions( wclist_state const flag_set ) {
        wclist_state old_flags = exception_flags;
        exception_flags = flag_set;
        return( old_flags );
    }
};




#define _WCLCOM_H_INCLUDED
#endif
