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

// Constructor que crea las celulas en memoria dinamica, con valor inicial de
// muerte. Este contructor se apoya de un metodo auxiliar para solicitar por
// teclado las posiciones de las celulas que deben estar vivas en la
// configuracion inicial.
Lattice::Lattice(int N, int M) {
  rows_ = N;
  columns_ = M;
  population_ = 0;
  lattice_.resize(N);
  for (int i = 0; i < N; i++) {
    lattice_[i].resize(M);
    for (int j = 0; j < M; j++) {
      lattice_[i][j] = new Cell(Position(i, j), kDead);
    }
  }
  loadInitialConfiguration(N, M);
  // setFrontier();
}

// Constructor que recibe como parámetro un nombre de un fichero. La primera
// fila del fichero contiene el numero de filas (M) y columnas (N) del reticulo.
// A continuación contiene las M cadenas de N caracteres, donde ' ' indica una
// celula <muerta> y 'X' indica una celula <viva>.
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
      char c;
      input >> c;
      if (c == 'X') {
        lattice_[i][j] = new Cell(Position(i, j), kAlive);
      } else {
        lattice_[i][j] = new Cell(Position(i, j), kDead);
      }
    }
  }
  // setFrontier();
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

void Lattice::nextGeneration() {
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

// Añade bordes al tablero para ver los limites del tablero
std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  os << "+-";
  for (int i = 0; i < lattice.columns_ ; i++) {
    os << "--";
  }
  os << "+" << std::endl;
  for (int i = 0; i < lattice.rows_; i++) {
    os << "| ";
    for (int j = 0; j < lattice.columns_; j++) {
      os << lattice.lattice_[i][j]->getState() << " ";
    }
    os << "|" << std::endl;
  }
  os << "+-";
  for (int i = 0; i < lattice.columns_ ; i++) {
    os << "--";
  }
  os << "+" << std::endl;

  return os;
}


// Metodo que solicita por teclado donde estarán las celulas vivas en el tablero
void Lattice::loadInitialConfiguration(int N, int M) {
  std::cout << "Introduce las posiciones de las celulas vivas (i j): " << std::endl;
  std::cout << "Para terminar, pulsa 'q'" << std::endl;
  int i, j;

  std::cout << "\nCelula " << population_ + 1 << std::endl;
  while (std::cin >> i >> j) {
    if (i >= N || j >= M) {
      std::cerr << "Error: Posicion fuera del tablero." << std::endl;
      continue;
    } else if (i < 0 || j < 0) {
      std::cerr << "Error: Posicion fuera del tablero." << std::endl;
      continue;
    } else if (std::cin.get() == 'q') {
      break;
    } else {
      lattice_[i][j]->setState(kAlive);
      population_++;
    }
    std::cout << "\nCelula " << population_ + 1 << std::endl;
  }
  std::cin.clear();
  system("clear");
}