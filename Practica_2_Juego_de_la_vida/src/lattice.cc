/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
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
#include "../include/functions.h"

Lattice::Lattice() {}

Lattice::Lattice(int M, int N) {
  rows_ = M;
  columns_ = N;
  population_ = 0;

  lattice_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (int j = 0; j < columns_; j++) {
      lattice_[i][j] = new Cell(Position(i, j), kDead);
    }
  }

  loadInitialConfiguration(N, M);
}

Lattice::Lattice(const char* file) {
  std::ifstream input(file);
  if (!input.is_open()) {
    std::cerr << "Error: File could not be opened." << file << std::endl;
    exit(EXIT_FAILURE);
  }

  input >> rows_ >> columns_;
  lattice_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (int j = 0; j < columns_; j++) {
      char state;
      input >> state;
      lattice_[i][j] = new Cell(Position(i, j), state == '1' ? kAlive : kDead);
    }
  }

  input.close();
}

Lattice::~Lattice() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      delete lattice_[i][j];
    }
  }
  lattice_.clear();
}

int Lattice::getRows() const { return rows_; }

int Lattice::getColumns() const { return columns_; }

Cell& Lattice::getCell(const Position& position) const {
  int i, j;

  if (position.getRow() < 0 || position.getRow() >= rows_ || position.getColumn() < 0 || position.getColumn() >= columns_) {
    if (borderType_ == kNoBorder) {
      Cell* cell = new Cell(Position(0), kDead);
      return *cell;
    } else if (borderType_ == kReflective) {
      i = position.getRow();
      j = position.getColumn();
      if (position.getRow() < 0) {
        i = 1;
      }
      if (position.getColumn() < 0) {
        j = 1;
      }
      if (position.getRow() >= rows_) {
        i = rows_ - 2;
      }
      if (position.getColumn() >= columns_) {
        j = columns_ - 2;
      }
      return *lattice_[i][j];
    }
  }

  return *lattice_[position.getRow()][position.getColumn()];
}

void Lattice::setBorderType(borderType borderType) {
  borderType_ = borderType;
}

borderType Lattice::getBorderType() const {
  return borderType_;
}

int Lattice::getGeneration() const {
  return generation_;
}

void Lattice::nextGeneration() {
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

  generation_++;
}

std::size_t Lattice::Population() const { 
  size_t count = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      if (lattice_[i][j]->getState() == kAlive) {
        count++;
      }
    }
  }
  return count;
}

void Lattice::saveToFile(const std::string& fileOut) const {
  std::ofstream output(fileOut);
  if (!output.is_open()) {
    std::cerr << "Error: File could not be opened." << fileOut << std::endl;
    exit(EXIT_FAILURE);
  }
  output << rows_ << " " << columns_ << std::endl;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      output << lattice_[i][j]->getState();
    }
    output << std::endl;
  }
  
  output.close();
}

Cell& Lattice::operator[](const Position& position) const {
  return getCell(position);
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  os << kGreenBold << "+-";
  for (int i = 0; i < lattice.columns_ ; i++) {
    os << "--";
  }
  os << "+" << std::endl;
  for (int i = 0; i < lattice.rows_; i++) {
    os << "| " << kReset;
    for (int j = 0; j < lattice.columns_; j++) {
      // os << lattice.lattice_[i][j]->getState() << " ";
      os << kRedBold << *lattice.lattice_[i][j] << " " << kReset;
    }
    os << kGreenBold << "|" << std::endl;
  }
  os << "+-";
  for (int i = 0; i < lattice.columns_ ; i++) {
    os << "--";
  }
  os << "+" << kReset << std::endl;

  return os;
}

void Lattice::loadInitialConfiguration(int N, int M) {
  std::cout << "Enter the positions of the live cells (i j): " << std::endl;
  std::cout << "To finish, press 'q'." << std::endl;
  std::string i, j;

  std::cout << "\nCell " << population_ + 1 << std::endl;
  while (true) {
    std::cout << "i: ";
    std::cin >> i;
    if (i == "q" || i == "Q") {
      break;
    } else if (stoi(i) >= N || stoi(i) < 0) {
      std::cerr << "Error: Position out of the board." << std::endl;
      continue;
    }

    std::cout << "j: ";
    std::cin >> j;
    if (j == "q" || j == "Q") {
      break;
    } else if (stoi(j) >= M || stoi(j) < 0) {
      std::cerr << "Error: Position out of the board." << std::endl;
      continue;
    }

    lattice_[stoi(i)][stoi(j)]->setState(kAlive);
    population_++;
    std::cout << "\nCell " << population_ + 1 << std::endl;
  }

  // Limpiar el búfer de entrada para descartar el carácter de nueva línea
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  system("clear");
}

void Lattice::expandLattice() {
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
        newLattice[i][j] = new Cell(Position(i, j), kDead);
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