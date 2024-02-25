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

Lattice::Lattice(int N, int M) {
  rows_ = M;
  columns_ = N;
  population_ = 0;

  lattice_.resize(M);
  for (int i = 0; i < rows_; i++) {
    lattice_[i].resize(N);
    for (int j = 0; j < columns_; j++) {
      lattice_[i][j] = new Cell(Position(i, j), kDead);
    }
  }

  loadInitialConfiguration(N, M);
  // setFrontier();


}

Lattice::Lattice(const char* file) {
  std::ifstream input(file);
  if (!input.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << file << std::endl;
    exit(EXIT_FAILURE);
  }

  input >> rows_ >> columns_;
  lattice_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (int j = 0; j < columns_; j++) {
      lattice_[i][j] = new Cell(Position(i, j), kDead);
    }
  }

  char state;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      input >> state;
      if (state == '1') {
        lattice_[i][j]->setState(kAlive);
        population_++;
      }
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
  return *lattice_[position.getRow()][position.getColumn()];
}

void Lattice::setBorderType(borderType borderType) {
  borderType_ = borderType;
}

borderType Lattice::getBorderType() const {
  return borderType_;
}

std::vector<std::vector<Cell*>> Lattice::getLattice() const {
  return lattice_;
}

void Lattice::nextGeneration() {
  expandLattice();

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

  // expandLattice();
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
    std::cerr << "Error: No se pudo abrir el archivo " << fileOut << std::endl;
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

Cell& Lattice::operator[](const Position& position) {
  return *lattice_[position.getRow()][position.getColumn()];
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
  std::cout << "Introduce las posiciones de las celulas vivas (i j): " << std::endl;
  std::cout << "Para terminar, pulsa 'q'" << std::endl;
  std::string i, j;

  std::cout << "\nCelula " << population_ + 1 << std::endl;
  while (true) {
    std::cout << "i: ";
    std::cin >> i;
    if (i == "q" || i == "Q") {
      break;
    } else if (stoi(i) >= N || stoi(i) < 0) {
      std::cerr << "Error: Posicion fuera del tablero." << std::endl;
      continue;
    }
    std::cout << "j: ";
    std::cin >> j;
    if (j == "q" || j == "Q") {
      break;
    } else if (stoi(j) >= M || stoi(j) < 0) {
      std::cerr << "Error: Posicion fuera del tablero." << std::endl;
      continue;
    }
    lattice_[stoi(i)][stoi(j)]->setState(kAlive);
    population_++;
    std::cout << "\nCelula " << population_ + 1 << std::endl;
  }

  system("clear");
}

void Lattice::setFrontier() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      if (i == 0 || i == rows_ - 1 || j == 0 || j == columns_ - 1) {
        lattice_[i][j]->setState(kAlive);
      }
    }
  }
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