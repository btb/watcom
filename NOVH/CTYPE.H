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

#ifndef _CTYPE_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#define _LOWER 0x80
#define _UPPER 0x40
#define _DIGIT 0x20
#define _XDIGT 0x10
#define _PRINT 0x08
#define _PUNCT 0x04
#define _SPACE 0x02
#define _CNTRL 0x01

extern int isalnum(
         int _aChar );

extern int isalpha(
         int _aChar );

extern int iscntrl(
         int _aChar );

extern int isdigit(
         int _aChar );

extern int isgraph(
         int _aChar );

extern int islower(
         int _aChar );

extern int isprint(
         int _aChar );

extern int ispunct(
         int _aChar );

extern int isspace(
         int _aChar );

extern int isupper(
         int _aChar );

extern int isxdigit(
         int _aChar );

extern int tolower(
         int _aChar );

extern int toupper(
         int _aChar );



#ifndef NO_EXT_KEYS  /* extensions enabled */

   extern  int isascii(
            int _aChar );

   #define isascii(__c) ((unsigned)(__c) <= 0x7f)

#endif

extern const char _IsTable[257];

#define isalnum(__c)  (_IsTable[(unsigned char)((__c)+1)] & (_LOWER|_UPPER|_DIGIT))
#define isalpha(__c)  (_IsTable[(unsigned char)((__c)+1)] & (_LOWER|_UPPER))
#define iscntrl(__c)  (_IsTable[(unsigned char)((__c)+1)] &  _CNTRL)
#define isdigit(__c)  (_IsTable[(unsigned char)((__c)+1)] &  _DIGIT)
#define isgraph(__c) ((_IsTable[(unsigned char)((__c)+1)] & (_PRINT|_SPACE)) == _PRINT)
#define islower(__c)  (_IsTable[(unsigned char)((__c)+1)] &  _LOWER)
#define isprint(__c)  (_IsTable[(unsigned char)((__c)+1)] &  _PRINT)
#define ispunct(__c)  (_IsTable[(unsigned char)((__c)+1)] &  _PUNCT)
#define isspace(__c)  (_IsTable[(unsigned char)((__c)+1)] &  _SPACE)
#define isupper(__c)  (_IsTable[(unsigned char)((__c)+1)] &  _UPPER)
#define isxdigit(__c) (_IsTable[(unsigned char)((__c)+1)] &  _XDIGT)

#define _CTYPE_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
