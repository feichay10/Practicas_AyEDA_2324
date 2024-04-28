/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file position.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef POSITION_H
#define POSITION_H

#include <stdarg.h>

#include <iostream>
#include <stdexcept>

typedef int Coor_t;

class Position {
 public:
  // Operador de acceso a la i-ésima coordenada
  virtual Coor_t operator[](unsigned int) const = 0;
};

#endif  // POSITION_H
