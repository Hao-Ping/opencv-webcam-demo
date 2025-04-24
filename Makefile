CXX = g++
CXXFLAGS = -std=c++17 -Wall `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

SRC = src/main.cpp
BIN_DIR = bin
TARGET = $(BIN_DIR)/opencv_app

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: all
	./$(TARGET)

clean:
	rm -rf $(BIN_DIR)