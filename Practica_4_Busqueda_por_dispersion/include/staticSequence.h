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
#include <vector>

template <class Key>
class StaticSequence : public Sequence<Key> {
 public:
  StaticSequence(unsigned blockSize);
  ~StaticSequence();

  bool search(const Key& k) const;
  bool insert(const Key& k);
  bool remove(const Key& k);
  bool isFull() const;
  void print();

 private:
  // Key* data_;
  // Key data_[];
  std::vector<Key> data_;
  unsigned blockSize_;
};

template <class Key>
StaticSequence<Key>::StaticSequence(unsigned blockSize) {
  // data_ = new Key[blockSize];
  data_.resize(blockSize);
  // Eliminar el contenido del array
  for (unsigned i = 0; i < blockSize; i++) {
    data_[i] = 0;
  }

  blockSize_ = blockSize;
}

template <class Key>
StaticSequence<Key>::~StaticSequence() {
  delete[] data_;
}

template <class Key>
bool StaticSequence<Key>::search(const Key& k) const {
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == k) {
      return true;
    }
  }
  return false;
}

template <class Key>
bool StaticSequence<Key>::insert(const Key& k) {
  if (search(k)) {
    std::cout << "Element " << k << " already exists " << std::endl;
    return false;
  }
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == 0) {
      data_[i] = k;
      return true;
    }
  }
  return false;
}

template <class Key>
bool StaticSequence<Key>::isFull() const {
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == 0) {
      return false;
    }
  }
  return true;
}

template <class Key>
bool StaticSequence<Key>::remove(const Key& k) {
  if (!search(k)) {
    std::cout << "Element " << k << " does not exist " << std::endl;
    return false;
  }
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == k) {
      data_[i] = 0;
      std::cout << "Element " << k << " removed " << std::endl;
      return true;
    }
  }
  return false;
}

template <class Key>
void StaticSequence<Key>::print() {
  for (unsigned i = 0; i < blockSize_; ++i) {
    std::cout << "[" << data_[i] << "] ";
  }  
}

#endif  // STATICSEQUENCE_H