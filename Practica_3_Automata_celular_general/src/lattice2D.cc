/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice2D.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/lattice2D.h"
#include "../include/positionDim.h"

Lattice2D::Lattice2D(int& rows, int& columns, const FactoryCell& factory, borderType border) {
  rows_ = rows;
  columns_ = columns;
  borderType_ = border;
  Position* position;

  lattice_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (int j = 0; j < columns_; j++) {
      position = new PositionDim<2>(2, i, j);
      lattice_[i][j] = factory.createCell(*position, kDead);
    }
  }
}

Lattice2D::Lattice2D(const char* fileName, const FactoryCell& factory, borderType border) {
  std::ifstream file(fileName);
  if (!file.is_open()) {
    std::cerr << "Error: File not found" << std::endl;
    exit(1);
  }
  file >> rows_;
  file >> columns_;
  lattice_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (int j = 0; j < columns_; j++) {
      Position* position = new PositionDim<2>(2, i, j);
      lattice_[i][j] = factory.createCell(*position, kDead);
    }
  }
  file.close();
}

Lattice2D::~Lattice2D() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      delete lattice_[i][j];
    }
  }
  lattice_.clear();
}

void Lattice2D::nextGeneration() {
  if (borderType_ == kNoBorder) {
    expandLattice();
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      lattice_[i][j]->nextState(*this);
    }
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      lattice_[i][j]->updateState();
    }
  }
}

std::size_t Lattice2D::Population() const {
  std::size_t population = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      if (lattice_[i][j]->getState() == kAlive) {
        population++;
      }
    }
  }
  return population;
}

void Lattice2D::saveToFile(const std::string& fileName) const {
  std::ofstream file(fileName);
  if (!file.is_open()) {
    std::cerr << "Error: File not found" << std::endl;
    exit(1);
  }
  file << rows_ << " " << columns_ << std::endl;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      file << lattice_[i][j]->getState();
    }
    file << std::endl;
  }
  file.close();
}

std::ostream& Lattice2D::display(std::ostream& os) const {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      os << lattice_[i][j]->getState();
    }
    os << std::endl;
  }
  return os;
}

void Lattice2D::loadInitialLattice(int row, int col) {
  std::string i, j;
  int population = 0;

  std::cout << "Enter the positions of the live cells (i j): " << std::endl;
  std::cout << "To finish, press 'q'." << std::endl;
  std::cout << "\nCell " << population + 1 << std::endl;
  while (true) {
    std::cout << "i: ";
    std::cin >> i;
    if (i == "q" || i == "Q") {
      break;
    } else if (stoi(i) >= row || stoi(i) < 0) {
      std::cerr << "Error: Position out of the board." << std::endl;
      continue;
    }

    std::cout << "j: ";
    std::cin >> j;
    if (j == "q" || j == "Q") {
      break;
    } else if (stoi(j) >= col || stoi(j) < 0) {
      std::cerr << "Error: Position out of the board." << std::endl;
      continue;
    }

    lattice_[stoi(i)][stoi(j)]->setState(kAlive);
    population++;
    std::cout << "\nCell " << population + 1 << std::endl;
  }

  // Limpiar el búfer de entrada para descartar el carácter de nueva línea
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  system("clear");
}

void Lattice2D::expandLattice() {
std::vector<std::vector<Cell*>> newLattice;
  bool expanded = false;

  for (int i = 0; i < rows_; i++) {
    if (lattice_[i][0]->getState() == kAlive) {
      expanded = true;
      break;
    }

    if (lattice_[i][columns_ - 1]->getState() == kAlive) {
      expanded = true;
      break;
    }
  }

  for (int i = 0; i < columns_; i++) {
    if (lattice_[0][i]->getState() == kAlive) {
      expanded = true;
      break;
    }

    if (lattice_[rows_ - 1][i]->getState() == kAlive) {
      expanded = true;
      break;
    }
  }

  if (expanded) {
    newLattice.resize(rows_ + 2);
    for (int i = 0; i < rows_ + 2; i++) {
      newLattice[i].resize(columns_ + 2);
      for (int j = 0; j < columns_ + 2; j++) {
        // newLattice[i][j] = new Cell(Position(i, j), kDead);
        Position* position = new PositionDim<2>(2, i, j);
        // newLattice[i][j] = 
      }
    }

    for (int i = 1; i < rows_ + 1; i++) {
      for (int j = 1; j < columns_ + 1; j++) {
        newLattice[i][j]->setState(lattice_[i - 1][j - 1]->getState());
      }
    }

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < columns_; j++) {
        delete lattice_[i][j];
      }
    }
    lattice_.clear();
    lattice_ = newLattice;
    rows_ += 2;
    columns_ += 2;
  }
}