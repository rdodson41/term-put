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

#include <stdlib.h>
#include <stdio.h>

//  Print term-put warning: Failed to find the terminal information database to standard error
void term_put_warning_term_info_location_failure() {
	fputs("Failed to find the terminal information database\n", stderr);
}

//  Print term-put warning: Terminal is a generic terminal to standard error
void term_put_warning_term_generic(const char* term) {
	fprintf(stderr, "term-put: error: Terminal is a generic terminal: %s\n", term);
}

//  Print term-put-error: Terminal is a hard-copy terminal to standard error
void term_put_warning_term_hard_copy(const char* term) {
	fprintf(stderr, "term-put: error: Terminal is a hard-copy terminal: %s\n", term);
}

//  Print term-put warning: Failed to convert number of terminal colors to a long integer to standard error
void term_put_warning_term_colors_conversion_failure(const char* term_colors) {
	fprintf(stderr, "term-put: warning: Failed to convert %s to a long integer\n", term_colors);
}

// Print term-put warning: Number of terminal colors is out of range to standard error
void term_put_warning_term_colors_overflow(const char* term_colors) {
	fprintf(stderr, "term-put: warning: %s is out of range\n", term_colors);
}

// Print term-put warning: Number of terminal colors is out of range to standard error
void term_put_warning_term_colors_underflow(const char* term_colors) {
	fprintf(stderr, "term-put: warning: %s is out of range\n", term_colors);
}

//  Print term-put warning: Terminal colors are unavailable to standard error
void term_put_warning_term_colors_unavailable() {
	fputs("term-put: warning: Terminal colors are unavailable\n", stderr);
}

//  Print term-put warning: Terminal colors are unsupported to standard error
void term_put_warning_term_colors_unsupported() {
	fputs("term-put: warning: Terminal colors are unsupported\n", stderr);
}
