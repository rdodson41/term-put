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
#include <string.h>

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
static TermColor _term_colors = { 0, false };

//  Set terminal type
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
		_term_colors = (TermColor) { tigetnum("colors"), true };
		if(_term_colors.value < 0)
			term_put_warning_term_colors_unsupported(value);
	}
	else if(status == ERR)
	{
		if(error == -1)
			term_put_warning_term_invalid(value);
		else if(error == 0)
			term_put_warning_term_generic(value);
		else if(error == 1)
			term_put_warning_term_hard_copy(value);
	}
}

//  Get terminal type
Term term_put_term_get()
{
	return _term;
}

//  Set count of terminal colors
void term_put_term_colors_set(String value)
{
	if(value == NULL)
	{
		value = getenv("TERM_COLORS");
		if(value == NULL)
			return;
	}
	errno = 0;
	String value_end;
	const TermColor term_colors = { strtol(value, &value_end, 0), true };
	if(errno == EINVAL || value[0] == '\0' || value_end[0] != '\0')
		term_put_warning_term_colors_invalid(value);
	else
		_term_colors = term_colors;
}

//  Get count of terminal colors
TermColor term_put_term_colors_get()
{
	return _term_colors;
}

//  Get terminal color
TermColor term_put_term_color_get(String value) {
	if(value == NULL)
		return (TermColor) { 0x00, false };
	else if(strcmp(value, "black") == 0)
		return (TermColor) { 0x00, true };
	else if(strcmp(value, "red") == 0)
		return (TermColor) { 0x01, true };
	else if(strcmp(value, "green") == 0)
		return (TermColor) { 0x02, true };
	else if(strcmp(value, "yellow") == 0)
		return (TermColor) { 0x03, true };
	else if(strcmp(value, "blue") == 0)
		return (TermColor) { 0x04, true };
	else if(strcmp(value, "magenta") == 0)
		return (TermColor) { 0x05, true };
	else if(strcmp(value, "cyan") == 0)
		return (TermColor) { 0x06, true };
	else if(strcmp(value, "white") == 0)
		return (TermColor) { 0x07, true };
	else if(strcmp(value, "bright-black") == 0)
		return (TermColor) { 0x08, true };
	else if(strcmp(value, "bright-red") == 0)
		return (TermColor) { 0x09, true };
	else if(strcmp(value, "bright-green") == 0)
		return (TermColor) { 0x0A, true };
	else if(strcmp(value, "bright-yellow") == 0)
		return (TermColor) { 0x0B, true };
	else if(strcmp(value, "bright-blue") == 0)
		return (TermColor) { 0x0C, true };
	else if(strcmp(value, "bright-magenta") == 0)
		return (TermColor) { 0x0D, true };
	else if(strcmp(value, "bright-cyan") == 0)
		return (TermColor) { 0x0E, true };
	else if(strcmp(value, "bright-white") == 0)
		return (TermColor) { 0x0F, true };
	errno = 0;
	String value_end;
	const TermColor term_color = { strtol(value, &value_end, 0), true };
	if(errno == EINVAL || value[0] == '\0' || value_end[0] != '\0')
		term_put_warning_term_color_invalid(value);
	else
		return term_color;
	return (TermColor) { 0x00, false };
}
