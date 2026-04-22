# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -O2

# Target executable
TARGET = program

# Source files
SRC = main.c

# Default rule
all: $(TARGET)

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean rule
clean:
	rm -f $(TARGET)