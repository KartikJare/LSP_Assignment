# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -O2

# Target
TARGET = app

# Source and object files
SRC = main.c helper.c
OBJ = main.o helper.o

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile rules with header dependency
main.o: main.c helper.h
	$(CC) $(CFLAGS) -c main.c

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c

# Clean
clean:
	rm -f $(TARGET) $(OBJ)

# Help
help:
	@echo "Usage:"
	@echo "  make        - Build the application"
	@echo "  ./$(TARGET) - Run the program"
	@echo "  make clean  - Remove object files and executable"
	@echo "  make help   - Show this help message"