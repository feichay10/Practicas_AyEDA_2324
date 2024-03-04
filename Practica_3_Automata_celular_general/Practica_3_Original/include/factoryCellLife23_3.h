/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file factoryCellLife23_3.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FACTORYCELLLIFE23_3_H
#define FACTORYCELLLIFE23_3_H

#include <iostream>

#include "cell.h"
#include "cellLife.h"
#include "cellLife23_3.h"
#include "factoryCell.h"

class FactoryCellLife23_3 : public FactoryCell {
 public:
  Cell* createCell(Position& p, const State& s) const override {
    return new CellLife23_3(p, s);
  }
};

#endif  // FACTORYCELLLIFE23_3_H