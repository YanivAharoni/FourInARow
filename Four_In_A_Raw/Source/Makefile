# we are using gcc, hence the need to define CC
CC=gcc
# C compiler flags
INC_DIR=../Include
CFLAGS= -g -pedantic -ansi -Wall -Werror -I$(INC_DIR)
# Linker (ld) flags
LDFLAGS= -g


# Target and sources
TARGET=Main
#
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

.PHONY: all clean run

all: $(TARGET) run

$(TARGET) : $(OBJECTS)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm *.o
	rm Main

run:
	./Main
	
