//
//  wclbase.h    Definitions for the base classes used by
//               the WATCOM Container List Class
//
//  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
//

#ifndef _WCLBASE_H_INCLUDED

#ifndef __cplusplus
#error wclbase.h is for use with C++
#endif




//
//  The WCIsvListBase class is used as a basis for intrusive lists.
//  It provides the common data and base functionality.  The WCListExcept
//  class provides the common exception handling for all lists.
//
//  This class is also used by the value classes. The values
//  are encapsulated in non-intrusive links which are then stored
//  in the list intrusively.
//
//  It is an abstract base class to prevent objects of this class
//  from being created.
//

class WCIsvListBase : public WCListExcept {
protected:
    WCSLink *       tail;
    int             entry_count;

    static void base_insert( WCIsvListBase * const, WCSLink * const );
    static WCSLink * base_next( const WCIsvListBase * const, WCSLink *, WCbool );
    static int base_index_check( const WCIsvListBase * const, int );
    static WCSLink * base_sget( WCIsvListBase * const, int );
    static WCDLink * base_dget( WCIsvListBase * const, int );
    static WCSLink * base_bfind( const WCIsvListBase * const, int );
    static WCSLink * base_sfind( const WCIsvListBase * const, int );
    static WCDLink * base_dfind( const WCIsvListBase * const, int );
    static WCbool base_contains( const WCIsvListBase * const, WCSLink * const );
    static void base_clear( WCIsvListBase * const );
    static void base_destroy( WCIsvListBase * const );

public:
    inline WCIsvListBase() : tail(0), entry_count(0) {};
    virtual ~WCIsvListBase() = 0;

    friend class WCListIterBase;
};





//
//  The WCIsvSListBase class defines an intrusive singly linked list
//  base class.
//
//  It is an abstract base class to prevent objects of this class
//  from being created.
//

template<class Type>
class WCIsvSListBase : public WCIsvListBase {
protected:
    void            clear();
    void            clearAndDestroy();
    void            insert( WCSLink * const );
    void            append( WCSLink * const );
    WCSLink *       get( int = 0 );
    WCSLink *       find( int = 0 ) const;
    WCSLink *       findLast() const;
    WCbool          contains( WCSLink * const ) const;
    WCbool          isEmpty() const;
    int             entries() const;
    void            forAll( void (*)( Type *, void * ), void *);

public:
    inline WCIsvSListBase() {};
    inline virtual ~WCIsvSListBase() = 0;
};

template<class Type>
inline WCIsvSListBase<Type>::~WCIsvSListBase() {};

template<class Type>
inline void WCIsvSListBase<Type>::clear() {
    base_clear( this );
};

template<class Type>
inline void WCIsvSListBase<Type>::clearAndDestroy() {
    base_destroy( this );
};

template<class Type>
inline void WCIsvSListBase<Type>::insert( WCSLink * const datum ) {
    base_insert( this, datum );
};

template<class Type>
inline void WCIsvSListBase<Type>::append( WCSLink * const datum ) {
    insert( datum );
    this->tail = datum;
};

template<class Type>
inline WCSLink * WCIsvSListBase<Type>::get( int index ) {
    return( base_sget( this, index ) );
};

template<class Type>
inline WCSLink * WCIsvSListBase<Type>::find( int index ) const {
    return( base_sfind( this, index ) );
};

template<class Type>
inline WCSLink * WCIsvSListBase<Type>::findLast() const {
    return( this->tail );
};

template<class Type>
inline WCbool WCIsvSListBase<Type>::contains( WCSLink * const datum ) const {
    return( base_contains( this, datum ) );
};

template<class Type>
inline WCbool WCIsvSListBase<Type>::isEmpty() const {
    return( this->tail == 0 );
};

template<class Type>
inline int WCIsvSListBase<Type>::entries() const {
    return( this->entry_count );
};

template<class Type>
void WCIsvSListBase<Type>::forAll(
                    register void (* func)( Type *, void * ), void * datum ) {
    Type * rover = (Type *)base_next( this, rover, TRUE );
    while( rover != 0 ) {
        (*func)( rover, datum );
        rover = (Type *)base_next( this, rover, FALSE );
    } 
};




