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
#include <stdlib.h>
#include <strings.h>

//  Include POSIX standard header files
#include <unistd.h>

//  Include ncurses header files
#include <ncurses.h>
#include <term.h>

//  Include term-put header files
#include <term-put.h>
#include <term-put-term.h>
#include <term-put-warning.h>

static Term _term = NULL;
static TermColor _term_color_count = { 0, false };

//  Set term-put terminal type
void term_put_term_set(String value)
{
	if(value == NULL)
	{
		value = getenv("TERM");
		if(value == NULL)
			return;
	}
	int error;
	const int status = setupterm(value, STDOUT_FILENO, &error);
	if(status == OK)
	{
		_term = value;
		const TermColor term_color_count = { tigetnum("colors"), true };
		if(term_color_count.value < 0)
			term_put_warning_term_color_count_unsupported(value);
		else
			_term_color_count = term_color_count;
	}
	else if(status == ERR)
	{
		if(error == -1)
			term_put_warning_term_unsupported(value);
		else if(error == 0)
			term_put_warning_term_generic(value);
		else if(error == 1)
			term_put_warning_term_hard_copy(value);
	}
}

//  Get term-put terminal type
Term term_put_term_get()
{
	return _term;
}

//  Set count of term-put terminal colors
void term_put_term_color_count_set(String value)
{
	if(value == NULL)
	{
		value = getenv("TERM_COLORS");
		if(value == NULL)
			return;
	}
	errno = 0;
	String value_end;
	const TermColor term_color_count = { strtol(value, &value_end, 0), true };
	if(errno == EINVAL || value_end[0] != '\0')
		term_put_warning_term_color_count_invalid(value);
	else
		_term_color_count = term_color_count;
}

//  Get count of term-put terminal colors
TermColor term_put_term_color_count_get()
{
	return _term_color_count;
}

//  Get term-put terminal color
TermColor term_put_term_color_get(String value) {
	if(value == NULL)
		return (TermColor) { 0x00, false };
	else if(strcasecmp(value, "black") == 0)
		return (TermColor) { 0x00, true };
	else if(strcasecmp(value, "red") == 0)
		return (TermColor) { 0x01, true };
	else if(strcasecmp(value, "green") == 0)
		return (TermColor) { 0x02, true };
	else if(strcasecmp(value, "yellow") == 0)
		return (TermColor) { 0x03, true };
	else if(strcasecmp(value, "blue") == 0)
		return (TermColor) { 0x04, true };
	else if(strcasecmp(value, "magenta") == 0)
		return (TermColor) { 0x05, true };
	else if(strcasecmp(value, "cyan") == 0)
		return (TermColor) { 0x06, true };
	else if(strcasecmp(value, "white") == 0)
		return (TermColor) { 0x07, true };
	else if(strcasecmp(value, "bright-black") == 0)
		return (TermColor) { 0x08, true };
	else if(strcasecmp(value, "bright-red") == 0)
		return (TermColor) { 0x09, true };
	else if(strcasecmp(value, "bright-green") == 0)
		return (TermColor) { 0x0A, true };
	else if(strcasecmp(value, "bright-yellow") == 0)
		return (TermColor) { 0x0B, true };
	else if(strcasecmp(value, "bright-blue") == 0)
		return (TermColor) { 0x0C, true };
	else if(strcasecmp(value, "bright-magenta") == 0)
		return (TermColor) { 0x0D, true };
	else if(strcasecmp(value, "bright-cyan") == 0)
		return (TermColor) { 0x0E, true };
	else if(strcasecmp(value, "bright-white") == 0)
		return (TermColor) { 0x0F, true };
	errno = 0;
	String value_end;
	const TermColor term_color = { strtol(value, &value_end, 0), true };
	if(errno == EINVAL || value_end[0] != '\0')
		term_put_warning_term_color_invalid(value);
	else
		return term_color;
	return (TermColor) { 0x00, false };
}
