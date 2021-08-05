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

    void            base_insert( WCSLink * const );
    WCSLink *       base_next( WCSLink *, WCbool ) const;
    int             base_index_check( int ) const;
    WCSLink * 	    base_sget( int );
    WCDLink *       base_dget( int );
    WCSLink *       base_bfind( int ) const;
    WCSLink *       base_sfind( int ) const;
    WCDLink *       base_dfind( int ) const;
    WCbool          base_contains( WCSLink * const ) const;
    void            base_clear( void );
    void            base_destroy( void );
    void	    base_empty_list( void ) const;
    void            base_not_empty( void );
    void	    base_out_of_memory( void ) const;
    void	    base_range_bad( void ) const;
//    WCSLink *	    WCListNew(  );
    inline virtual void	WCListDelete( WCSLink * datum ){ delete datum; };

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
    WCbool          insert( WCSLink * const );
    WCbool          append( WCSLink * const );
    WCSLink *       get( int = 0 );
    WCSLink *       find( int = 0 ) const;
    WCSLink *       findLast() const;
    WCbool          contains( WCSLink * const ) const;
    WCbool          isEmpty() const;
    int             entries() const;
    void            forAll( void (*)( Type *, void * ), void *);

public:
    inline WCIsvSListBase( void * (*)( size_t )
                , void (*)( void *, size_t )
		) { };

    inline WCIsvSListBase() {};
    inline virtual ~WCIsvSListBase() = 0;
};

template<class Type>
inline WCIsvSListBase<Type>::~WCIsvSListBase() {};

template<class Type>
inline void WCIsvSListBase<Type>::clear() {
    base_clear();
};

template<class Type>
inline void WCIsvSListBase<Type>::clearAndDestroy() {
    base_destroy();
};

template<class Type>
inline WCbool WCIsvSListBase<Type>::insert( WCSLink * const datum ) {
    base_insert( datum );
    return( TRUE );
};

template<class Type>
inline WCbool WCIsvSListBase<Type>::append( WCSLink * const datum ) {
    insert( datum );
    tail = datum;
    return( TRUE );
};

template<class Type>
inline WCSLink * WCIsvSListBase<Type>::get( int index ) {
    return( base_sget( index ) );
};

template<class Type>
inline WCSLink * WCIsvSListBase<Type>::find( int index ) const {
    return( base_sfind( index ) );
};

template<class Type>
inline WCSLink * WCIsvSListBase<Type>::findLast() const {
    if( tail == 0 ) {
	base_empty_list();
    }
    return( tail );
};

template<class Type>
inline WCbool WCIsvSListBase<Type>::contains( WCSLink * const datum ) const {
    return( base_contains( datum ) );
};

template<class Type>
inline WCbool WCIsvSListBase<Type>::isEmpty() const {
    return( tail == 0 );
};

template<class Type>
inline int WCIsvSListBase<Type>::entries() const {
    return( entry_count );
};

