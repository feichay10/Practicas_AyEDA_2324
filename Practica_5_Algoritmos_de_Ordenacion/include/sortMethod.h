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
  virtual void Sort(StaticSequence<Key>& sequence, int size) = 0;
  void setTrace(bool trace);
  bool getTrace();
  void print(StaticSequence<Key>& sequence, int size);

 protected:
  void swap(Key& a, Key& b);
  bool trace_ = false;
};

template <typename Key>
void SortMethod<Key>::setTrace(bool trace) {
  trace_ = trace;
}

template <typename Key>
bool SortMethod<Key>::getTrace() {
  return trace_;
}

template <typename Key>
void SortMethod<Key>::print(StaticSequence<Key>& sequence, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << sequence[i] << " ";
  }
  std::cout << std::endl;
}

template <typename Key>
void SortMethod<Key>::swap(Key& a, Key& b) {
  Key temp = a;
  a = b;
  b = temp;
}

#endif  // SORTMETHOD_H