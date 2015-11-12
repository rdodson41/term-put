//
//  Name:     rdodson41/term-put/src/term-put-error.c
//  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
//  Created:  Wed Nov 11 22:38:58 UTC 2015
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
#include <term-put.h>

//  Print term-put error: Invalid option to standard error and exit
void term_put_error_option_long_invalid(const char* option) {
	static const char TERM_PUT_ERROR_OPTION_LONG_INVALID[] = "term-put: error: Invalid option: --%s\n";
	fprintf(stderr, TERM_PUT_ERROR_OPTION_LONG_INVALID, option);
	exit(1);
}

//  Print term-put error: Malformed option to standard error and exit
void term_put_error_option_long_malformed(const char* option) {
	static const char TERM_PUT_ERROR_OPTION_LONG_MALFORMED[] = "term-put: error: Malformed option: --%s requires an argument\n";
	fprintf(stderr, TERM_PUT_ERROR_OPTION_LONG_MALFORMED, option);
	exit(1);
}

//  Print term-put error: Invalid option to standard error and exit
void term_put_error_option_short_invalid(const char option) {
	static const char TERM_PUT_ERROR_OPTION_SHORT_INVALID[] = "term-put: error: Invalid option: -%c\n";
	fprintf(stderr, TERM_PUT_ERROR_OPTION_SHORT_INVALID, option);
	exit(1);
}

//  Print term-put error: Malformed option to standard error and exit
void term_put_error_option_short_malformed(const char option) {
	static const char TERM_PUT_ERROR_OPTION_SHORT_MALFORMED[] = "term-put: error: Malformed option: -%c requires an argument\n";
	fprintf(stderr, TERM_PUT_ERROR_OPTION_SHORT_MALFORMED, option);
	exit(1);
}

//  Print term-put error: Invalid attribute to standard error and exit
void term_put_error_attribute_invalid(const char* attribute) {
	static const char TERM_PUT_ERROR_ATTRIBUTE_INVALID[] = "term-put: error: Invalid attribute: %s\n";
	fprintf(stderr, TERM_PUT_ERROR_ATTRIBUTE_INVALID, attribute);
	exit(1);
}

//  Print term-put error: Malformed attribute to standard error and exit
void term_put_error_attribute_malformed(const char* attribute) {
	static const char TERM_PUT_ERROR_ATTRIBUTE_MALFORMED[] = "term-put: error: Malformed attribute: %s requires a value\n";
	fprintf(stderr, TERM_PUT_ERROR_ATTRIBUTE_MALFORMED, attribute);
	exit(1);
}

//  Print term-put error: Terminal type is unsupported to standard error and exit
void term_put_error_term_unsupported(const char* term) {
	static const char TERM_PUT_ERROR_TERM_UNSUPPORTED[] = "term-put: error: Terminal type is unspported: %s\n";
	fprintf(stderr, TERM_PUT_ERROR_TERM_UNSUPPORTED, term);
	exit(1);
}
