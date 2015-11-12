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

//  Define macros to process command line arguments
#define ARGUMENT (*(argv))
#define OPTION ((ARGUMENT) + 2)
#define OPTION_LENGTH ((argument_length) - 2)

//  Print term-put usage to standard error and exit
void term_put_usage()
{
	static const char TERM_PUT_USAGE[] =
		"term-put: usage: term-put [<option>|<attribute>[=<value>]]\n"
		"\n"
		"        --help               print term-put help\n"
		"        --version            print term-put version\n"
		"        --term=<term>        set terminal type to <term>\n"
		"        --colors=<colors>    set number of terminal colors to <colors>\n"
		"\n"
	;
	FWRITE(stderr, TERM_PUT_USAGE);
	exit(1);
}

//  Print term-put version to standard error and exit
void term_put_version()
{
	static const char TERM_PUT_VERSION[] = "term-put: version: 0.0.0\n";
	FWRITE(stderr, TERM_PUT_VERSION);
	exit(1);
}

//  Disable terminal output attributes
void term_put_normal()
{
	static const char TERM_PUT_NORMAL[] = "\x1b[0m";
	FWRITE(stdout, TERM_PUT_NORMAL);
}

//  Enable bold terminal output
void term_put_bold()
{
	static const char TERM_PUT_BOLD[] = "\x1b[1m";
	FWRITE(stdout, TERM_PUT_BOLD);
}

//  Enable underlined terminal output
void term_put_underline()
{
	static const char TERM_PUT_UNDERLINE[] = "\x1b[4m";
	FWRITE(stdout, TERM_PUT_UNDERLINE);
}

//  Process command line arguments
int main(int argc, char* argv[])
{
	term_put_term_set(NULL);
	term_put_term_colors_set(NULL);

	for(argv++; --argc > 0; argv++)
	{
		char* separator = strchr(ARGUMENT, '=');
		char* value = separator == NULL ? NULL : separator + 1;
		const size_t argument_length = separator == NULL ? strlen(ARGUMENT) : separator - ARGUMENT;

		if(argument_length == 0)
			term_put_error_attribute_invalid(ARGUMENT);
		else if(ARGUMENT[0] == '-')
			if(argument_length == 1)
				term_put_error_option_invalid(ARGUMENT);
			else if(ARGUMENT[1] == '-')
				if(argument_length == 2)
					term_put_error_option_invalid(ARGUMENT);
				else if(strncmp(OPTION, "help", OPTION_LENGTH) == 0)
					term_put_usage();
				else if(strncmp(OPTION, "usage", OPTION_LENGTH) == 0)
					term_put_usage();
				else if(strncmp(OPTION, "version", OPTION_LENGTH) == 0)
					term_put_version();
				else if(strncmp(OPTION, "term", OPTION_LENGTH) == 0)
					if(value == NULL)
						term_put_error_option_malformed(ARGUMENT);
					else
						term_put_term_set(value);
				else if(strncmp(OPTION, "colors", OPTION_LENGTH) == 0)
					if(value == NULL)
						term_put_error_option_malformed(ARGUMENT);
					else
						term_put_term_colors_set(value);
				else
					term_put_error_option_invalid(ARGUMENT);
			else
				for(ARGUMENT++; *ARGUMENT != '\0'; ARGUMENT++)
					term_put_error_option_short_invalid(*ARGUMENT);
		else if(strncmp(ARGUMENT, "normal", argument_length) == 0)
			term_put_normal();
		else if(strncmp(ARGUMENT, "bold", argument_length) == 0)
			term_put_bold();
		else if(strncmp(ARGUMENT, "underline", argument_length) == 0)
			term_put_underline();
		else if(strncmp(ARGUMENT, "colors", argument_length) == 0)
			term_put_term_colors();
		else
			term_put_error_attribute_invalid(ARGUMENT);
	}
}
