/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file cell.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Representa la presencia o ausencia de vida en una posición del
 * tablero. Siendo responsable de encapsular su estado y posición, de conocer su
 * vecindad y la función de transición local, y de actualizar su estado para la
 * siguiente generación. Hay
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 *
 */

#ifndef CELL_H_
#define CELL_H_

#include <iostream>
#include <vector>

#include "lattice.h"
#include "position.h"

enum State { kDead = 0, kAlive = 1 };

class Lattice;

class Cell {
 public:
  // Constructor
  Cell();
  Cell(const Position&, const State&);

  // Getters y Setters
  State getState() const;
  State setState(State);
  void setPosition(const Position& position) { position_ = position; }

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