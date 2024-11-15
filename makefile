# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra

# File names
SOURCES = main.c engine.c ui.c file_io.c globals.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = tictactoe.exe

# Default target
all: $(EXECUTABLE)

# Link the program
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

# Compile source files
%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	del /F /Q $(OBJECTS) $(EXECUTABLE)

# Run the program
run: $(EXECUTABLE)
	.\$(EXECUTABLE)

.PHONY: all clean run
