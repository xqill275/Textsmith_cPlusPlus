# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
ENGINE_SRC_DIR = src/engine
GAME_SRC_DIR = src/game
BUILD_DIR = build
LIB_DIR = $(BUILD_DIR)/lib
OBJ_DIR = $(BUILD_DIR)/obj

# Files
ENGINE_SRCS := $(wildcard $(ENGINE_SRC_DIR)/*.cpp)
ENGINE_OBJS := $(patsubst $(ENGINE_SRC_DIR)/%.cpp, $(OBJ_DIR)/engine/%.o, $(ENGINE_SRCS))
GAME_SRC := $(GAME_SRC_DIR)/main.cpp
GAME_OBJ := $(OBJ_DIR)/game/main.o

# Targets
STATIC_LIB = $(LIB_DIR)/libtextsmith.a
TARGET = $(BUILD_DIR)/textsmith

# Default target
all: $(TARGET)

# Link game with engine library
$(TARGET): $(GAME_OBJ) $(STATIC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

# Build engine static library
$(STATIC_LIB): $(ENGINE_OBJS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# Compile engine source files
$(OBJ_DIR)/engine/%.o: $(ENGINE_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile game source
$(OBJ_DIR)/game/%.o: $(GAME_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the game
run: all
	$(TARGET)

# Clean all build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean run