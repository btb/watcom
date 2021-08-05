//
//  iomanip.h	I/O streams manipulators
//
//  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
//
#ifndef _IOMANIP_H_INCLUDED

#ifndef __cplusplus
#error iomanip.h is for use with C++
#endif

#include <iostream.h>
#include <generic.h>

// In the absence of templates, these macros convert a statement such as
//      SMANIP_define( int )
// into the class definitions for
//      SMANIPint
//      SAPPint
//	IMANIPint
//      IAPPint
//	OMANIPint
//      OAPPint
//	IOMANIPint
//      IOAPPint

#define SMANIP(__Typ)	name2(SMANIP,__Typ)
#define SAPP(__Typ)	name2(SAPP,__Typ)
#define IMANIP(__Typ)	name2(IMANIP,__Typ)
#define IAPP(__Typ)	name2(IAPP,__Typ)
#define OMANIP(__Typ)	name2(OMANIP,__Typ)
#define OAPP(__Typ)	name2(OAPP,__Typ)
#define IOMANIP(__Typ)	name2(IOMANIP,__Typ)
#define IOAPP(__Typ)	name2(IOAPP,__Typ)

#define SMANIP_define(__Typ) \
class SMANIP(__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
    __Typ __p; \
public: \
    SMANIP(__Typ)( ios & (*__f_in)( ios &, __Typ ), __Typ __p_in ) : \
	__f(__f_in), __p(__p_in) {} \
    friend istream &operator >> ( istream &, const SMANIP(__Typ) & ); \
    friend ostream &operator << ( ostream &, const SMANIP(__Typ) & ); \
}; \
class IMANIP(__Typ) { \
    istream & (*__f)( istream &, __Typ ); \
    __Typ __p; \
public: \
    IMANIP(__Typ)( istream & (*__f_in)( istream &, __Typ ), __Typ __p_in ) : \
	__f(__f_in), __p(__p_in) {} \
    friend istream &operator >> ( istream &, const IMANIP(__Typ) & ); \
}; \
class OMANIP(__Typ) { \
    ostream & (*__f)( ostream &, __Typ ); \
    __Typ __p; \
public: \
    OMANIP(__Typ)( ostream & (*__f_in)( ostream &, __Typ ), __Typ __p_in ) : \
	__f(__f_in), __p(__p_in) {} \
    friend ostream &operator << ( ostream &, const OMANIP(__Typ) & ); \
}; \
class IOMANIP(__Typ) { \
    iostream & (*__f)( iostream &, __Typ ); \
    __Typ __p; \
public: \
    IOMANIP(__Typ)( iostream & (*__f_in)( iostream &, __Typ ), __Typ __p_in ) : \
	__f(__f_in), __p(__p_in) {} \
    friend istream &operator >> ( iostream &, const IOMANIP(__Typ) & ); \
    friend ostream &operator << ( iostream &, const IOMANIP(__Typ) & ); \
}; \
class SAPP(__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
public: \
    SAPP(__Typ)( ios & (*__f_in)( ios &, __Typ ) ) : __f( __f_in ) {} \
    SMANIP(__Typ) operator () ( __Typ __p ) { \
	return SMANIP(__Typ)( __f, __p ); \
    } \
}; \
class IAPP(__Typ) { \
    istream & (*__f)( istream &, __Typ ); \
public: \
    IAPP(__Typ)( istream & (*__f_in)( istream &, __Typ ) ) : __f( __f_in ) {} \
    IMANIP(__Typ) operator () ( __Typ __p ) { \
	return IMANIP(__Typ)( __f, __p ); \
    } \
}; \
class OAPP(__Typ) { \
    ostream & (*__f)( ostream &, __Typ ); \
public: \
    OAPP(__Typ)( ostream & (*__f_in)( ostream &, __Typ ) ) : __f( __f_in ) {} \
    OMANIP(__Typ) operator () ( __Typ __p ) { \
	return OMANIP(__Typ)( __f, __p ); \
    } \
}; \
class IOAPP(__Typ) { \
    iostream & (*__f)( iostream &, __Typ ); \
public: \
    IOAPP(__Typ)( iostream & (*__f_in)( iostream &, __Typ ) ) : __f( __f_in ) {} \
    IOMANIP(__Typ) operator () ( __Typ __p ) { \
	return IOMANIP(__Typ)( __f, __p ); \
    } \
}; \
inline istream &operator >> ( istream &__is, const SMANIP(__Typ) &__m ) { \
    (__m.__f)( __is, __m.__p ); \
    return( __is ); \
} \
inline ostream &operator << ( ostream &__os, const SMANIP(__Typ) &__m ) { \
    (__m.__f)( __os, __m.__p ); \
    return( __os ); \
} \
inline istream &operator >> ( istream &__is, const IMANIP(__Typ) &__m ) { \
    (__m.__f)( __is, __m.__p ); \
    return( __is ); \
} \
inline ostream &operator << ( ostream &__os, const OMANIP(__Typ) &__m ) { \
    (__m.__f)( __os, __m.__p ); \
    return( __os ); \
} \
inline istream &operator >> ( iostream &__is, const IOMANIP(__Typ) &__m ) { \
    (__m.__f)( __is, __m.__p ); \
    return( __is ); \
} \
inline ostream &operator << ( iostream &__os, const IOMANIP(__Typ) &__m ) { \
    (__m.__f)( __os, __m.__p ); \
    return( __os ); \
}
#define IOMANIPdeclare(__Typ) SMANIP_define(__Typ)

// In the absence of templates, this macro converts a statement such as
//      SMANIP_make( int, setw );
// into
//      SMANIPint setw( int __p );
// to create the prototypes for the manipulators used with streams.

#define SMANIP_make(__Typ,__n) SMANIP(__Typ) __n(__Typ __p)

// Create instances of:
//      SMANIPint
//      SAPPint
//	IMANIPint
//      IAPPint
//	OMANIPint
//      OAPPint
//	IOMANIPint
//      IOAPPint
//      SMANIPlong
//      SAPPlong
//	IMANIPlong
//      IAPPlong
//	OMANIPlong
//      OAPPlong
//	IOMANIPlong
//      IOAPPlong

#pragma pack(1);
SMANIP_define( int );
SMANIP_define( long );
#pragma pack();

// Create the prototypes for the manipulator functions.

SMANIP_make( long, resetiosflags );
SMANIP_make( int,  setbase );
SMANIP_make( int,  setfill );
SMANIP_make( long, setiosflags );
SMANIP_make( int,  setprecision );
SMANIP_make( int,  setw );

#define _IOMANIP_H_INCLUDED
#endif
