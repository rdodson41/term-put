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

//  Print term-put warning: Terminal is unsupported to standard error
void term_put_warning_term_unsupported(const bool term_env, const char* term)
{
	fprintf(stderr, "term-put: warning: %s is unsupported: \"%s\"\n", term_env ? "TERM" : "Terminal", term);
}

//  Print term-put warning: Terminal is a generic terminal to standard error
void term_put_warning_term_generic(const bool term_env, const char* term)
{
	fprintf(stderr, "term-put: warning: %s is a generic terminal: \"%s\"\n", term_env ? "TERM" : "Terminal", term);
}

//  Print term-put warning: Terminal is a hard-copy terminal to standard error
void term_put_warning_term_hard_copy(const bool term_env, const char* term)
{
	fprintf(stderr, "term-put: warning: %s is a hard-copy terminal: \"%s\"\n", term_env ? "TERM" : "Terminal", term);
}

//  Print term-put warning: Terminal colors are unavailable to standard error
void term_put_warning_term_colors_unavailable(const bool term_env, const char* term)
{
	fprintf(stderr, "term-put: warning: %s colors are unavailable: \"%s\"\n", term_env ? "TERM" : "Terminal", term);
}

//  Print term-put warning: Terminal colors are unsupported to standard error
void term_put_warning_term_colors_unsupported(const bool term_env, const char* term)
{
	fprintf(stderr, "term-put: warning: %s colors are unsupported: \"%s\"\n", term_env ? "TERM" : "Terminal", term);
}

//  Print term-put warning: Failed to convert number of terminal colors to a long integer to standard error
void term_put_warning_term_colors_conversion_failure(const bool term_colors_env, const char* term_colors)
{
	fprintf(stderr, "term-put: warning: Failed to convert %s to a long integer: \"%s\"\n", term_colors_env ? "TERM_COLORS" : "number of terminal colors", term_colors);
}

// Print term-put warning: Number of terminal colors is out of range to standard error
void term_put_warning_term_colors_overflow(const bool term_colors_env, const char* term_colors)
{
	fprintf(stderr, "term-put: warning: %s is out of range: \"%s\"\n", term_colors_env ? "TERM_COLORS" : "Number of terminal colors", term_colors);
}

// Print term-put warning: Number of terminal colors is out of range to standard error
void term_put_warning_term_colors_underflow(const bool term_colors_env, const char* term_colors)
{
	fprintf(stderr, "term-put: warning: %s is out of range: \"%s\"\n", term_colors_env ? "TERM_COLORS" : "Number of terminal colors", term_colors);
}
