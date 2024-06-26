/****************************************************************************
*
* (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
* (c) Copyright WATCOM Systems Inc. 1988. All rights reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
* NetWare C NLM Runtime Library source code
*
*****************************************************************************/

#ifndef _MATH_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1);
extern  double      _HugeValue;
#define HUGE_VAL    _HugeValue

double    acos(
            double __x );
double    asin(
            double __x );
double    atan(
            double __x );
double    atan2(
            double __y,
            double __x );
double    ceil(
            double __x );
double    cos(
            double __x );
double    cosh(
            double __x );
double    exp(
            double __x );
double    fabs(
            double __x );
double    floor(
            double __x );
double    fmod(
            double __x,
            double __y );
double    frexp(
            double __value,
            int *__exp );
double    ldexp(
            double __x,
            int __exp );
double    log(
            double __x );
double    log10(
            double __x );
double    modf(
            double __value,
            double *__iptr );
double    pow(
            double __x,
            double __y );
double    sin(
            double __x );
double    sinh(
            double __x );
double    sqrt(
            double __x );
double    tan(
            double __x );
double    tanh(
            double __x );

/* non-ANSI */
#ifndef NO_EXT_KEYS    /* extensions enabled */

struct _complex {
	double	x;
	double	y;
};
#ifndef __cplusplus
struct complex {
	double	x;
	double	y;
};
#endif

double	acosh( double __x );
double	asinh( double __x );
double	atanh( double __x );
double    cabs(
            struct _complex);
double    hypot(
            double __x,
            double __y );
double    j0(
            double __x );
double    j1(
            double __x );
double    jn(
            int __n,
            double __x );
double	log2( double __x );
double    y0(
            double __x );
double    y1(
            double __x );
double    yn(
            int __n,
            double __x );

#define DOMAIN      1    /* argument domain error */
#define SING        2    /* argument singularity  */
#define OVERFLOW    3    /* overflow range error  */
#define UNDERFLOW   4    /* underflow range error */
#define TLOSS       5    /* total loss of significance */
#define PLOSS       6    /* partial loss of significance */

/* The following struct is used to record errors detected in the math library.
 * matherr is called with a pointer to this struct for possible error recovery.
 */

struct    exception {
            int    type;        /* type of error, see below */
            char   *name;       /* name of math function */
            double arg1;        /* value of first argument to function */
            double arg2;        /* second argument (if indicated) */
            double retval;      /* default return value */
};


int       matherr(
            struct exception * );

int      RegisterMatherrHandler(int(*_newFunc)(struct exception *));

double    _matherr(
            int,
            char   *,
            double *,
            double *,
            double);

#endif    /* NO_EXT_KEYS */

#ifndef __NO_MATH_OPS
/*
    Defining the __NO_MATH_OPS macro will stop the compiler from recogizing
    the following functions as intrinsic operators.
*/
    #pragma intrinsic(log,cos,sin,tan,sqrt,fabs,pow,atan2,fmod)
    #pragma intrinsic(acos,asin,atan,cosh,exp,log10,sinh,tanh)
#endif

#pragma pack();

#define _MATH_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
