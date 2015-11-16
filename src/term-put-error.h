//
//  Name:     rdodson41/term-put/src/term-put-error.h
//  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
//  Created:  Mon Nov 16 20:48:24 UTC 2015
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

#ifndef TERM_PUT_ERROR
#define TERM_PUT_ERROR

//  Include term-put header files
#include <term-put.h>

void term_put_error_option_invalid(const String option);
void term_put_error_option_incomplete(const String option);
void term_put_error_option_short_invalid(const char option);
void term_put_error_attribute_invalid(const String attribute);
void term_put_error_attribute_incomplete(const String attribute);

#endif
