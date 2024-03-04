/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice2D_reflective.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/lattice2D_reflective.h"
#include "../include/positionDim.h"

Lattice2D_Reflective::Lattice2D_Reflective(int& rows, int& columns, const FactoryCell& factory, borderType border) : Lattice2D(rows, columns, factory, border) {}

Lattice2D_Reflective::~Lattice2D_Reflective() {}

Cell& Lattice2D_Reflective::operator[](const Position& position) const {
  int row = position[0];
  int column = position[1];

  if (row < 0 || row >= rows_ || column < 0 || column >= columns_) {
    Position* newPosition;
    if (row < 0) {
      row = 0;
    } 
    if (column < 0) {
      column = 1;
    }
    if (row >= rows_) {
      row = rows_ - 2;
    }
    if (column >= columns_) {
      column = columns_ - 2;
    }
    return *lattice_[row][column];
  }

  return *lattice_[row][column];
}