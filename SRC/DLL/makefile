# wmake lang=c   
# wmake lang=cpp 

!ifeq lang c
compile286 = wcc
compile386 = wcc386
!endif

!ifeq lang cpp
compile286 = wpp
compile386 = wpp386
!endif

dllflags = -bd -zc
cflags = -bt=windows -d1

.EXTENSIONS:
.EXTENSIONS: .dll .exe .obj .c

.BEFORE
    set include=$(%watcom)\h\win;$(%include)

all : dll16.dll dll32.dll gen16.exe gen32.exe .SYMBOLIC

gen16.exe : gen16.obj
    wlink @gen16

dll16.dll : dll16.obj
    wlink @dll16

gen32.exe : gen32.obj
    wlink @gen32
    wbind -n gen32
    @del gen32.rex

dll32.dll : dll32.obj
    wlink @dll32
    wbind -d -n dll32
    @del dll32.rex

dll16.obj : dll16.c
    $(compile286) dll16 -mc-zu $(dllflags) $(cflags)

dll32.obj : dll32.c
    $(compile386) dll32 $(dllflags) $(cflags)

gen16.obj : gen16.c
    $(compile286) gen16 $(cflags)

gen32.obj : gen32.c
    $(compile386) gen32 $(cflags)

clean : .SYMBOLIC
	@rm *.exe *.dll *.obj *.map
