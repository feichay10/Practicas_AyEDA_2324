/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cell.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/cell.h"

Cell::Cell(const Position& position, const State& state) : position_(position), state_(state) {}

State Cell::getState() const {
  return state_;
}

void Cell::setState(State state) {
  state_ = state;
}

void Cell::updateState() {
  state_ = nextState_;
}

std::ostream& operator<<(std::ostream& os, Cell& cell) {
  return cell.display(os);
}

// Clase ACE
CellACE::CellACE(const Position& position, const State& state) : Cell(position, state) {}

// Clase ACE110
CellACE110::CellACE110(const Position& position, const State& state) : CellACE(position, state) {}

void CellACE110::nextState(const Lattice1D& lattice) {
  int left = lattice[position_[0] - 1].getState();
  int center = lattice[position_[0]].getState();
  int right = lattice[position_[0] + 1].getState();

  nextState_ = static_cast<State>((center + right + center * right + left * center * right) % 2);
}

std::ostream& CellACE110::display(std::ostream& os) {
  os << state_;
  return os;
}