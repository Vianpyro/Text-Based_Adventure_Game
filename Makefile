CXX = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -I$(INC_DIR) -MMD -MP
LDFLAGS =
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests

# Source and Object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Test source and object files
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/test_%.o)

# Target executables
TARGET = $(BIN_DIR)/ShatteredKingdom
TEST_BIN = $(BIN_DIR)/test_suite

# Look for header files in include/ and its subdirectories
CXXFLAGS += -I$(shell find $(INC_DIR) -type d)

# Default rule
all: $(TARGET)

# Rule to link object files and create the main executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(TARGET)

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
	$(CXX) $(filter-out $(OBJ_DIR)/main.o,$(OBJS)) $(TEST_OBJS) $(LDFLAGS) -o $(TEST_BIN)

# Rule to run tests
check: $(TEST_BIN)
	$(TEST_BIN)

# Combines all and check targets to ensure everything is built and tests are run
distcheck: all check
	@echo "Distcheck: All checks passed successfully!"

# Removes all generated files (objects and binaries)
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Include dependency files
-include $(OBJS:.o=.d)
-include $(TEST_OBJS:.o=.d)

.PHONY: all check clean distcheck
