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
  size_ = size + 2; // Se añaden dos celdas para las fronteras
  borderType_ = borderType;
  openBorderType_ = openBorderType;
  cells_ = new Cell*[size_];

  for (int i = 0; i < size_; i++) {
    cells_[i] = new Cell(i, kDead);
  }

  loadInitialConfiguration(file);
  setFrontier();
  printLatticeInformation(file);
}

Lattice::~Lattice() { 
  for (int i = 0; i < size_; i++) {
    delete cells_[i];
  }
  delete[] cells_;
}

Cell& Lattice::getCell(const Position& position) const {
  return *cells_[position];
}

int Lattice::getSize() const { return size_; }

void Lattice::setSize(int size) { size_ = size; }

borderType Lattice::getBorderType() { return borderType_; }

void Lattice::setBorderType(borderType borderType) { borderType_ = borderType; }

void Lattice::nextGeneration() {
  if (borderType_ == kOpen) {
    for (int i = 1; i < size_ - 1; i++) {
      cells_[i]->nextState(*this);
    }
    for (int i = 1; i < size_ - 1; i++) {
      cells_[i]->updateState();
    }
  } else {
    for (int i = 1; i < size_ - 1; i++) {
      cells_[i]->nextState(*this);
    }
    for (int i = 1; i < size_ - 1; i++) {
      cells_[i]->updateState();
    }

    // Actualizar las fronteras para el caso periódico
    cells_[0]->setState(cells_[size_ - 2]->getState());
    cells_[size_ - 1]->setState(cells_[1]->getState());
  }
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  // os << kPurpleBold << lattice.getCell(0) << kResetText << kGreenBold << "|" << kResetText;
  for (int i = 1; i < lattice.getSize() - 1; ++i) {
    // os << kRedBold << lattice.getCell(i);
    os << lattice.getCell(i);
  }
  // os << kGreenBold << "|" << kResetText << kPurpleBold << lattice.getCell(lattice.getSize() - 1) << kResetText;
  return os;
}

void Lattice::printLatticeInformation(std::string file) {
  std::cout << "+---------------------------------+" << std::endl;
  std::cout << "|           Lattice Info          |" << std::endl;
  std::cout << "+---------------------------------+" << std::endl;
  std::cout << "| Size: " << size_ - 2
            << std::setw(27 - std::to_string(size_).length()) << "|"
            << std::endl;
  std::cout << "| Border type: " << (borderType_ == kOpen ? "Open" : "Periodic")
            << std::setw(20 - (borderType_ == kOpen ? 4 : 8)) << "|"
            << std::endl;
  if (borderType_ == kOpen) {
    std::cout << "| Open border type: "
              << (openBorderType_ == kCold ? "Cold" : "Hot")
              << std::setw(15 - (openBorderType_ == kCold ? 4 : 3)) << "|"
              << std::endl;
  }
  std::cout << "| File: " << (file.empty() ? "No file" : file)
            << std::setw(27 - (file.empty() ? 7 : file.length())) << "|"
            << std::endl;
  std::cout << "+---------------------------------+" << std::endl;
  std::cout << "Initial configuration: " << initialConfiguration_ << std::endl;
}

void Lattice::loadInitialConfiguration(std::string file) {
  if (file.empty() || file == "") { // Si no se especifica un archivo
    cells_[size_ / 2]->setState(kAlive);
    for (int i = 1; i < size_ - 1; i++) {
      initialConfiguration_ += std::to_string(cells_[i]->getState());
    }
  } else {  
    std::ifstream file_config(file);
    if (file_config.is_open()) {
      std::string line;
      int i = 0;
      while (std::getline(file_config, line)) {
        for (int j = 0; j < line.size(); j++) {
          cells_[i + 1]->setState(line[j] == '1' ? kAlive : kDead);
          initialConfiguration_ += std::to_string(cells_[i + 1]->getState());
          i++;
        }
      }
    }
  }
}

void Lattice::setFrontier() {
  if (borderType_ == kOpen) {
    if (openBorderType_ == kCold) {
      cells_[0]->setState(kDead);
      cells_[size_ - 1]->setState(kDead);
    } else {
      cells_[0]->setState(kAlive);
      cells_[size_ - 1]->setState(kAlive);
    }
  } else {
    cells_[0]->setState(cells_[size_ - 2]->getState());
    cells_[size_ - 1]->setState(cells_[1]->getState());
  }
}