CXX		 := g++
CXXFLAGS=-g -std=c++14 #-fsanitize=address #-Wall #-Wextra

BIN     := bin
SRC     := src
BUILD	:= build
INCLUDE := include
LIB     := lib
LIBRARIES   := 
EXECUTABLE  := dispersionSearch
PARAMS	:= 
SOURCES := $(wildcard $(SRC)/*.cc)
OBJS	:= $(patsubst $(SRC)/%.cc, $(BUILD)/%.o,$(SOURCES))

.PHONY: all project run clean

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L$(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cc
	@echo "🚧 Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

project:
	clear
	@echo "📁 Creating Project Structure..."
	mkdir -p bin build include src

run:
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMS)

clean:
	@echo "🧹 Clearing..."
	rm -f $(BIN)/* $(BUILD)/*