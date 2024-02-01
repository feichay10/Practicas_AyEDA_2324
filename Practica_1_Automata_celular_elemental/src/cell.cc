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

Cell::Cell() : position_(0), state_(0), nextState_(0) {}

Cell::Cell(const Position& position_, const State& state_) : position_(position_), state_(state_), nextState_(0) {}

State Cell::getState() const { return state_; }

void Cell::setState(State newState) { state_ = newState; }

int Cell::nextState(const Lattice& lattice) {
    int left = position_ - 1 < 0 ? 0 : lattice.getCell(position_ - 1).getState();
    int right = position_ + 1 >= lattice.getSize() ? 0 : lattice.getCell(position_ + 1).getState();
    nextState_ = left ^ (state_ | right); // Rule 30
    return nextState_;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  os << (cell.state_ ? 'X' : ' ');
  return os;
}