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

//  Define macro variables to process command line arguments
#define ARGUMENT (*argv)
#define OPTION (ARGUMENT + 2)
#define VALUE (separator == NULL ? NULL : separator + 1)

//  Define STRNCMP to compare a constant string to an argument
#define STRNCMP(ARGUMENT, STRING) strncmp(ARGUMENT, STRING, sizeof(STRING) - sizeof(char))

//  Define FWRITE to write a constant string to a file
#define FWRITE(FILE, STRING) fwrite(STRING, sizeof(char), sizeof(STRING) - sizeof(char), FILE)

//  Print term-put usage to standard error and exit
void term_put_usage()
{
	FWRITE(stderr,
		"term-put: usage: term-put [<option>|<attribute>[=<value>]]\n"
		"\n"
		"        --help               print term-put help\n"
		"        --version            print term-put version\n"
		"        --term=<term>        set terminal type to <term>\n"
		"        --colors=<colors>    set number of terminal colors to <colors>\n"
		"\n"
	);
	exit(1);
}

//  Print term-put version to standard error and exit
void term_put_version()
{
	FWRITE(stderr, "term-put: version: 0.0.0\n");
	exit(1);
}

//  Disable terminal output attributes
void term_put_normal()
{
	FWRITE(stdout, "\x1b[0m");
}

//  Enable bold terminal output
void term_put_bold()
{
	FWRITE(stdout, "\x1b[1m");
}

//  Enable underlined terminal output
void term_put_underline()
{
	FWRITE(stdout, "\x1b[4m");
}

//  Process command line arguments
int main(int argc, char* argv[])
{
	term_put_term_set(NULL);
	term_put_term_colors_set(NULL);

	for(argv++; --argc > 0; argv++)
	{
		char* separator = strchr(ARGUMENT, '=');

		if(ARGUMENT[0] == '-')
			if(ARGUMENT[1] == '-')
				if(STRNCMP(OPTION, "help") == 0)
					term_put_usage();
				else if(STRNCMP(OPTION, "usage") == 0)
					term_put_usage();
				else if(STRNCMP(OPTION, "version") == 0)
					term_put_version();
				else if(STRNCMP(OPTION, "term") == 0)
					if(separator == NULL)
						term_put_error_option_malformed(ARGUMENT);
					else
						term_put_term_set(VALUE);
				else if(STRNCMP(OPTION, "colors") == 0)
					if(separator == NULL)
						term_put_error_option_malformed(ARGUMENT);
					else
						term_put_term_colors_set(VALUE);
				else
					term_put_error_option_invalid(ARGUMENT);
			else
				for(ARGUMENT++; *ARGUMENT != '\0'; ARGUMENT++)
					term_put_error_option_short_invalid(*ARGUMENT);
		else if(STRNCMP(ARGUMENT, "normal") == 0)
			term_put_normal();
		else if(STRNCMP(ARGUMENT, "bold") == 0)
			term_put_bold();
		else if(STRNCMP(ARGUMENT, "underline") == 0)
			term_put_underline();
		else if(STRNCMP(ARGUMENT, "foreground") == 0)
			;
		else if(STRNCMP(ARGUMENT, "background") == 0)
			;
		else if(STRNCMP(ARGUMENT, "colors") == 0)
			term_put_term_colors();
		else
			term_put_error_attribute_invalid(ARGUMENT);
	}
}
