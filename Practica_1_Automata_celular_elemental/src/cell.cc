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
  state_ = kDead;
  nextState_ = kDead;
}

State Cell::getState() const {
  return state_;
}

State Cell::setState(State newState) {
  state_ = newState;
}

int Cell::nextState(const Lattice& lattice) {
  // Funcion de transicion de estado: (C+R+C*R+L*C*R)%2
  int left = lattice.getCell(position_ - 1).getState();
  int right = lattice.getCell(position_ + 1).getState();
  
}

void Cell::updateState() {
  state_ = nextState_;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  
}