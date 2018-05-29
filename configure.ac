dnl Copyright (c) 2012 Konstantin Belousov <kib@FreeBSD.org>
dnl All rights reserved.
dnl
dnl Redistribution and use in source and binary forms, with or without
dnl modification, are permitted provided that the following conditions
dnl are met:
dnl 1. Redistributions of source code must retain the above copyright
dnl    notice unmodified, this list of conditions, and the following
dnl    disclaimer.
dnl 2. Redistributions in binary form must reproduce the above copyright
dnl    notice, this list of conditions and the following disclaimer in the
dnl    documentation and/or other materials provided with the distribution.
dnl
dnl THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
dnl IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
dnl OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
dnl IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
dnl INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
dnl NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
dnl DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
dnl THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
dnl (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
dnl THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

AC_INIT([pstacku],[0.10.0],[kib@FreeBSD.org])
AC_PREREQ([2.69])
AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_HOST
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE
AM_CONFIG_HEADER(config.h)


LIBUNWIND_REQUIRED=1.21
AC_SUBST([LIBUNWIND_REQUIRED])

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AM_PROG_LIBTOOL

PKG_CHECK_MODULES([LIBUNWIND], [libunwind >= $LIBUNWIND_REQUIRED])
AC_SUBST([LIBUNWIND_CFLAGS])
AC_SUBST([LIBUNWIND_LIBS])

AS_CASE([$host],
	[amd64-*-*], [ARCH_OBJ=pstack-amd64.$OBJEXT],
	[i?86-*-*],   [ARCH_OBJ=pstack-i386.$OBJEXT],
	[arm-*-*],   [ARCH_OBJ=pstack-arm.$OBJEXT],
	[armv6-*-*],   [ARCH_OBJ=pstack-arm.$OBJEXT],
	[ARCH_OBJ=""]
)
AC_SUBST([ARCH_OBJ])

AC_CONFIG_FILES(Makefile)

AC_OUTPUT
