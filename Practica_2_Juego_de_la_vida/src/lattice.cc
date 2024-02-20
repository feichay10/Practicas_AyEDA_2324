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

/**
 * @brief Constructor que crea las celulas en memoria dinamica, con valor
 * inicial de muerte. Este contructor se apoya de un metodo auxiliar para
 * solicitar por teclado las posiciones de las celulas que deben estar vivas en
 * la configuracion inicial.
 *
 * @param N
 * @param M
 */
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
  setFrontier();
}

/**
 * @brief Constructor que recibe como parámetro un nombre de un fichero. La
 * primera fila del fichero contiene el numero de filas (M) y columnas (N) del
 * reticulo. A continuación contiene las M cadenas de N caracteres, donde ' '
 * indica una celula <muerda> y 'X' indica una celula <viva>.
 *
 * @param file
 */
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
  setFrontier();
  input.close();
}


Lattice::~Lattice() {}

int Lattice::getRows() const {
  return rows_;
}

int Lattice::getColumns() const {
  return columns_;
}

Cell& Lattice::getCell(const Position& position) const {
  
}

/**
 * @brief Tiene la responsabilidad de conocer la población, esto es el numero de
 * celulas vivas en la generación actual.
 *
 * @return std::size_t
 */
std::size_t Lattice::Population() const {

}