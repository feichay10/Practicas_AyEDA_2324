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

#include "cellACE.h"

class CellACE110 : public CellACE {
 public:
  CellACE110(const Position& position, const State& state) : CellACE(position, state) {}
  void nextState(const Lattice& lattice) override;
  void updateState() override;
  std::ostream& display(std::ostream& os) override;
};

#endif  // CELLACE110_H