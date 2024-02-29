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
  Cell(Position& position, const State& state);

  State getState() const;
  void setState(State);

  virtual void nextState(const Lattice&) = 0;
  virtual void updateState();

  friend std::ostream& operator<<(std::ostream&, const Cell&);

 protected:
  State state_;
  State nextState_;
  Position& position_;

  virtual std::ostream& display(std::ostream&) = 0;
};

#endif  // CELL_H