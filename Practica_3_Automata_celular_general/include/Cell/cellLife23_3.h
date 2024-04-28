/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellLife23_3.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CELLLIFE23_3_H
#define CELLLIFE23_3_H

#include <vector>

#include "cellLife.h"

class CellLife23_3 : public CellLife {
 public:
  CellLife23_3(Position& position, const State& state);
  void nextState(const Lattice& lattice);
  void updateState();
  std::ostream& display(std::ostream& os);
};

#endif  // CELLLIFE23_3_H