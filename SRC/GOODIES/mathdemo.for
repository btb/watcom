      program mathdemo

* MATHDEMO.FOR - This program forms part of a collection of FORTRAN
*		 code that demonstrates how to take over control of
*		 math error handling from the run-time system.

* Compile: &cmpcmd mathdemo
* Link:    &lnkcmd file mathdemo, cw87, _matherr

* Notes:
* (1) We call "cw87" to enable underflow exceptions which are
*     masked (ignored) by default.
* (2) The signal handler must be re-installed after each signal
*     (it can also be re-installed even when there is no signal).
* (3) To prevent compile-time constant folding in expressions,
*     we add log(1.0) which is 0.  We do this for the sake of
*     demonstrating exception handling.

      implicit none

      double precision x, y, z

      call cw87 	! init 80x87 control word

      call resetFPE	! install signal handler
      print *, ' '
      print *, 'Divide by zero will be attempted'
      x = 1.0d0 + DLOG( 1.0d0 )
      y = 0.0d0
      z = x / y
      call chkFPE	! check for exception
      print *, z

      call resetFPE	! install signal handler
      print *, ' '
      print *, 'Overflow will be attempted'
      x = 1.2d300 + DLOG( 1.0d0 )
      y = 1.2d300
      z = x * y
      call chkFPE	! check for exception
      print *, z

      call resetFPE	! install signal handler
      print *, ' '
      print *, 'Underflow will be attempted'
      x = 1.14d-300 + DLOG( 1.0d0 )
      y = 2.24d-308
      z = x * y
      call chkFPE	! check for exception
      print *, z

      call resetFPE	! install signal handler
      print *, ' '
      print *, 'Math error will be attempted'
      x = -12.0
      y = SQRT( x )
      call chkFPE	! check for exception
      print *, x, y
      end

      subroutine resetFPE
      include 'fsignal.fi'
      external fpe_handler
      logical fpe_flag
      common fpe_flag
      fpe_flag = .false.
      call fsignal( SIGFPE, fpe_handler )
      end

      subroutine fpe_handler()
      logical fpe_flag
      common fpe_flag
      fpe_flag = .true.
      end

      subroutine chkFPE
      logical fpe_flag
      common fpe_flag
*     "volatile" is not needed here but would be
*     needed in main program if it references "fpe_flag"
      if( volatile( fpe_flag ) ) then
	print *, '*ERROR* exception occurred'
      else
	print *, '*OK* no exception occurred'
      endif
      end
