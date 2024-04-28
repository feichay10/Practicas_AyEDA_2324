/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file factoryCellACE30.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FACTORYCELLACE30_H
#define FACTORYCELLACE30_H

#include <iostream>

#include "../Cell/cell.h"
#include "../Cell/cellACE.h"
#include "../Cell/cellACE110.h"
#include "factoryCell.h"

class FactoryCellACE30 : public FactoryCell {
 public:
  Cell* createCell(Position& p, const State& s) const override {
    return new CellACE30(p, s);
  }
};

#endif  // FACTORYCELLACE30_H