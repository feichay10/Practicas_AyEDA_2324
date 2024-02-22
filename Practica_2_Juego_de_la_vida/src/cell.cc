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
// TODO: Corregir el calculo de vecinos
int Cell::neighbours(const Lattice& lattice) {
  int alive_neighbours = 0;
  for (int i = position_.getRow() - 1; i <= position_.getRow() + 1; i++) {
    for (int j = position_.getColumn() - 1; j <= position_.getColumn() + 1; j++) {
      if (i >= 0 && i < lattice.getRows() && j >= 0 && j < lattice.getColumns() && (i != position_.getRow() || j != position_.getColumn())) {
        if (lattice.getCell(Position(i, j)).getState() == kAlive) {
          alive_neighbours++;
        }
      }
    }
  }
  return alive_neighbours;
}

// Funcion de transicion local:
//  - Una celula en estado viva con 2 o 3 vecinas en estado viva continua en
//  estado viva en la siguiente generacion. En caso contrario, muere.
//  - Una celula en estado muerta con exactamente 3 vecinas en estado viva pasa
//  al estado viva en la siguiente generacion. En caso contrario, permanece en
//  estado muerta.
int Cell::nextState(const Lattice& lattice) {
  int alive_neighbours = neighbours(lattice);
  if (state_ == kAlive) {
    if (alive_neighbours == 2 || alive_neighbours == 3) {
      nextState_ = kAlive;
    } else {
      nextState_ = kDead;
    }
  } else {
    if (alive_neighbours == 3) {
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
  os << ((cell.getState() == kAlive) ? "X" : " ");
  return os;
}