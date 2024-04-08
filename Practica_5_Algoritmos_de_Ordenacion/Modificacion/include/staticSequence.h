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

/**
 * @brief Class StaticSequence that represents a static sequence of elements.
 * 
 * @tparam Key 
 */
template <class Key>
class StaticSequence : public Sequence<Key> {
 public:
  StaticSequence(const int& size);
  ~StaticSequence();
  int getSize();
  Key& operator[](const Position& i) const override;

 private:
  Key* sequence_;
  int size_;
};

/**
 * @brief Construct a new Static Sequence< Key>:: Static Sequence object
 * 
 * @tparam Key 
 * @param size 
 */
template <class Key>
StaticSequence<Key>::StaticSequence(const int& size) {
  size_ = size;
  sequence_ = new Key[size_];
}

/**
 * @brief Destroy the Static Sequence< Key>:: Static Sequence object
 * 
 * @tparam Key 
 */
template <class Key>
StaticSequence<Key>::~StaticSequence() {
  delete[] sequence_;
}

/**
 * @brief Function that returns the size of the sequence.
 * 
 * @tparam Key 
 * @return int 
 */
template <class Key>
int StaticSequence<Key>::getSize() {
  return size_;
}

/**
 * @brief Function that returns the element at the position i.
 * 
 * @tparam Key 
 * @param i 
 * @return Key& 
 */
template <class Key>
Key& StaticSequence<Key>::operator[](const Position& i) const {
  return sequence_[i];
}

#endif  // STATICSEQUENCE_H