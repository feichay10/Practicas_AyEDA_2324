/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file staticSequence.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
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
  StaticSequence(int blockSize);
  ~StaticSequence();
  bool search(const Key& k) const;
  bool insert(const Key& k);
  virtual bool isFull() const = 0;

 private:
  Key* data_;
  int size_;
  int capacity_;
  int blockSize_;
};

template <class Key>
StaticSequence<Key>::StaticSequence(int blockSize) : blockSize_(blockSize) {
  data_ = new Key[blockSize_];
  size_ = 0;
  capacity_ = blockSize_;
}

template <class Key>
StaticSequence<Key>::~StaticSequence() {
  delete[] data_;
}

template <class Key>
bool StaticSequence<Key>::search(const Key& k) const {
  for (int i = 0; i < size_; i++) {
    if (data_[i] == k) {
      return true;
    }
  }
  return false;
}

template <class Key>
bool StaticSequence<Key>::insert(const Key& k) {
  if (isFull()) {
    return false;
  }
  data_[size_] = k;
  size_++;
  return true;
}

#endif  // STATICSEQUENCE_H