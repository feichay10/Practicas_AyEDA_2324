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
#include "lattice.h"

enum State { kDead = 0, kAlive = 1 };

class Lattice;
class Cell {
 public:
  Cell();
  Cell(const Position&, const State);

  State getState() const;
  void setState(State);

  virtual void nextState(const Lattice&) = 0;
  virtual void updateState();

  virtual std::ostream& display(std::ostream&) = 0;
  friend std::ostream& operator<<(std::ostream&, const Cell&);

protected:
  State state_;
  State nextState_;
};

#endif  // CELL_H