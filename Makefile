# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I./src $(shell sdl2-config --cflags)
LDFLAGS := $(shell sdl2-config --libs)

# Sources and objects
SRC := src/main.cpp src/chip8.cpp
OBJ := $(SRC:.cpp=.o)

# Output binary
TARGET := chip8_emulator.exe

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile .cpp → .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJ) $(TARGET)