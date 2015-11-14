//
//  Name:     rdodson41/term-put/src/term-put-warning.c
//  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
//  Created:  Wed Nov 11 22:39:02 UTC 2015
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

//  Include C standard header files
#include <stdbool.h>
#include <stdio.h>

//  Print unsupported term-put terminal warning to standard error
void term_put_warning_term_unsupported(const char* term)
{
	fprintf(stderr, "term-put: warning: \"%s\" is not supported\n", term);
}

//  Print generic term-put terminal warning to standard error
void term_put_warning_term_generic(const char* term)
{
	fprintf(stderr, "term-put: warning: \"%s\" is a generic terminal\n", term);
}

//  Print hard-copy term-put terminal warning to standard error
void term_put_warning_term_hard_copy(const char* term)
{
	fprintf(stderr, "term-put: warning: \"%s\" is a hard-copy terminal\n", term);
}

//  Print unavailable term-put terminal colors warning to standard error
void term_put_warning_term_colors_unavailable(const char* term)
{
	fprintf(stderr, "term-put: warning: \"%s\" colors are not available\n", term);
}

//  Print unsupported term-put terminal colors warning to standard error
void term_put_warning_term_colors_unsupported(const char* term)
{
	fprintf(stderr, "term-put: warning: \"%s\" colors are not supported\n", term);
}

//  Print invalid number of term-put terminal colors warning to standard error
void term_put_warning_term_colors_invalid(const char* term_colors)
{
	fprintf(stderr, "term-put: warning: \"%s\" is not a valid number of terminal colors\n", term_colors);
}

// Print overflow number of term-put terminal colors warning to standard error
void term_put_warning_term_colors_overflow(const char* term_colors)
{
	fprintf(stderr, "term-put: warning: \"%s\" is greater than the maximum number of terminal colors\n", term_colors);
}

// Print underflow number of term-put terminal colors warning to standard error
void term_put_warning_term_colors_underflow(const char* term_colors)
{
	fprintf(stderr, "term-put: warning: \"%s\" is less than the minimum number of terminal colors\n", term_colors);
}

//  Print invalid term-put terminal color warning to standard error
void term_put_warning_term_color_invalid(const char* term_color)
{
	fprintf(stderr, "term-put: warning: \"%s\" is not a valid terminal color\n", term_color);
}

// Print overflow term-put terminal color warning to standard error
void term_put_warning_term_color_overflow(const char* term_color)
{
	fprintf(stderr, "term-put: warning: \"%s\" is greater than the maximum terminal color\n", term_color);
}

// Print underflow term-put terminal color warning to standard error
void term_put_warning_term_color_underflow(const char* term_color)
{
	fprintf(stderr, "term-put: warning: \"%s\" is less than the minimum terminal color\n", term_color);
}
