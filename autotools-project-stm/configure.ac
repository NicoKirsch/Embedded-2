AC_INIT([heartbeat_sensor], [1.0], [you@example.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Cross-Compilation für STM32L432
AC_CANONICAL_HOST
AM_CONDITIONAL([CROSS_COMPILE], [test "$cross_compiling" = yes])

# Setze ARM Cross-Compiler
if test "$cross_compiling" = yes; then
    CC=arm-none-eabi-gcc
    CXX=arm-none-eabi-g++
fi

AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB

# STM32L432 Cortex-M4 Compiler-Flags
CFLAGS="-mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g -O2 -Wall -Wextra"
CXXFLAGS="-mcpu=cortex-m4 -mthumb -mfloat-abi=soft -fno-exceptions -fno-rtti -std=c++11 -g -O2 -Wall -Wextra"
LDFLAGS="-mcpu=cortex-m4 -mthumb -mfloat-abi=soft -nostdlib"

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile
src/Makefile])
AC_OUTPUT
