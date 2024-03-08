/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file dfSum.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DFSUM_H
#define DFSUM_H

#include "dispersionFunction.h"

template <class Key>
class dfSum : public DispersionFunction<Key> {
 public:
  explicit dfSum(const unsigned n) : tableSize_(n) {}
  unsigned operator()(const Key& k) const;

 private:
  unsigned tableSize_; 
};

// Basada en la suma, h(k) = sum(k_i) % tableSize
template <class Key>
unsigned dfSum<Key>::operator()(const Key& k) const {
  unsigned sum = 0;
  for (unsigned i = 0; i < k.size(); i++) {
    sum += k[i];
  }
  return sum % tableSize_;
}

#endif  // DFSUM_H