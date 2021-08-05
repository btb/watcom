*  MIX2F.FOR - This FORTRAN program calls a C function to
*	       compute the max of three numbers.
*
* Compile: wfc[386] mix2f
* Link:    wlink file mix2f, mix2c name mix2

*$pragma aux tmax3 "*_" parm (value)

	program mix2f

	integer*4  tmax3
	integer*4  result
	integer*4  i, j, k

	i = -1
	j = 12
	k = 5
	result = tmax3( i, j, k )
	print *, 'Maximum is ', result
	end
