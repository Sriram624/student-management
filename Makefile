CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# Directories
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

# Source files - all issue_*.c files plus globals
ISSUE_SOURCES = $(wildcard $(SRC_DIR)/issue_*.c)
SOURCES = $(SRC_DIR)/globals.c $(ISSUE_SOURCES)
TEST_SOURCES = $(TEST_DIR)/test.c $(SRC_DIR)/globals.c $(ISSUE_SOURCES)

# Output
TEST_EXECUTABLE = $(BUILD_DIR)/test_runner
MAIN_EXECUTABLE = $(BUILD_DIR)/student_management

# Create build directory
$(shell mkdir -p $(BUILD_DIR))

# Default target
all: $(MAIN_EXECUTABLE)

# Build main application
$(MAIN_EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ main.c $(SOURCES) $(LDFLAGS)

# Build and run tests
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_SOURCES)
	$(CC) $(CFLAGS) -o $@ $(TEST_SOURCES) $(LDFLAGS)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Rebuild everything
rebuild: clean all

# Run tests with verbose output
test-verbose: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

.PHONY: all test clean rebuild test-verbose
