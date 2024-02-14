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
  state_ = state;
  return state_;
}

/**
 * Reglas del autómata celular:
 * 111 -> 0
 * 110 -> 1
 * 101 -> 1
 * 100 -> 0
 * 011 -> 1
 * 010 -> 0
 * 001 -> 1
 * 000 -> 1
 */
int Cell::nextState(const Lattice& lattice) {
  int left = lattice.getCell(position_ - 1).getState();
  int right = lattice.getCell(position_ + 1).getState();
  int center = lattice.getCell(position_).getState();

  // nextState_ = static_cast<State>((center + right + center * right + left * center * right) % 2);
  
  // return 0;

  if (left == kAlive && center == kAlive && right == kAlive) {       // 111
    nextState_ = kDead;
  } else if (left == kAlive && center == kAlive && right == kDead) { // 110
    nextState_ = kAlive;
  } else if (left == kAlive && center == kDead && right == kAlive) { // 101
    nextState_ = kAlive;
  } else if (left == kAlive && center == kDead && right == kDead) {  // 100
    nextState_ = kDead;
  } else if (left == kDead && center == kAlive && right == kAlive) { // 011
    nextState_ = kAlive;
  } else if (left == kDead && center == kAlive && right == kDead) {  // 010
    nextState_ = kDead;
  } else if (left == kDead && center == kDead && right == kAlive) {  // 001
    nextState_ = kAlive;
  } else if (left == kDead && center == kDead && right == kDead) {   // 000
    nextState_ = kAlive;
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