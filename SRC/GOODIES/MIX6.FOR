* MIX6.FOR - This FORTRAN program calls the C
*	     printf function.

* Compile: wfc[386] mix6
* Link (286): wlink file mix6 lib \watcom\lib286\dos\clibl
*      (386): wlink file mix6 lib \watcom\lib386\dos\clib3r

*$pragma aux printf "*_" parm (value) caller []

	program mix6

	character cr/z0d/, nullchar/z00/

	call printf( 'Value is %ld.'//cr//nullchar, 47 )
	end
