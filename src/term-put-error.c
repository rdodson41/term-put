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

//  Include C standard header files
#include <stdio.h>
#include <stdlib.h>

//  Print unsupported term-put option error to standard error and exit
void term_put_error_option_unsupported(const char* option)
{
	fprintf(stderr, "term-put: error: Option \"%s\" is not supported\n", option);
	exit(1);
}

//  Print incomplete term-put option error to standard error and exit
void term_put_error_option_incomplete(const char* option)
{
	fprintf(stderr, "term-put: error: Option \"%s\" requires an argument\n", option);
	exit(1);
}

//  Print unsupported term-put option error to standard error and exit
void term_put_error_option_short_unsupported(const char option)
{
	fprintf(stderr, "term-put: error: Option \"%c\" is not supported\n", option);
	exit(1);
}

//  Print unsupported term-put attribute error to standard error and exit
void term_put_error_attribute_unsupported(const char* attribute)
{
	fprintf(stderr, "term-put: error: Attribute \"%s\" is not supported\n", attribute);
	exit(1);
}

//  Print incomplete term-put attribute error to standard error and exit
void term_put_error_attribute_incomplete(const char* attribute)
{
	fprintf(stderr, "term-put: error: Attribute \"%s\" requires an argument\n", attribute);
	exit(1);
}
