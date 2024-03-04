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

#include <fstream>
#include <iostream>
#include <vector>
#include <limits>

#include "factoryCell.h"
#include "lattice.h"

class Lattice2D : public Lattice {
 public:
  Lattice2D(int& M, int& N, const FactoryCell& factory, borderType border);
  Lattice2D(const char* fileName, const FactoryCell& factory, borderType border);
  virtual ~Lattice2D();

  void nextGeneration();
  std::size_t Population() const;

 protected:
  std::ostream& display(std::ostream& os) const;
  void loadInitialLattice(int row, int col);
  void expandLattice();

  int rows_;
  int columns_;
  std::vector<std::vector<Cell*>> lattice_;
};

#endif  // LATTICE2D_H