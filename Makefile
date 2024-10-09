CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TARGET = $(BIN_DIR)/ShatteredKingdom
TEST_BIN = $(BIN_DIR)/test_suite

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(CXXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Unit testing targets
$(TEST_BIN): $(TEST_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(TEST_OBJS) -o $(TEST_BIN) $(CXXFLAGS)

# Pattern rule for test objects
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

check: $(TEST_BIN)
	$(TEST_BIN)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all check clean
