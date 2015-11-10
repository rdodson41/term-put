#!/usr/bin/make -f

#  
#  Name:     rdodson41/term-put/makefile
#  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
#  Created:  Sun Nov 08 20:52:57 UTC 2015
#  License:  GNU General Public License, Version 3, 29 June 2007
#  
#  Copyright (C) 2015 Richard E. Dodson <richard.elias.dodson@gmail.com>
#  
#  This file is part of term-put.
#  
#  term-put is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#  
#  term-put is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with term-put. If not, see <http://www.gnu.org/licenses/>.
#

#  Set shell to bash
SHELL = bash -o pipefail

#  Set absolute directories
root =

#  Set relative directories
bin = bin
lib = lib
include = include
obj = obj
src = src
usr = usr
usr_local = $(usr)/local

#  Set build targets
build = build
build_bin_term_put_all = $(patsubst $(src)/%.c,$(build)/$(obj)/%.o,$(wildcard $(src)/term-put.c $(src)/term-put-*.c)) 
build_all = $(build)/$(bin)/term-put

#  Set install targets
install = $(root)/$(usr_local)
install_all = $(patsubst $(build)/%,$(install)/%,$(build_all))

#  Print makefile usage
.PHONY: help usage
help usage:
	@echo "make: usage: make [ help | pull | push | build | clean | install | uninstall ]" >&2

#  Pull repository
.PHONY: pull
pull:
	@git pull --verbose 2>&1 | sed -e "s/^/make: git: /" >&2

#  Push repository
.PHONY: push
push:
	@git push --verbose 2>&1 | sed -e "s/^/make: git: /" >&2

#  Build targets
.PHONY: build
build: $(build_all)

$(build)/$(bin):
	@echo "make: mkdir: $@" >&2
	@mkdir -p "$@" 2>&1 | sed -e "s/^/make: /" >&2

$(build)/$(bin)/term-put: $(build_bin_term_put_all) | $(build)/$(bin)
	@echo "make: $(CC): $^ -> $@" >&2
	@$(CC) -o "$@" "-L$(lib)" -lncurses $^ 2>&1 | sed -e "s/^/make: cc: /" >&2

$(build)/$(obj):
	@echo "make: mkdir: $@" >&2
	@mkdir -p "$@" 2>&1 | sed -e "s/^/make: /" >&2

$(build)/$(obj)/%.o: $(src)/%.c | $(build)/$(obj)
	@echo "make: $(CC): $? -> $@" >&2
	@$(CC) -o "$@" "-I$(include)" "-I$(src)" -c "$?" 2>&1 | sed -e "s/^/make: cc: /" >&2

#  Clean targets
.PHONY: clean
clean:
	@echo "make: rm: $(build)" >&2
	@rm -f -r "$(build)" 2>&1 | sed -e "s/^/make: /" >&2

#  Install targets
.PHONY: install
install: $(install_all)

$(install)/$(bin):
	@echo "make: mkdir: $@" >&2
	@mkdir -p "$@" 2>&1 | sed -e "s/^/make: /" >&2

$(install)/$(bin)/%: $(build)/$(bin)/% | $(install)/$(bin)
	@echo "make: ln: $? -> $@" >&2
	@ln -f -r -s "$?" "$@" 2>&1 | sed -e "s/^/make: /" >&2

#  Uninstall targets
.PHONY: uninstall
uninstall:
	@echo "make: rm: $(install_all)" >&2
	@rm -f $(install_all) 2>&1 | sed -e "s/^/make: /" >&2
