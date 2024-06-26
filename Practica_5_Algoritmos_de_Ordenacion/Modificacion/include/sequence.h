/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file sequence.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <fstream>

typedef int Position; // Position in the sequence

/**
 * @brief Class Sequence that represents a sequence of elements.
 * 
 * @tparam Key 
 */
template <class Key>
class Sequence {
 public:
  virtual Key& operator[](const Position& i) const = 0;
};

#endif  // SEQUENCE_H