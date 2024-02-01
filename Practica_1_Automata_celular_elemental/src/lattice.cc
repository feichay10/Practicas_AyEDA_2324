/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
 * @file lattice.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/lattice.h"

Lattice::Lattice(int size_, std::string border_) : size_(size_), border_(border_) {
  cells_ = new Cell[size_];
  for (int i = 0; i < size_; i++) {
    cells_[i] = Cell(i, 0);
  }
}

Lattice::~Lattice() { delete[] cells_; }

Cell& Lattice::getCell(const Position& position) const { return cells_[position]; }

int Lattice::getSize() const { return size_; }

void Lattice::setSize(int size) { size_ = size; }

void Lattice::nextGeneration() {
  for (int i = 0; i < size_; i++) {
    cells_[i].nextState(*this);
  }
  for (int i = 0; i < size_; i++) {
    cells_[i].updateState();
  }
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.size_; i++) {
    os << lattice.cells_[i];
  }
  return os;
}