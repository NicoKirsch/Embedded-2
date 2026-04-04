CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -MMD -MP

SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin
TARGET = $(BIN_DIR)/manualapp

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
^^I@mkdir -p $(BIN_DIR)
^^I$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
^^I@mkdir -p $(OBJ_DIR)
^^I$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
^^Irm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
^^I@$(TARGET)

.PHONY: all clean run