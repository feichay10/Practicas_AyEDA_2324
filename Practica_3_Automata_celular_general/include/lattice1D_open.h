/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice1D_open.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LATTICE1D_OPEN_H
#define LATTICE1D_OPEN_H

#include <iostream>

#include "lattice1D.h"

enum openBorderType { kCold = 0, kHot = 1 };

class Lattice1D_Open : public Lattice1D {
 public:
  Lattice1D_Open(int& size, const FactoryCell& factory, borderType border, openBorderType openBorderType);
  Lattice1D_Open(const std::string fileName, const FactoryCell& factory, borderType border, openBorderType openBorderType);
  ~Lattice1D_Open();
  Cell& operator[](const Position& position) const override;

 private:
  openBorderType openBorderType_ = kCold;
  Cell* borderLattice_;
};

#endif  // LATTICE1D_OPEN_H