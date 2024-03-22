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
  StaticSequence(int size);
  Key operator[](const Position&) const override;

 private:
  int size_;
  Key* array_;
};

template <class Key>
StaticSequence<Key>::StaticSequence(int size) : size_(size) {
  array_ = new Key[size_];
}

template <class Key>
Key StaticSequence<Key>::operator[](const Position& position) const {
  return array_[position];
}

#endif  // STATICSEQUENCE_H