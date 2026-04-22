# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Library name
LIB = libmath.a

# Object files for library
LIB_OBJ = add.o sub.o mul.o div.o

# App
APP = app

# Default
all: lib app

# Build static library
lib: $(LIB)

$(LIB): $(LIB_OBJ)
	ar rcs $(LIB) $(LIB_OBJ)

# Build app
app: main.o $(LIB)
	$(CC) $(CFLAGS) -o $(APP) main.o -L. -lmath

# Compile rules
%.o: %.c math.h
	$(CC) $(CFLAGS) -c $<

# Clean
clean:
	rm -f *.o $(LIB) $(APP)

# Help
help:
	@echo "Usage:"
	@echo "  make lib    - Build static library (libmath.a)"
	@echo "  make app    - Build application using static library"
	@echo "  make        - Build everything"
	@echo "  ./$(APP)    - Run the program"
	@echo "  make clean  - Remove all build files"