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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <term.h>
#include <term-put.h>

//  Define macros to process command line arguments
#define ARGUMENT (*(argv))
#define OPTION_LONG ((ARGUMENT) + 2)
#define OPTION_SHORT (*(ARGUMENT))

//  Print term-put usage to standard error and exit
void term_put_usage() {
	fputs(
		"term-put: usage: term-put [<option>|<attribute>[=<value>]]\n"
		"\n"
		"        --help               print term-put help\n"
		"        --version            print term-put version\n"
		"        --term=<term>        set terminal type to <term>\n"
		"        --colors=<colors>    set number of terminal colors to <colors>\n"
		"\n"
		, stderr);
	exit(1);
}

//  Print term-put version to standard error and exit
void term_put_version() {
	fputs("term-put: version: 0.0.0\n", stderr);
	exit(1);
}

//  Set terminal type
void term_put_term_set(const char* term) {
	int error = 0;
	int result = setupterm((char*)term, STDOUT_FILENO, &error);
}

//  Disable terminal output attributes
void term_put_normal() {
	static const char TERM_PUT_NORMAL[] = "\x1b[0m";
	fwrite(TERM_PUT_NORMAL, sizeof(char), sizeof(TERM_PUT_NORMAL) - sizeof(char), stdout);
}

//  Enable bold terminal output
void term_put_bold() {
	static const char TERM_PUT_BOLD[] = "\x1b[1m";
	fwrite(TERM_PUT_BOLD, sizeof(char), sizeof(TERM_PUT_BOLD) - sizeof(char), stdout);
}

//  Enable underlined terminal output
void term_put_underline() {
	static const char TERM_PUT_UNDERLINE[] = "\x1b[4m";
	fwrite(TERM_PUT_UNDERLINE, sizeof(char), sizeof(TERM_PUT_UNDERLINE) - sizeof(char), stdout);
}

//  Process command line arguments
int main(int argc, char* argv[]) {
	for(argv++; --argc > 0; argv++) {
		const char* separator = strchr(ARGUMENT, '=');
		const char* value = separator == NULL ? NULL : separator + 1;
		const size_t argument_length = separator == NULL ? strlen(ARGUMENT) : separator - ARGUMENT;
		const size_t option_long_length = separator == NULL ? strlen(OPTION_LONG) : separator - OPTION_LONG;
		if(ARGUMENT[0] == '-')
			if(ARGUMENT[1] == '-')
				if(strncmp(OPTION_LONG, "help", option_long_length) == 0)
					term_put_usage();
				else if(strncmp(OPTION_LONG, "usage", option_long_length) == 0)
					term_put_usage();
				else if(strncmp(OPTION_LONG, "version", option_long_length) == 0)
					term_put_version();
				else if(strncmp(OPTION_LONG, "term", option_long_length) == 0)
					if(value == NULL)
						term_put_error_option_long_malformed(OPTION_LONG);
					else
						term_put_term_set(value);
				else
					term_put_error_option_long_invalid(OPTION_LONG);
			else
				for(ARGUMENT++; OPTION_SHORT != '\0'; ARGUMENT++)
					term_put_error_option_short_invalid(OPTION_SHORT);
		else if(strncmp(ARGUMENT, "normal", argument_length) == 0)
			term_put_normal();
		else if(strncmp(ARGUMENT, "bold", argument_length) == 0)
			term_put_bold();
		else if(strncmp(ARGUMENT, "underline", argument_length) == 0)
			term_put_underline();
		else
			term_put_error_attribute_invalid(ARGUMENT);
	}
}
