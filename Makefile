# Makefile for the SAR (Simple Ascii Renderer) library
# deps: SDL2, SDL2_image

CC:=gcc-5 -std=c11
CFLAGS:=-c -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes
INCLUDES:=-I/usr/local/include/ #-I/usr/local/Cellar/sdl2/2.0.4/include
LDFLAGS:=-L/usr/local/Cellar/sdl2/2.0.4/lib -L/usr/local/Cellar/sdl2_image/2.0.0_1/lib
LDLIBS:=-lSDL2 -lSDL2_image
SRC:=$(wildcard *.c)
OBJ:=$(notdir $(SRC:.c=.o))
SHARED_LIB:=libsar.so

$(SHARED_LIB): $(OBJ)
	@echo "\nLinking. . .\n"
	$(CC) $(LDFLAGS) $(LDLIBS) -shared -o $@ $^
	@echo "\nLinking for target $(SHARED_LIB) succeeded!\n\n"
	
%.o: %.c
	@echo "\nCompiling:"
	$(CC) $(CFLAGS) $(INCLUDES) -fPIC -o $@ $<
	
.PHONY: clean
clean:
	-rm $(OBJ) $(SHARED_LIB)

# all:
# 	$(CC) $(CFLAGS) $(INCLUDES) -fPIC $(LDFLAGS) $(LDLIBS) $(SRC) -o $(OBJ)
   
# link:
# 	$(CC) $(LDFLAGS) $(LDLIBS) -shared -o $(SHARED_LIB) $(OBJ);
	
# .PHONY: clean
# clean:
# 	-rm $(OBJ) $(SHARED_LIB)