/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file dynamicSequence.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DYNAMICSEQUENCE_H
#define DYNAMICSEQUENCE_H

#include "sequence.h"

/**
 * @brief Clase para implementar la técnica dispersion abierta
 * 
 * @tparam Key 
 */
template <class Key>
class DynamicSequence : public Sequence<Key> {
 public:
  DynamicSequence();
  ~DynamicSequence();

  bool search(const Key& k) const;
  bool insert(const Key& k);

 private:
  Key* data_;
  int size_ = 0;
};

template <class Key>
DynamicSequence<Key>::DynamicSequence() {
  data_ = new Key[size_];
}

template <class Key>
DynamicSequence<Key>::~DynamicSequence() {
  delete[] data_;
}

template <class Key>
bool DynamicSequence<Key>::search(const Key& k) const {
  for (int i = 0; i < size_; i++) {
    if (data_[i] == k) {
      return true;
    }
  }
  return false;
}

template <class Key>
bool DynamicSequence<Key>::insert(const Key& k) {
  if (!search(k)) {
    size_++;
    for (int i = 0; i < size_; i++) {
      if (data_[i] == NULL) {
        data_[i] = k;
        return true;
      }
    }
  }
  return false;
}

#endif // DYNAMICSEQUENCE_H