/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file cell.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/cell.h"

Cell::Cell() {}

Cell::Cell(const Position& position, const State& state) {
  position_ = position;
  state_ = state;
}

State Cell::getState() const { return state_; }

State Cell::setState(State state) {
  state_ = state;
  return state_;
}

// Modificacion: Las vecindades son una posicion mas en el tablero
// por lo que se debe de cambiar la forma de acceder a ellas:
//                   |(i-2,j)|
//                   |(i-1,j)|
// (i,j-2) | (i,j-1) | (i,j) | (i,j+1) | (i,j+2)
//                   |(i+1,j)|
//                   |(i+2,j)|
// Luego probar con frontera reflectora
int Cell::nextState(const Lattice& lattice) {
  int aliveNeighbours = 0;
  std::vector<Cell> neighbours = {
    lattice[Position(position_.getRow() - 2, position_.getColumn())],
    lattice[Position(position_.getRow() - 1, position_.getColumn())],
    lattice[Position(position_.getRow(), position_.getColumn() - 2)],
    lattice[Position(position_.getRow(), position_.getColumn() - 1)],
    lattice[Position(position_.getRow(), position_.getColumn() + 1)],
    lattice[Position(position_.getRow(), position_.getColumn() + 2)],
    lattice[Position(position_.getRow() + 1, position_.getColumn())],
    lattice[Position(position_.getRow() + 2, position_.getColumn())]
  };

  for (const auto& neighbour : neighbours) {
    if (neighbour.getState() == kAlive) {
      aliveNeighbours++;
    }
  }

  if (state_ == kAlive) {
    nextState_ = (aliveNeighbours < 2 || aliveNeighbours > 3) ? kDead : kAlive;
  } else {
    nextState_ = (aliveNeighbours == 3) ? kAlive : kDead;
  }

  return nextState_;
}

void Cell::updateState() {
  state_ = nextState_;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  os << ((cell.getState() == kAlive) ? 'X' : ' ');
  return os;
}