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

#include "position.h"

enum State { kDead = 0, kAlive = 1 };

class Lattice;
class Lattice1D;

class Cell {
 public:
  Cell() = default;
  Cell(Position& position, const State& state);

  virtual ~Cell() {}

  State getState() const { return state_; }
  void setState(State state) { state_ = state; }

  virtual void updateState() { state_ = nextState_; }
  virtual void nextState(const Lattice& lattice) = 0;

  virtual std::ostream& display(std::ostream&) = 0;
  friend std::ostream& operator<<(std::ostream& os, Cell& cell) {
    return cell.display(os);
  }

 protected:
  State state_;
  State nextState_;
  Position& position_;
};

class CellACE : public Cell {
 public:
  CellACE() = default;
  CellACE(const Position& position, const State state);

  virtual void nextState(const Lattice& lattice) override = 0;
  void updateState() override { state_ = nextState_; }

  virtual std::ostream& display(std::ostream& os) override = 0;
  friend std::ostream& operator<<(std::ostream& os, const CellACE& cell);
};

class CellACE110 : public CellACE {
 public:
  CellACE110() = default;
  CellACE110(const Position& position, const State state) : CellACE(position, state) {
    position_ = position;
    state_ = state;
  }

  void nextState(const Lattice1D& lattice) {
    int left = lattice[PositionDim<1, int>(position_[0] - 1)].getState();
    int right = lattice[PositionDim<1, int>(position_[0] + 1)].getState();
    int center = lattice[position_].getState();
  }

  std::ostream& display(std::ostream& os) const {
    os << state_;
    return os;
  }

  friend std::ostream& operator<<(std::ostream& os, const CellACE110& cell) {
    return cell.display(os);
  }
};

#endif  // CELL_H