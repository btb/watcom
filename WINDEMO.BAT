@echo off
set __opath=%path%
set path=M:\WATCOM\bin;M:\WATCOM\binb;M:\WATCOM\binw
set __oinc=%include%
set include=M:\WATCOM\h;M:\WATCOM\h\win
set watcom=M:\WATCOM\.
cd M:\WATCOM\src\win\life
wmake
if errorlevel 1 goto errorexit
..\iswin
if errorlevel 1 goto win
set path=%__opath%
win life
goto exit
:win
echo Return to windows with ALT-ESCAPE.
echo Select "File" from the program manager, and select
echo the RUN option to run life
goto exit
:errorexit
echo make did not work!
:exit
cd M:\WATCOM\.
set include=%__oinc%
set __oinc=
set path=%__opath%
set __opath=
