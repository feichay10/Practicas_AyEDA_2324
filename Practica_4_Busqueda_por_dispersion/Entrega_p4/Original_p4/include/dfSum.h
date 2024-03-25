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

/**
 * @brief Class that represents the sum dispersion function
 * 
 * @tparam Key 
 */
template <class Key>
class dfSum : public DispersionFunction<Key> {
 public:
  explicit dfSum(const unsigned tableSize) : tableSize_(tableSize) {}
  unsigned operator()(const Key& k) const override;

 private:
  unsigned tableSize_; 
};

/**
 * @brief Operator that returns the sum of the key
 * 
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template <class Key>
unsigned dfSum<Key>::operator()(const Key& k) const {
  unsigned sum = 0;
  unsigned count = 0;
  // Iterate over the digits of the NIF to obtain the number of digits
  for (auto i : k) { 
    count++;
  }
  // Iterate over the digits of the NIF to sum them up
  for (unsigned i = 0; i < count; i++) { 
    sum += k[i];
  }
  return sum % tableSize_;
}

#endif  // DFSUM_H