# Makefile for TextSmith C++ project

# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build/textsmith

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable
TARGET = $(BUILD_DIR)/textsmith

# Default target
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
