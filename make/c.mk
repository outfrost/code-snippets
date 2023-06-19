###
# Generic C99 project Makefile
###

PROJECT ::= program
BINNAME ::= $(PROJECT)
BUILDDIR ?= target/$(PROJECT)
SRCDIR ?= src

CPPFLAGS ::= -iquotesrc/ $(CPPFLAGS)
CFLAGS ::= -g -std=c99 -Wall -Wextra -Wpedantic -Werror \
           -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=unused-parameter $(CFLAGS)
LDFLAGS ::= $(LDFLAGS)
LDLIBS ::= $(LDLIBS)

# ######
# Paths
# ######

sources ::= main.c

srcfiles ::= $(addprefix $(SRCDIR)/, $(sources))

objects ::= $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(srcfiles)))
depfiles ::= $(addprefix $(BUILDDIR)/, $(addsuffix .mk, $(srcfiles)))

# Set executable name
ifeq ($(OS),Windows_NT)
	binext ::= .exe
else
	binext ::=
endif
binary ::= $(BUILDDIR)/$(BINNAME)$(binext)

# ######
# Main build rules
# ######

# Default rule: build executable
$(binary): $(objects)
	@mkdir -p $(@D)
	@echo "Linking executable"
	@$(CC) $(LDFLAGS) -o $(binary) $^ $(LOADLIBES) $(LDLIBS)

# Build C translation units
$(objects): $(BUILDDIR)/%.c.o: %.c $(BUILDDIR)/%.c.mk
	@mkdir -p $(@D)
	@echo "Building $@"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

# ######
# Setup
# ######

# Initialise build environment
init:
	@echo "Creating build directory $(BUILDDIR)"
	@mkdir -p $(BUILDDIR)
.PHONY: init

# ######
# Aliases
# ######

# Build and run
run: $(binary)
	@echo
	@$(binary)
.PHONY: run

# Build project
$(PROJECT): $(binary)
.PHONY: $(PROJECT)

# ######
# Prerequisites
# ######

# Generate C prerequisite makefiles
$(depfiles): $(BUILDDIR)/%.c.mk: %.c Makefile
	@mkdir -p $(@D)
	@echo "Generating prerequisites for $<"
	@$(CPP) -MM -MT $(BUILDDIR)/$*.c.o -MF $@ $(CPPFLAGS) $<
# Give the same prerequisites to the prerequisite makefile,
# so that it is regenerated whenever any of said prerequisites change
	@sed -E -i 's|^([^\s:]+)([ :])|\1 $@\2|' $@

# Include generated C prerequisites
include $(foreach depfile, $(depfiles), $(shell [ -r "$(depfile)" ] && echo "$(depfile)"))

# Do not automatically delete generated prerequisites
.SECONDARY: $(depfiles)

# ######
# Cleanup rules
# ######

clean:
	@echo "Removing $(BUILDDIR)"
	@rm -rf $(BUILDDIR)
.PHONY: clean

