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

#  Set relative file paths
bin = bin
obj = obj
src = src

#  Print makefile usage
.PHONY: help usage
help usage:
	@echo "make: usage: make [ help | pull | push | build | clean ]" >&2

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
build: $(bin)/term-put

$(bin):
	@mkdir -p $@ 2>&1 | sed -e "s/^/make: /" >&2

$(bin)/%: $(patsubst $(bin)/%,$(src)/%,$@).c
#$(patsubst $(src)/%.c,$(obj)/%.o,$(shell find $(src) -path $(patsubst $(bin)/%,$(src)/%,$@).c)) | $(bin)
	@echo "$(patsubst $(bin)/%,$(src)/%,$@).c"
	@echo "$(shell find $(src) -path $(src)/$*.c)"
	@echo "$^"
	@echo "$?"
	@cc -o $@ $^ 2>&1 | sed -e "s/^/make: cc: /" >&2

$(obj):
	@mkdir -p $@ 2>&1 | sed -e "s/^/make: /" >&2

$(obj)/%.o: $(src)/%.c | $(obj)
	@cc -o $@ -c -I$(src) $? 2>&1 | sed -e "s/^/make: cc: /" >&2

#  Clean targets
.PHONY: clean
clean:
	rm -f -r $(bin)
	rm -f -r $(obj)
