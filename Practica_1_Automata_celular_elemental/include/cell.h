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

#ifndef CELL_H_
#define CELL_H_

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "lattice.h"

typedef int State;
typedef int Position;

// class Lattice;

class Cell {
 public:
  Cell() : position_(0), state_(0), nextState_(0) {}  // Default constructor
  Cell(const Position& position_, const State& state_)
      : position_(position_), state_(state_), nextState_(0) {}
  State getState() const;
  void setState(State newState) { state_ = newState; }
  int nextState(const Lattice& lattice);
  void updateState() { state_ = nextState_; }
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

 private:
  Position position_;
  State state_;
  State nextState_;
};

#endif  // CELL_H_