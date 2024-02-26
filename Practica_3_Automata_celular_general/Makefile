CC=g++
CXXFLAGS=-g -std=c++14

OBJS = build/cellular_automata.o build/cell.o build/lattice.o build/functions.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o cellular_automata ${OBJS}

build/%.o: src/%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf build/*.o cellular_automata