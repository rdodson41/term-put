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

//  Define macro variables to help process command line arguments
#define ARGUMENT (*argv)
#define OPTION (ARGUMENT + 2)
#define VALUE (separator + 1)

void term_put_usage();
void term_put_version();

void term_put_term();
void term_put_term_color_count();

void term_put_normal();
void term_put_bold();
void term_put_underline();

void term_put_foreground(char* value);
void term_put_background(char* value);

#endif
