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

#include "state.h"
#include "cell.h"

class Cell;
class CellACE110;
class Position;

class FactoryCell {
 public:
  // Método creador de células
  virtual Cell* createCell(const Position& position, const State& state) const = 0;
};

class FactoryCellACE110 : public FactoryCell {
 public:
  Cell* createCell (const Position& p, const State& s) const override {
    // Cell* cell = new CellACE110(p, s);
    // return &cell;

    return new CellACE110(p, s);
  }
};

#endif  // FACTORYCELL_H