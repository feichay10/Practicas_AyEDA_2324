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

#include <stdarg.h>

#include <iostream>
#include <stdexcept>

#include "position.h"

template <int Dim = 2, class Coordinate_t = int>
class PositionDim : public Position {
 public:
  // Constructor con lista variable de parámetros
  PositionDim(int sz, ...);

  // Operador de acceso a la i-ésima coordenada
  Coor_t operator[](unsigned int) const;

 private:
  Coordinate_t coordinates_[Dim];
};

template <int Dim, class Coordinate_t>
PositionDim<Dim, Coordinate_t>::PositionDim(int sz, ...) {
  if (sz != Dim) {
    throw std::invalid_argument("Invalid number of coordinates");
  }
  va_list args;
  va_start(args, sz);
  for (int i = 0; i < sz; i++) {
    coordinates_[i] = va_arg(args, Coordinate_t);
  }
  va_end(args);
}

template <int Dim, class Coordinate_t>
Coor_t PositionDim<Dim, Coordinate_t>::operator[](unsigned int i) const {
  if (i >= Dim) {
    throw std::out_of_range("Invalid coordinate index");
  }
  return coordinates_[i];
}

#endif  // POSITIONDIM_H