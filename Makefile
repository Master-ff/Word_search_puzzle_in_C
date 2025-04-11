# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = word_search
SRC = word_search_puzzle.c

# Default rule to build the binary
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Clean rule to remove the compiled binary
clean:
	rm -f $(TARGET)

# Prevent make from confusing these with actual files
.PHONY: all clean
