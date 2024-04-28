/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file factoryCellACE110.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FACTORYCELLACE110_H
#define FACTORYCELLACE110_H

#include <iostream>

#include "../Cell/cell.h"
#include "../Cell/cellACE.h"
#include "../Cell/cellACE110.h"
#include "factoryCell.h"

class FactoryCellACE110 : public FactoryCell {
 public:
  Cell* createCell(Position& p, const State& s) const override {
    return new CellACE110(p, s);
  }
};

#endif  // FACTORYCELLACE110_H