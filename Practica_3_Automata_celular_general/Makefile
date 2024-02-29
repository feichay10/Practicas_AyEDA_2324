# CC=g++
# CXXFLAGS=-g -std=c++14

# OBJS = build/cellular_automata.o build/cell.o build/lattice.o build/functions.o

# all: ${OBJS}
# 	$(CC) $(CXXFLAGS) -o cellular_automata ${OBJS}

# build/%.o: src/%.cc
# 	$(CC) $(CXXFLAGS) -c $< -o $@

# clean: 
# 	rm -rf build/*.o cellular_automata

CXX		 := g++
CXXFLAGS=-g -std=c++17 #-fsanitize=address #-Wall #-Wextra

BIN     := bin
SRC     := src
BUILD	:= build
INCLUDE := include
LIB     := lib
LIBRARIES   := 
EXECUTABLE  := cellular_automata
PARAMS	:= -size 10 10 -border open 0
PARAMS1	:= -size 10 10 -border reflective -init ../dataFile/file2.txt
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