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
#include "position.h"

class Lattice1D : public Lattice {
 public:
  Lattice1D(int size, const FactoryCell& factory) {
    size_ = size;
    cells_ = new Cell*[size_];
    for (int i = 0; i < size_; i++) {
      cells_[i] = factory.createCell(PositionDim<1, int>(i), kDead);
    }    
  }
  Lattice1D(const char* file, const FactoryCell& factory) {}
  ~Lattice1D();

  void nextGeneration() override;
  std::size_t Population() const override;

  Cell& operator[](const Position&) const override;
  std::ostream& display(std::ostream&) const override;

 protected:
  Cell** cells_;
  int size_;
  PositionDim<1, int> position_;
};

#endif  // LATTICE1D_H