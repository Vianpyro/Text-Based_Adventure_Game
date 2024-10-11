CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INC_DIR)

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests

# Source and Object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) # Source files in src directory
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) # Object files for main program

# Test source and object files
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp) # Test source files in tests directory
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/test_%.o) # Object files for test suite

TARGET = $(BIN_DIR)/ShatteredKingdom # Main executable
TEST_BIN = $(BIN_DIR)/test_suite # Test suite executable

# Look for header files in include/ and its subdirectories
CXXFLAGS += -I$(shell find $(INC_DIR) -type d)

all: $(TARGET) # Build the main executable

# Rule to link object files and create the main executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile test files into object files
$(OBJ_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to build the test suite, excluding main.o
$(TEST_BIN): $(TEST_OBJS) $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(filter-out obj/main.o,$(OBJS)) $(TEST_OBJS) -o $(TEST_BIN)

check: $(TEST_BIN) # Runs the test suite
	$(TEST_BIN)

# Combines all and check targets to ensure everything is built and tests are run
distcheck: all check
	@echo "Distcheck: All checks passed successfully!"

clean: # Removes all generated files (objects and binaries)
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all check clean distcheck
