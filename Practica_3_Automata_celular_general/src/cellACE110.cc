/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellACE110.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/cellACE110.h"

CellACE110::CellACE110(const Position& position, const State& state) : CellACE(position, state) {}

void CellACE110::nextState(const Lattice1D& lattice) {
  int left = lattice[PositionDim<1, int>(1, position_[0] - 1)].getState();
  int right = lattice[PositionDim<1, int>(1, position_[0] + 1)].getState();
  int center = lattice[PositionDim<1, int>(1, position_[0] + 1)].getState();

  nextState_ = static_cast<State>((left + center + right) % 2);
}