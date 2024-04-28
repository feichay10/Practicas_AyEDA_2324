/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice1D.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/Lattice/lattice1D.h"

Lattice1D::Lattice1D(int& size, FactoryCell*& factory) {
  size_ = size + 2;
  lattice_ = new Cell*[size_];
  Position* position;
  for (int i = 0; i < size_; i++) {
    position = new PositionDim<1>(1, i);
    lattice_[i] = factory->createCell(*position, kDead);
  }

  loadInitialLattice();
}

Lattice1D::Lattice1D(std::string& fileName, FactoryCell*& factory) {
  std::ifstream file(fileName);
  std::string line;
  State state;
  Position* position;
  char dim;

  if (!file.is_open()) {
    std::cerr << "Error: File not found" << std::endl;
    exit(1);
  }

  file >> dim;
  file >> size_;
  size_ += 2;
  lattice_ = new Cell*[size_];
  
  for (int i = 0; i < size_; i++) {
    position = new PositionDim<1>(1, i);
    std::string line;
    std::getline(file, line); // Read the line from the file
    state = (line[i] == '0') ? kDead : kAlive; // Initialize the state of each cell based on the characters in the line
    lattice_[i] = factory->createCell(*position, state);
  }
  
}

Lattice1D::~Lattice1D() {
  for (int i = 0; i < size_; i++) {
    delete lattice_[i];
  }
  delete[] lattice_;
}

void Lattice1D::nextGeneration() {
  for (int i = 1; i < size_ - 1; i++) {
    lattice_[i]->nextState(*this);
  }
  for (int i = 1; i < size_ - 1; i++) {
    lattice_[i]->updateState();
  }
}

std::size_t Lattice1D::Population() const {
  std::size_t population = 0;
  for (int i = 1; i < size_ - 1; i++) {
    if (lattice_[i]->getState() == kAlive) {
      population++;
    }
  }
  return population;
}

void Lattice1D::loadInitialLattice() {
  std::string pos;
  int population = 0;
  std::cout << "Enter the position of the live cells." << std::endl;
  std::cout << "To finish, press 'q'. " << std::endl;
  std::cout << "\nCell " << population + 1 << std::endl;

  while (population <= size_ - 2) {
    std::cin >> pos;
    if (pos == "q") {
      break;
    }
    int position = std::stoi(pos);

    if (position < 1 || position > size_ - 1) {
      std::cerr << "Error: Position out of range" << std::endl;
      continue;
    }

    lattice_[position]->setState(kAlive);
    population++;
    std::cout << "\nCell " << population + 1 << std::endl;
  }

  system("clear");
}

std::ostream& Lattice1D::display(std::ostream& os) const {
  os << *lattice_[0] << "|";
  for (int i = 1; i < size_ - 1; i++) {
    os << *lattice_[i];
  }
  os << "|" << *lattice_[size_ - 1];
  return os;
}

std::ofstream& Lattice1D::displayFile(std::ofstream& os) const {
  // os << dim_ << std::endl;
  os << size_ - 2 << std::endl;
  for (int i = 1; i < size_ - 1; i++) {
    os << lattice_[i]->getState();
  }
  os << std::endl;
  return os;
}