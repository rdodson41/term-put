//  
//  Name:     rdodson41/term-put/src/term-put.h
//  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
//  Created:  Thu Nov 05 21:55:50 UTC 2015
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

#ifndef TERM_PUT
#define TERM_PUT

//  Define TRUE if it is not already defined
#ifndef TRUE
#define TRUE 1
#endif

//  Define FALSE if it is not already defined
#ifndef FALSE
#define FALSE 0
#endif

//  Define FWRITE to write a constant string to a file if it is not already defined
#ifndef FWRITE
#define FWRITE(FILE, STRING) fwrite(STRING, sizeof(char), sizeof(STRING) - sizeof(char), FILE)
#endif

void term_put_usage();
void term_put_version();

void term_put_error_option_long_invalid(const char* option);
void term_put_error_option_long_malformed(const char* option);
void term_put_error_option_short_invalid(const char option);
void term_put_error_option_short_malformed(const char option);
void term_put_error_attribute_invalid(const char* attribute);
void term_put_error_attribute_malformed(const char* attribute);

void term_put_warning_term_colors_conversion_failure(char* term_colors);
void term_put_warning_term_colors_overflow(char* term_colors);
void term_put_warning_term_colors_underflow(char* term_colors);
void term_put_warning_term_colors_unavailable();
void term_put_warning_Term_colors_unsupported();

void term_put_normal();
void term_put_bold();
void term_put_underline();

#endif
