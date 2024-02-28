/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice2D.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LATTICE2D_H
#define LATTICE2D_H

#include <iostream>
#include <vector>

#include "lattice.h"

class Lattice2D : public Lattice {
 public:
  Lattice2D(int N, int M);
  ~Lattice2D();

  void nextGeneration();
  std::size_t Population() const;

  Cell& operator[](const Position&) const;

  std::ostream& display(std::ostream&);

 private:
  int rows_;
  int columns_;
  std::vector<std::vector<Cell*>> lattice_;
  borderType borderType_;
};

#endif  // LATTICE2D_H