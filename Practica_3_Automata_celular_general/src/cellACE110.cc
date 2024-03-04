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
 *
 */

#include "../include/cellACE110.h"
#include "../include/lattice1D.h"
#include "../include/positiondim.h"

CellACE110::CellACE110(Position& position, const State& state) : CellACE(position, state) {}

// Implementar la regla 110-> C^{G+1} = (C + R + C * R + L * C * R) % 2
void CellACE110::nextState(const Lattice& lattice) {
  int leftState = lattice[PositionDim<1>(1, position_[0] - 1)].getState();
  int rightState = lattice[PositionDim<1>(1, position_[0] + 1)].getState();
  int centerState = lattice[PositionDim<1>(1, position_[0])].getState();

  nextState_ = static_cast<State>((centerState + rightState + centerState * rightState + leftState * centerState * rightState) % 2);
}

void CellACE110::updateState() {
  state_ = nextState_;
}

std::ostream& CellACE110::display(std::ostream& os) {
  os << (state_ == kDead ? " " : "X");
  return os;
}