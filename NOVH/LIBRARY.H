/****************************************************************************
*
* (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
* NetWare C NLM Runtime Library source code
*
*****************************************************************************/

#ifndef _LIBRARY_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif
                                                                          
#include <nwtypes.h>

#define Thread_Data_Area        *__get_thread_data_area_ptr()

extern int *__get_thread_data_area_ptr();


extern LONG RegisterLibrary( 
         int (*cleanupFunc)( void *__dataAreaPtr ) );

extern int DeregisterLibrary( 
         LONG __libraryHandle );

extern int SaveDataAreaPtr( 
         LONG  __libraryHandle, 
         void *__dataAreaPtr );

extern void *GetDataAreaPtr( 
         LONG __libraryHandle );

#define _LIBRARY_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _LIBRARY_H_INCLUDED  */
