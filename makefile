# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -I./src/header

# Source files
SRC = src/main.cpp src/TextSmithEngine.cpp

# Output
OUT = build/textsmith

# Default target
all: $(OUT)

# Build rule
$(OUT): $(SRC)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

# Clean rule
clean:
	rm -f $(OUT)

.PHONY: all clean
