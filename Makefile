# Compiler flags
CFLAGS = -Wall -Werror -g 
# Include flags, assuming you have header files in an 'include' directory
# Uncomment and adjust the next line if necessary
# CFLAGS += -I./include

# Source files for each executable
SRC_BEAUTIFIER = c_beautifier.c
SRC_BEAUTIFIERV2 = c_beautifierv2.c

# Object files for each executable
OBJ_BEAUTIFIER = $(SRC_BEAUTIFIER:.c=.o)
OBJ_BEAUTIFIERV2 = $(SRC_BEAUTIFIERV2:.c=.o)

# Executable names
EXEC = c_beautifier c_beautifierv2

# Default target
all: $(EXEC)

# Rule for building c_beautifier
c_beautifier: $(OBJ_BEAUTIFIER)
	gcc $(CFLAGS) $(OBJ_BEAUTIFIER) -o $@

# Rule for building c_beautifierv2
c_beautifierv2: $(OBJ_BEAUTIFIERV2)
	gcc $(CFLAGS) $(OBJ_BEAUTIFIERV2) -o $@

# Generic rule for compiling .c to .o files
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

# Clean target for removing build artifacts
clean:
ifeq ($(OS),Windows_NT)
	@del /Q /F *.o *.exe
else
	@rm -f *.o $(EXEC)
endif


# Run targets for each executable
run_beautifier: c_beautifier
	./c_beautifier

run_beautifierv2: c_beautifierv2
	./c_beautifierv2

# Phony targets for commands that don't represent files
.PHONY: all clean run_beautifier run_beautifierv2
