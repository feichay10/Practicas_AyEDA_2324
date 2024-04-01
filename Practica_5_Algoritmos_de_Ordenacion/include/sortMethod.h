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
#include "ordenation.h"

template <typename Key>
class SortMethod {
 public:
  SortMethod(StaticSequence<Key>& sequence, int size);
  virtual void Sort() = 0;

 protected:
  StaticSequence<Key>& sequence_;
  int size_;
};

template <typename Key>
SortMethod<Key>::SortMethod(StaticSequence<Key>& sequence, int size) : sequence_(sequence), size_(size) {}

#endif  // SORTMETHOD_H