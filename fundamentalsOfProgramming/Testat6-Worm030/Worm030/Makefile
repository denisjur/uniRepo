############################################################
# General purpose makefile
#
# Works for all C-projects where
# - binaries are compiled into sub-dir bin
# - binaries are created from a multiple c-sources
#   and depend on all headers and object files in ./
#
# Note: due to the dependencies encoded multiple targets
#       are not sensible
#

# Please add all header files in ./ here
HEADERS += prep.h
HEADERS += worm.h
HEADERS += worm_model.h
HEADERS += board_model.h

# Please add all object files in ./ here
OBJECTS += prep.o
OBJECTS += worm.o
OBJECTS += worm_model.o
OBJECTS += board_model.o

# Please add THE target in ./bin here
TARGET += $(BIN_DIR)/worm
 
#################################################
# There is no need to edit below this line
#################################################

MACHINE := $(shell uname -m)
$(info $$MACHINE is $(MACHINE))
ifeq ($(MACHINE), i686)
  CFLAGS = -g -Wall
  LDLIBS = -lncurses
else ifeq ($(MACHINE), armv7l)
  CFLAGS = -g -Wall
  LDLIBS = -lncurses
else ifeq ($(MACHINE), arm64)
  CFLAGS = -g -Wall
  LDLIBS = -lncurses
else ifeq ($(MACHINE), x86_64)
  CFLAGS = -g -Wall
  LDLIBS = -lncurses
endif

#### Fixed variable definitions
CC = gcc
RM_DIR = rm -rf
MKDIR = mkdir
SHELL = /bin/bash
BIN_DIR = bin

#### Default target
all: $(BIN_DIR) $(TARGET)

#### Fixed build rules for binaries with multiple object files

# Object files
%.o : %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $< 

#### Binaries
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

.PHONY: clean
clean :
	$(RM_DIR) $(BIN_DIR) $(OBJECTS)

