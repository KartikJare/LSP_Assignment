# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC

# Shared library
LIB = libmath.so

# Object files
LIB_OBJ = add.o sub.o mul.o div.o

# App
APP = app

# Default
all: so app

# Build shared library
so: $(LIB)

$(LIB): $(LIB_OBJ)
	$(CC) -shared -o $(LIB) $(LIB_OBJ)

# Build app (link with shared lib)
app: main.o $(LIB)
	$(CC) -o $(APP) main.o -L. -lmath

# Compile rule
%.o: %.c math.h
	$(CC) $(CFLAGS) -c $<

# Run with LD_LIBRARY_PATH
run: $(APP)
	LD_LIBRARY_PATH=. ./$(APP)

# Clean
clean:
	rm -f *.o $(LIB) $(APP)

# Help
help:
	@echo "Usage:"
	@echo "  make so     - Build shared library (libmath.so)"
	@echo "  make app    - Build application"
	@echo "  make run    - Run app with LD_LIBRARY_PATH"
	@echo "  make clean  - Remove all build files"