template<class Type>
void WCIsvSListBase<Type>::forAll(
                    register void (* func)( Type *, void * ), void * datum ) {
    Type * rover = (Type *)base_next( rover, TRUE );
    while( rover != 0 ) {
        (*func)( rover, datum );
        rover = (Type *)base_next( rover, FALSE );
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
    WCbool          insert( WCDLink * const );
    WCbool          append( WCDLink * const );
    WCDLink *       get( int = 0 );
    WCDLink *       find( int = 0 ) const;
    WCDLink *       findLast() const;
    WCbool          contains( WCDLink * const ) const;
    WCbool          isEmpty() const;
    int             entries() const;
    void            forAll( void (*)( Type *, void * ), void *);

public:
    inline WCIsvDListBase( void * (*)( size_t )
                , void (*)( void *, size_t )
		) { };
    inline WCIsvDListBase() {};

    inline virtual ~WCIsvDListBase() = 0;
};

template<class Type>
inline WCIsvDListBase<Type>::~WCIsvDListBase() {};

template<class Type>
inline void WCIsvDListBase<Type>::clear() {
    base_clear();
};

template<class Type>
inline void WCIsvDListBase<Type>::clearAndDestroy() {
    base_destroy();
};

template<class Type>
WCbool WCIsvDListBase<Type>::insert( WCDLink * const datum ) {
    WCbool empty_list = (tail == 0);
    base_insert( datum );
    if( empty_list ) {
	datum->prev.link = datum;
    } else {
        datum->prev.link = tail;
        ((WCDLink *)datum->link)->prev.link = datum;
    }
    return( TRUE );
};

template<class Type>
WCbool WCIsvDListBase<Type>::append( WCDLink * const datum ) {
    insert( datum );
    tail = datum;
    return( TRUE );
};


template<class Type>
inline int WCIsvDListBase<Type>::entries() const {
    return( entry_count );
};

template<class Type>
inline WCDLink * WCIsvDListBase<Type>::get( int index ) {
    return( base_dget( index ) );
};

template<class Type>
inline WCDLink * WCIsvDListBase<Type>::find( int index ) const {
    return( base_dfind( index ) );
};

template<class Type>
inline WCDLink * WCIsvDListBase<Type>::findLast() const {
    if( tail == 0 ) {
	base_empty_list();
    }
    return( (WCDLink *)tail );
};

template<class Type>
inline WCbool WCIsvDListBase<Type>::contains( WCDLink * const datum ) const {
    return( base_contains( datum ) );
};

template<class Type>
inline WCbool WCIsvDListBase<Type>::isEmpty() const {
    return( tail == 0 );
};

template<class Type>
void WCIsvDListBase<Type>::forAll(
                    register void (* func)( Type *, void * ), void * datum ) {
    Type * rover = (Type *)base_next( rover, TRUE );
    while( rover != 0 ) {
        (*func)( rover, datum );
        rover = (Type *)base_next( rover, FALSE );
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
    LType * WCListNew( const Type& datum );
    virtual void WCListDelete( WCSLink * );

    void base_construct( const WCValListBase * );
    void base_assign( const WCValListBase * );

public:
    inline WCValListBase() {};
    virtual ~WCValListBase() = 0;

    inline void clear()  {
        FType::clearAndDestroy();
    };

    inline void clearAndDestroy()  {
        FType::clearAndDestroy();
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
    WCbool insert( const Type& datum );
    WCbool append( const Type& datum );
};


template<class Type, class FType, class LType>
LType * WCValListBase<Type,FType,LType>::WCListNew( const Type& datum ){
    return( new LType( datum ) );
}


template<class Type, class FType, class LType>
void WCValListBase<Type,FType,LType>::WCListDelete( WCSLink * old_link ){
    delete old_link;
}
	

template<class Type, class FType, class LType>
void WCValListBase<Type,FType,LType>::base_construct(
                             const WCValListBase<Type,FType,LType> * olist ) {
    
    WCListExcept::base_construct( olist );
    LType * rover = (LType *)( olist->base_next( rover, TRUE ) );
    while( rover != 0 ) {
        append( rover->data );
        rover = (LType *)( olist->base_next( rover, FALSE ) );
    } 
};


template<class Type, class FType, class LType>
void WCValListBase<Type,FType,LType>::base_assign(
                              const WCValListBase<Type,FType,LType> * olist ) {
    if( this != (WCValListBase * const)olist ) {
        base_destroy();
        base_construct( olist );
    }
};


template<class Type, class FType, class LType>
WCValListBase<Type,FType,LType>::~WCValListBase() {
    if( tail != 0 ) {
	base_not_empty();
	base_destroy();
    }
};


template<class Type, class FType, class LType>
WCbool WCValListBase<Type,FType,LType>::insert( const Type& datum ) {
    LType * new_link = WCListNew( datum );
    if( new_link != 0 ) {
	return( FType::insert( new_link ) );
    } else {
	base_out_of_memory();
	return( FALSE );
    }
};


template<class Type, class FType, class LType>
WCbool WCValListBase<Type,FType,LType>::append( const Type& datum ) {
    LType * new_link = WCListNew( datum );
    if( new_link != 0 ) {
	return( FType::append( new_link ) );
    } else {
	base_out_of_memory();
	return( FALSE );
    }
};


template<class Type, class FType, class LType>
WCbool WCValListBase<Type,FType,LType>::contains(
                                        const Type & lookup_data ) const {
    LType * rover = (LType *)base_next( rover, TRUE );
    if( rover == 0 ) {
        return( FALSE );
    }
    while( rover != 0 ) {
        if( rover->data == lookup_data ) {
            return( TRUE );
        }
        rover = (LType *)base_next( rover, FALSE );
    } 
    return( FALSE );
};


template<class Type, class FType, class LType>
Type WCValListBase<Type,FType,LType>::get( int index ) {
    LType * ret_obj = (LType *)FType::get( index );
    if( ret_obj == 0 ) {
	Type ret_val;
	return( ret_val );
    } else {
	Type ret_val = ret_obj->data;
	WCListDelete( ret_obj );
	return( ret_val );
    }
};


template<class Type, class FType, class LType>
Type WCValListBase<Type,FType,LType>::find( int index ) const {
    LType * ret_obj = (LType *)FType::find( index );
    if( ret_obj == 0 ) {
	Type ret_val;
	return( ret_val );
    } else {
	Type ret_val = ret_obj->data;
	return( ret_val );
    }
};


template<class Type, class FType, class LType>
Type WCValListBase<Type,FType,LType>::findLast() const {
    LType * ret_obj = (LType *)FType::findLast();
    if( ret_obj == 0 ) {
	Type ret_val;
	return( ret_val );
    } else {
	Type ret_val = ret_obj->data;
	return( ret_val );
    }
};


template<class Type, class FType, class LType>
void WCValListBase<Type,FType,LType>::forAll(
                      register void (* func)( Type, void * ), void * datum ) {
    LType * rover = (LType *)base_next( rover, TRUE );
    while( rover != 0 ) {
        (*func)( rover->data, datum );
        rover = (LType *)base_next( rover, FALSE );
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

    inline WCbool insert( Type * ptr )  {
        return( FType::insert( ptr ) );
    };

    inline WCbool append( Type * ptr )  {
        return( FType::append( ptr ) );
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
