@echo off
set __opath=%path%
set path=M:\WATCOM\binp;M:\WATCOM\binb
set __oinc=%include%
set include=M:\WATCOM\h;%TOOLKIT%\c\os2h;%INCLUDE%
set watcom=M:\WATCOM\.
wcl386 /l=os2v2_pm /bt=os2 M:\WATCOM\src\shapes
shapes
set include=%__oinc%
set __oinc=
set path=%__opath%
set __opath=
