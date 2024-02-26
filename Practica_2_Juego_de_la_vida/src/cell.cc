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

// Devuelve el numero de vecinos en estado viva
// La vecindad es la siguiente:
// (i-1,j-1)|(i-1,j)|(i-1,j+1)
// ---------------------------
// (i,j-1)| (i,j)| (i,j+1)
// ---------------------------
// (i+1,j-1)|(i+1,j)|(i+1,j+1)
// Devuelve el siguiente estado de la célula usar operador[] de Lattice
int Cell::nextState(const Lattice& lattice) {
  std::vector<Cell> neighbours = {
    lattice[Position(position_.getRow() - 1 , position_.getColumn() - 1)],
    lattice[Position(position_.getRow() - 1, position_.getColumn())],
    lattice[Position(position_.getRow() - 1, position_.getColumn() + 1)],
    lattice[Position(position_.getRow(), position_.getColumn() - 1)],
    lattice[Position(position_.getRow(), position_.getColumn() + 1)],
    lattice[Position(position_.getRow() + 1, position_.getColumn() - 1)],
    lattice[Position(position_.getRow() + 1, position_.getColumn())],
    lattice[Position(position_.getRow() + 1, position_.getColumn() + 1)],
  };

  // std::vector<Cell*> neighbours = lattice.getNeighbours(position_);
  int aliveNeighbours = 0;

  for (int i = 0; i < neighbours.size(); i++) {
    if (neighbours[i].getState() == kAlive) {
      aliveNeighbours++;
    }
  }

  if (state_ == kAlive) {
    if (aliveNeighbours < 2 || aliveNeighbours > 3) {
      nextState_ = kDead;
    } else {
      nextState_ = kAlive;
    }
  } else {
    if (aliveNeighbours == 3) {
      nextState_ = kAlive;
    } else {
      nextState_ = kDead;
    }
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