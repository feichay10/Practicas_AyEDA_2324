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

#include <iostream>

#include "lattice.h"
#include "cellACE.h"

class Lattice1D : public Lattice {
 public:
  Lattice1D(int size);
  ~Lattice1D();

  void nextGeneration();
  std::size_t Population() const;

  Cell& operator[](const Position&) const;
  std::ostream& display(std::ostream&);

 private:
  void loadInitialConfiguration();

  int size_;
  CellACE** lattice1D_;
  int population_;
  borderType borderType_;
};

#endif  // LATTICE1D_H