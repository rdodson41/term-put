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
#include <stdio.h>

//  Include term-put header files
#include <term-put.h>
#include <term-put-warning.h>

//  Print invalid term-put terminal type warning to standard error
void term_put_warning_term_invalid(const String term)
{
	fprintf(stderr, "term-put: warning: \"%s\" is not a valid terminal type\n", term);
}

//  Print generic term-put terminal type warning to standard error
void term_put_warning_term_generic(const String term)
{
	fprintf(stderr, "term-put: warning: \"%s\" is a generic terminal type\n", term);
}

//  Print hard-copy term-put terminal type warning to standard error
void term_put_warning_term_hard_copy(const String term)
{
	fprintf(stderr, "term-put: warning: \"%s\" is a hard-copy terminal type\n", term);
}

//  Print unsupported count of term-put terminal colors warning to standard error
void term_put_warning_term_color_count_unsupported(const String term)
{
	fprintf(stderr, "term-put: warning: \"%s\" does not support terminal colors\n", term);
}

//  Print invalid count of term-put terminal colors warning to standard error
void term_put_warning_term_color_count_invalid(const String term_color_count)
{
	fprintf(stderr, "term-put: warning: \"%s\" is not a valid number of terminal colors\n", term_color_count);
}

//  Print invalid term-put terminal color warning to standard error
void term_put_warning_term_color_invalid(const String term_color)
{
	fprintf(stderr, "term-put: warning: \"%s\" is not a valid terminal color\n", term_color);
}
