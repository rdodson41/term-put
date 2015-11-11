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
#include <term-put.h>

//  Define FWRITE to write a constant string to a file
#define FWRITE(FILE, STRING) fwrite(STRING, sizeof(char), sizeof(STRING) - sizeof(char), FILE)

//  Define macros to process command line arguments
#define ARGUMENT (*(argv))
#define OPTION_LONG ((ARGUMENT) + 2)
#define OPTION_SHORT (*(ARGUMENT))

//  Print term-put usage to standard error and exit
void term_put_usage() {
	static const char TERM_PUT_USAGE[] =
		"term-put: usage: term-put [<option>|<attribute>[=<value>]]\n"
		"\n"
		"        --help               print term-put help\n"
		"        --version            print term-put version\n"
		"        --term=<term>        set terminal type to <term>\n"
		"        --colors=<colors>    set number of terminal colors to <colors>\n"
		"\n";
	FWRITE(stderr, TERM_PUT_USAGE);
	exit(1);
}

//  Print term-put version to standard error and exit
void term_put_version() {
	static const char TERM_PUT_VERSION[] = "term-put: version: 0.0.0\n";
	FWRITE(stderr, TERM_PUT_VERSION);
	exit(1);
}

//  Print term-put error: Invalid option to standard error and exit
void term_put_error_option_long_invalid(const char* option) {
	fprintf(stderr, "term-put: error: Invalid option: --%s\n", option);
	exit(1);
}

//  Print term-put error: Malformed option to standard error and exit
void term_put_error_option_long_malformed(const char* option) {
	fprintf(stderr, "term-put: error: Malformed option: --%s requires an argument\n", option);
	exit(1);
}

//  Print term-put error: Invalid option to standard error and exit
void term_put_error_option_short_invalid(const char option) {
	fprintf(stderr, "term-put: error: Invalid option: -%c\n", option);
	exit(1);
}

//  Print term-put error: Malformed option to standard error and exit
void term_put_error_option_short_malformed(const char option) {
	fprintf(stderr, "term-put: error: Malformed option: -%c requires an argument\n", option);
	exit(1);
}

//  Print term-put error: Invalid attribute to standard error and exit
void term_put_error_attribute_invalid(const char* attribute) {
	fprintf(stderr, "term-put: error: Invalid attribute: %s\n", attribute);
	exit(1);
}

//  Print term-put error: Malformed attribute to standard error and exit
void term_put_error_attribute_malformed(const char* attribute) {
	fprintf(stderr, "term-put: error: Malformed attribute: %s requires a value\n", attribute);
	exit(1);
}

//  Print term-put warning: Failed to convert number of terminal colors to a long integer to standard error
void term_put_warning_term_colors_conversion_failure(const char* term_colors) {
	fprintf(stderr, "term-put: warning: Failed to convert %s to a long integer\n", term_colors);
}

// Print term-put warning: Number of terminal colors is out of range to standard error
void term_put_warning_term_colors_overflow(const char* term_colors) {
	fprintf(stderr, "term-put: warning: %s is out of range\n", term_colors);
} 

// Print term-put warning: Number of terminal colors is out of range to standard error
void term_put_warning_term_colors_underflow(const char* term_colors) {
	fprintf(stderr, "term-put: warning: %s is out of range\n", term_colors);
} 

//  Print term-put warning: Terminal colors are unavailable to standard error
void term_put_warning_term_colors_unavailable() {
	static const char TERM_PUT_WARNING_TERM_COLORS_UNAVAILABLE[] = "term-put: warning: Terminal colors are unavailable\n";
	FWRITE(stderr, TERM_PUT_WARNING_TERM_COLORS_UNAVAILABLE);
}

//  Print term-put warning: Terminal colors are unsupported to standard error
void term_put_warning_term_colors_unsupported() {
	static const char TERM_PUT_WARNING_TERM_COLORS_UNSUPPORTED[] = "term-put: warning: Terminal colors are unsupported\n";
	FWRITE(stderr, TERM_PUT_WARNING_TERM_COLORS_UNSUPPORTED);
}

//  Disable terminal output attributes
void term_put_normal() {
	static const char TERM_PUT_NORMAL[] = "\x1b[0m";
	FWRITE(stdout, TERM_PUT_NORMAL);
}

//  Enable bold terminal output
void term_put_bold() {
	static const char TERM_PUT_BOLD[] = "\x1b[1m";
	FWRITE(stdout, TERM_PUT_BOLD);
}

//  Enable underlined terminal output
void term_put_underline() {
	static const char TERM_PUT_UNDERLINE[] = "\x1b[4m";
	FWRITE(stdout, TERM_PUT_UNDERLINE);
}	

//  Process command line arguments
int main(int argc, char* argv[]) {
	for(argv++; --argc > 0; argv++) {
		char* separator = strchr(ARGUMENT, '=');
		size_t argument_length = separator == NULL ? strlen(ARGUMENT) : separator - ARGUMENT;
		size_t option_long_length = separator == NULL ? strlen(OPTION_LONG) : separator - OPTION_LONG;
		char* value = separator == NULL ? NULL : separator + 1;
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
						printf("term=\"%s\"\n", value);
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
