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

Lattice::Lattice(int size, borderType borderType, openBorderType openBorderType, std::string file) {
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Size: " << size << std::endl;
  std::cout << "Border type: " << (borderType == kOpen ? "Open" : "Periodic") << std::endl;
  std::cout << "Open border type: " << (openBorderType == kCold ? "Cold" : "Hot") << std::endl;
  std::cout << "File: " << (file.empty() ? "No file" : file) << std::endl;
  std::cout << "-----------------------------------" << std::endl << std::endl;

  size_ = size + 2;
  borderType_ = borderType;
  openBorderType_ = openBorderType;
  cells_ = new Cell[size_];

  for (int i = 0; i < size_; i++) {
    cells_[i] = Cell(i, kDead);
  }

  // Tipo de frontera:
  if (borderType_ == kOpen) {
    if (openBorderType_ == kCold) {
      cells_[0].setState(kDead);
      cells_[size_ - 1].setState(kDead);
    } else {
      cells_[0].setState(kAlive);
      cells_[size_ - 1].setState(kAlive);
    }
  } else { 
    cells_[0].setState(cells_[size_ - 1].getState());
    cells_[size_ - 1].setState(cells_[0].getState());
  }

  loadInitialConfiguration(file);
}

Lattice::~Lattice() {
  delete[] cells_; 
}

void Lattice::loadInitialConfiguration(std::string file) {
  if (file.empty() || file == "") {
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

Cell& Lattice::getCell(const Position& position) const {
  return cells_[position];
}

int Lattice::getSize() const {
  return size_; 
}

void Lattice::setSize(int size) {
  size_ = size; 
}

borderType Lattice::getBorderType() {
  return borderType_;
}

void Lattice::setBorderType(borderType borderType) {
  borderType_ = borderType;
}

void Lattice::nextGeneration() {
  if (borderType_ == kOpen) {
    for (int i = 1; i < size_ - 1; i++) {
      cells_[i].nextState(*this);
    }
    for (int i = 1; i < size_ - 1; i++) {
      cells_[i].updateState();
    }
  } else {
    for (int i = 0; i < size_; i++) {
      cells_[i].nextState(*this);
    }
    for (int i = 0; i < size_; i++) {
      cells_[i].updateState();
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  // os << lattice.getCell(0) << "|";
  for (int i = 1; i < lattice.getSize() - 1; ++i) {
    os << lattice.getCell(i);
  }
  // os << "|" << lattice.getCell(lattice.getSize() - 1);
  return os;
}