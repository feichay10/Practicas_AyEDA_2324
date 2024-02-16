CC=g++
CXXFLAGS=-g -std=c++14

OBJS = src/cellular_automaton.o src/cell.o src/lattice.o src/functions.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o cellular_automaton ${OBJS}

clean: 
	rm -rf src/*.o cellular_automaton