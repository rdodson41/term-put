//
//  Name:     rdodson41/term-put/src/term-put.h
//  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
//  Created:  Thu Nov 05 21:55:50 UTC 2015
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

#ifndef TERM_PUT
#define TERM_PUT

//  Include C standard header files
#include <stdbool.h>

typedef struct
{
	long value;
	bool has_value;
}
LongOptional;

void term_put_term_set(char* value);
char* term_put_term_get();
void term_put_term_colors_set(char* value);
LongOptional term_put_term_colors_get();
LongOptional term_put_term_color_get(char* value);

void term_put_error_option_invalid(const char* option);
void term_put_error_option_incomplete(const char* option);
void term_put_error_option_short_invalid(const char option);
void term_put_error_attribute_invalid(const char* attribute);
void term_put_error_attribute_incomplete(const char* attribute);

void term_put_warning_term_unsupported(const char* term);
void term_put_warning_term_generic(const char* term);
void term_put_warning_term_hard_copy(const char* term);
void term_put_warning_term_colors_unavailable(const char* term);
void term_put_warning_term_colors_unsupported(const char* term);
void term_put_warning_term_colors_invalid(const char* term_colors);
void term_put_warning_term_colors_overflow(const char* term_colors);
void term_put_warning_term_colors_underflow(const char* term_colors);
void term_put_warning_term_color_invalid(const char* term_color);
void term_put_warning_term_color_overflow(const char* term_color);
void term_put_warning_term_color_underflow(const char* term_color);

#endif
