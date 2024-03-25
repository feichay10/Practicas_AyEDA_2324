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
  SortMethod(StaticSequence<Key>& sequence, int size);
  virtual void Sort() = 0;

  void setTrace(bool trace);

 protected:
  void swap(Key& a, Key& b);
  void print();

  StaticSequence<Key>& sequence_;
  int size_;
  bool trace_ = false;
};

template <typename Key>
SortMethod<Key>::SortMethod(StaticSequence<Key>& sequence, int size) : sequence_(sequence), size_(size) {}

template <typename Key>
void SortMethod<Key>::setTrace(bool trace) {
  trace_ = trace;
}

template <typename Key>
void SortMethod<Key>::swap(Key& a, Key& b) {
  Key temp = a;
  a = b;
  b = temp;
}

template <typename Key>
void SortMethod<Key>::print() {
  for (int i = 0; i < size_; i++) {
    std::cout << sequence_[i] << sequence_[i].letterNif(sequence_[i]) << " ";
  }
  std::cout << std::endl;
}

#endif  // SORTMETHOD_H