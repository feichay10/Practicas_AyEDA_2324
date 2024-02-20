CC=g++
CXXFLAGS=-g -std=c++14

OBJS = src/life_game.o src/cell.o src/lattice.o src/functions.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o life_game ${OBJS}

clean: 
	rm -rf src/*.o life_game