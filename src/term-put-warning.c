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

#include <stdio.h>
#include <term-put.h>

//  Print term-put warning: Failed to convert number of terminal colors to a long integer to standard error
void term_put_warning_term_colors_conversion_failure(const char* term_colors) {
	static const char TERM_PUT_WARNING_TERM_COLORS_CONVERSION_FAILURE[] = "term-put: warning: Failed to convert %s to a long integer\n";
	fprintf(stderr, TERM_PUT_WARNING_TERM_COLORS_CONVERSION_FAILURE, term_colors);
}

// Print term-put warning: Number of terminal colors is out of range to standard error
void term_put_warning_term_colors_overflow(const char* term_colors) {
	static const char TERM_PUT_WARNING_TERM_COLORS_OVERFLOW[] = "term-put: warning: %s is out of range\n";
	fprintf(stderr, TERM_PUT_WARNING_TERM_COLORS_OVERFLOW, term_colors);
}

// Print term-put warning: Number of terminal colors is out of range to standard error
void term_put_warning_term_colors_underflow(const char* term_colors) {
	static const char TERM_PUT_WARNING_TERM_COLORS_UNDERFLOW[] = "term-put: warning: %s is out of range\n";
	fprintf(stderr, TERM_PUT_WARNING_TERM_COLORS_UNDERFLOW, term_colors);
}

//  Print term-put warning: Terminal colors are unavailable to standard error
void term_put_warning_term_colors_unavailable() {
	static const char TERM_PUT_WARNING_TERM_COLORS_UNAVAILABLE[] = "term-put: warning: Terminal colors are unavailable\n";
	FWRITE(stderr, TERM_PUT_WARNING_TERM_COLORS_UNAVAILABLE);
}

//  Print term-put warning: Terminal colors are unsupported to standard error
void term_put_warning_term_colors_unsupported() {
	static const char TERM_PUT_WARNING_TERM_COLORS_UNSUPPORTED[] = "term-put: warning: Terminal colors are unsupported\n";
	FWRITE(stderr, TERM_PUT_WARNING_TERM_COLORS_UNSUPPORTED);
}
