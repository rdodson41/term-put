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
#include <string.h>

//  Include POSIX standard header files
#include <unistd.h>

//  Include ncurses header files
#include <ncurses.h>
#include <term.h>

//  Include term-put header files
#include <term-put.h>

static TermColors _term_colors = { 0, false };

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
			_term_colors = (TermColors) { term_colors_value, true };
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
		_term_colors = (TermColors) { term_colors_value, true };
}

//  Get number of terminal colors
TermColors term_put_term_colors_get() {
	return _term_colors;
}

//  Get terminal color
TermColor term_put_term_color_get(char* term_color) {
	if(term_color == NULL)
		return (TermColor) { 0x00, false };
	else if(strcmp(term_color, "black") == 0)
		return (TermColor) { 0x00, true };
	else if(strcmp(term_color, "red") == 0)
		return (TermColor) { 0x01, true };
	else if(strcmp(term_color, "green") == 0)
		return (TermColor) { 0x02, true };
	else if(strcmp(term_color, "yellow") == 0)
		return (TermColor) { 0x03, true };
	else if(strcmp(term_color, "blue") == 0)
		return (TermColor) { 0x04, true };
	else if(strcmp(term_color, "magenta") == 0)
		return (TermColor) { 0x05, true };
	else if(strcmp(term_color, "cyan") == 0)
		return (TermColor) { 0x06, true };
	else if(strcmp(term_color, "white") == 0)
		return (TermColor) { 0x07, true };
	else if(strcmp(term_color, "bright-black") == 0)
		return (TermColor) { 0x08, true };
	else if(strcmp(term_color, "bright-red") == 0)
		return (TermColor) { 0x09, true };
	else if(strcmp(term_color, "bright-green") == 0)
		return (TermColor) { 0x0A, true };
	else if(strcmp(term_color, "bright-yellow") == 0)
		return (TermColor) { 0x0B, true };
	else if(strcmp(term_color, "bright-blue") == 0)
		return (TermColor) { 0x0C, true };
	else if(strcmp(term_color, "bright-magenta") == 0)
		return (TermColor) { 0x0D, true };
	else if(strcmp(term_color, "bright-cyan") == 0)
		return (TermColor) { 0x0E, true };
	else if(strcmp(term_color, "bright-white") == 0)
		return (TermColor) { 0x0F, true };
	errno = 0;
	char* term_color_end;
	const long term_color_value = strtol(term_color, &term_color_end, 0);
	if(errno == EINVAL)
		term_put_warning_term_color_conversion_failure(term_color);
	else if(errno == ERANGE && term_color_value == LONG_MAX)
		term_put_warning_term_color_overflow(term_color);
	else if(errno == ERANGE && term_color_value == LONG_MIN)
		term_put_warning_term_color_underflow(term_color);
	else if(term_color_end[0] != '\0')
		term_put_warning_term_color_conversion_failure(term_color);
	else
		return (TermColor) { term_color_value, true };
	return (TermColor) { 0x00, false };
}
