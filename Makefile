# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -I /opt/homebrew/include/ -DBOOST_BIND_GLOBAL_PLACEHOLDERS
LDFLAGS = -L /opt/homebrew/lib
LIBS = -lboost_system -lboost_serialization

# Source and build directories
SRC_DIR = src
BUILD_DIR = build

# Targets
TARGET = client
SRCS = $(SRC_DIR)/client.cpp
OBJS = $(BUILD_DIR)/client.o

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

