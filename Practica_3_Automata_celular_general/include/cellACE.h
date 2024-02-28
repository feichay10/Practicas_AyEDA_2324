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
 * @brief Representa una célula de un autómata celular elemental y hereda de la
 * clase Cell
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

class Lattice;

class CellACE : public Cell {
 public:
  CellACE() = default;
  CellACE(const PositionDim<1, int>&, const State);

  std::ostream& display(std::ostream&);
  friend std::ostream& operator<<(std::ostream&, const CellACE&);

 protected:
  PositionDim<1, int> position_;
};

#endif  // CELLACE_H