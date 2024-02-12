/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
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

State Cell::getState() const {
  return state_;
}

State Cell::setState(State state) {
  state_ = State(state);
  return state_;
}

/**
 * * Funcion de transicion de estado: (C + R + C * R + L * C * R) % 2
 * C = current, R = right, L = left
 */
int Cell::nextState(const Lattice& lattice) {
  // State left = lattice.getCell(position_ - 1).getState();
  // State right = lattice.getCell(position_ + 1).getState();
  // State current = lattice.getCell(position_).getState();

  // nextState_ = static_cast<State>((current + right + current * right + left * current * right) % 2);
  
  // return nextState_;

  State right = lattice.getCell(position_ + 1).getState();
  State left = lattice.getCell(position_ - 1).getState();

  nextState_ = static_cast<State>((state_ + right + state_ * right + left * state_ * right) % 2);

  return 0;
}

void Cell::updateState() {
  state_ = nextState_;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.getState() == kAlive) {
    os << "X";
  } else {
    os << " ";
  }

  // os << (cell.getState() == kAlive) ? "X" : " ";
  return os;
}