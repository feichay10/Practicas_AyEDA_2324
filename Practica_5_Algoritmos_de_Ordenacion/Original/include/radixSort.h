/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file radixSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "sortMethod.h"

/**
 * @brief Class RadixSort that inherits from SortMethod.
 * 
 * @tparam Key 
 */
template <class Key>
class RadixSort : public SortMethod<Key> {
 public:
  RadixSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

/**
 * @brief Construct a new Radix Sort< Key>:: Radix Sort object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <class Key>
RadixSort<Key>::RadixSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

/**
 * @brief Function that sorts the sequence using the radix sort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void RadixSort<Key>::Sort() {
  radixSort(this->sequence_, this->size_, this->trace_);
}


#endif // RADIXSORT_H