CC=g++
CXXFLAGS=-g -std=c++14

OBJS = build/life_game.o build/cell.o build/lattice.o build/functions.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o life_game ${OBJS}

build/%.o: src/%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf build/*.o life_game