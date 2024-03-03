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
#include <fstream>
#include <vector>

#include "lattice.h"
#include "factoryCell.h"

class Lattice1D : public Lattice {
 public:
  Lattice1D(const int& size, const FactoryCell& factory);
  Lattice1D(const char* fileName, const FactoryCell& factory);
  ~Lattice1D();

  void nextGeneration() override;
  std::size_t Population() const override;

  Cell* operator[](const PositionDim<1,int>& position) const;

 protected:
  std::ostream& display(std::ostream& os, const Lattice& lattice) override;
  int size_;
  Cell** cells_;
  borderType borderType_;
};

#endif  // LATTICE1D_H