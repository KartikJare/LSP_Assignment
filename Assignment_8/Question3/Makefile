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

# Help target
help:
	@echo "Usage:"
	@echo "  make        - Build the program"
	@echo "  ./$(TARGET) - Run the program"
	@echo "  make clean  - Remove the executable"
	@echo "  make help   - Show this help message"

# Clean rule
clean:
	rm -f $(TARGET)