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
#include "positionDim.h"

class CellACE : public Cell {
 public:
  CellACE(const Position&, const State);
  void nextState(const Lattice&) override;
  void updateState() override;
  std::ostream& display(std::ostream&);
  friend std::ostream& operator<<(std::ostream&, const CellACE&);

 private:
  PositionDim<1, int> position_;
};

#endif  // CELLACE_H