/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file shakeSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SHAKESORT_H
#define SHAKESORT_H

#include "sortMethod.h"

/**
 * @brief Class ShakeSort that inherits from SortMethod.
 * 
 * @tparam Key 
 */
template <class Key>
class ShakeSort : public SortMethod<Key> {
 public:
  ShakeSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

/**
 * @brief Construct a new Shake Sort< Key>:: Shake Sort object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <class Key>
ShakeSort<Key>::ShakeSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

/**
 * @brief Function that sorts the sequence using the shake sort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void ShakeSort<Key>::Sort() {
  shakeSort(this->sequence_, this->size_, this->trace_);
}

#endif  // SHAKESORT_H