/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

// #include <iostream>
// #include <vector>

// #include "cell.h"
// #include "lattice.h"
// #include "position.h"
// #include "state.h"

// int main(int argc, char* argv[]) {
  
// }

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/cell.h"
#include "../include/lattice.h"

// typedef int State;
// typedef int Position;

// class Lattice;

// class Cell {
// public:
//     Cell() : position_(0), state_(0), nextState_(0) {} // Default constructor
//     Cell(const Position& position_, const State& state_) : position_(position_), state_(state_), nextState_(0) {}
//     State getState() const { return state_; }
//     void setState(State newState) { state_ = newState; }
//     int nextState(const Lattice& lattice);
//     void updateState() { state_ = nextState_; }
//     friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
// private:
//     Position position_;
//     State state_;
//     State nextState_;
// };

// class Lattice {
// public:
//   Lattice(int size_, std::string border_) : size_(size_), border_(border_) {
//       cells_ = new Cell[size_];
//       for (int i = 0; i < size_; i++) {
//           cells_[i] = Cell(i, 0);
//       }
//   }
//   ~Lattice() { delete[] cells_; }
//   Cell& getCell(const Position& position) const { return cells_[position]; }
//   void nextGeneration();
//   friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);

//   // Getter for size_
//   int getSize() const { return size_; }

//   // Setter for size_
//   void setSize(int size) { size_ = size; }

// private:
//     Cell* cells_;
//     int size_;
//     std::string border_;
// };

// int Cell::nextState(const Lattice& lattice) {
//     int left = position_ - 1 < 0 ? 0 : lattice.getCell(position_ - 1).getState();
//     int right = position_ + 1 >= lattice.getSize() ? 0 : lattice.getCell(position_ + 1).getState();
//     nextState_ = left ^ (state_ | right); // Rule 30
//     return nextState_;
// }

// void Lattice::nextGeneration() {
//     for (int i = 0; i < size_; i++) {
//         cells_[i].nextState(*this);
//     }
//     for (int i = 0; i < size_; i++) {
//         cells_[i].updateState();
//     }
// }

// std::ostream& operator<<(std::ostream& os, const Cell& cell) {
//     os << (cell.state_ ? 'X' : ' ');
//     return os;
// }

// std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
//     for (int i = 0; i < lattice.getSize(); i++) {
//         os << lattice.cells_[i];
//     }
//     return os;
// }

int main(int argc, char* argv[]) {
    // Check that the correct number of arguments have been provided
    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " size border" << std::endl;
        return 1;
    }

    // Parse command line arguments
    try {
        int size = std::stoi(argv[2]);
        std::string border = argv[4];
        std::string initFile = argc > 5 ? argv[6] : "";

        // Create Lattice instance
        Lattice lattice(size, border);

        // If initial configuration file is provided, load configuration
        if (!initFile.empty()) {
            std::ifstream file(initFile);
            std::string line;
            if (file.is_open()) {
                getline(file, line);
                for (int i = 0; i < size && i < line.length(); i++) {
                    lattice.getCell(i).setState(line[i] == '1' ? 1 : 0);
                }
                file.close();
            }
        } else {
            // Default configuration: a "1" in the middle
            lattice.getCell(size / 2).setState(1);
        }

        // Display initial state
        std::cout << lattice << std::endl;

        // In a loop, update state and display new state
        for (int i = 0; i < 10; i++) {
            lattice.nextGeneration();
            std::cout << lattice << std::endl;
        }

    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return 1;
    }

    return 0;
}