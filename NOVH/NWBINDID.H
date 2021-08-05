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

#ifndef _NWBINDID_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

int AddBinderyObjectToSetWithID( LONG __objectID, char *__propertyName,
                                 LONG __memberID );
int ChangeBinderyObjectPasswordWithID( LONG __objectID, char *__oldPassword,
                                       char *__newPassword );
int ChangeBinderyObjectSecurityWithID( LONG __objectID,
                                       BYTE __newObjectSecurity );
int ChangePropertySecurityWithID( LONG __objectID, char *__propertyName,
                                  BYTE __newPropertySecurity);
int CreatePropertyWithID( LONG __objectID, char *__propertyName,
                          BYTE __propertyFlags, BYTE __propertySecurity );
int DeleteBinderyObjectWithID( LONG __objectID );
int DeleteBinderyObjectFromSetWithID( LONG __objectID, char *__propertyName,
                                      LONG __memberID );
int DeletePropertyWithID( LONG __objectID, char *__propertyName );
int IsBinderyObjectInSetWithID( LONG __objectID, char *__propertyName,
                                LONG __memberID );
int ReadPropertyValueWithID( LONG objectID, char *__propertyName,
                             int __segmentNumber, BYTE *__propertyValue,
                             BYTE *__moreSegments, BYTE *__propertyFlags );
int RenameBinderyObjectWithID( LONG __objectID, char *__newObjectName );
int ScanPropertyWithID( LONG __objectID, char *__searchPropertyName,
                        long *__sequenceNumber, char *__propertyName,
                        char *__propertyFlags, char *__propertySecurity,
                        char *__propertyHasValue, char *__moreProperties );
int VerifyBinderyObjectPasswordWithID( LONG __objectID, char *__password );
int WritePropertyValueWithID( LONG __objectID, char *__propertyName,
                              int __segmentNumber, BYTE *__propertyValue,
                              BYTE __moreSegments );

#define _NWBINDID_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NWBINDID_H_INCLUDED */
