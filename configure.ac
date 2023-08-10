# Process this file with autoconf to produce a configure script.

# Order of itmes is suggested in the autoconf documentation to be that
# below, to be as below. Let's try to stick to it.

# checks for programs
# checks for lib4aries
# checks for header files
# checks for typedefs
# checks for structures
# checks for compiler characteristics
# checks for library functions
# checks for system services
# AC_OUTPUT([file...])

AC_INIT([cppcc], [0.02], [drkirkby@kirkbymicrowave.co.uk])
AM_INIT_AUTOMAKE
AC_PREREQ([2.57])
AC_CONFIG_SRCDIR([src/cppcc.c])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_ISC_POSIX

# AC_OUTPUT_COMMANDS([exit])

# Checks for libraries.
# check for optimised math library on SPARC
# AC_CHECK_LIB([mopt],[main])
# check for the optimised
# AC_CHECK_LIB([copt],[main])
AC_CHECK_LIB(m,log)
AC_CHECK_LIB(pthread,pthread_create)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h math.h malloc.h stdlib.h string.h time.h limits.h ])




# checks for system services

AC_ARG_ENABLE(debug, AC_HELP_STRING([--enable-debug],[ with debugging code]), AC_DEFINE([DEBUG],[1],[with debugging code]))
dnl Only use -Wall if we have gcc
if test "x$GCC" = "xyes"; then
  if test -z "`echo "$CFLAGS" | grep "\-Wall" 2> /dev/null`" ; then
      CFLAGS="$CFLAGS -Wall"
  fi
fi
AC_SUBST(compiled_with_compiler,"$CC")
AC_SUBST(compiled_with_cflags,"$CFLAGS")
AC_OUTPUT([\
Makefile                                        \
src/Makefile 
])