//
//  The WCIsvDListBase class defines an intrusive doubly linked list
//  base class.
//
//  It is an abstract base class to prevent objects of this class
//  from being created.
//

template<class Type>
class WCIsvDListBase : public WCIsvListBase {
protected:
    void            clear();
    void            clearAndDestroy();
    void            insert( WCDLink * const );
    void            append( WCDLink * const );
    WCDLink *       get( int = 0 );
    WCDLink *       find( int = 0 ) const;
    WCDLink *       findLast() const;
    WCbool          contains( WCDLink * const ) const;
    WCbool          isEmpty() const;
    int             entries() const;
    void            forAll( void (*)( Type *, void * ), void *);

public:
    inline WCIsvDListBase() {};
    inline virtual ~WCIsvDListBase() = 0;
};

template<class Type>
inline WCIsvDListBase<Type>::~WCIsvDListBase() {};

template<class Type>
inline void WCIsvDListBase<Type>::clear() {
    base_clear( this );
};

template<class Type>
inline void WCIsvDListBase<Type>::clearAndDestroy() {
    base_destroy( this );
};

template<class Type>
void WCIsvDListBase<Type>::insert( WCDLink * const datum ) {
    WCbool empty_list = (this->tail == 0);
    base_insert( this, datum );
    if( !empty_list ) {
        datum->prev.link = this->tail;
        ((WCDLink *)datum->link)->prev.link = datum;
    }
};

template<class Type>
inline void WCIsvDListBase<Type>::append( WCDLink * const datum ) {
    insert( datum );
    this->tail = datum;
};

template<class Type>
inline int WCIsvDListBase<Type>::entries() const {
    return( this->entry_count );
};

template<class Type>
inline WCDLink * WCIsvDListBase<Type>::get( int index ) {
    return( base_dget( this, index ) );
};

template<class Type>
inline WCDLink * WCIsvDListBase<Type>::find( int index ) const {
    return( base_dfind( this, index ) );
};

template<class Type>
inline WCDLink * WCIsvDListBase<Type>::findLast() const {
    return( (WCDLink *)this->tail );
};

template<class Type>
inline WCbool WCIsvDListBase<Type>::contains( WCDLink * const datum ) const {
    return( base_contains( this, datum ) );
};

template<class Type>
inline WCbool WCIsvDListBase<Type>::isEmpty() const {
    return( this->tail == 0 );
};

template<class Type>
void WCIsvDListBase<Type>::forAll(
                    register void (* func)( Type *, void * ), void * datum ) {
    Type * rover = (Type *)base_next( this, rover, TRUE );
    while( rover != 0 ) {
        (*func)( rover, datum );
        rover = (Type *)base_next( this, rover, FALSE );
    } 
};




//
//  The WCValListBase template class is used as a basis for non-intrusive
//  (value) lists.  The template supplies the type of the list data,
//  the methods for manipulating the list, and the link type of the list.
//
//  The member functions clear() and clearAndDestroy() perform the same
//  action since this is a value list (the list elements were created by
//  the list to contain the values, so we must destroy them.  But we can't
//  get rid of the list elements without getting rid of the values).
//
//  It is an abstract base class to prevent objects of this class
//  from being created.
//

template<class Type, class FType, class LType >
class WCValListBase : public FType {
protected:    
    void base_construct( const WCValListBase * );
    void base_assign( const WCValListBase * );

public:
    inline WCValListBase() {};
    inline virtual ~WCValListBase() = 0;

    inline void clear()  {
        FType::clearAndDestroy();
    };

    inline void clearAndDestroy()  {
        FType::clearAndDestroy();
    };

    inline void insert( const Type& datum )  {
        FType::insert( new LType( datum ) );
    };

    inline void append( const Type& datum )  {
        FType::append( new LType( datum ) );
    };

    inline WCbool isEmpty() const {
        return( FType::isEmpty() );
    };

    inline int entries() const {
        return( FType::entries() );
    }

    WCbool contains( const Type & ) const;
    Type get( int = 0 );
    Type find( int = 0 ) const;
    Type findLast() const;
    void forAll( void (*)( Type, void * ), void *);
};

