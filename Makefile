CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -Iinclude
LDFLAGS = $(shell sdl2-config --libs)

# Folders
SRC_DIR = src
BUILD_DIR = build
TARGET = chip_emulator

# Files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

all: $(TARGET)

# build target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean