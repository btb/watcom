//
//  wclistit.h    Defines for the WATCOM Container List Iterator Class
//
//  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
//

#ifndef _WCLISTIT_H_INCLUDED
#pragma warning 621 9       // I want the behaviour this warning points to

#ifndef __cplusplus
#error wclistit.h is for use with C++
#endif

#include <wcdefs.h>
#ifndef _WCLIST_H_INCLUDED
#include <wclist.h>
#endif
#include <wclibase.h>




//
//  This defines an iterator class for the single linked list of
//  values.
//
//  The operators --() and -=() are made private to prevent their
//  being used with a single linked list.
//

template<class Type>
class WCValSListIter : public WCValListIterBase<Type, WCValSList<Type>,
                                                      WCNIsvSLink<Type> >  {
private:
    int operator--();                                                          
    int operator-=( int );
    void insert( Type& );

public:
    inline WCValSListIter() {};
    inline virtual ~WCValSListIter() {};
    inline WCValSListIter( WCValSList<Type> & slist )
         : WCValListIterBase( &slist ) {};
};




//
//  This defines an iterator class for the double linked list of
//  values.
//

template<class Type>
class WCValDListIter : public WCValListIterBase<Type, WCValDList<Type>,
                                                      WCNIsvDLink<Type> >  {
public:
    inline WCValDListIter() {};
    inline virtual ~WCValDListIter() {};
    inline WCValDListIter( WCValDList<Type> & slist )
         : WCValListIterBase( &slist ) {};
};




//
//  This defines an iterator class for the single linked list of
//  pointers.
//
//  The operators --() and -=() are made private to prevent their
//  being used with a single linked list.
//

template<class Type>
class WCPtrSListIter : public WCValListIterBase<Type *, WCPtrSList<Type>,
                                                     WCNIsvSLink<Type *> >  {
private:
    int operator--();
    int operator-=( int );
    void insert( Type * );

public:
    inline WCPtrSListIter() {};
    inline virtual ~WCPtrSListIter() {};
    inline WCPtrSListIter( WCPtrSList<Type> & slist )
         : WCValListIterBase( &slist ) {};

    inline void append( Type * datum ) {
        WCValListIterBase::append( datum );
    }
};




//
//  This defines an iterator class for the double linked list of
//  pointers.
//

template<class Type>
class WCPtrDListIter : public WCValListIterBase<Type *, WCPtrDList<Type>,
                                                     WCNIsvDLink<Type *> >  {
public:
    inline WCPtrDListIter() {};
    inline virtual ~WCPtrDListIter() {};
    inline WCPtrDListIter( WCPtrDList<Type> & dlist )
         : WCValListIterBase( &dlist ) {};

    inline void insert( Type * datum ) {
        WCValListIterBase::insert( datum );
    }

    inline void append( Type * datum ) {
        WCValListIterBase::append( datum );
    }
};




//
//  This defines an iterator class for the intrusive single linked list.
//
//  The operators --() and -=() are made private to prevent their
//  being used with a single linked list.
//

template<class Type>
class WCIsvSListIter : public WCIsvListIterBase<Type, WCIsvSList<Type> > {
private:
    Type * operator--();
    Type * operator-=( int );
    void insert( Type * );

public:
    inline WCIsvSListIter() {};
    inline virtual ~WCIsvSListIter() {};
    inline WCIsvSListIter( WCIsvSList<Type> & slist )
         : WCIsvListIterBase( &slist ) {};
};




//
//  This defines an iterator class for the intrusive double linked list.
//

template<class Type>
class WCIsvDListIter : public WCIsvListIterBase<Type, WCIsvDList<Type> > {
public:
    inline WCIsvDListIter() {};
    inline virtual ~WCIsvDListIter() {};
    inline WCIsvDListIter( WCIsvDList<Type> & dlist )
         : WCIsvListIterBase( &dlist ) {};
};




#define _WCLISTIT_H_INCLUDED
#endif
