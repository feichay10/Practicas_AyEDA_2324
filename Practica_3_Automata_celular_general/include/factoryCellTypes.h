/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file factoryCellTypes.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FACTORYCELLTYPES_H
#define FACTORYCELLTYPES_H

#include <iostream>

#include "cell.h"
#include "cellACE.h"
#include "cellACE110.h"
#include "factoryCell.h"

class FactoryCellACE110 : public FactoryCell {
 public:
  Cell* createCell(const Position& p, const State& s) const override {
    return new CellACE110(p, s);
  }
};

// class FactoryCellACE30 : public FactoryCell {
//  public:
//   Cell* createCell (const Position& p, const State& s) const override {
//     return new CellACE30(p, s);
//   }
// };

// class FactoryCellLife23_3 : public FactoryCell {
//  public:
//   Cell* createCell (const Position& p, const State& s) const override {
//     return new CellLife23_3(p, s);
//   }
// };

// class FactoryCellLife51_346 : public FactoryCell {
//  public:
//   Cell* createCell (const Position& p, const State& s) const override {
//     return new CellLife51_346(p, s);
//   }
// };

#endif  // FACTORYCELLTYPES_H