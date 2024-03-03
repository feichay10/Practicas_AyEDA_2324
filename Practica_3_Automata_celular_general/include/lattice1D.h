/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice1D.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LATTICE1D_H
#define LATTICE1D_H

#include <fstream>
#include <iostream>
#include <vector>

#include "factoryCell.h"
#include "lattice.h"

class Lattice1D : public Lattice {
 public:
  Lattice1D(int& size, const FactoryCell& factory);
  Lattice1D(const char* fileName, const FactoryCell& factory);
  virtual ~Lattice1D();

  void nextGeneration();
  std::size_t Population() const;

 protected:
  std::ostream& display(std::ostream& os) const;
  void loadInitialLattice();
 
  int size_;
  Cell** lattice_;
};

#endif  // LATTICE1D_H