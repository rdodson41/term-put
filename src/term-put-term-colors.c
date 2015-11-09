//  
//  Name:     rdodson41/term-put/src/term-put-term-colors.c
//  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
//  Created:  Fri Nov 06 00:57:25 UTC 2015
//  License:  GNU General Public License, Version 3, 29 June 2007
//  
//  Copyright (C) 2015 Richard E. Dodson <richard.elias.dodson@gmail.com>
//  
//  This file is part of term-put.
//  
//  term-put is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  term-put is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with term-put. If not, see <http://www.gnu.org/licenses/>.
//

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <term.h>
#include <term-put.h>

static int term_colors_set = FALSE;
static long term_colors = 0;

//  Initialize terminal colors
void term_put_term_colors_initialize() {
	static const char TERM_COLORS[] = "TERM_COLORS";
	char* value = getenv(TERM_COLORS);
	if(value != NULL) {
		errno = 0;
		term_colors = strtol(value, &value, 0);
		if(errno == EINVAL)
			term_put_warning_term_colors_conversion_failure(TERM_COLORS);
		else if(errno == ERANGE && term_colors == LONG_MAX)
			term_put_warning_term_colors_overflow(TERM_COLORS);
		else if(errno == ERANGE && term_colors == LONG_MIN)
			term_put_warning_term_colors_underflow(TERM_COLORS);
		else if(value[0] != '\0')
			term_put_warning_term_colors_conversion_failure(TERM_COLORS);
		else
			term_colors_set = TRUE;
	}
}

//  Print number of terminal colors to standard output
int term_put_term_colors() {
	if(term_colors_set) {
		int length = fprintf(stdout, "%ld\n", term_colors);
		return length < 0 ? 0 : length;
	} else {
		long term_colors = tigetnum("colors");
		if(term_colors < 0) {
			if(term_colors == -2)
				term_put_warning_term_colors_unavailable();
			else if(term_colors == -1)
				term_put_warning_term_colors_unsupported();
			return term_colors;
		} else {
			int length = fprintf(stdout, "%ld\n", term_colors);
			return length < 0 ? 0 : length;
		}
	}
}
