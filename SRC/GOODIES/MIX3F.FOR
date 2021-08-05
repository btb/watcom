* MIX3F.FOR - This FORTRAN program calls a function written
*	      in C that passes back a string.
*
* Compile: wfc[386] mix3f
* Link:    wlink file mix3f, mix3c name mix3

	program mix3f

	character*80 sendstr
	character*80 cstring

	cstring = sendstr()
	print *, cstring(1:lentrim(cstring))
	end
