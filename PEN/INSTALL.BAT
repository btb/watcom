@echo off
if [%2] == [] goto usage
if [%1] == [] goto usage
if [%1] == [?] goto usage
if not exist %1\wparserv.dll goto nowatcom
if not exist %2\sdk\util\dos\stamp.exe goto nopenpoint
    if not exist %2\service\wparserv\nul md %2\service\wparserv
    copy %1\wparserv.dll %2\service\wparserv >nul
    %2\sdk\util\dos\stamp %2\service\wparserv\..  /g "wparserv" /d wparserv
    %2\sdk\util\dos\stamp %2\service\wparserv\.. /g "wparserv" /a 01E00208 "1.0"
    %2\sdk\util\dos\stamp %2\service\wparserv\.. /g "wparserv" /a 01600182 "WATCOM0-par_server-V1(0)"
    %2\sdk\util\dos\stamp %2\service\wparserv\.. /g "wparserv" /a 0660013a "Test"
    %2\sdk\util\dos\stamp %2\service\wparserv\.. /g "wparserv" /a 0080013a 1000240
    %2\sdk\util\dos\stamp %2\service\wparserv\.  /g "wparserv.dll" /d wparserv.dll
    goto done
:nowatcom
    echo.
    echo '%1' is not the location of the PenPoint debugger
    echo.
    goto done
:nopenpoint
    echo.
    echo '%2' is not the root of a penpoint SDK
    echo.
    goto done
:usage
    echo.
    echo.
    echo Usage:
    echo        %0 C:\WATCOM\PEN C:\PENPOINT
    echo Where:
    echo        C:\WATCOM\PEN is the location of this batch file.
    echo        C:\PENPOINT is the root of a PenPoint SDK installation.
    echo.
    echo.
:done
