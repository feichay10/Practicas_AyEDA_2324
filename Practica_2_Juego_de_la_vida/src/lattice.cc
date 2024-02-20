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
// celula <muerda> y 'X' indica una celula <viva>.
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

Lattice::~Lattice() {}

// Metodo que solicita por teclado donde estarán las celulas vivas en el tablero
void Lattice::loadInitialConfiguration(int N, int M) {
  std::cout << "Introduce las posiciones de las celulas vivas (i j): " << std::endl;
  int i, j;
  while (std::cin >> i >> j) {
    if (i < 0 || i >= N || j < 0 || j >= M) {
      std::cerr << "Error: Posicion fuera de rango." << std::endl;
      continue;
    }
    lattice_[i][j]->setState(kAlive);
  }
}

int Lattice::getRows() const { return rows_; }

int Lattice::getColumns() const { return columns_; }

Cell& Lattice::getCell(const Position& position) const {}

std::size_t Lattice::Population() const { int count = 0; }

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.rows_; i++) {
    for (int j = 0; j < lattice.columns_; j++) {
      os << lattice.lattice_[i][j]->getState() << " ";
    }
    os << std::endl;
  }
  return os;
}