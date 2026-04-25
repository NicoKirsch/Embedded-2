AC_INIT([heartbeat_sensor], [1.0], [you@example.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB

# STM32L432 Cortex-M4 Cross-Compilation Flags
ARM_CPU_FLAGS="-mcpu=cortex-m4 -mthumb -mfloat-abi=soft"
ARM_CXXFLAGS="-fno-exceptions -fno-rtti -std=c++11"

CFLAGS="${CFLAGS} ${ARM_CPU_FLAGS} -Wall -Wextra"
CXXFLAGS="${CXXFLAGS} ${ARM_CPU_FLAGS} ${ARM_CXXFLAGS} -Wall -Wextra"
LDFLAGS="${LDFLAGS} ${ARM_CPU_FLAGS}"

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile
src/Makefile])
AC_OUTPUT
