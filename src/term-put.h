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

#ifndef TERM_PUT_VERSION
#define TERM_PUT_VERSION "(unknown)"
#endif

typedef char* String;

typedef struct
{
	long value;
	bool has_value;
}
LongOptional;

typedef String Term;
typedef LongOptional TermColor;

void term_put_quit();
void term_put_usage();
void term_put_version();
void term_put_term();
void term_put_term_colors();
void term_put_normal();
void term_put_bold();
void term_put_underline();
void term_put_foreground(String value);
void term_put_background(String value);

#endif
