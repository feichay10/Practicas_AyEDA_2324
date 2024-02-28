/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellACE110.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CELLACE110_H
#define CELLACE110_H

#include <iostream>

#include "cellACE.h"

class CellACE110 : public CellACE {
 public:
  CellACE110(const PositionDim<1, int>&, const State);

  void nextState(const Lattice&);
  void updateState();

  std::ostream& display(std::ostream&);
  friend std::ostream& operator<<(std::ostream&, const CellACE110&);
};

#endif  // CELLACE110_H