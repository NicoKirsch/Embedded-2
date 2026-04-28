AC_INIT([heartbeat_sensor], [1.0], [you@example.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CC
AC_PROG_CXX

AC_CHECK_TOOL([OBJCOPY], [objcopy])
AC_CHECK_TOOL([SIZE], [size])
AC_PROG_RANLIB

CPU_FLAGS="-mcpu=cortex-m4 -mthumb -mfloat-abi=soft"
AC_SUBST([CPU_FLAGS])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT