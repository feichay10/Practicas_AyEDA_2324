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
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/cell.h"

Cell::Cell(const Position& position, const State& state) {
  position_ = position;
  state_ = state;
  nextState_ = 0;
}

State Cell::getState() const {
  return state_;
}

State Cell::setState(State newState) {
  state_ = newState;
  return state_;
}

int Cell::nextState(const Lattice& lattice) {
  int left = position_ - 1;
  int right = position_ + 1;
  if (left < 0) {
    left = lattice.getSize() - 1;
  }
  if (right == lattice.getSize()) {
    right = 0;
  }
  nextState_ = (lattice.getCell(left).getState() + lattice.getCell(right).getState()) % 2;
  return nextState_;
}

void Cell::updateState() {
  state_ = nextState_;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  os << cell.getState();
  return os;
}