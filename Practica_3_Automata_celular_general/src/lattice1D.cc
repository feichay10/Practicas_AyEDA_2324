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

#include "../include/lattice1D.h"
#include "../include/positionDim.h"

Lattice1D::Lattice1D(int& size, const FactoryCell& factory) {
  size_ = size + 2;
  lattice_ = new Cell*[size_];
  Position* position;
  for (int i = 0; i < size_; i++) {
    position = new PositionDim<1>(1, i);
    lattice_[i] = factory.createCell(*position, kDead);
  }

  loadInitialLattice();
}

Lattice1D::Lattice1D(const char* fileName, const FactoryCell& factory) {
  std::ifstream file(fileName);
  if (!file.is_open()) {
    std::cerr << "Error: File not found" << std::endl;
    exit(1);
  }
  file >> size_;
  lattice_ = new Cell*[size_];
  Position* position;
  for (int i = 0; i < size_; i++) {
    position = new PositionDim<1>(1, i);
    lattice_[i] = factory.createCell(*position, kDead);
  }
  file.close();
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
  for (int i = 0; i < size_; i++) {
    if (lattice_[i]->getState() == kAlive) {
      population++;
    }
  }
  return population;
}

std::ostream& Lattice1D::display(std::ostream& os) const {
  os << *lattice_[0] << "|";
  for (int i = 1; i < size_ - 1; i++) {
    os << *lattice_[i];
  }
  os << "|" << *lattice_[size_ - 1] << std::endl;
  return os;
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