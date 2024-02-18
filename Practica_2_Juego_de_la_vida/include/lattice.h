/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file lattice.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LATTICE_H_
#define LATTICE_H_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "cell.h"
#include "position.h"

class Cell;

class Lattice {
 public:
  // Constructor y destructor
  Lattice(int N, int M);
  Lattice(const char*);
  ~Lattice();

  // Getters y Setters
  Cell& getCell(const Position& position) const;
  
  // Métodos de la clase
  void nextGeneration();
  std::size_t Population() const;

  // Sobrecarga de operadores
  Cell& operator[](const Position&);
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);

 private:
  void loadInitialConfiguration(int N, int M);
  void setFrontier();

  int rows_;
  int columns_;
  Cell** lattice_;
  Cell** nextLattice_;
};

#endif  // LATTICE_H_