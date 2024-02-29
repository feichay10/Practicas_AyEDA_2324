/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cell.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CELL_H
#define CELL_H

#include <iostream>

#include "lattice.h"
#include "position.h"
#include "factoryCell.h"

class Lattice;
class Cell {
 public:
  Cell() = default;
  Cell(Position& position, const State& state) : position_(position), state_(state) {
    nextState_ = state_;
  }

  State getState() const { return state_; }
  void setState(State state) { state_ = state; }

  virtual void nextState(const Lattice& lattice) = 0;
  virtual void updateState() {
    state_ = nextState_;
  }

  virtual std::ostream& display(std::ostream&) = 0;
  friend std::ostream& operator<<(std::ostream& os, Cell& cell) {
    return cell.display(os);
  }

 protected:
  State state_;
  State nextState_;
  Position& position_;
};

#endif  // CELL_H