/*
 *  Multi2Sim
 *  Copyright (C) 2012  Yifan Sun (yifansun@coe.neu.edu)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "debug.h"


void m2s_hsa_fatal(char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nHSA runtime error: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
	fflush(NULL);
	exit(1);
}


void m2s_hsa_panic(char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nHSA runtime panic: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
	fflush(NULL);
	abort();
}


void m2s_hsa_warning(char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nHSA runtime warning: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
}
