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

class Cell {
 public:
  Cell() = default;
  Cell(const Position& position, const State& state);
  Cell(const PositionDim<1, int>& position, const State& state);
  Cell(const PositionDim<2, int>& position, const State& state);

  State getState() const;
  void setState(State state);

  virtual void nextState(const Lattice& lattice) = 0;
  virtual void updateState();

  friend std::ostream& operator<<(std::ostream& os, Cell& cell);

 protected:
  virtual std::ostream& display(std::ostream&) = 0;

  State state_;
  State nextState_;
  const Position& position_;
};

#endif  // CELL_H