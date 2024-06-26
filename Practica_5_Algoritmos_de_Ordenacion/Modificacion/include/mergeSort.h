/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file mergeSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include "sortMethod.h"

/**
 * @brief Class MergeSort that inherits from SortMethod.
 * 
 * @tparam Key 
 */
template <class Key>
class MergeSort : public SortMethod<Key> {
 public:
  MergeSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

/**
 * @brief Construct a new Merge Sort< Key>:: Merge Sort object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <class Key>
MergeSort<Key>::MergeSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

/**
 * @brief Function that sorts the sequence using the merge sort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void MergeSort<Key>::Sort() {
  mergeSort(this->sequence_, 0, this->size_ - 1, this->trace_);
}

#endif  // MERGESORT_H