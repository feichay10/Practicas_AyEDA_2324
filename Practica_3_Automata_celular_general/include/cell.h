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
#include "state.h"

class Cell {
 public:
  Cell(const Position& position, const State& state);

  State getState() const;
  void setState(State state);

  virtual void nextState(const Lattice& lattice) = 0;
  void updateState();

  virtual std::ostream& display(std::ostream&) = 0;
  friend std::ostream& operator<<(std::ostream& os, Cell& cell);

 protected:
  State state_;
  State nextState_;
  const Position& position_;
};

class CellACE : public Cell {
 public:
  CellACE(const Position& position, const State& state) : Cell(position, state) {}

  virtual void nextState(const Lattice1D&) = 0;
  virtual std::ostream& display(std::ostream&) = 0;
};

class CellACE110 : public CellACE {
 public:
  CellACE110(const Position& position, const State& state);

  void nextState(const Lattice1D& lattice);
  
  std::ostream& display(std::ostream& os) override;
};

#endif  // CELL_H