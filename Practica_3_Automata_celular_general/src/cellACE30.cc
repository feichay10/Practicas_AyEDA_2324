/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellACE30.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/cellACE30.h"
#include "../include/lattice1D_open.h"
#include "../include/positiondim.h"

CellACE30::CellACE30(Position& position, const State& state) : CellACE(position, state) {}

//  Implementar la regla 30 -> C^{G+1} = (L + C + R + C * R) % 2
void CellACE30::nextState(const Lattice& lattice) {
  int leftState = lattice[PositionDim<1>(1, position_[0] - 1)].getState();
  int rightState = lattice[PositionDim<1>(1, position_[0] + 1)].getState();
  int centerState = lattice[PositionDim<1>(1, position_[0])].getState();

  nextState_ = static_cast<State>((leftState + centerState + rightState + centerState * rightState) % 2);
}

void CellACE30::updateState() {
  state_ = nextState_;
}

std::ostream& CellACE30::display(std::ostream& os) {
  if (state_ == kDead) {
    os << " ";
  } else {
    os << "X";
  }

  return os;
}