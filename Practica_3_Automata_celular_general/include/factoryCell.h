/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file factoryCell.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FACTORYCELL_H
#define FACTORYCELL_H

#include <iostream>

#include "cell.h"
#include "position.h"

enum State { kDead = 0, kAlive = 1 };

class Cell;

class FactoryCell {
 public:
  // Método creador de células
  virtual Cell* createCell(const Position& position, const State& state) const = 0;
};

#endif  // FACTORYCELL_H