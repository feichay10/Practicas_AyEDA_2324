/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellLife23_3.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/Cell/cellLife23_3.h"
#include "../include/Lattice/lattice2D.h"
#include "../include/Position/positionDim.h"

CellLife23_3::CellLife23_3(Position& position, const State& state) : CellLife(position, state) {}

void CellLife23_3::nextState(const Lattice& lattice) {
  // int aliveNeighbours = 0;
  // Position* pos_1 = new PositionDim<2>(2, position_[0] - 1, position_[1] - 1);
  // Position* pos_2 = new PositionDim<2>(2, position_[0] - 1, position_[1]);
  // Position* pos_3 = new PositionDim<2>(2, position_[0] - 1, position_[1] + 1);
  // Position* pos_4 = new PositionDim<2>(2, position_[0], position_[1] - 1);
  // Position* pos_5 = new PositionDim<2>(2, position_[0], position_[1] + 1);
  // Position* pos_6 = new PositionDim<2>(2, position_[0] + 1, position_[1] - 1);
  // Position* pos_7 = new PositionDim<2>(2, position_[0] + 1, position_[1]);
  // Position* pos_8 = new PositionDim<2>(2, position_[0] + 1, position_[1] + 1);
  
  // std::vector<Cell> neighbours = {
  //   lattice[*pos_1],
  //   lattice[*pos_2],
  //   lattice[*pos_3],
  //   lattice[*pos_4],
  //   lattice[*pos_5],
  //   lattice[*pos_6],
  //   lattice[*pos_7],
  //   lattice[*pos_8]
  // };

  // for (const auto& neighbour : neighbours) {
  //   if (neighbour.getState() == kAlive) {
  //     aliveNeighbours++;
  //   }
  // }

  // if (state_ == kAlive) {
  //   nextState_ = (aliveNeighbours < 2 || aliveNeighbours > 3) ? kDead : kAlive;
  // } else {
  //   nextState_ = (aliveNeighbours == 3) ? kAlive : kDead;
  // }
}

void CellLife23_3::updateState() {
  state_ = nextState_;
}

std::ostream& CellLife23_3::display(std::ostream& os) {
  os << (state_ == kDead ? " " : "X");
  return os;
}