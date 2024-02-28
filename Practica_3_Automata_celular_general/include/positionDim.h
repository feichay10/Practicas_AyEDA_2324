/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file positionDim.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef POSITIONDIM_H
#define POSITIONDIM_H

#include <iostream>
#include <stdexcept>

#include "position.h"

template <int Dim = 2, class Coordinate_t = int>
class PositionDim : public Position {
 private:
  Coordinate_t coordinates_[Dim];

 public:
  // Constructor con lista variable de parámetros
  PositionDim(int sz, ...) {
    va_list vl;
    va_start(vl, sz);
    for (int d = 0; d < Dim; d++) {
      coordinates_[d] = va_arg(vl, Coor_t);
    }
    va_end(vl);
  }

  Coor_t operator[](unsigned int) const;
};

template <int Dim, class Coordinate_t>
Coor_t PositionDim<Dim, Coordinate_t>::operator[](unsigned int i) const {
  if (i >= Dim) {
    throw std::out_of_range("PositionDim::operator[]");
  }
  return coordinates_[i];
}

#endif  // POSITIONDIM_H