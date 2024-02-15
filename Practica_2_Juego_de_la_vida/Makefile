CC=g++
CXXFLAGS=-g -std=c++14

OBJS = src/automata_celular.o src/cell.o src/lattice.o src/functions.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o automata_celular ${OBJS}

clean: 
	rm -rf src/*.o automata_celular