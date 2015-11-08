#!/usr/bin/make -f

#  
#  Name:     rdodson41/term-put/makefile
#  Author:   Richard E. Dodson <richard.elias.dodson@gmail.com>
#  Created:  Sun Nov  8 20:52:57 UTC 2015
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

#  Set absolute file paths
root = 
root_home = $(HOME)
root_pwd = $(PWD)

#  Set relative file paths
home = /home
opt = /opt
usr = /usr
usr_local = $(usr)/local

#  Log usage
.PHONY: help usage
help usage:
	@echo "make: usage: make [ help | pull | push | install | uninstall | reinstall | update ]" >&2

#  Pull repository
.PHONY: pull
pull:
	@git pull --verbose 2>&1 | sed -e "s/^/make: git: /" >&2

#  Push repository
.PHONY: push
push:
	@git push --verbose 2>&1 | sed -e "s/^/make: git: /" >&2

#  Install repository
.PHONY: install
install: $(patsubst $(root_pwd)$(home)/%,$(root_home)/%,$(shell find $(root_pwd)$(home) ! -type d))

$(root_home)/%: $(root_pwd)$(home)/%
	@echo "make: ln: $@ -> $<" >&2
	@mkdir -p "$(@D)" 2>&1 | sed -e "s/^/make: /" >&2
	@ln -s "$<" "$@" 2>&1 | sed -e "s/^/make: /" >&2

#  Uninstall repository
.PHONY: uninstall
uninstall: $(patsubst $(root_pwd)$(home)/%,uninstall-$(root_home)/%,$(shell find $(root_pwd)$(home) ! -type d)) 

uninstall-$(root_home)/%:
	@echo "make: rm: $(root_home)/$*" >&2
	@rm -f "$(root_home)/$*" 2>&1 | sed -e "s/^/make: /" >&2

#  Reinstall repository
.PHONY: reinstall
reinstall: uninstall install

#  Update repository
.PHONY: update
update: uninstall pull install
