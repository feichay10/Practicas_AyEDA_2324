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

Lattice1D::Lattice1D(const int& size, const FactoryCell& factory) {
  size_ = size + 2;
  cells_ = new Cell*[size_];
  for (int i = 0; i < size_; i++) {
    cells_[i] = factory.createCell(PositionDim<1, int>(1, i), kDead);
  }
}

Lattice1D::Lattice1D(const char* fileName, const FactoryCell& factory) {
  std::ifstream file(fileName);
  if (!file.is_open()) {
    std::cerr << "Error: File not found" << std::endl;
    exit(1);
  }
  file >> size_;
  cells_ = new Cell*[size_];
  for (int i = 0; i < size_; i++) {
    int state;
    file >> state;
    cells_[i] = factory.createCell(PositionDim<1, int>(1, i), static_cast<State>(state));
  }
  file.close();
}

Lattice1D::~Lattice1D() {
  for (int i = 0; i < size_; i++) {
    delete cells_[i];
  }
  delete[] cells_;
}

void Lattice1D::nextGeneration() {
  for (int i = 0; i < size_; i++) {
    cells_[i]->nextState(*this);
  }
  for (int i = 0; i < size_; i++) {
    cells_[i]->updateState();
  }
}

std::size_t Lattice1D::Population() const {
  std::size_t population = 0;
  for (int i = 0; i < size_; i++) {
    if (cells_[i]->getState() == kAlive) {
      population++;
    }
  }
  return population;
}

Cell* Lattice1D::operator[](const PositionDim<1, int>& position) const {
  return cells_[position[0]];
}

std::ostream& Lattice1D::display(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < size_; i++) {
    os << *cells_[i];
  }
  return os;
}