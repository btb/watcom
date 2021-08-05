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

// In the absence of templates, this macro converts a statement such as
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

#define SMANIP_define(__Typ) \
class name2(SMANIP,__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
    __Typ __p; \
public: \
    name2(SMANIP,__Typ)( ios & (*__f_in)( ios &, __Typ ), __Typ __p_in ) : \
	__f(__f_in), __p(__p_in) {} \
    friend istream &operator >> ( istream &, name2(SMANIP,__Typ) & ); \
    friend ostream &operator << ( ostream &, name2(SMANIP,__Typ) & ); \
}; \
class name2(IMANIP,__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
    __Typ __p; \
public: \
    name2(IMANIP,__Typ)( ios & (*__f_in)( ios &, __Typ ), __Typ __p_in ) : \
	__f(__f_in), __p(__p_in) {} \
    friend istream &operator >> ( istream &, name2(IMANIP,__Typ) & ); \
}; \
class name2(OMANIP,__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
    __Typ __p; \
public: \
    name2(OMANIP,__Typ)( ios & (*__f_in)( ios &, __Typ ), __Typ __p_in ) : \
	__f(__f_in), __p(__p_in) {} \
    friend ostream &operator << ( ostream &, name2(OMANIP,__Typ) & ); \
}; \
class name2(IOMANIP,__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
    __Typ __p; \
public: \
    name2(IOMANIP,__Typ)( ios & (*__f_in)( ios &, __Typ ), __Typ __p_in ) : \
	__f(__f_in), __p(__p_in) {} \
    friend istream &operator >> ( istream &, name2(IOMANIP,__Typ) & ); \
    friend ostream &operator << ( ostream &, name2(IOMANIP,__Typ) & ); \
}; \
class name2(SAPP,__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
public: \
    name2(SAPP,__Typ)( ios & (*__f_in)( ios &, __Typ ) ) : __f( __f_in ) {} \
    name2(SMANIP,__Typ) operator () ( __Typ __p ) { \
	return name2(SMANIP,__Typ)( __f, __p ); \
    } \
}; \
class name2(IAPP,__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
public: \
    name2(IAPP,__Typ)( ios & (*__f_in)( ios &, __Typ ) ) : __f( __f_in ) {} \
    name2(IMANIP,__Typ) operator () ( __Typ __p ) { \
	return name2(IMANIP,__Typ)( __f, __p ); \
    } \
}; \
class name2(OAPP,__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
public: \
    name2(OAPP,__Typ)( ios & (*__f_in)( ios &, __Typ ) ) : __f( __f_in ) {} \
    name2(OMANIP,__Typ) operator () ( __Typ __p ) { \
	return name2(OMANIP,__Typ)( __f, __p ); \
    } \
}; \
class name2(IOAPP,__Typ) { \
    ios & (*__f)( ios &, __Typ ); \
public: \
    name2(IOAPP,__Typ)( ios & (*__f_in)( ios &, __Typ ) ) : __f( __f_in ) {} \
    name2(IOMANIP,__Typ) operator () ( __Typ __p ) { \
	return name2(IOMANIP,__Typ)( __f, __p ); \
    } \
}; \
inline istream &operator >> ( istream &__is, name2(SMANIP,__Typ) &__m ) { \
    (__m.__f)( __is, __m.__p ); \
    return( __is ); \
} \
inline ostream &operator << ( ostream &__os, name2(SMANIP,__Typ) &__m ) { \
    (__m.__f)( __os, __m.__p ); \
    return( __os ); \
} \
inline istream &operator >> ( istream &__is, name2(IMANIP,__Typ) &__m ) { \
    (__m.__f)( __is, __m.__p ); \
    return( __is ); \
} \
inline ostream &operator << ( ostream &__os, name2(OMANIP,__Typ) &__m ) { \
    (__m.__f)( __os, __m.__p ); \
    return( __os ); \
} \
inline istream &operator >> ( istream &__is, name2(IOMANIP,__Typ) &__m ) { \
    (__m.__f)( __is, __m.__p ); \
    return( __is ); \
} \
inline ostream &operator << ( ostream &__os, name2(IOMANIP,__Typ) &__m ) { \
    (__m.__f)( __os, __m.__p ); \
    return( __os ); \
}

// In the absence of templates, this macro converts a statement such as
//      SMANIP_make( int, setw );
// into
//      SMANIPint setw( int __p );
// to create the prototypes for the manipulators used with streams.

#define SMANIP_make(__Typ,__n) name2(SMANIP,__Typ) __n(__Typ __p)

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

#endif
