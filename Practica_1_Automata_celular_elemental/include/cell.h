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

// typedef int State;
enum State { kDead = 0, kAlive = 1 };
typedef int Position;

// class Lattice;

class Cell {
 public:
  // Constructor
  Cell() = default;
  Cell(const Position&, const State&);

  // Getters y Setters
  State getState() const;
  State setState(State);
  
  // Métodos de la clase
  int nextState(const Lattice&);
  void updateState();

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream&, const Cell&);

 private:
  Position position_;
  State state_;
  State nextState_;
};

#endif  // CELL_H_