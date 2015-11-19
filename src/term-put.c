//
//  Name:     rdodson41/term-put/src/term-put.c
//  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
//  Created:  Thu Nov 05 11:51:56 UTC 2015
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
#include <string.h>

//  Include term-put header files
#include <term-put.h>
#include <term-put-term.h>
#include <term-put-error.h>

//  Quit
void term_put_quit(const int status)
{
	exit(status);
}

//  Print usage to standard error and quit
void term_put_usage()
{
	fprintf(stderr, "term-put: usage: term-put [option|attribute] ...\n");
	term_put_quit(1);
}

//  Print version to standard error and quit
void term_put_version()
{
	fprintf(stderr, "term-put: version: %s\n", TERM_PUT_VERSION);
	term_put_quit(1);
}

//  Print terminal type to standard output
void term_put_term()
{
	const Term term = term_put_term_get();
	if(term != NULL)
		fprintf(stdout, "%s\n", term);
}

//  Print count of terminal colors to standard output
void term_put_term_colors()
{
	const TermColor term_colors = term_put_term_colors_get();
	if(term_colors.has_value)
		fprintf(stdout, "%ld\n", term_colors.value);
}

//  Disable terminal text attributes
void term_put_normal()
{
	fprintf(stdout, "\x1b[0m");
}

//  Enable bold terminal text
void term_put_bold()
{
	fprintf(stdout, "\x1b[1m");
}

//  Enable underlined terminal text
void term_put_underline()
{
	fprintf(stdout, "\x1b[4m");
}

//  Set foreground terminal text color
void term_put_foreground(String value) {
	const TermColor term_colors = term_put_term_colors_get();
	if(!term_colors.has_value || term_colors.value < 0x00)
		return;
	const TermColor term_color = term_put_term_color_get(value);
	if(!term_color.has_value || term_color.value < 0x00 || term_colors.value <= term_color.value)
		return;
	else if(0x10 < term_colors.value)
		fprintf(stdout, "\x1b[38;5;%ldm", term_color.value);
	else if(0x08 < term_colors.value && 0x08 <= term_color.value)
		fprintf(stdout, "\x1b[%ldm", 90 + term_color.value - 0x08);
	else
		fprintf(stdout, "\x1b[%ldm", 30 + term_color.value);
}

//  Set background terminal text color
void term_put_background(String value) {
	const TermColor term_colors = term_put_term_colors_get();
	if(!term_colors.has_value || term_colors.value < 0x00)
		return;
	const TermColor term_color = term_put_term_color_get(value);
	if(!term_color.has_value || term_color.value < 0x00 || term_colors.value <= term_color.value)
		return;
	else if(0x10 < term_colors.value)
		fprintf(stdout, "\x1b[48;5;%ldm", term_color.value);
	else if(0x08 < term_colors.value && 0x08 <= term_color.value)
		fprintf(stdout, "\x1b[%ldm", 100 + term_color.value - 0x08);
	else
		fprintf(stdout, "\x1b[%ldm", 40 + term_color.value);
}

//  Define macro variables to help process command line arguments
#define ARGUMENT (*argv)
#define OPTION (ARGUMENT + 2)
#define VALUE (separator + 1)

//  Process command line arguments
int main(int argc, String argv[])
{
	term_put_term_set(NULL);
	term_put_term_colors_set(NULL);

	for(argv++; --argc > 0; argv++)
	{
		String separator = strchr(ARGUMENT, '=');
		if(separator != NULL)
			*separator = '\0';

		if(ARGUMENT[0] == '-')
			if(ARGUMENT[1] == '-')
				if(strcmp(OPTION, "help") == 0)
					term_put_usage();
				else if(strcmp(OPTION, "usage") == 0)
					term_put_usage();
				else if(strcmp(OPTION, "version") == 0)
					term_put_version();
				else if(strcmp(OPTION, "term") == 0)
					if(separator == NULL)
						term_put_error_option_incomplete(OPTION);
					else
						term_put_term_set(VALUE);
				else if(strcmp(OPTION, "colors") == 0)
					if(separator == NULL)
						term_put_error_option_incomplete(OPTION);
					else
						term_put_term_colors_set(VALUE);
				else
					term_put_error_option_invalid(OPTION);
			else
				for(ARGUMENT++; *ARGUMENT != '\0'; ARGUMENT++)
					term_put_error_option_short_invalid(*ARGUMENT);
		else if(strcmp(ARGUMENT, "term") == 0)
			term_put_term();
		else if(strcmp(ARGUMENT, "colors") == 0)
			term_put_term_colors();
		else if(strcmp(ARGUMENT, "normal") == 0)
			term_put_normal();
		else if(strcmp(ARGUMENT, "bold") == 0)
			term_put_bold();
		else if(strcmp(ARGUMENT, "underline") == 0)
			term_put_underline();
		else if(strcmp(ARGUMENT, "foreground") == 0)
			if(separator == NULL)
				term_put_error_attribute_incomplete(ARGUMENT);
			else
				term_put_foreground(VALUE);
		else if(strcmp(ARGUMENT, "background") == 0)
			if(separator == NULL)
				term_put_error_attribute_incomplete(ARGUMENT);
			else
				term_put_background(VALUE);
		else
			term_put_error_attribute_invalid(ARGUMENT);
	}

	term_put_quit(0);
}