template<class Type, class FType, class LType>
inline WCValListBase<Type,FType,LType>::~WCValListBase() {};


template<class Type, class FType, class LType>
void WCValListBase<Type,FType,LType>::base_construct(
                             const WCValListBase<Type,FType,LType> * olist ) {
    LType * rover = (LType *)FType::base_next(
                             (const WCValListBase * const)olist, rover, TRUE );
    while( rover != 0 ) {
        append( rover->data );
        rover = (LType *)FType::base_next( (const WCValListBase * const)olist,
                                           rover, FALSE );
    } 
};


template<class Type, class FType, class LType>
void WCValListBase<Type,FType,LType>::base_assign(
                              const WCValListBase<Type,FType,LType> * olist ) {
    if( this != (WCValListBase * const)olist ) {
        FType::base_destroy( this );
        base_construct( olist );
    }
};


template<class Type, class FType, class LType>
WCbool WCValListBase<Type,FType,LType>::contains(
                                        const Type & lookup_data ) const {
    LType * rover = (LType *)FType::base_next( this, rover, TRUE );
    if( rover == 0 ) {
        return( FALSE );
    }
    while( rover != 0 ) {
        if( rover->data == lookup_data ) {
            return( TRUE );
        }
        rover = (LType *)FType::base_next( this, rover, FALSE );
    } 
    return( FALSE );
};


template<class Type, class FType, class LType>
Type WCValListBase<Type,FType,LType>::get( int index ) {
    LType * ret_obj = (LType *)FType::get( index );
    Type ret_val = ret_obj->data;
    delete ret_obj;
    return( ret_val );
};


template<class Type, class FType, class LType>
Type WCValListBase<Type,FType,LType>::find( int index ) const {
    LType * ret_obj = (LType *)FType::find( index );
    Type ret_val = ret_obj->data;
    return( ret_val );
};


template<class Type, class FType, class LType>
Type WCValListBase<Type,FType,LType>::findLast() const {
    LType * ret_obj = (LType *)FType::findLast();
    Type ret_val = ret_obj->data;
    return( ret_val );
};


template<class Type, class FType, class LType>
void WCValListBase<Type,FType,LType>::forAll(
                      register void (* func)( Type, void * ), void * datum ) {
    LType * rover = (LType *)FType::base_next( this, rover, TRUE );
    while( rover != 0 ) {
        (*func)( rover->data, datum );
        rover = (LType *)FType::base_next( this, rover, FALSE );
    } 
};




//
//  The WCPtrListBase template class is used as a basis for intrusive
//  (pointer) lists.  The template supplies the type of the list data and
//  the methods for manipulating the list.
//
//  It is an abstract base class to prevent objects of this class
//  from being created.
//

template<class Type, class FType>
class WCPtrListBase : public FType {
public:
    inline WCPtrListBase() {};
    inline virtual ~WCPtrListBase() = 0;

    inline void clear() {
        FType::clear();
    };

    inline void insert( Type * ptr )  {
        FType::insert( ptr );
    };

    inline void append( Type * ptr )  {
        FType::append( ptr );
    };

    inline WCbool contains( Type * ptr ) const {
        return( FType::contains( ptr ) );
    };

    inline WCbool isEmpty() const {
        return( FType::isEmpty() );
    };

    inline int entries() const {
        return( FType::entries() );
    };

    inline Type * get( int index = 0 ) {
        return( (Type *)FType::get( index ) );
    };

    inline Type * find( int index = 0 ) const {
        return( (Type *)FType::find( index ) );
    };

    inline Type * findLast() const {
        return( (Type *)FType::findLast() );
    };

    inline void forAll( void (* func)( Type *, void * ), void * datum ) {
        FType::forAll( func, datum );
    };

    void clearAndDestroy();
};

template<class Type, class FType>
inline WCPtrListBase<Type,FType>::~WCPtrListBase() {};


template<class Type, class FType>
void WCPtrListBase<Type,FType>::clearAndDestroy() {
    Type *  ptr_val;
    while( !isEmpty() ) {
        ptr_val = get();
        delete ptr_val;
    }
    clear();
}




#define _WCLBASE_H_INCLUDED
#endif
