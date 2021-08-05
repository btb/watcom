//
//  wclist.h    Defines for the WATCOM Container List Class
//
//  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
//

#ifndef _WCLIST_H_INCLUDED
#pragma warning 621 9       // I want the behaviour this warning points to

#ifndef __cplusplus
#error wclist.h is for use with C++
#endif

#include <wcdefs.h>
#include <wclcom.h>
#include <wclbase.h>




//
//  This defines a single linked list of values of type <Type>
//
//  The base class is invoked to process the copy and assignment
//  constructors.  The copies are shallow, in that only the values
//  contained in the list are copied.  If the contained values
//  themselves have defined copy constructors, they can effect a
//  deeper copy.
//

template<class Type>
class WCValSList : public WCValListBase< Type,
                   WCIsvSListBase<WCNIsvSLink<Type> >, WCNIsvSLink<Type> > {
public:
    inline WCValSList() {};

    inline ~WCValSList() {};

    inline WCValSList( const WCValSList & olist ) {
        base_construct( &olist );
    };

    inline WCValSList & operator=( const WCValSList & olist ) {
        base_assign( &olist );
        return( *this );
    };
};




//
//  This defines a double linked list of values of type <Type>
//
//  The base class is invoked to process the copy and assignment
//  constructors.  The copies are shallow, in that only the values
//  contained in the list are copied.  If the contained values
//  themselves have defined copy constructors, they can effect a
//  deeper copy.
//

template<class Type>
class WCValDList : public WCValListBase<Type,
                   WCIsvDListBase<WCNIsvDLink<Type> >, WCNIsvDLink<Type> > {
public:
    inline WCValDList() {};

    inline ~WCValDList() {};

    inline WCValDList( const WCValDList & olist ) {
        base_construct( &olist );
    };

    inline WCValDList & operator=( const WCValDList & olist ) {
        base_assign( &olist );
        return( *this );
    };
};




//
//  This defines a single linked list of pointers of type <Type>
//
//  The base class is invoked to process the copy and assignment
//  constructors.  The copies are shallow, in that only the values
//  contained in the list are copied.  If the contained values
//  themselves have defined copy constructors, they can effect a
//  deeper copy.
//

template<class Type>
class WCPtrSList : public WCPtrListBase<Type, WCValSList<Type *> > {
public:
    inline WCPtrSList() {};

    inline ~WCPtrSList() {};

    inline WCPtrSList( const WCPtrSList & olist ) {
        base_construct( &olist );
    };

    inline WCPtrSList & operator=( const WCPtrSList & olist ) {
        base_assign( &olist );
        return( *this );
    };
};




//
//  This defines a double linked list of pointers of type <Type>
//
//  The base class is invoked to process the copy and assignment
//  constructors.  The copies are shallow, in that only the values
//  contained in the list are copied.  If the contained values
//  themselves have defined copy constructors, they can effect a
//  deeper copy.
//

template<class Type>
class WCPtrDList : public WCPtrListBase<Type, WCValDList<Type *> > {
public:
    inline WCPtrDList() {};

    inline ~WCPtrDList() {};

    inline WCPtrDList( const WCPtrDList & olist ) {
        base_construct( &olist );
    };

    inline WCPtrDList & operator=( const WCPtrDList & olist ) {
        base_assign( &olist );
        return( *this );
    };
};


 

//
//  This defines a single linked list of values of type <Type>,
//  stored intrusively.
//
//  The copy and assignment constructors are made private so
//  that a second copy of the list is not made (intrusive list
//  require modification of the base links, making second copies
//  a problem).
//

template<class Type>
class WCIsvSList : public WCPtrListBase<Type, WCIsvSListBase<Type> > {
private:
    WCIsvSList( const WCIsvSList & );
    WCIsvSList & operator=( const WCIsvSList & );

public:    
    inline WCIsvSList() {};
    inline ~WCIsvSList() {};
};




//
//  This defines a double linked list of values of type <Type>,
//  stored intrusively.
//
//  The copy and assignment constructors are made private so
//  that a second copy of the list is not made (intrusive list
//  require modification of the base links, making second copies
//  a problem).
//

template<class Type>
class WCIsvDList : public WCPtrListBase<Type, WCIsvDListBase<Type> > {
private:
    WCIsvDList( const WCIsvDList & );
    WCIsvDList & operator=( const WCIsvDList & );

public:    
    inline WCIsvDList() {};
    inline ~WCIsvDList() {};
};




#define _WCLIST_H_INCLUDED
#endif
