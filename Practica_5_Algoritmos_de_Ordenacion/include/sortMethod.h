/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file sortMethod.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SORTMETHOD_H
#define SORTMETHOD_H

#include "staticSequence.h"

template <typename Key>
class SortMethod {
 public:
  SortMethod(StaticSequence<Key>& sequence) : sequence_{sequence} {}
  virtual void Sort() const = 0;

 protected:
  StaticSequence<Key>& sequence_;
};

#endif  // SORTMETHOD_H