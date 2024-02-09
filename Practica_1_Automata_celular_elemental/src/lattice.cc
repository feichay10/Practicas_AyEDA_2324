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
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/lattice.h"

/**
 * TODO: Constructor del retículo crea las células en memoria dinámica
 */
Lattice::Lattice(int size, borderType borderType, openBorderType openBorderType, std::string file) {
  size_ = size;
  borderType_ = borderType;
  cells_ = new Cell[size_];
  for (int i = 0; i < size_; i++) {
    cells_[i] = Cell(i, kDead);
  }
  loadInitialConfiguration(file);
}

Lattice::~Lattice() {
  delete[] cells_; 
}

Cell& Lattice::getCell(const Position& position) const {
  return cells_[position];
}

int Lattice::getSize() const {
  return size_; 
}

void Lattice::setSize(int size) {
  size_ = size; 
}

/**
 * TODO: Si no se especifica un archivo de configuracion inicial, se coloca
 * valor de estado "0" en todas la celulas, salvo en al celula central del
 * reticulo que tendrá el valor de estado 1
 */
void Lattice::loadInitialConfiguration(std::string file) {
  if (file == " ") {
    for (int i = 0; i < size_; i++) {
      cells_[i].setState(kDead);
    }
    cells_[size_ / 2].setState(kAlive);
  } else { // Si se especifica un archivo de configuracion inicial
    std::ifstream file_config(file);
    if (file_config.is_open()) {
      std::string line;
      int i = 0;
      while (std::getline(file_config, line)) {
        for (int j = 0; j < line.size(); j++) {
          if (line[j] == '1') {
            cells_[i].setState(kAlive);
          } else {
            cells_[i].setState(kDead);
          }
          i++;
        }
      }
    }
  }
}

void Lattice::nextGeneration() {
  for (int i = 0; i < size_; i++) {
    cells_[i].nextState(*this);
  }
  for (int i = 0; i < size_; i++) {
    cells_[i].updateState();
  }
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.getSize(); i++) {
    os << lattice.getCell(i);
  }
  return os;
}