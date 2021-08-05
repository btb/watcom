@echo off
rem *************************************************************************
rem PenPoint Parallel Link Debug Server Installation
rem Copyright 1993 by WATCOM International Corporation. All rights reserved.
rem *************************************************************************
if [%2] == [] goto usage
if [%1] == [] goto usage
if [%1] == [?] goto usage
set $$$wp=wparserv
if [%3] == [d] set $$$wp=dparserv
if not exist %1\%$$$wp%.dll goto nowatcom
if not exist %2\sdk\util\dos\stamp.exe goto nopenpoint
if exist %2\boot\jpn.res goto penpoint20
    echo Installing WATCOM's PenPoint 1.0 Parallel Link Debug Server...
    if not exist %2\service\%$$$wp%\nul md %2\service\%$$$wp%
    copy %1\%$$$wp%.dll %2\service\%$$$wp% >nul
    %2\sdk\util\dos\stamp %2\service\%$$$wp%\..  /g "%$$$wp%" /d %$$$wp%
    %2\sdk\util\dos\stamp %2\service\%$$$wp%\.. /g "%$$$wp%" /a 01E00208 "1.0"
    %2\sdk\util\dos\stamp %2\service\%$$$wp%\.. /g "%$$$wp%" /a 01600182 "WATCOM0-par_server-V1(0)"
    %2\sdk\util\dos\stamp %2\service\%$$$wp%\.. /g "%$$$wp%" /a 0660013a "Test"
    %2\sdk\util\dos\stamp %2\service\%$$$wp%\.. /g "%$$$wp%" /a 0080013a 1000240
    %2\sdk\util\dos\stamp %2\service\%$$$wp%\.	/g "%$$$wp%.dll" /d %$$$wp%.dll
    goto done
:penpoint20
    echo Installing WATCOM's PenPoint 2.0 Parallel Link Debug Server...
    if not exist %2\service\%$$$wp%\nul md %2\service\%$$$wp%
    copy %1\wparsrv2.dll %2\service\%$$$wp%\%$$$wp%.dll >nul
    echo %2\service\%$$$wp%\.. >%$$$wp%.stm
    echo /u >>%$$$wp%.stm
    echo /n >>%$$$wp%.stm
    echo /g "%$$$wp%" >>%$$$wp%.stm
    echo /d %$$$wp% >>%$$$wp%.stm
    echo /a imAttrVersion "1.0" >>%$$$wp%.stm
    echo /a cimAttrProgramName "WATCOM0-\x65e5\x672c\x8a9epar_server-V1(0)" >>%$$$wp%.stm
    echo /a appAttrClassName "Test" >>%$$$wp%.stm
    echo /a appAttrClass 1000240 >>%$$$wp%.stm
    %2\sdk\util\dos\stamp /s %$$$wp%.stm
    echo %2\service\%$$$wp%\. >%$$$wp%.stm
    echo /u >>%$$$wp%.stm
    echo /n >>%$$$wp%.stm
    echo /g "%$$$wp%.dll" /d %$$$wp%.dll >>%$$$wp%.stm
    %2\sdk\util\dos\stamp /s %$$$wp%.stm
    del %$$$wp%.stm
    goto done
:nowatcom
    echo.
    echo '%1' is not the location of the PenPoint debug server
    echo.
    goto done
:nopenpoint
    echo.
    echo '%2' is not the root of a PenPoint SDK
    echo.
    goto done
:usage
    echo PenPoint Parallel Link Debug Server Installation
    echo Usage: %0 C:\WATCOM\PEN C:\PENPOINT
    echo where:
    echo       C:\WATCOM\PEN is the location of this batch file.
    echo       C:\PENPOINT is the root of a PenPoint SDK installation.
    echo Example:
    echo       %0 A:\WATCOM\PEN D:\2_0\PENPOINT
    echo.
:done
set $$$wp=
