/*-
 * Copyright (c) 2015 Konstantin Belousov <kib@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/param.h>
#include <assert.h>
#include <err.h>
#include <stdbool.h>
#include <libunwind.h>
#include "pstack.h"

#ifndef __unused
#define	__unused	__attribute__((__unused__))
#endif

static int reg_idx[] = {
	UNW_ARM_R0,
	UNW_ARM_R1,
	UNW_ARM_R2,
	UNW_ARM_R3
};

int
pstack_get_arg(unw_addr_space_t as __unused, void *ui __unused,
    unw_cursor_t *c, int index, unw_word_t *arg)
{
	int reg, ret;

	assert(index >= 0);
	if ((unsigned)index < nitems(reg_idx)) {
		reg = reg_idx[index];
		ret = unw_get_reg(c, reg, arg);
		if (ret < 0) {
			if (verbose) {
				warnx("unw_get_reg(%d) failed, %s", reg,
				      unw_strerror(ret));
			}
			return (0);
		}
	} else {
		/* XXX */
		*arg = 0;
	}
	return (1);
}
