/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file factoryCellLife51_346.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FACTORYCELLLIFE51_346_H
#define FACTORYCELLLIFE51_346_H

#include <iostream>

#include "cell.h"
#include "position.h"
#include "factoryCell.h"

class FactoryCellLife51_346 : public FactoryCell {
 public:
  Cell* createCell(const Position& p, const State& s) const {
    return new CellLife51_346(p, s);
  }
};

#endif  // FACTORYCELLLIFE51_346_H