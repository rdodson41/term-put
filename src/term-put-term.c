//
//  Name:     rdodson41/term-put/src/term-put-term.c
//  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
//  Created:  FThu Nov 12 02:17:34 UTC 2015
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
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

//  Include POSIX standard header files
#include <unistd.h>

//  Include ncurses header files
#include <ncurses.h>
#include <term.h>

//  Include term-put header files
#include <term-put.h>

typedef struct
{
	bool null;
	long value;
}
OptionalLong;

static OptionalLong _term_colors = { true, 0 };

//  Set terminal type
void term_put_term_set(char* term)
{
	const bool term_env = term == NULL;
	if(term_env)
	{
		term = getenv("TERM");
		if(term == NULL)
			return;
	}
	int error;
	const int status = setupterm(term, STDOUT_FILENO, &error);
	if(status == OK)
	{
		const long term_colors_value = tigetnum("colors");
		if(term_colors_value == -2)
			term_put_warning_term_colors_unavailable(term_env, term);
		else if(term_colors_value == -1)
			term_put_warning_term_colors_unsupported(term_env, term);
		else
			_term_colors = (OptionalLong) { false, term_colors_value };
	}
	else if(status == ERR)
	{
		if(error == -1)
			term_put_warning_term_unsupported(term_env, term);
		else if(error == 0)
			term_put_warning_term_generic(term_env, term);
		else if(error == 1)
			term_put_warning_term_hard_copy(term_env, term);
	}
}

//  Set number of terminal colors
void term_put_term_colors_set(char* term_colors)
{
	const bool term_colors_env = term_colors == NULL;
	if(term_colors_env)
	{
		term_colors = getenv("TERM_COLORS");
		if(term_colors == NULL)
			return;
	}
	errno = 0;
	char* term_colors_end;
	const long term_colors_value = strtol(term_colors, &term_colors_end, 0);
	if(errno == EINVAL)
		term_put_warning_term_colors_conversion_failure(term_colors_env, term_colors);
	else if(errno == ERANGE && term_colors_value == LONG_MAX)
		term_put_warning_term_colors_overflow(term_colors_env, term_colors);
	else if(errno == ERANGE && term_colors_value == LONG_MIN)
		term_put_warning_term_colors_underflow(term_colors_env, term_colors);
	else if(term_colors_end[0] != '\0')
		term_put_warning_term_colors_conversion_failure(term_colors_env, term_colors);
	else
		_term_colors = (OptionalLong) { false, term_colors_value };
}

//  Print number of terminal colors to standard output
void term_put_term_colors() {
	if(_term_colors.null)
		term_put_error_term_colors_undefined();
	else
		fprintf(stdout, "%ld\n", _term_colors.value);
}
