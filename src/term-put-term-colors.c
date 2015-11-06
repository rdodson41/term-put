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
#include <term.h>
#include <term-put.h>

static int term_colors_set = FALSE;
static long term_colors = 0;

//  Initialize number of terminal colors
void term_put_term_colors_initialize() {
	char* value = getenv("TERM_COLORS");
	if(value != NULL) {
		errno = 0;
		term_colors = strtol(value, &value, 0);
		if(errno == EINVAL)
			;
		else if(errno == ERANGE)
			;
		else if(value[0] != '\0')
			;
		else
			term_colors_set = TRUE;
	}
}

//  Print number of terminal colors to standard output
int term_put_term_colors(const int term_colors_set, int term_colors) {
	if(!term_colors_set) {
		term_colors = tigetnum("colors");
		if(term_colors < 0)
			return term_colors;
	}
	int length = fprintf(stdout, "%d\n", term_colors);
	return length < 0 ? 0 : length;
}
