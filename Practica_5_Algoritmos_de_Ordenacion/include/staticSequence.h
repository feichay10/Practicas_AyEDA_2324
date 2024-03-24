/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file staticSequence.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef STATICSEQUENCE_H
#define STATICSEQUENCE_H

#include "sequence.h"

template <class Key>
class StaticSequence : public Sequence<Key> {
 public:
  StaticSequence(const int& size);
  ~StaticSequence();

  void insert(const Key& k);
  void print();
  Key operator[](const int& i) const;
  int getSize() const;

 private:
  Key* sequence_;
  int size_;
};

template <class Key>
StaticSequence<Key>::StaticSequence(const int& size) {
  size_ = size;
  sequence_ = new Key[size_];
}

template <class Key>
StaticSequence<Key>::~StaticSequence() {
  delete[] sequence_;
}

template <class Key>
void StaticSequence<Key>::insert(const Key& k) {
  for (int i = 0; i < size_; i++) {
    if (sequence_[i] == 0) {
      sequence_[i] = k;
      break;
    }
  }
}

template <class Key>
void StaticSequence<Key>::print() {
  for (int i = 0; i < size_; i++) {
    std::cout << sequence_[i] << " ";
  }
}

template <class Key>
Key StaticSequence<Key>::operator[](const int& i) const {
  return sequence_[i];
}

template <class Key>
int StaticSequence<Key>::getSize() const {
  return size_;
}

#endif  // STATICSEQUENCE_H