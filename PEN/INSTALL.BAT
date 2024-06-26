@echo off
rem *************************************************************************
rem ** PenPoint Parallel Link Debug Server Installation                    **
rem ** Copyright 1993 by WATCOM International Corporation. All rights      **
rem ** reserved.                                                           **
rem *************************************************************************
rem *************************************************************************
rem **                                                                     **
rem **   リモートデバッカ作成ツール                                        **
rem **                                                                     **
rem **              Copyright 1993 FUJITSU LIMITED. All rights reserved.   **
rem ** ─────────────────────────────────  **
rem **                                                                     **
rem **     これは, PenPoint上で動作するﾘﾓｰﾄﾃﾞﾊﾞｯｶを作成するﾊﾞｯﾁﾌｧｲﾙです.   **
rem **   PenPoint SDK・WATCOM C32をｲﾝｽﾄｰﾙしたら, 本ﾊﾞｯﾁﾌｧｲﾙを起動してく    **
rem **   ださい.                                                           **
rem **                                                                     **
rem *************************************************************************
set $$PEN=%WATCOM%\PEN
set $$SDK=%PENPOINT_PATH%
set $$SRV=wparserv
if [%1] == [] goto NOMORE
if [%1] == [d] goto DEBUGSRVR
set $$PEN=%1
if [%2] == [] goto NOMORE
if [%2] == [d] goto DEBUGSRVR
set $$SDK=%2
if not [%3] == [d] goto NOMORE
:DEBUGSRVR
set $$SRV=dparserv
:NOMORE
if not exist %$$PEN%\%$$SRV%.dll             goto ERR1
if not exist %$$SDK%\sdk\util\dos\stamp.exe  goto ERR2

if exist %$$SDK%\boot\jpn.res goto PENPOINT20
    echo Installing WATCOM's PenPoint 1.0 Parallel Link Debug Server...
    if not exist %$$SDK%\service\%$$SRV%\nul md %$$SDK%\service\%$$SRV%
    copy %$$PEN%\%$$SRV%.dll %$$SDK%\service\%$$SRV% >nul

    %$$SDK%\sdk\util\dos\stamp %$$SDK%\service\%$$SRV%\..  /g "%$$SRV%" /d %$$SRV%
    %$$SDK%\sdk\util\dos\stamp %$$SDK%\service\%$$SRV%\.. /g "%$$SRV%" /a 01E00208 "1.0"
    %$$SDK%\sdk\util\dos\stamp %$$SDK%\service\%$$SRV%\.. /g "%$$SRV%" /a 01600182 "WATCOM0-par_server-V1(0)"
    %$$SDK%\sdk\util\dos\stamp %$$SDK%\service\%$$SRV%\.. /g "%$$SRV%" /a 0660013a "Test"
    %$$SDK%\sdk\util\dos\stamp %$$SDK%\service\%$$SRV%\.. /g "%$$SRV%" /a 0080013a 1000240
    %$$SDK%\sdk\util\dos\stamp %$$SDK%\service\%$$SRV%\.  /g "%$$SRV%.dll" /d %$$SRV%.dll
    goto done

:PENPOINT20
    echo Installing WATCOM's PenPoint 2.0 Parallel Link Debug Server...
    if not exist %$$SDK%\service\%$$SRV%\nul md %$$SDK%\service\%$$SRV%
    if [%$$SRV%]==[dparserv] copy %$$PEN%\dparsrv2.dll %$$SDK%\service\%$$SRV%\%$$SRV%.dll >nul
    if not [%$$SRV%]==[dparserv] copy %$$PEN%\wparsrv2.dll %$$SDK%\service\%$$SRV%\%$$SRV%.dll >nul

    echo %$$SDK%\service\%$$SRV%\..       > %$$SRV%.stm
    echo /u                              >> %$$SRV%.stm
    echo /n                              >> %$$SRV%.stm
    echo /g "%$$SRV%"                    >> %$$SRV%.stm
    echo /d %$$SRV%                      >> %$$SRV%.stm
    echo /a imAttrVersion "1.0"          >> %$$SRV%.stm
    echo /a cimAttrProgramName "WATCOM0-\x65e5\x672c\x8a9epar_server-V1(0)" >> %$$SRV%.stm
    echo /a appAttrClassName "Test"      >> %$$SRV%.stm
    echo /a appAttrClass 1000240         >> %$$SRV%.stm
    %$$SDK%\sdk\util\dos\stamp /s %$$SRV%.stm

    echo %$$SDK%\service\%$$SRV%\.        > %$$SRV%.stm
    echo /u                              >> %$$SRV%.stm
    echo /n                              >> %$$SRV%.stm
    echo /g "%$$SRV%.dll" /d %$$SRV%.dll >> %$$SRV%.stm
    %$$SDK%\sdk\util\dos\stamp /s %$$SRV%.stm

    del %$$SRV%.stm
    goto done
:ERR1
    echo.
    if exist CLOCK  goto ERR1B
    if not [%WATCOM%] == [] goto ERR1A
    echo The WATCOM environment variable is not defined.
:ERR1A
    echo '%$$PEN%' is not the location of the PenPoint debug server.
    echo.
    goto ERR2
:ERR1B
    echo      ┌──────────────────────────────┐
    echo      │ [0;1;32mWATCOM C32がインストールされていないか, 環境変数｢ WATCOM ｣[0;37m │
    echo      │ [0;1;32mが正しく設定されていません. 確認してください.             [0;37m │
    echo      │ ---------------------------------------------------------- │
    echo      │ 例) 環境変数  WATCOM=C:\WATCOM                             │
    echo      └──────────────────────────────┘
    echo.
:ERR2
    if exist %$$SDK%\sdk\util\dos\stamp.exe  goto DONE
    if exist CLOCK  goto ERR2B
    if not [%PENPOINT_PATH%] == [] goto ERR2A
    echo The PENPOINT_PATH environment variable is not defined.
:ERR2A
    echo '%$$SDK%' is not the root of a PenPoint SDK
    echo.
    goto DONE
:ERR2B
    echo      ┌──────────────────────────────┐
    echo      │ [0;1;32mPenPoint 2.01 SDK 日本語がインストールされていないか, 環境[0;37m │
    echo      │ [0;1;32m変数｢ PENPOINT_PATH ｣ が正しく設定されていません. 確認して[0;37m │
    echo      │ [0;1;32mください.                                                 [0;37m │
    echo      │ ---------------------------------------------------------- │
    echo      │ 例) 環境変数  PENPOINT_PATH=C:\2_01\PENPOINT               │
    echo      └──────────────────────────────┘
    echo.
:DONE
set $$PEN=
set $$SDK=
set $$SRV=
