CXX = g++
CC = gcc
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -MMD -MP
CFLAGS = -Wall -Wextra -Iinclude -MMD -MP
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin
TARGET = $(BIN_DIR)/manualapp

SRCS_CPP = $(wildcard $(SRC_DIR)/*.cpp)
SRCS_C = $(wildcard $(SRC_DIR)/*.c)
OBJS_CPP = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS_CPP))
OBJS_C = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_C))
OBJS = $(OBJS_CPP) $(OBJS_C)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	@$(TARGET)

.PHONY: all clean run