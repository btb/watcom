@echo off
set __opath=%path%
set path=M:\WATCOM\bin;M:\WATCOM\binb
set __oinc=%include%
set include=M:\WATCOM\h
set watcom=M:\WATCOM\.
wcl386 /l=dos4g /bt=dos M:\WATCOM\src\grdemo
dos4gw grdemo
set include=%__oinc%
set __oinc=
set path=%__opath%
set __opath=
