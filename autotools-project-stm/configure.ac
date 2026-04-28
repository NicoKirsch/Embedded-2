AC_INIT([heartbeat_sensor], [1.0], [you@example.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_NO_EXECUTABLES

AC_PROG_CC
AC_PROG_CXX

AC_CHECK_TOOL([OBJCOPY], [objcopy])
AC_CHECK_TOOL([SIZE], [size])

CPU_FLAGS="-mcpu=cortex-m4 -mthumb -mfloat-abi=soft"
AC_SUBST([CPU_FLAGS])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT