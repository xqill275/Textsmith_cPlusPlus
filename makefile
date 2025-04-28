# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -MMD -MP

# Build modes
BUILD ?= debug

ifeq ($(BUILD), debug)
    CXXFLAGS += -g -O0
else ifeq ($(BUILD), release)
    CXXFLAGS += -O2 -DNDEBUG
endif

# Directories
ENGINE_SRC_DIR = src/engine
GAME_SRC_DIR = src/game
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
LIB_DIR = $(BUILD_DIR)/lib
BIN_DIR = $(BUILD_DIR)

# Files
ENGINE_SRCS := $(wildcard $(ENGINE_SRC_DIR)/*.cpp)
ENGINE_OBJS := $(patsubst $(ENGINE_SRC_DIR)/%.cpp, $(OBJ_DIR)/engine/%.o, $(ENGINE_SRCS))
GAME_SRCS := $(wildcard $(GAME_SRC_DIR)/*.cpp)
GAME_OBJS := $(patsubst $(GAME_SRC_DIR)/%.cpp, $(OBJ_DIR)/game/%.o, $(GAME_SRCS))

DEPS := $(ENGINE_OBJS:.o=.d) $(GAME_OBJS:.o=.d)

# Targets
STATIC_LIB = $(LIB_DIR)/libtextsmith.a
TARGET = $(BIN_DIR)/textsmith

# Default target
all: prepare_dirs $(TARGET)

# Prepare build directories
prepare_dirs:
	@mkdir -p $(OBJ_DIR)/engine $(OBJ_DIR)/game $(LIB_DIR) $(BIN_DIR)

# Link game with engine static library
$(TARGET): $(GAME_OBJS) $(STATIC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build engine static library
$(STATIC_LIB): $(ENGINE_OBJS)
	ar rcs $@ $^

# Compile engine sources
$(OBJ_DIR)/engine/%.o: $(ENGINE_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile game sources
$(OBJ_DIR)/game/%.o: $(GAME_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the game
run: all
	$(TARGET)

# Clean all build files
clean:
	rm -rf $(BUILD_DIR)

# Install binary (optional)
install: all
	cp $(TARGET) /usr/local/bin/textsmith

# Include dependency files
-include $(DEPS)

.PHONY: all clean run install prepare_dirs
