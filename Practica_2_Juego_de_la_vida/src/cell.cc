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

/**
 * @brief Funcion de transicion local:
 *  - Una celula en estado viva con 2 o 3 vecinas en estado viva continua en
 * estado viva en la siguiente generacion. En caso contrario, muere.
 *  - Una celula en estado muerta con exactamente 3 vecinas en estado viva pasa
 * al estado viva en la siguiente generacion. En caso contrario, permanece en
 * estado muerta.
 *
 * @param lattice
 * @return int
 */
int Cell::nextState(const Lattice& lattice) {
  // int alive_neighbours = neighbours(lattice);
  // if (state_ == kAlive) {
  //   if (alive_neighbours == 2 || alive_neighbours == 3) {
  //     nextState_ = kAlive;
  //   } else {
  //     nextState_ = kDead;
  //   }
  // } else {
  //   if (alive_neighbours == 3) {
  //     nextState_ = kAlive;
  //   } else {
  //     nextState_ = kDead;
  //   }
  // }
  // return nextState_;
}

void Cell::updateState() {}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {}