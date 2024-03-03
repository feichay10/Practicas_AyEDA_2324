/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellACE.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CELLACE_H
#define CELLACE_H

#include "cell.h"

class Lattice1D;

class CellACE : public Cell {
 public:
  CellACE(const Position& position, const State& state);
  virtual void nextState(const Lattice1D& lattice) = 0;
  std::ostream& display(std::ostream& os) override;
};

#endif  // CELLACE_H