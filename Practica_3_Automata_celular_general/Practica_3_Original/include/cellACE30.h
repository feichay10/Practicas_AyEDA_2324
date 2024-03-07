/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellACE30.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CELLACE30_H
#define CELLACE30_H

#include "cellACE.h"

class CellACE30 : public CellACE {
 public:
  CellACE30(Position& position, const State& state);
  void nextState(const Lattice& lattice);
  void updateState();
  std::ostream& display(std::ostream& os);
};

#endif  // CELLACE30_H