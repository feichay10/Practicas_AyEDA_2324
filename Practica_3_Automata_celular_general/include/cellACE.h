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

#include <iostream>

#include "cell.h"

// class Cell;

class CellACE : public Cell {
 public:
  CellACE() = default;
  CellACE(const Position&, const State);

  void nextState(const Lattice& lattice);
  void updateState();

  friend std::ostream& operator<<(std::ostream&, const CellACE&);

 private:
  PositionDim<1, int> position_;

  std::ostream& display(std::ostream&) override;
};

#endif  // CELLACE_H